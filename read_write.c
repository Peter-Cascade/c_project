#include <unistd.h>  // 提供 read, write, STDIN_FILENO 等系统调用
#include <string.h>  // 提供 strlen
#include <stdio.h>   // 提供 perror, putchar

#define BUFFSIZE 4
void main() { // ❌ 老规矩，你自己写必须写 int main(void)
    const char* prompt = "Four characters, please: ";
    char buffer[BUFFSIZE]; // 准备一个 4 字节的数组（接水的水桶）
    
    // 1. 往屏幕（fd=1）输出提示语
    write(1, prompt, strlen(prompt));
    
    // 2. 从键盘（fd=0）读取最多 4 个字节，放到 buffer 里
    // flag 记录实际读到了几个字节，比如用户输入"ab\n"，flag 就是 3
    ssize_t flag = read(0, buffer, sizeof(buffer));
    
    if (flag < 0) {
        // 3. 如果 read 返回 -1，说明读取失败（比如被中断）
        perror("Ooops..."); // perror 会打印 "Ooops... + 系统具体错误原因"
    } else {
        // 4. 如果读取成功，把读到的数据原样写到屏幕（fd=1）
        write(1, buffer, sizeof(buffer)); // ⚠️ 这里书上写得有漏洞！
    }
    
    putchar('\n'); // 打印一个换行符
}