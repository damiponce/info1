#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main() {
    /*

    Ingresar nombre y DNI de los alumnos de un curso. Como maximo hay 50 alumnos.
    La carga finaliza con un alumno de nombre "fin".

    Al finalizar la carga:

        a) Permitir buscar alumnos por nombre y si lo encuentra mostrar su DNI.
           Fin del proceso de busqueda al ingresar como nombre "NOBUSCARMAS"

        b) Mostrar listado de alumnos (nombre y DNI) ordenado alfabeticamente.
    */

    char nombre[50][30], nombreS[50][30];
    int dni[50], dniS[50];

    char nombre_in[30];
    int i = 0;
    do {
        printf("Ingresar nombre: ");
        read_str(nombre_in, 30);
        if (strcmpi(nombre_in, "fin")) {
            strcpy(nombre[i], nombre_in);
            do {
                printf("Ingresar DNI: ");
                scanf("%d", &dni[i]);
                fflush(stdin);
            } while (dni[i] < 1000000 || dni[i] > 99999999);
            i++;
        }
    } while (strcmpi(nombre_in, "fin"));

    sortArray(i, nombre, nombreS, dni, dniS);
    printArray(i, nombreS, dniS);

    return 0;
}

void printArray(int len, char str[len][30], int arr[len]) {
    for (int i = 0; i < len; i++) {
        printf("%30s %d\n", str[i], arr[i]);
    }
}


void sortArray(int len, char arrA[len][30], char sortedArrA[len][30], int arrB[len][30], int sortedArrB[len]) {

    for (int i = 0; i < len; i++) {
//        sortedArrA[i] = i + 1;
        strcpy(sortedArrA[i], arrA[i]);
//        sortedArrB[i] = i + 1;
        sortedArrB[i] =  arrB[i];
    }

    int n = len, newn;

    do {
        newn = 0;
        for (int i = 1; i < n; i++) {
//            if (sortedArr[1][i-1] < sortedArr[1][i]) {
            if (strcmpi(sortedArrA[i-1], sortedArrA[i])) {
                char temp[30];
                strcpy(temp, sortedArrA[i-1]);
                strcpy(sortedArrA[i-1], sortedArrA[i]);
                strcpy(sortedArrA[i], temp);

                int tempN = sortedArrB[i-1];
                sortedArrB[i-1] = sortedArrB[i];
                sortedArrB[i] = tempN;

                newn = i;
            }
        }
        n = newn;
    } while (n > 1);



}


void read_str(char str[], int len) {
    int i = 0;
    fgets(str, len, stdin);
    while (str[i] != '\0') i++;
    if (str[i-1] == '\n') str[i-1] = '\0';
}

int str_len(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}
