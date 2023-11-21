#include<stdio.h>

int main() {
    // ingresar 3 variables distintas, la calle (string), numero de calle (int), localidad (string)
    char calle[50], localidad[50];
    int altura;

    read_str(calle, 50);
    scanf("%d", &altura);
    fflush(stdin);
    read_str(localidad, 50);

    printf("%s, %d, %s", calle, altura, localidad);

    return 0;
}


void read_str(char str[], int len) {
    int i = 0;
    fgets(str, len, stdin);
    while (str[i] != '\0') i++;
    if (str[i-1] == '\n') str[i-1] = '\0';
}

