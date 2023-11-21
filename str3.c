#include <stdio.h>
#include <string.h>


int main() {
    char nombre[50], apellido[50], completo[100];

    read_str(nombre, 50);
    read_str(apellido, 50);

    strcpy(completo, apellido);
    strcat(completo, ", ");
    strcat(completo, nombre);
    printf("%s", completo);

    return 0;
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
