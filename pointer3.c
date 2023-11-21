#include <stdio.h>

void main() {
    typedef struct {
        char nom[31];
        int dni;
    } alumno;

    alumno al;

    printf("Ingresar nombre: ");
    read_str(al.nom, 31);
    printf("Ingresar dni: ");
    scanf("%d", &al.dni);

    alumno *p = &al;

    printf("Nombre y DNI (*): %s, %d\n", (*p).nom, (*p).dni);
    printf("Nombre y DNI (->): %s, %d\n", p->nom, p->dni);





}


void read_str(char str[], int len) {
    int i = 0;
    fgets(str, len, stdin);
    while (str[i] != '\0') i++;
    if (str[i-1] == '\n') str[i-1] = '\0';
}
