#include <stdio.h>
#include <stdlib.h>

int main(void){
    const char* s1 = "27";
    const char* s2 = "27.99";
    const char* s3 = " 123";
    const char* e1 = "1z2q";
    const char* e2 = "4m3.abc!#";

    printf("%s + 3 is %i\n", s1, atoi(s1) + 3);
    printf("%s + 3 is %f.\n", s1, atoi(s2) + 3.0);
    printf("%s to int is %i.\n", s3, atoi(s3)); 
    printf("%s to int is %i.\n", e1, atoi(e1)); 
    printf("%s to float is %f.\n", e2, atof(e2));

    char* bad_chars = NULL;
    const char* e3 = "9876 !foo bar";
    long num = strtol(e3, &bad_chars, 10);
    printf("Number: %li\tJunk: %s\n", num, bad_chars);
    
    
    return 0;
}