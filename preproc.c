#include "preproc_macros.c"

void main() {
    int arr[LEN];
    cargar(arr);
    mostrar(arr);
    ordenar(arr);
    mostrar(arr);
    int max;
    maximo(arr,max);
    printf("\nMaximo: %d", max);
}
