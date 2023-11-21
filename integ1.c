#include <stdio.h>
#include "SimIntegrador1.c"

#define ordenarMayoraMenor(vec,N) { int i,j;server *aux; \
    for (i=0; i<N-1; i++) \
        for (j=0; j<N-1; j++) \
            if ((*(vec+j))->prom < (*(vec+j+1))->prom) { \
                aux = *(vec+j); \
                *(vec+j) = *(vec+j+1); \
                *(vec+j+1) = aux;\
            }}

typedef struct {
    unsigned int se:5;
    unsigned int t :7;
             int   :2;
    unsigned int s :1;
    unsigned int f :1;
} sensor_data;

typedef union {
    unsigned char c[2];
    sensor_data d;
} un;

typedef struct {
    unsigned int suma;
    unsigned int cant;
    unsigned int id;
    unsigned int alarma;
    unsigned int prom;
} server;

void main() {
    ioperm(0x400, 2, 1);
    ioperm(0x911, 1, 1);

    server temps[32] = {0};
    server *pnt[32];
    for (int i = 0; i<32; i++)
        *(pnt+i) = temps+i;

    un data;

    int n_alarmas = 0;

    int f = 0;
    do {
        do {
            data.c[1] = inb(0x401);
        } while(data.d.s == 0);

        if (data.d.f == 1) {
            f = 1;
        } else {
            data.c[0] = inb(0x400);
            data.c[1] = inb(0x401);

            temps[data.d.se].suma += data.d.t;
            temps[data.d.se].cant++;
            temps[data.d.se].id = data.d.se;
            if (data.d.t > 100) {
                outb(0xff, 0x911);
                temps[data.d.se].alarma = 1;
            } else {
                temps[data.d.se].alarma = 0;
            }
            do {
                data.c[1] = inb(0x401);
            } while(data.d.s == 1);

            data.c[0] = inb(0x400);
            data.c[1] = inb(0x401);
        }
//        printf("finished %d", data.d.se);
    } while(f == 0);

    for (int i = 0; i < 32; i++)
        if (temps[i].cant > 0)
            temps[i].prom = temps[i].suma/temps[i].cant;

    printf("===================\n");
    printf(" RAW DATA          \n");
    printf("===================\n");

    printf(" ID SUM   N AVG   A\n");
    printf("--- --- --- --- ---\n");
    for (int i = 0; i < 32; i++) {
        server k = temps[i];
        if (k.cant > 0)
            printf("%3d %3d %3d %3d %3d\n", k.id, k.suma, k.cant, k.prom, k.alarma);
    }

    ordenarMayoraMenor(pnt, 32);


    printf("\n");
    printf("===================\n");
    printf(" SORTED DATA       \n");
    printf("===================\n");

    printf(" ID SUM   N AVG   A\n");
    printf("--- --- --- --- ---\n");
    for (int i = 0; i < 32; i++) {
        server k = **(pnt+i);
        if (k.cant > 0)
            printf("%3d %3d %3d %3d %3d\n", k.id, k.suma, k.cant, k.prom, k.alarma);
    }


    printf("\n");
    for (int i = 0; i < 32; i++) {
        if (temps[i].alarma) {
            n_alarmas++;
            printf("Servidor #%d salto alarma.\n", temps[i].id);
        }
    }

    printf("Cant. alarmas: %d\n", n_alarmas);

    ioperm(0x400, 2, 0);
    ioperm(0x911, 1, 0);
}

