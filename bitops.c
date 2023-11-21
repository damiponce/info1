#include <stdio.h>

void main() {
//    Inversor();
//    InversorEjercicio();
//    AndOrEjercicio();

}


void RightBitshift() {
    // rellena 0 si A es unsigned
    // rellena 0 si A es signed positiva (MSB = 0)
    // rellena 1 si A es signed negativa (MSB = 1)
    // A>>N -> A/(2^N)
}

void LeftBitshift() {
    // rellena con 0
    // A<<N -> A*(2^N)
}

void XOR() {
    // A^0 -> A
    // A^1 -> ~A
}

void AndOrEjercicio() {
    int var, mod;
    scanf("%d", &var);
    printf("0x%x, %d\n", var, var);
    mod = (var&0xDF)|0xC0;
    printf("0x%x, %d\n", mod, mod);
}

void AND() {
    // A&0 -> 0
    // A&1 -> A
}

void OR() {
    // A|0 -> A
    // A|1 -> 1
}

void InversorEjercicio() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", a + ~b + 1);
}

void Inversor() {
    char num = 0xA8;
    num = ~num;
    printf("%x", num);

    // 0xA8
    //   10101000
    //   01010111
    // 0x57
}


