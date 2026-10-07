#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    unsigned id;
    unsigned len;
    float* heap_nums;

} HeapStruct;
unsigned structId = 1;

HeapStruct* get_heap_struct(unsigned n){
    HeapStruct* heaps_truct = malloc(sizeof(HeapStruct));
    if (NULL == heaps_truct){
        return NULL;
    }

    heaps_truct -> heap_nums = malloc(sizeof(float) * n);
    if (NULL == heaps_truct -> heap_nums){
        free(heaps_truct);

        return NULL;
    }

    heaps_truct -> id = structId++;
    heaps_truct -> len = n;
    return heaps_truct;

}

void free_all(HeapStruct* heap_struct){
    if (NULL == heap_struct){
        return;
    }

    free(heap_struct -> heap_nums);

    free(heap_struct);

}

int main(){
    const unsigned n = 100;
    HeapStruct* hs = get_heap_struct(n);

    unsigned i;
    for (i = 0; i < n; i++) {
        hs -> heap_nums[i] = 3.14 + (float) i;
    }
    for (i = 0; i < n; i += 10) {
        printf("%12f\n", hs -> heap_nums[i]);
    }

    free_all(hs);

    return 0;
}