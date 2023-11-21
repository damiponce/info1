/** @file SimIntegrador1.c
 *
 *	@date 5 de noviembre de 2019
 *	@version 1.0
 *
 *	@authors Vazquez Saraullo, Federico Alejandro.
 *
 *	@brief  Archivo fuente que simula a los puertos 0x400, 0x401 y 0x911, y se
 * 			utiliza para validar el programa del ejercicio 1 de los
 *			integradores. Los resultados esperados son:
 *
 *		 	Servidor	Temperatura			Promedio
 *				0		sin datos			sin datos
 *				1		60 (30+30)				30
 *				2		sin datos			sin datos
 *				3		sin datos			sin datos
 *				4		sin datos			sin datos
 *				5		sin datos			sin datos
 *				6		sin datos			sin datos
 *				7		145 (25 + 120)			72.5
 *				8		sin datos			sin datos
 *				9		sin datos			sin datos
 *				10		sin datos			sin datos
 *				11		sin datos			sin datos
 *				12		sin datos			sin datos
 *				13		sin datos			sin datos
 *				14		sin datos			sin datos
 *				15		50 (20+30)				25
 *				16		sin datos			sin datos
 *				17		sin datos			sin datos
 *				18		sin datos			sin datos
 *				19		sin datos			sin datos
 *				20		sin datos			sin datos
 *				21		sin datos			sin datos
 *				22		212 (101+111)			106
 *				23		sin datos			sin datos
 *				24		sin datos			sin datos
 *				25		sin datos			sin datos
 *				26		sin datos			sin datos
 *				27		sin datos			sin datos
 *				28			20 					20
 *				29		sin datos			sin datos
 *				30		sin datos			sin datos
 *				31			35					35
 *
 *			Cantidad de veces que suena la alarma: 3.
 *			Servidores que activan la alarma: 7 y 22.
 *
 *	@note Solo se pueden habilitar los puertos con dirección 0x400, 0x401 y
 *		  0x911. Los demás puertos se toman como que no están disponibles en la
 *		  PC.
 */

/** \addtogroup Simulador para ejercicio 1 de los integradores.
 * @{
 */

/*==================[inclusiones]============================================*/
#include <stdio.h>

/*==================[macros]=================================================*/
/**	@def PUERTO_BASE1
 *	@brief Dirección base del puerto 0x400 disponible según este simulador.*/
#define PUERTO_BASE1 0x400

/**	@def PUERTO_BASE2
 *	@brief Dirección base del puerto 0x911 disponible según este simulador.*/
#define PUERTO_BASE2 0x911

/**	@def CANT_ELEM_VEC(x)
 *	@brief Macro para calcular la cantidad de elementos de un vector "X".*/
#define CANT_ELEM_VEC(x) (sizeof(x) / sizeof(x[0]))

/*==============================[Tipos de datos]=============================*/
typedef enum{
	FIN_OFF,
	FIN_ON
}finStatus_t;

typedef enum{
	SINC_OFF,
	SINC_ON
}sincStatus_t;

typedef enum{
	TEMP20 = 20,
	TEMP25 = 25,
	TEMP30 = 30,
	TEMP35 = 35,
	TEMP101 = 101,
	TEMP111 = 111,
	TEMP120 = 120,
}temp_t;

typedef enum{
	SER0,
	SER1,
	SER2,
	SER3,
	SER4,
	SER5,
	SER6,
	SER7,
	SER8,
	SER9,
	SER10,
	SER11,
	SER12,
	SER13,
	SER14,
	SER15,
	SER16,
	SER17,
	SER18,
	SER19,
	SER20,
	SER21,
	SER22,
	SER23,
	SER24,
	SER25,
	SER26,
	SER27,
	SER28,
	SER29,
	SER30,
	SER31
}numSer_t;

typedef enum{
	DESHABILITADO,
	HABILITADO,
	ERROR_ESTADO
}portStatus_t;

typedef struct{
	unsigned int dir;
	portStatus_t estado;
}puerto_t;

typedef enum{
	OK,
	ERROR1,
	ERROR2,
	ERROR3
}estadoActivacion_t;

/*==================[declaración de variables internas]======================*/
/**@var dirPuertos
 * @brief Vector que almacena la dirección y estado de los puertos, los cuales
 *		  están inicialmente deshabilitados.*/
static puerto_t dirPuertos[] = {
	{ .dir = PUERTO_BASE1,		.estado = DESHABILITADO},
	{ .dir = PUERTO_BASE1 + 1,	.estado = DESHABILITADO},
	{ .dir = PUERTO_BASE2,		.estado = DESHABILITADO}
};

/*==================[definición de funciones internas]=======================*/
/** @fn unsigned char ArmarDatoPuerto (unsigned int port, unsigned int tem,
							  numSer_t ns, sincStatus_t sinc, finStatus_t fin )
 * 	@brief Permite armar un valor de 8 bits según el puerto que se desea leer.
 *		   Se piden los datos de bits de fin, sincronismo, temperatura y número
 *		   del servidor, aunque devuelve solo lo necesario para el puerto
 * 		   solicitado.
 *	@return unsigned char Dato armado para ser enviado al puerto.
 */
unsigned char ArmarDatoPuerto (unsigned int port, unsigned int tem, numSer_t ns,\
							  sincStatus_t sinc, finStatus_t fin )
{
	/* Declaraciones locales */
	unsigned char valor;

	/* Cuerpo de la función*/
	switch(port){
		case PUERTO_BASE1:
				valor = ( ((((unsigned int) tem) & 0x07) << 5 ) + \
						(((unsigned int) ns) & 0x01F));
				break;

		case (PUERTO_BASE1 + 1):
				valor = ( (((unsigned int) fin) << 7 ) + \
						  (((unsigned int) sinc) << 6 ) + \
						  (((unsigned int) tem) >> 3));
				break;

		default:valor = 0;
	}
	return valor;
}

/** @fn int BuscarPuerto (puerto_t portVec[], int cnt, unsigned int port)
 * 	@brief Permite buscar en forma secuencial la dirección "port" dentro del
	       vector "portVec" el cual tiene "cnt" elementos.
 *	@return int que vale:
 *		-1: No se encontró al "port" en "porVec".
 *		otro valor: Se encontró.
 */
int BuscarPuerto (puerto_t portVec[], int cnt, unsigned int port)
{
	/* Declaraciones locales */
	int i = 0;
	int pos = -1;

	/* Cuerpo de la función*/
	while(i < cnt && pos == -1){
		if(portVec[i].dir == port){
			pos = i;
		}
		else{
			i++;
		}
	}
	return pos;
}

/** @fn int ioperm (unsigned int port, unsigned int cant, int accion)
 * 	@brief Permite habilitar o deshabilitar una cantidad entera de puertos consecutivos.
 *	@return estadoActivacion_t que vale:
 *		OK: Se habilita/deshabilita correctamente.
 *		ERROR1: Error por valores de cant y/o accion.
 *		ERROR2: Error por dirección del puerto.
 *		ERROR3: Error por direcciones consecutivas de puertos.
 */
int ioperm (unsigned int port, unsigned int cant, int accion)
{
	/* Declaraciones locales */
	unsigned int i = 0;
	int pos;
	estadoActivacion_t activacion;
	portStatus_t estadoASetear;

	/* Cuerpo de la función*/

	/*Se guarda el estado a setear. Aunque "estadoASetear" sea enum, admite
	 *valores negativos y mayores a 1.*/
	switch(accion){
		case 0: estadoASetear = DESHABILITADO;
				break;

		case 1: estadoASetear = HABILITADO;
				break;

		default: estadoASetear = ERROR_ESTADO;
	}

	/*Se validan los parámetros formales.*/
	if(cant > 0 && (estadoASetear == HABILITADO || estadoASetear == DESHABILITADO) ){
		/*Se hace primero una búsqueda secuencial de la dirección "port" en el
		 *vector "dirPuertos".*/
		pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);

		/*Si se encuentra el puerto, se chequea que los puertos consecutivos se
		 *puedan habilitar. Por defecto, se supone que se pueden habilitar hasta
		 *que se demuestre lo contrario.*/
		if(pos != -1){
			i = 1;
			activacion = OK;
			/*Se buscan los puertos consecutivos en el vector "dirPuertos".*/
			while(i < cant && activacion == OK){
				if((port + i) != dirPuertos[pos + i].dir){
					activacion = ERROR3;
				}
				else{
					i++;
				}
			}
			/*Se habilitan/deshabilitan si es posible.*/
			if(activacion == OK){
				for (i = 0; i < cant; i++){
					dirPuertos[pos + i].estado = estadoASetear;
				}
			}
		}
		else{
			activacion = ERROR2;
		}
	}
	else{
		activacion = ERROR1;
	}

	return activacion;
}

/** @fn void MostrarErrorLectura()
 * 	@brief Muestra un mensaje de error en caso de que exista uno cuando se usa la función "inb".
 */
void MostrarErrorLectura()
{
	/* Declaraciones locales */

	/* Cuerpo de la función*/
	printf("\n\n****************************************************************************************\n");
	printf("ERROR. El puerto, por el que desea leer un dato, no existe o no esta habilitado.\n");
	printf("****************************************************************************************\n");
}

/*Para esta función se consideraron los siguientes casos:
 *	-Datos válidos de servidores 1, 7, 15, 22, 28 y 31.
 *	-Poner varios casos para cada valor para así tener en cuenta la posible
 * 	 doble lectura innecesaria en el programa de aplicación.
 *	-Bit F en 1 cuando el dato NO es válido para que el usuario solo analice
 *	 ese bit si el dato es válido. De no hacerlo, el programa se cierra.
 *	-Bit F en 1 en caso de agotarse los casos.*/
unsigned char inb( int port)
{
    /* Declaraciones locales */
	static int orden=0;
	int pos;
    unsigned char dato = 0;

	/*Se verifica que el puerto está habilitado*/
	pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);

	if( pos == -1 || dirPuertos[pos].estado == DESHABILITADO){
		MostrarErrorLectura();
	}
	else{
	    switch(port)
	    {
	        case PUERTO_BASE1:
	            switch(orden)
	            {
	            	case 0:
	                case 1:
	                case 2:
	                case 3:
	                case 4: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	break;

					case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9: dato = ArmarDatoPuerto(PUERTO_BASE1, 30, SER1, SINC_ON, FIN_OFF);
	                    	break;

	                case 10:
	                case 11:
	                case 12:
	                case 13:
	                case 14: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 15:
	                case 16:
	                case 17:
	                case 18:
	                case 19: dato = ArmarDatoPuerto(PUERTO_BASE1, 25, SER7, SINC_ON, FIN_OFF);
	                    	 break;

	                case 20:
	                case 21:
	                case 22:
	                case 23:
	                case 24: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 25:
	                case 26:
	                case 27:
	                case 28:
	                case 29: dato = ArmarDatoPuerto(PUERTO_BASE1, 20, SER15, SINC_ON, FIN_OFF);
	                    	 break;

	                case 30:
	                case 31:
	                case 32:
	                case 33:
	                case 34: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 35:
	                case 36:
	                case 37:
	                case 38:
	                case 39: dato = ArmarDatoPuerto(PUERTO_BASE1, 101, SER22, SINC_ON, FIN_OFF);
							 break;

	                case 40:
	                case 41:
	                case 42:
	                case 43:
	                case 44: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 45:
	                case 46:
	                case 47:
	                case 48:
	                case 49: dato = ArmarDatoPuerto(PUERTO_BASE1, 20, SER28, SINC_ON, FIN_OFF);
							 break;

	                case 50:
	                case 51:
	                case 52:
	                case 53:
	                case 54: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 55:
	                case 56:
	                case 57:
	                case 58:
	                case 59: dato = ArmarDatoPuerto(PUERTO_BASE1, 35, SER31, SINC_ON, FIN_OFF);
	                    	 break;

					case 60:
					case 61:
	                case 62:
	                case 63:
	                case 64: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 65:
	                case 66:
	                case 67:
	                case 68:
					case 69: dato = ArmarDatoPuerto(PUERTO_BASE1, 30, SER1, SINC_ON, FIN_OFF);
			    			 break;

	                case 70:
	                case 71:
	                case 72:
	                case 73:
					case 74: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
			    			 break;

	                case 75:
	                case 76:
	                case 77:
	                case 78:
					case 79: dato = ArmarDatoPuerto(PUERTO_BASE1, 120, SER7, SINC_ON, FIN_OFF);
			    			 break;

	                case 80:
	                case 81:
	                case 82:
	                case 83:
					case 84: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
			    			 break;

	                case 85:
	                case 86:
	                case 87:
	                case 88:
					case 89: dato = ArmarDatoPuerto(PUERTO_BASE1, 30, SER15, SINC_ON, FIN_OFF);
			    			 break;

	                case 90:
	                case 91:
	                case 92:
	                case 93:
					case 94: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
			    			 break;

	                case 95:
	                case 96:
	                case 97:
	                case 98:
					case 99: dato = ArmarDatoPuerto(PUERTO_BASE1, 111, SER22, SINC_ON, FIN_OFF);
			    			 break;

	                case 100:
	                case 101:
	                case 102:
	                case 103:
					case 104: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_OFF, FIN_ON);
			    			  break;

	                case 105:
	                case 106:
	                case 107:
	                case 108:
					case 109: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_ON, FIN_ON);
			    			 break;

					default: dato = ArmarDatoPuerto(PUERTO_BASE1, 0, SER0, SINC_ON, FIN_ON);
	            }
	            break;

	        case (PUERTO_BASE1 + 1):
	 			switch(orden)
	            {
	                case 0:
	                case 1:
	                case 2:
	                case 3:
	                case 4: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                    	break;

	                case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 30, SER1, SINC_ON, FIN_OFF);
	                    	break;

	                case 10:
	                case 11:
					case 12:
					case 13:
	                case 14: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 15:
	                case 16:
	                case 17:
	                case 18:
	                case 19: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 25, SER7, SINC_ON, FIN_OFF);
	                    	 break;

	                case 20:
	                case 21:
	                case 22:
	                case 23:
	                case 24: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 25:
	                case 26:
	                case 27:
	                case 28:
	                case 29: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 20, SER15, SINC_ON, FIN_OFF);
	                    	 break;

	                case 30:
	                case 31:
	                case 32:
	                case 33:
	                case 34: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 35:
	                case 36:
	                case 37:
	                case 38:
	                case 39: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 101, SER22, SINC_ON, FIN_OFF);
							 break;

	                case 40:
	                case 41:
	                case 42:
	                case 43:
	                case 44: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 45:
	                case 46:
	                case 47:
	                case 48:
	                case 49: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 20, SER28, SINC_ON, FIN_OFF);
							 break;

	                case 50:
	                case 51:
	                case 52:
	                case 53:
	                case 54: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                     	 break;

	                case 55:
	                case 56:
	                case 57:
	                case 58:
	                case 59: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 35, SER31, SINC_ON, FIN_OFF);
	                    	 break;

					case 60:
					case 61:
	                case 62:
	                case 63:
	                case 64: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
	                    	 break;

	                case 65:
	                case 66:
	                case 67:
	                case 68:
					case 69: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 30, SER1, SINC_ON, FIN_OFF);
							 break;

	                case 70:
	                case 71:
	                case 72:
	                case 73:
					case 74: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
			    			 break;

	                case 75:
	                case 76:
	                case 77:
	                case 78:
					case 79: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 120, SER7, SINC_ON, FIN_OFF);
			    			 break;

	                case 80:
	                case 81:
	                case 82:
	                case 83:
					case 84: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
			    			 break;

	                case 85:
	                case 86:
	                case 87:
	                case 88:
					case 89: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 30, SER15, SINC_ON, FIN_OFF);
			    			 break;

	                case 90:
	                case 91:
	                case 92:
	                case 93:
					case 94: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
			    			 break;

	                case 95:
	                case 96:
	                case 97:
	                case 98:
					case 99: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 111, SER22, SINC_ON, FIN_OFF);
			    			 break;

	                case 100:
	                case 101:
	                case 102:
	                case 103:
					case 104: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_OFF, FIN_ON);
			    			  break;

	                case 105:
	                case 106:
	                case 107:
	                case 108:
					case 109: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_ON, FIN_ON);
			    			  break;

					default: dato = ArmarDatoPuerto(PUERTO_BASE1 + 1, 0, SER0, SINC_ON, FIN_ON);
	            }
	            break;

	        default: dato=0; /*En el caso de que existiese otro puerto
							habilitado, se devuelve 0.*/
					break;
	    }

	    orden ++;
	}
	return dato;
}

/** @fn void MostrarErrorEscritura()
 * 	@brief Muestra un mensaje de error en caso de que exista uno cuando se usa la función "outb".
 */
void MostrarErrorEscritura()
{
	/* Declaraciones locales */

	/* Cuerpo de la función*/
	printf("\n\n****************************************************************************************\n");
	printf("ERROR. El puerto, por el que desea enviar un dato, no existe o no esta habilitado.\n");
	printf("****************************************************************************************\n");
}

void outb ( unsigned char dato, unsigned short int port)
{
	/* Declaraciones locales */
	int pos;

	/* Cuerpo de la función*/

	/*Se verifica que el puerto está habilitado*/
	pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);

	if( pos == -1 || dirPuertos[pos].estado == DESHABILITADO){
		MostrarErrorEscritura();
	}
	else{
		if(port == PUERTO_BASE2){
			if(dato == 0xFF){
				printf("\n\n\n\t\t ***ALARMA ACTIVADA***\n\n\n");
			}
			else{
				printf("\n\n\n\t\t ***COMANDO INCORRECTO PARA ACTIVAR LA ALARMA***\n\n\n");
			}
		}
	}
}
/** @} doxygen end group definition */
/*==================[fin del archivo]============================================*/
