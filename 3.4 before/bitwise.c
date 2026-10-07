#include <stdio.h>

int main(){
    unsigned a;
    scanf("%u", &a);
    printf("result:%x", (a >> 8)|(a << 8));
    return 0;
}