#include <stdio.h>

#define SIZEF 109
#define SIZEB 87

void foo(){
    static unsigned n = 0;
    if (SIZEF == ++n){
        printf("foo: %i\n", n);

    }
}

void bar(){
    static unsigned n;
    if (SIZEB == ++n){
        printf("bar: %i\n", n);
    }
}

int main(void){
    unsigned i = 0, limit_foo = SIZEF, limit_bar = SIZEB;
    while (i++ < limit_foo){
        foo();
    }
    i = 0;
    while (i++ < limit_bar){
        bar();
    }
    
    return 0;
}