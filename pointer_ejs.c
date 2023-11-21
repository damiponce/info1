#include <stdio.h>
#include <string.h>

void main() {
//    ej1();
//    ej2();
//    ej3();
    ej4();
}

void ej1() {
    printf("== EJERCICIO 1 ==\n");

    int a = 6;
    int b = 9;
    int *pa = &a;
    int *pb = &b;

    printf("a: %d\n", *pa);
    printf("b: %d\n", *pb);
    printf("a+b: %d\n", *pa + *pb);

    printf("\n");
}

///== BEGIN EJ2 ==///


void ingreso(int * pint, float * pfloat, char * pchar) {
    scanf("%d", pint);
    scanf("%f", pfloat);
    getchar();
    scanf("%c", pchar);
}

void ej2() {
    printf("== EJERCICIO 2 ==\n");

    int i;
    float f;
    char c;

    ingreso(&i, &f, &c);

    printf("%d, %f, %c",i, f, c);

    printf("\n");
}

///== END EJ2 ==///



///== BEGIN EJ3 ==///

void ej3() {
    printf("== EJERCICIO 3 ==\n");

    char str1[50] = "Esta noche va a llover!";
    char str2[50] = "va a llover";

    printf("Encontrado: %d", buscar_str(&str1, &str2));

    printf("\n");
}

int buscar_str(char * pstr1, char * pstr2) {
    char * b_pstr2 = pstr2;
    int found = 0;

    for (int i = 0; i < 50; i++) {
        if (tolower(*pstr1) == tolower(*pstr2)) {
            pstr2++;
        } else {
            pstr2 = b_pstr2;
        }

        if (*pstr2 == '\0') found = 1;
        pstr1++;
    }
    return found;
}

///== END EJ3 ==///




///== BEGIN EJ4 ==///

void ej4() {
    printf("== EJERCICIO 4 ==\n");

    int vec[10] = {1,2,3,4,2,1,8,1,3,9};
    int * pts[10];

    printf("\nCantidad de minimo: %d", mins(vec, pts));

    printf("\n");
}

int mins(int *pvec, int **ppvec) {
    int min = pvec[0], j = 0;

    for (int i = 1; i < 10; i++) {
        if (pvec[i] < min) min = pvec[i];
    }

    for (int i = 0; i < 10; i++) {
        if (pvec[i] == min) {
            ppvec[j] = &pvec[i];
            j++;
        };
    }

    printf("Minimo en indice(s): ");

    for (int k = 0; k < j; k++) {
        printf("%d ", *(ppvec+k) - pvec);
    }

    return j;

}


///== END EJ4 ==///
