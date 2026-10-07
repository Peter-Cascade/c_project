#include <stdio.h>
#include <stdlib.h>
#define SIZES 1000
#define SIZEA 100

typedef struct 
{
    /* data */
    double nums[SIZES];
    int n;

}BigNumsStruct;

int comp(const void* p1, const void* p2){
    BigNumsStruct* ptr1 = *((BigNumsStruct**) p1);
    BigNumsStruct* ptr2 = *((BigNumsStruct**) p2);
    return ptr1->n - ptr2->n;

}

int main(void){
    BigNumsStruct big_nums[SIZEA];
    BigNumsStruct* pointers[SIZEA];

    int i; 
    for (i = 0; i < SIZEA; i++)
}