#include <stdio.h>


void main() {
//    ej1();
//    ej2();
//    ej3();
    ej4();
}

void ej4() {
    struct b {
        unsigned int lsb:4;
        unsigned int msb:4;
    };

    union un {
        unsigned char ch;
        struct b bits;
    };

    union un A, B, C;
    A.ch = 0xF1;
    B.ch = 0x69;

    C.bits.lsb = B.bits.lsb;
    C.bits.msb = A.bits.msb;
    printf("%x", C.ch);

}

void ej3() {
// DxCCCCCC CCCBBAAA
// 10001000 01010101
// A: u101 -> 5
// B: 10 -> -2
// C: u001000010 -> 66
// D: 1 -> -1

    struct sbit {
        unsigned int A:3;
        int B:2;
        unsigned int C:9;
        int :1;
        int D:1;
    };

    union un {
        struct sbit camposBit;
        unsigned char v[2];
    };

    union un u;
    u.v[0] = 0x55;
    u.v[1] = 0x88;

    printf("%d %d %d %d", u.camposBit.A, u.camposBit.B, u.camposBit.C, u.camposBit.D);

}

void ej2() {
    #define N 1
    struct product {
        unsigned int code: 4;
        unsigned int amount: 9;
        unsigned int origin: 1;
    };

    struct product prods[N];

    for (int i = 0; i < N; i++) {
        int code, amount, origin;
        printf("Ingresar codigo (1-10): ");
        code = scanRange(1, 10);
        printf("Ingresar cantidad (0-500): ");
        amount = scanRange(0, 500);
        printf("Ingresar (0=NAC, 1=IMP): ");
        origin = scanRange(0, 1);

        prods[i].code = code;
        prods[i].amount = amount;
        prods[i].origin = origin;
    }

    printf("    C   A O\n");
    for (int i = 0; i < N; i++) {
        printf("%2d %2d %3d %1d\n",i, prods[i].code, prods[i].amount, prods[i].origin);
    }


}


int scanRange(int min, int max) {
    int var;
    do {
        scanf("%d", &var);
    } while(var < min || var > max);
    return var;
}


void ej1() {
    struct sbit {
        unsigned int a:1;
        unsigned int b:1;
        unsigned int c:1;
        unsigned int d:1;
        unsigned int e:1;
        unsigned int f:1;
        unsigned int g:1;
        unsigned int h:1;
    };

    union un {
        unsigned char num;
        struct sbit bits;
    };

    int num;

    union un u;
    do {
        scanf("%d", &num);
    } while(num > 255 || num < 0);
    u.num = num;
    printf("%x", u.bits.h);
    printf("%x", u.bits.g);
    printf("%x", u.bits.f);
    printf("%x", u.bits.e);
    printf("%x", u.bits.d);
    printf("%x", u.bits.c);
    printf("%x", u.bits.b);
    printf("%x", u.bits.a);

}
