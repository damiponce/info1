#include "sim7segWin.c"
#include <unistd.h>

#define SLEEP  500000
#define ZERO   0x3F //abcdef
#define ONE    0x06 //bc
#define TWO    0x5B //abged
#define THREE  0x4F //abgcd
#define FOUR   0x66 //fgbc
#define FIVE   0x6D //afgcd
#define SIX    0x7D //acdefg
#define SEVEN  0x07 //abc
#define EIGHT  0x7F //abcdefg
#define NINE   0x6F //abcdfg

#define H      0x76 // .gfe .cb.
#define E      0x79 // .gfe d..a
#define L      0x38 // ..fe d...
#define O      0x3F // ..fe dcba

int num[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
int hello[] = {H, E, L, L, O};

void main() {
    ioperm(0x378,1,1);
    count();
    ioperm(0x378,1,0);
    return 0;
}


void numbers() {
    int i = 0;
    while(1) {
        outb(num[i], 0x378);
//      usleep(SLEEP);
        getchar();
        i = i > 8 ? 0 : i + 1;

    }
}

void hola() {
    for (int i = 0; i < 5; i++) {
        outb(hello[i], 0x378);
        usleep(500000);
    }
}

void count() {
    int delay = 500000;
    for (int i = 9; i >= 0 ; i--) {
        outb(num[i], 0x378);
        usleep(delay);
    }
    for (int i = 0; i < 4 ; i++) {
        outb(0, 0x378);
        usleep(delay/2);
        outb(num[0], 0x378);
        usleep(delay);
    }
}
