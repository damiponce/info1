#include<stdio.h>

int main() {
    int v1[5], v2[5], vsum[10];
    carga(v1, 5);
    carga(v2, 5);
    unir(v1, v2, vsum);
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
        int temp;
        if (i < 5)
            {temp = v1[i];}
        else
            {temp = v2[i-5];}
        vsum[i] =  temp;
    }
}

void mostrar(int vec[], int len) {
    for (int i = 0; i < length(vec); i++) {
        printf("%d ", vec[i]);
    }
}

