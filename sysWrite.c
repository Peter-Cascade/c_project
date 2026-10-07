#include <stdio.h>
#include <fcntl.h>

int main(void){
    printf("O_RDONLY = %d (0x%x)\n", O_RDONLY, O_RDONLY);
    printf("O_WRONLY = %d (0x%x)\n", O_WRONLY, O_WRONLY);
    printf("O_RDWR   = %d (0x%x)\n", O_RDWR, O_RDWR);
    printf("O_CREAT  = %d (0x%x)\n", O_CREAT, O_CREAT);

    int my_flags = O_RDWR |O_CREAT;
    printf("O_REWR | O_CREAT + %d (0x%x)\n", my_flags, my_flags);

    if (my_flags & O_CREAT) {
        printf("检查通过：用户要求 O_CREAT\n");
    }
    if (my_flags & O_RDWR) {
        printf("检查通过：用户要求 O_RDWR\n");
    }
    
    return 0;
}
