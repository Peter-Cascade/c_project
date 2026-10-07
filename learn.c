#include <stdio.h>
#include <stdlib.h>

#define SOURCE "source.txt"
#define DEST "dest.txt"

int main(void){
    FILE* fptr_s = fopen(SOURCE, "r");
    FILE* fptr_d = fopen(DEST, "w");
    if (NULL == fptr_s || NULL == fptr_d) {
        fprintf(stdout, "fopen error\n");
        return 1;
    }

    char buffer[1024];
    int bytes_Size = fread(buffer, 1, sizeof(buffer), fptr_s);
    while (bytes_Size > 0){
        fwrite(buffer, 1, bytes_Size, fptr_d);
        bytes_Size = fread(buffer, 1, sizeof(buffer), fptr_s);
    }

    fclose(fptr_s);
    fclose(fptr_d);

    return 0;
}