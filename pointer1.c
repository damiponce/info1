#include <stdio.h>

int * busqueda(int * pvec, int search);
int * max_pointer(int * pvec);

void main() {
//a();
//b();
//c();
//d();
//e();
f();
}

void f() {
    int vec[7] = {1,2,5,3,6,9,4};
    int * max = max_pointer(&vec);
    printf("Puntero max: %p", max);
    printf("\nValor max: %d", * max);
    printf("\nPosicion max: %d", max - vec );
}

int * max_pointer(int * pvec) {
    int max_value = *pvec;
    int * max_pointer = pvec;
    for (int i = 0; i < 6; i++) {
        pvec++;
        if (*pvec > max_value) {max_value = *pvec; max_pointer = pvec;}
    }
    return max_pointer;
}

void e() {
    int vec[5];
    carga(&vec);
    mostrar(&vec);

    printf("\nAddr. of 77: %p", busqueda(&vec, 77));
}

int * busqueda(int *pvec, int search) {
    int * found = NULL;
    for (int i = 0; i < 5; i++) {
        if (*pvec == search) {
            found = pvec;
        }
        pvec++;
    }
    return found;
}

void carga(int *pvec) {
    for (int i = 0; i < 5; i++) {
        printf("Ingresar entero: ");
        scanf("%d", pvec++);
    }
}

void mostrar(int *pvec) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", * pvec++);
    }
}

void d() {
    int vec[5];
    int *p;
    p = vec;
//  p + i = &vec[i];
//  *(p + i) = vec[i]
}

void c() {
    int *p = (int *) 0x20BCFA00;
    int *q = (int *) 0x20BCFA08;
    printf("%d", q-p);
}

void b() {
    int *p = (int *) 0x20BCFA00;
    p++;
    printf("%p", p);
    p += 2;
    printf("\n%p", p);
}


void a() {
    int var, *p;
    p = &var;
    *p = 10;

    printf("Addr. var: %p\n", &var);
    printf("Addr. pnt: %p\n", &p);
    printf("Cont. var: %d\n", var);
    printf("Cont. var: %d\n", *p);
    printf("Cont. pnt: %d\n", p);
}
