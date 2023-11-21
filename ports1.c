#include "simledswin.c"
#include <unistd.h>

#define SLEEP 100000

void main() {
//   backAndForth();
    return 0;
}


void backAndForth() {
    ioperm(0x378,1,1);
    int addr;
    for (int j = 0; j < 10; j++) {
        addr = 0x01;
        for (int i = 0; i < 7; i++) {
            outb(addr, 0x378);
            addr <<= 1;
            usleep(SLEEP);
        }
        addr = 0x80;
        for (int i = 0; i < 7; i++) {
            outb(addr, 0x378);
            addr >>= 1;
            usleep(SLEEP);
        }
    }
    ioperm(0x378,1,0);
}
