#define DEBUG

int main() {
    int i, s = 0;
    for (i = 0; i < 10; i++) {
        s+=i;
        #ifdef DEBUG
            printf("\nSuma parcial: %d", s);
        #endif // DEBUG
    }
    printf("\nSuma total: %d", s);
}
