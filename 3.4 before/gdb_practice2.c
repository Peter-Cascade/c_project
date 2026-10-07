#include <stdio.h>

int main(){
    printf("%s\n", "hello");
    int *p = NULL;
    *p = 10;
    printf("%s\n", "world");

    return 0;
}