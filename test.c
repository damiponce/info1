#include<stdio.h>

#define LEN 10

int main() {
    int vec[LEN];
    int invec[LEN];
    printf("%d", length(vec));
    carga(vec);
    invertir(vec, invec);
    mostrar(invec);
    return 0;
}

void carga(int vec[]) {
    for (int i = 0; i < length(vec); i++) {
        printf("Ingresar numero: ");
        scanf("%d", &vec[i]);
    }
}

void invertir(int vec[], int invec[]) {
    for (int i = 0; i < length(vec); i++) {
        invec[length(vec)-1-i] = vec[i];
    }
}

void mostrar(int vec[]) {
    for (int i = 0; i < length(vec); i++) {
        printf("%d ", vec[i]);
    }
}

int length(int vec[]) {
    return 10;
    return sizeof(vec)/sizeof(vec[0]);
}
