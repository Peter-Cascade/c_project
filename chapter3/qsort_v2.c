#include <stdio.h>
#include <stdlib.h>

typedef int (*CompFunc)(const void*, const void*);

int comp_ascd(const void* p1, const void* p2){
    return *((int*) p1) - *((int*) p2);
}

int main(void){
    CompFunc func = comp_ascd;

    int arr[] = {541, 87, 22, 1, 364};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), func);
    printf("sorted arr: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}