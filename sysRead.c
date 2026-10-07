#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define FILE_NAME "nums.dat"
int main(void){
    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) {
        perror(NULL);
        return 1;

    }
    int read_in[5];
    ssize_t how_many = read(fd, read_in, sizeof(read_in));
    if (how_many < 0) {
        perror(NULL);
        return 1;
    }

    close(fd);

    int i;
    int n = how_many / sizeof(int);
    for (i = 0; i < n; i++){
        printf("%i\n", read_in[i] * 10);
    }

    return 0;
}