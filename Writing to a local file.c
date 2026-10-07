#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_NAME "numes.dat"

int main(void){
    int fd = open(FILE_NAME,
        O_CREAT | O_RDWR,

        S_IRUSR | S_IWUSR | S_IXUSR| 
        
        S_IROTH | S_IWOTH | S_IXOTH);  // permission 0777
    
    if (fd < 0) {
        perror(NULL);
        return 1;
    }

    int nums[] = {9, 7, 5, 3, 1};
    ssize_t flag = write(fd, nums, sizeof(nums));
    if (flag < 0) {
        perror(NULL);
        return 1;
    }

    flag = close(fd);
    if (flag < 0) {
        perror(NULL);
    }

    return 0;
}