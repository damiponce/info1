#include<stdio.h>
#define I 12
#define J 9
int cols[9] = {8,6,4,2,1,3,5,7,9};


int main() {
    int matrix[I][J] = {{0}};
    int i = 0, j, n;

    do {
        printf("\n");
        nicePrintMatrix(I,J,matrix);

        printf("\nRESERVA (fila negativa termina)\n");
        do {
            printf("Ingrese fila: ");
            scanf("%d", &i);
        } while (i == 0 || i > I );

        if (!(i < 0)) {
            do {
                printf("Ingrese butaca: ");
                scanf("%d", &j);
            } while (j < 1 || j > J);

            do {
                printf("Ingrese cantidad: ");
                scanf("%d", &n);
            } while (j < 1 || j > J);

//            j = searchVec(cols, J, j);

            int available = 1, k, jj = searchVec(cols, J, j);

            if (J - jj  < n) available = 0;
            while (available == 1 && k < jj && jj < J) {
                k = jj;

                if (matrix[i-1][k] != 0) {
                    available = 0;

                }

                k++;
            }
            system("cls");
            if (available == 1) {
                for (k = jj; k < jj + n; k++) {
                    matrix[i-1][k] = 1;
                }
            } else {
                printf("\n!!! Rango de asientos ocupado !!!");
            }
        }
    } while (i >= 0);

    int available = 0, reserved = 0, rowCounts[I], rowCountsSorted[2][I], colCounts[J], colCountsSorted[J];


    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            if (matrix[i][j] == 0)
                available++;
            else reserved++;
        }
    }

    printf("\n\n");
    printf("Disponibles: %d\n", available);
    printf("Reservados: %d\n", reserved);

    for (int i = 0; i < I; i++) {
        int thisRow = 0;
        for (int j = 0; j < J; j++) {
           if (matrix[i][j] > 0) thisRow++;
        }
        rowCounts[i] = thisRow;
    }


    printf("\n");
    int arr[J];
    sortArray(J, rowCounts, rowCountsSorted);
    printf("Filas");
    printMatrix(2, J, rowCountsSorted);
    printf("Reservas en fila \n");


    return 0;
}

void sortArray(int len, int arr[len], int sortedArr[2][len]) {

    for (int i = 0; i < len; i++) {
        sortedArr[0][i] = i + 1;
        sortedArr[1][i] = arr[i];
    }

    int n = len, newn;

    do {
        newn = 0;
        for (int i = 1; i < n; i++) {
            if (sortedArr[1][i-1] < sortedArr[1][i]) {
                int temp = sortedArr[1][i-1];
                sortedArr[1][i-1] = sortedArr[1][i];
                sortedArr[1][i] = temp;

                temp = sortedArr[0][i-1];
                sortedArr[0][i-1] = sortedArr[0][i];
                sortedArr[0][i] = temp;

                newn = i;
            }
        }
        n = newn;
    } while (n > 1);



}


void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}




int searchVec(int vec[], int len, int search) {
    // devuelve el indice de search en el array
    // si no se encuentra devuelve -1

    int index = -1;
    int iter = 0;
    while (iter < len && index == -1) {
        if (vec[iter] == search) index = iter;
        iter++;
    }

    return index;
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

void nicePrintMatrix(int a, int b, int matrix[a][b]) {
    printf("\n");
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == 0 && j == 0) {
                printf("   ");
            } else if (i == 0 && j > 0) {
                printf("%2d", cols[j-1]);
            } else if (j == 0 && i > 0) {
                printf("F%02d", i);
            } else if (i > 0 && j > 0) {
                if (matrix[i-1][j-1] == 0)
                    printf("%2c", '*');
                else printf("%2c", 'R');
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
