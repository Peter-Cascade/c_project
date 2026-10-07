#include <stdio.h>

int main(void){
    char* s1 = "123456";
    char* s2 = "123.45";
    int n1;
    float n2;

    sscanf(s1, "%i", n1);
    sscanf(s2, "%f", &n2);
    printf("%i %f\n", n1 + 3, n2 + 8.7f);

    char buffer[64];
    sprintf(buffer, "%i", n1 + 3);
    printf("%s\n", buffer);

    return 0;
}