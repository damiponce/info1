#include <stdio.h>

void main() {

    typedef struct {
        unsigned int a;
        unsigned int b:5;
        unsigned int c:3;
    } st;

    typedef union {
        st s;
        unsigned char c[9];
    } u;

    u X;


    printf("%d", sizeof(X.s.a));



}
