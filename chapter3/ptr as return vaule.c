#include <stdio.h>
#include <limits.h>

// 为了测试方便，我们可以不覆盖，或者定义一个新的宏
// 假设我们要测试 16 * 48 = 768，用真正的 INT_MAX 是不会溢出的
// 如果要用 100 作为阈值，就用 100 代替

int safe_mult(int n1, int n2, int *product){
    int flag = 0; // 默认无溢出
    
    // 检查 n2 不为 0，且 n1 大于 INT_MAX / n2，说明 n1 * n2 会溢出
    if (n2 != 0 && n1 > INT_MAX / n2) {
        flag = 1; // 标记溢出
    }
    
    *product = n1 * n2; // 无论是否溢出，都计算并写入
    return flag;
}

int main(void) {
    int result;
    int flag = safe_mult(16, 48, &result);
    printf("16 * 48 = %d, 溢出标志: %d\n", result, flag);
    
    // 如果把 INT_MAX 改成 100，那么 16 * 48 = 768 肯定溢出了
    return 0;
}