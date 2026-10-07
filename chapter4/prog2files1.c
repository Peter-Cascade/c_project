#include <stdio.h>

int global_num = -999;
extern void doubleup();
extern void print(){
    printf("global_num: %i\n", global_num);

}

static void set2zero(){
    global_num = 0;

}
int main(void){
    doubleup();
    doubleup();
    print();

    set2zero();
    print();
    return 0;
}