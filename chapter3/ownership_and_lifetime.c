#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 64

void get_name1(char buffer[], size_t len){
    strncpy(buffer, "Gandalf", len);

}

void* get_name2(){
    void* ptr = malloc(BUFFSIZE + 1);
    if (!ptr) {
        return 0;
    }
    strcpy(ptr, "Sam");
    return ptr;
}

char* get_name3(){
    char buffer[BUFFSIZE + 1];
    strcpy(buffer, "Frodo");
    return buffer;
}

int main(void){
    // test 1
    char buffer1[BUFFSIZE + 1];
    get_name1(buffer1, BUFFSIZE);
    printf("test1: %s\n", buffer1);

    // test 2
    void* retval2 = get_name2();
    printf("test2: %s\n", (char*)retval2);

    // test 3
    const char* retval3 = get_name3();
    printf("test3: %s\n", retval3);

    free(retval2);

    return 0;
}