#include<stdio.h>
#define I 2
#define J 3

int main() {
    int matrix[I][J];
    int Tmatrix[J][I];

    loadMatrix(I,J,matrix);
    printMatrix(I,J,matrix);

    transposeMatrix(matrix,Tmatrix);

    printMatrix(J,I,Tmatrix);
    return 0;
}

void transposeMatrix(int matrix[I][J], int Tmatrix[J][I]) {
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            Tmatrix[j][i] = matrix[i][j];
        }
    }
}

void loadMatrix(int i, int j, int matrix[I][J]) {
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
}

void printMatrix(int a, int b, int matrix[a][b]) {
    printf("\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
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
    printf("\n    C1  C2  C3");
    for (int i = 0; i < I; i++) {
        printf("\nF%d", i+1);
        for (int j = 0; j < J; j++) {
            printf("%4d", matrix[i][j]);
        }
    }
}
