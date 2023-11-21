#include <stdio.h>
#include <time.h>

void funcA(int vec[], int N) {
    // Funcion para ingresar elementos enteros random
    // de 0 al 999 a un vector de N elementos.

    srand(time(NULL));

    for (int i = 0; i < N; i++) vec[i] = (rand()%1000);
}


int funcB(int vec[], int N) {
    // Funcion que devuelve la posicion del maximo del vector.

    int max = vec[0];
    int pos = 0;

    for (int i =1; i < N; i++)
        if(vec[i] > max) {
            max = vec[i];
            pos = i;
        }

    return pos;
}

int funcC(int vec[], int N) {
    // Funcion que devuelve la posicion del minimo del vector.

    int min = vec[0];
    int pos = 0;

    for (int i =1; i < N; i++)
        if(vec[i] < min) {
            min = vec[i];
            pos = i;
        }

    return pos;
}

void funcD(int vec[], int N) {
    // Funcion que muestra el vector en pantalla.

    printf("Vector: ");
    for (int i = 0; i < N; i++) {
        printf("%d", vec[i]);
        if (i != N-1)
            printf(", ");
        else
            printf("\n");
    }
}
