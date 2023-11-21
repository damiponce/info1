#include<stdio.h>

int main() {
    int id[10] = {0};
    int prod[10] = {0};
    int num, index;

    printf("Ingresar IDs iniciales\n");
    for (int i = 0; i < 10; i++) {
        id[i] = ingresarID();
    }

    printf("\nCantidades\n");
    do {
        num = ingresarID();
        index = buscar(id, 10, num);
        if (num != 0 && index != -1) {
            prod[index] += ingresarCantidad();
        } else {
            printf("\n");
        }
    } while (num != 0);

    for (int i = 0; i < 10; i++) {
        printf("Cantidad de ID %d: %d\n", id[i], prod[i]);
    }

    return 0;
}

int ingresarCantidad() {
    int cant;
    do {
        printf("Ingresar cantidad positiva: ");
        scanf("%d", &cant);
    } while(cant < 0);
    return cant;
}

int buscar(int vec[], int len, int search) {
    // devuelve el indice de search en el array
    // si no se encuentra devuelve -1

    int index = -1;
    int i = 0;
    while (i < len && index == -1) {
        if (vec[i] == search) index = i;
        i++;
    }

    return index;
}

int ingresarID() {
    int num;
    do {
        printf("Ingrese ID de 4 digitos o 0: ");
        scanf("%d", &num);
    } while (num < 0 || num > 9999);
    return num;
}

void carga(int vec[], int len) {
    for (int i = 0; i < len; i++) {
        printf("Ingresar numero: ");
        scanf("%d", &vec[i]);
    }
}

void mostrar(int vec[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", vec[i]);
    }
}

