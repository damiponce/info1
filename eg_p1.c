#include <stdio.h>
#include <ctype.h>
#include <string.h>

char frase[201] = {};
int fin = 0;
int inicio_palabra = 0;

void main() {
    fin = read_str(frase, 201);
//    printf("\nOriginal: %s\n", frase);

    int j = 0;
    for (int i = 0; i <= fin; i++) {
        if (!(frase[i] == ' ' || frase[i] == '\0')) {
            if (j == 0) {
                inicio_palabra = i;
            }
            j++;
        } else {
            if (j > 3) mayus(frase, inicio_palabra);
            j = 0;
        }
    }

    printf("\n%s\n", frase);
}

void mayus(char str[], int i) {
    str[i] = toupper(str[i]);
}

int read_str(char str[], int len) {
    int i = 0;
    fgets(str, len, stdin);
    while (str[i] != '\0') i++;
    if (str[i-1] == '\n') str[i-1] = '\0';
    return i-1;
}
