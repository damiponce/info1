#include <stdio.h>

void main()
{
   int vector[10] = {1,4,6,73,3,2,1,3,1,1};
   int *ps[10] = {0};

   printf("%d", MinimoMultiple(vector, ps, 10));
}

int MinimoMultiple (int * numeros, int ** posMinimos, int ce)
{
    int min = * numeros;
    int n = 0;
    for (int i = 1; i < ce; i++)
        if (*(numeros + i) < min) min = *(numeros + i);

    for (int i = 0; i < ce; i++)
        if (*(numeros + i) == min)
        {
            *(posMinimos + n) = numeros + i;
            n++;
        }

    return n;
}
