#include<stdio.h>

int main() {
    int prod[10] = {0};
    int num;

    do {
        num = scan();
        if (num != 0) {
            int cant;
            do {
                printf("Ingresar cantidad positiva: ");
                scanf("%d", &cant);
            } while(cant < 0);
            prod[num-1] += cant;
        } else {
            printf("\n");
        }
    } while (num != 0);

    for (int i = 0; i < 10; i++) {
        printf("Cantidad de ID %d: %d\n", i+1, prod[i]);
    }

    return 0;
}

int scan() {
    int num;
    do {
        printf("Ingrese ID o 0: ");
        scanf("%d", &num);
    } while (num < 0 || num > 10);
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

