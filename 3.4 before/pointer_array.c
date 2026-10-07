#include <stdio.h>

#define SIZE 8

int main(void){
    int arr[8] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("arr's address(value) is %p\n", (void*) arr);
    printf("p's adderss %p\n", (void*)p);
    printf("arr[0]'s address %p\n", (void*)&arr[0]);
    printf("arr[1]'s address %p\n", (void*)&arr[1]);
    printf("arr[2]: %d, *(arr+2): %d, *(p+2): %d\n", arr[2], *(arr+2), *(p+2));
    
    p = p + 1; // 合法！p 是变量，钥匙换到下一个房间
    printf("p 移动后，*p 的值: %d\n", *p);
    return 0;
}