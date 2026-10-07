#include <stdio.h>
#include <stdlib.h>

int main(void){
    int* p = (int*)malloc(sizeof(int));

    if (p == NULL){
        printf("malloc failed\n");
        return 1;
    }

    *p = 42;
    printf("the value on heap: %d\n", *p);
    printf("address of p: %p\n", (void*)&p);
    printf("address p point to: %p\n", (void*)p);

    free(p);

    p = NULL;

    return 0;
}
