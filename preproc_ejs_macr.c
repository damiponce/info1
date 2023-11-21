#define ordenarMayoraMenor(vec,N) { int i,j,aux; \
    for (i=0; i<N-1; i++) \
        for (j=0; j<N-1; j++) \
            if (vec[j] > vec[j+1]) { \
                aux = vec[j]; \
                vec[j] = vec[j+1]; \
                vec[j+1] = aux;\
            }}


#define ordenarMenoraMayor(vec,N) { int i,j,aux; \
    for (i=0; i<N-1; i++) \
        for (j=0; j<N-1; j++) \
            if (vec[j] < vec[j+1]) { \
                aux = vec[j]; \
                vec[j] = vec[j+1]; \
                vec[j+1] = aux;\
            }}
