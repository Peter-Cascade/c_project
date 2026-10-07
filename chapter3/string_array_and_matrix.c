#include <stdio.h>

int main(void){
    char *strings[] = {"qejd", "g", "png", 0};
    for (int i = 0; strings[i] != 0; i++){
        printf("strings[%d] 的地址: %p, 指向的内容: %s\n", i, (void*)strings[i], strings[i]);
    }
    char matrix[3][5] = {"qr", "qerf", "q"};
    printf("matrix[0]'s address: %p\n", (void*)(matrix[0]));
    printf("matrix[1]'s address: %p\n", (void*)(matrix[1]));
    printf("matrix[2]'s address: %p\n", (void*)(matrix[2]));

    printf("&strings[0] 指针变量自己的地址: %p\n", (void*)&strings[0]);
    printf("&strings[1] 指针变量自己的地址: %p\n", (void*)&strings[1]);
    printf("&strings[2] 指针变量自己的地址: %p\n", (void*)&strings[2]);

    return 0;
}



#include <stdio.h>

// 1. 定义别名（函数接收 int 数组和长度，返回 int）
typedef int (*ArrayOp)(int arr[], int len);

int len_arr(int arr[]){
    return sizeof(arr) / sizeof(arr[0]);
}

int my_max(int arr[], int len) {
    // 你的代码：遍历找最大值
    int max = arr[0];
    for (int i = 1; i < len; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int my_min(int arr[], int len) {
    // 你的代码：遍历找最小值
    int min = arr[0];
    for (int i = 1; i < len; i++){
        if (arr[i] > min){
            min = arr[i];
        }
    }
    return min;
}

// 3. 执行器
int execute(ArrayOp op, int arr[], int len) {
    return op(arr, len); // 调用函数指针
}

int main(void) {
    int nums[] = {42, 17, 99, 5, 33};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    // 4. 调用
    printf("Max: %d\n", execute(my_max, nums, n));
    printf("Min: %d\n", execute(my_min, nums, n));
    return 0;
}