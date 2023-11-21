#include <stdio.h>

struct bits
{
    char primero: 3;
    char segundo: 2;
    unsigned char tercero: 2;
    char cuarto: 1;
};

union unido
{
    struct bits campos;
    unsigned char todo;
};

void main()
{
    union unido junto;
    junto.todo = 0xF4;
    junto.campos.segundo = junto.campos.segundo ^ 0xFF;
    junto.campos.primero >>= 1;
    printf("Primero: %d\n", junto.campos.primero);
    printf("Segundo: %d\n", junto.campos.segundo);
    printf("Tercero: %d\n", junto.campos.tercero);
    printf("Cuarto: %d\n", junto.campos.cuarto);
}
