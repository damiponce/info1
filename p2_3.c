#include <stdio.h>
//#include <>

struct bits
{
             int temp: 5;
             int     : 1;
    unsigned int sens: 8;
    unsigned int f   : 1;
    unsigned int s   : 1;
};

union un
{
    unsigned char c[2];
    struct bits b;
};

void main()
{
    union un data;

    int negativos[256] = {1};
    int leidos[256] = {0};

    //port_on(0x400, 2, 1);

    do
    {
        do
        {
           data.c[1] = inb(0x401);
        } while (data.b.s == 0);

        if (data.b.f == 1)
        {
            data.c[0] = inb(0x400);

            leidos[data.b.sens] = 1;

            if (data.b.temp  >= 0)
                negativos[data.b.sens] = 0;

//            else
//                if (negativos[data.b.sens] == 1) negativos[data.b.sens] = 0;


            do
            {
               data.c[1] = inb(0x401);
            } while (data.b.s == 1);
        }
    } while (data.b.f == 1);

    //port_off(0x400, 2, 0);

    printf("\nSensores solo temp negativa: ");
    for (int i = 0; i < 256; i++)
        if (negativos[i] == 1 && leidos[i] == 1)
        {
            printf("%d ", i);
        }

    printf("\nSensores no leidos: ");
    for (int i = 0; i < 256; i++)
        if (leidos[i] == 0)
        {
            printf("%d ", i);
        }

}
