#include <stdio.h>
#include <stdlib.h>

int comp_ascd(const void* p1, const void* p2){
    int n1 = *((int*) p1);
    int n2 = *((int*) p2);
    return n1 - n2;
}

int comp_dscd(const void* p1, const void* p2){
    return *((int*) p2) - *((int*) p1);
}

int main(void){
    int arr[] = {59, 45, 63, 1, 22, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("the original array:\n");
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }

    printf("sort by ascend:\n");
    qsort(arr, n, sizeof(int), comp_ascd);
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}