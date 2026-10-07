#include <stdio.h>

int main(){
    int n = -1;
    while(1){
        printf("A non-negative intiger, please:");
        scanf("%i", &n);
        if (n > 0) break;
    printf("n is %i\n", n);
    return 0;
    }
}