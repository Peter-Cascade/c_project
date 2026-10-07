#include <stdio.h>
#define SIZE 100

typedef struct 
{double nums1[SIZE];
double nums2[SIZE];
int nums3[SIZE];
float nums4[SIZE];
float nums5[SIZE];
int n;
    /* data */
}BigNumsStruct;

void good(BigNumsStruct* ptr){
    printf("%lu\n", sizeof(ptr));
    printf("%i %i\n", (*ptr).n, ptr->n);
}

void bad(BigNumsStruct arg){
    printf("Argument size is: %lu\n", sizeof(arg));

}

int main(void){
    BigNumsStruct bns;
    bns.n = -9876;
    bad(bns);
    good(&bns);  /*encode first and decode when used*/
}