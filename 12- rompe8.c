#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar(int[][3]);
void moverNumero(int[][3], int, int);
int comprobarEstado(int[][3]);
int main()
{
	int f, c;
	int m[3][3]={1,2,3,4,6,8,7,5,0};
//	int m[3][3]={4,8,2,3,6,7,0,1,5};
	//int m[3][3]={1,2,3,4,5,6,7,0,8};  //matriz de prueba practicamente ordenada
	int gano=0,num,encontrado,movimientos = 0,scanned;
    generarMatriz(m);
	while (!gano)
	{
		mostrar(m);
		do {
		    do {
                fflush(stdin);
                printf("\n Mover: ");
                scanned = scanf("%d",&num);
			} while (scanned == 0);
		} while ((num<1||num>8));

		encontrado=0;
		f=0;c=0;
		while (!encontrado)
		{
			/*COMPLETAR
			realizar un algoritmo que busque en la matriz en numero ingresado
			y que se encuentra en la variable num
			El algoritmo debe finalizar en el momento que encuentra el número y
			completar las variables f y c con la fila y columna donde lo encontró
			*/

			for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (m[i][j] == num) {
                        f = i;
                        c = j;
                        encontrado = 1;
                    }
                }
            }
		}

		moverNumero(m,f,c);
		movimientos++;
		gano = comprobarEstado (m);
	}

  	mostrar(m);
	printf("\n\GANASTE!!!\n");
	printf("(en %d movimientos)\n\n", movimientos);
	system("pause");
	return 0;
}

void generarMatriz(int m[][3]) {
    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = -1;
        }
    }
    int random = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {

                random = (rand() % 9);
                if (!isInMat(m,random)) m[i][j] = random;
            } while (m[i][j] == -1);
        }
    }
}

int isInMat(int m[][3], int search) {
    int found = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] == search) found = 1;
        }
    }
    return found;
}

void moverNumero(int m[][3], int f, int c)
{
	int movimiento=0;
	int num= m[f][c];

	/*COMPLETAR
	La funcion recibe la fila y columna de la matriz donde está el numero que
	se desea mover. Se debe realizar el algoritmo para que lo mueva al casillero
	adyacente que este libre, es decir que tenga un 0.
	Tener en cuenta que no siempre se puede mover solo lo debe mover si el 0 está
	en una de cuatro posiciones en la celda de arriba, de abajo de la derecha o
	izquierda sino no hace nada.
	Tambien considerar que no siempre están las 4 opciones ya que el numero a mover
	puede estar en alguno de los extremos de la matriz

	Ayuda puede resolverse con 4 if anidados (arriba,abajo, izquierda y derecha  de
	la celda recibida por parámetro)
	*/


	for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) &&
                (i == 0 || j == 0) &&
                f + i >= 0 &&
                c + j >= 0 &&
                f + i < 3 &&
                c + j < 3 &&
                movimiento == 0)
            {
//                printf("%d, %d\n", i, j);
                if (m[f+i][c+j] == 0) {
                    m[f+i][c+j] = m[f][c];
                    m[f][c] = 0;
                    movimiento = 1;
                }
            }
        }
    }

}

void mostrar(int m[][3])
{
	system("cls");

	/*COMPLETAR
	Mostrar la matriz pero teniendo en cuenta que el 0 no debe mostrarse
	cuando el valor sea 0 se debe mostrar un espacio en blanco
	*/

	printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] != 0) {
                printf("%2d", m[i][j]);
            } else {
                printf("%2c", ' ');
            }
        }
        printf("\n");
    }

}

int comprobarEstado(int m[][3])
{
	int gano = 1;
	int ordenada[3][3]={1,2,3,4,5,6,7,8,0};
	/*COMPLETAR
	Si la matriz quedó ordenada en la variable gano debe quedar un 1 sino un 0.
	Para que esté ordenada la matriz debe estar de la siguiente forma:
	1 2 3
	4 5 6
	7 8 0
	*/

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] != ordenada[i][j]) {
                gano = 0;
            }
        }
    }

	return gano;
}
