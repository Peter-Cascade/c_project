#include <stdio.h>
#include <stdlib.h>


typedef int(*CompFunc)(const int, const int);

int max(const int n1, const int n2){
    return (n1 > n2)? n1: n2;
}

int len(int arr[]){
    return sizeof(arr) / sizeof(arr[0]);
}

int execute(CompFunc func, int arr[], int len){
    int result = arr[0];
    for (int i = 1; i < len; i++){
        result = func(result, arr[i]);
    }
    return result;
}

int main(){
    int arr[] = {156, 8888, 30, 141414, 10};
    int n = len(arr);
    int result = execute(max, arr, n);
    printf("the max element is: %d\n", result);
    return 0;
}

/*1.C 语言里，数组作为参数传递时，永远会丢失长度信息。你不能在函数里计算长度，必须在数组退化为指针之前算好。修改你的 main 函数.
2.你在 execute 里写了 int arr[]，这在语法上是合法的（它其实等同于 int *arr）。但为了严谨，通常写成 int *arr 更能提醒自己它是个指针。
3.*/