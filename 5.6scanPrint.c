#include <stdio.h>
#define FILE_NAME "data.in"

int main(void) {
    float num;
    printf("A floating-point value, please: ");
    int how_many_floats = fscanf(stdin, "%f", &num);

    if (how_many_floats < 1){
        fprintf(stderr, "Bad scan -- probably bad characters\n");

    }
    else {
        fprintf(stdout, "%f times 2.1 is %f\n", num, num * 2.1);

    }

    FILE* fptr = fopen(FILE_NAME, "w");
    if (!fptr) {
        perror("Error on fopen");

    }
    int i;
    for (i = 0; i < 5; i++){
        fprintf(fptr, "%i\n", i + 1);
    fclose(fptr);

    fptr = fopen(FILE_NAME, "r");
    int n;
    puts("\nScanning from the input file:");
    while (fscanf(fptr, "%i", &n) != EOF) /* EOF == -1 == all 1s 
in binary */
    printf("%i\n", n);
    fclose(fptr);
    }
}