#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SOURCE "source.txt"
#define DESK "desk.txt"
int main(void) {
    int fd = open(SOURCE, O_RDONLY);
    int to = open(DESK, O_RDWR | O_CREAT | O_TRUNC, 0644);

    char buffer[1024];
    ssize_t total_read = 0;
    ssize_t bytes_read;
    while (1) {
        bytes_read = read(fd, buffer + total_read, sizeof(buffer) - total_read);
        if (bytes_read < 0) {
            return -1;
        }
        if (0 == bytes_read){
            break;
        }
        total_read += bytes_read;
    }
    write(to, buffer, total_read);

    close(fd);
    close(to);

    return 0;

}