#include <stdio.h>
#include <ctype.h>
#include <string.h>

int i_maq, i_hs;

// data[maq-100][hs-8];
int data[10][11];
int suma_dia[10];

void main() {
    input();

}

void input() {
    do {
        input_maq();
        if (i_maq != 0) {
            input_hs();
            data[i_maq-100][i_hs-8]++;
        }
    } while (i_maq != 0);
    show_table();
    sin_fallas();
}

void sin_fallas() {
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 11; j++) {
            suma_dia[i] += data[i][j];
        }
    }
    printf("Maqs sin fallas: \n");
    for (int i = 0; i < 10; i++) {
        if (suma_dia[i] == 0) printf("%d, ", i + 100);
    }
}

void show_table() {
    printf("\nFALLAS\nMaq  ");
    for (int i = 0; i < 10; i++) {
        printf(" %d", 100 + i);
    }
    printf("\nHora \n");

    for (int i = 0; i < 11; i++) {
        printf("%-5d", i + 8);
        for (int j = 0; j < 10; j++) {
            printf("%4d", data[j][i]);
        }
        printf("\n");
    }
}

void input_maq() {
    do {
        printf("Ingresar numero de maquina: ");
        scanf("%d", &i_maq);
    } while(!(i_maq == 0 || (i_maq >= 100 && i_maq <= 109)));
}

void input_hs() {
    do {
        printf("Ingresar hora de la falla: ");
        scanf("%d", &i_hs);
    } while(!(i_hs >= 8 && i_hs <= 18));
}
