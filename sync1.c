#include <stdio.h>
#include "sim10.c"
#define PORT 0x400

struct data {
    unsigned int s:1;
    unsigned int m:3;
             int  :3;
    unsigned int f:1;
};

union un {
    unsigned char c;
    struct data d;
};

int molinetes[8] = {0};
void main() {
    ioperm(0x400, 1, 1);
    union un u;
    int f = 0;
    do {
        do {
            u.c = inb(0x400);
        } while(u.d.s == 0);

        if (u.d.f == 0) {
                molinetes[u.d.m]++;
            do {
                u.c = inb(0x400);
            } while(u.d.s == 1);
        } else {
            f = 1;
        }

    } while(f == 0);

    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%d\n", molinetes[i]);

    ioperm(0x400, 1, 0);
}
