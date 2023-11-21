#include <stdio.h>
#include "preproc_ejs_func.c"
#include "preproc_ejs_macr.c"


#define EJERCICIO 4

#if EJERCICIO == 12
void main() {
    int vec[10];
    funcA(vec, 10);
    printf("index max.: %d\n", funcB(vec, 10));
    printf("index min.: %d\n", funcC(vec, 10));
    funcD(vec, 10);
    ordenarMayoraMenor(vec, 10);
    funcD(vec, 10);
    ordenarMenoraMayor(vec, 10);
    funcD(vec, 10);
}
#elif EJERCICIO == 3
#define N 100
void main() {
    int vec[N];
    int SELECT = 3;
    funcA(vec, N);
    switch(SELECT){
        case 0:
            printf("index max.: %d\n", funcB(vec, 10));
            break;
        case 1:
            printf("index min.: %d\n", funcC(vec, 10));
            break;
        case 2:
            ordenarMayoraMenor(vec, 10);
            funcD(vec, 10);
            break;
        case 3:
            ordenarMenoraMayor(vec, 10);
            funcD(vec, 10);
            break;
    }
}
#elif EJERCICIO == 4
#define DEBUG
void main() {
    int i, s = 0;
    for (i = 0; i < 10; i++) {
        s+=i;
        #ifdef DEBUG
            printf("Suma parcial: %d\n", s);
        #endif // DEBUG
    }
    printf("\nSuma total: %d\n", s);
}
#endif
