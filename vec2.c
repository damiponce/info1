#include<stdio.h>

int main() {
    int v1[5], v2[5], vsum[10];

    printf("Primer array\n");
    carga(v1, 5);

    printf("\nSegundo array\n");
    carga(v2, 5);

    unir(v1, v2, vsum);

    printf("\nArray unido:\n");
    mostrar(vsum, 10);

    return 0;
}

void carga(int vec[], int len) {
    for (int i = 0; i < len; i++) {
        printf("Ingresar numero: ");
        scanf("%d", &vec[i]);
    }
}

void unir(int v1[], int v2[], int vsum[]) {
    for (int i = 0; i < 10; i++) {
        if (i < 5)
            vsum[i] = v1[i];
        else
            vsum[i] = v2[i-5];
    }
}

void mostrar(int vec[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", vec[i]);
    }
}

