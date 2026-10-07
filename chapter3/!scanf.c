#include <stdio.h>

int main(void) {
    const char* raw = "12:34:56";
    int h, m, s;
    
    // 1. 尝试解析
    int items = sscanf(raw, "%d:%d:%d", &h, &m, &s);
    printf("Time: %02d:%02d:%02d (Parsed %d items)\n", h, m, s, items);
    
    // 2. 制造错误格式
    const char* bad = "12-34-56";
    items = sscanf(bad, "%d:%d:%d", &h, &m, &s);
    printf("Items parsed from bad string: %d\n", items); // 你猜是多少？
    
    // 3. 使用磁盘文件/缓冲区时，sscanf 的常见替代方案是 strtok（以后学）
    
    return 0;
}