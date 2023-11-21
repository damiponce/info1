#include <stdio.h>

typedef struct {
    char nombre[10];
    int codigo;
    float precio;
} Item;

void main() {
    Item item;
    item.codigo = 23452;
    item.precio = 199999.99;

    for (int i = 0; i < 10; i++) {
        item.nombre[i] = 'a';
    }

    printf("Nombre: %s, Codigo: %d, Precio: $%f", item.nombre, item.codigo, item.precio);

}

