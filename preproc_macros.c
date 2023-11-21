#define LEN 5

#define cargar(vec) {for (int i = 0; i < LEN; i++) { \
    scanf("%d", &vec[i]); \
}}

#define mostrar(vec) {printf("\n"); \
    for (int i = 0; i < LEN; i++) { \
        printf("%d\n", vec[i]); \
    }}

#define ordenar(vec) { int i,j,aux; \
    for (i=0; i<LEN-1; i++) \
        for (j=0; j<LEN-1; j++) \
            if (vec[j] > vec[j+1]) { \
                aux = vec[j]; \
                vec[j] = vec[j+1]; \
                vec[j+1] = aux;\
            }}

#define maximo(vec,max) {int this_max = vec[0]; \
    for (int i = 1; i < LEN; i++) { \
        if (vec[i] > this_max) this_max = vec[i];\
    } \
    max = this_max; \
    }
