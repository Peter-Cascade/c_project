# include <stdio.h>

#define BAD_SQUARE(x) x * x
#define GOOD_SQUARE(x) ((x) * (x))

int main(void){
    printf("BAD_SQUARE(1+2) = %d\n",BAD_SQUARE(1 + 2));
    printf("GOOD_SQUARE(1+2) = %d\n", GOOD_SQUARE(1 + 2));
    
    return 0;
}