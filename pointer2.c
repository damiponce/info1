#include <stdio.h>

void main() {
    int vec[10] = {1,54,2,64,12,6,32,96,23,4};
    int *pvec[10];
    for (int i = 0; i < 10; i++) {
        pvec[i] = &vec[i];
    }

    int n = 10, nn, *ptemp;
    do {
        nn = 0;
        for (int i = 1; i < n; i++) {
            if (*(pvec[i-1]) > *(pvec[i])) {
                ptemp = pvec[i-1];
                pvec[i-1] = pvec[i];
                pvec[i] = ptemp;
                nn = i;
            }
        }
        n = nn;
    } while(n > 1);

    for (int i = 0; i < 10; i++) {
        printf("%d ",  vec[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", *pvec[i]);
    }

}
