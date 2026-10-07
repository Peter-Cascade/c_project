# include <stdio.h>

int main(void){
    int table[3][4] = {
        {1, 2, 3, 4},
        {9, 8, 7, 6},
        {3, 5, 7, 9}
    };
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            printf("%i ", table[i][j]);
    printf("\n");

    int* ptr = (int*) table;
    for (i = 0; i < 12; i++)
        printf("%i ", ptr[i]);
    printf("\n");

    return 0;
}
