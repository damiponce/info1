#include<stdio.h>
#define I 3
#define J 2

int main() {
    int matrix[I][J];

    loadMatrix(I,J,matrix);
nicerPrintMatrix(I,J,matrix);

    return 0;
}

void loadMatrix(int i, int j, int matrix[I][J]) {
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
}

void printMatrix(int i, int j, int matrix[I][J]) {
    printf("\n");
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void nicePrintMatrix(int i, int j, int matrix[I][J]) {
    printf("\n");
    for (int i = 0; i <= I; i++) {
        for (int j = 0; j <= J; j++) {
            if (i == 0 && j == 0) {
                printf("    ");
            } else if (i == 0 && j > 0) {
                printf("  C%d", j);
            } else if (j == 0 && i > 0) {
                printf("  F%d", i);
            } else if (i > 0 && j > 0) {
            printf("%4d", matrix[i-1][j-1]);
            }
        }
        printf("\n");
    }
}

void nicerPrintMatrix(int i, int j, int matrix[I][J]) {
    printf("\n    C1  C2");
    for (int i = 0; i < I; i++) {
        printf("\nF%d", i+1);
        for (int j = 0; j < J; j++) {
            printf("%4d", matrix[i][j]);
        }
    }
}
