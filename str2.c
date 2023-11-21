#include <stdio.h>
#include <string.h>


int main() {
    char str[200];

    read_str(str, 200);

    printf("\nString: %s", str);
    printf("\nLength: %d", strlen(str));


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
