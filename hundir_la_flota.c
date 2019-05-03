#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMBARCOS1 4
#define NUMBARCOS2 2
#define NUMBARCOS3 1

int menu();
void hundirLaFlota(int opcion, int f,  int c);
void colocarBarcosManualmente(int *t, int f, int c);
void colocarBarcosAutomaticamente(int *t, int f, int c);
void inicializarTablero(int *t, int f, int c);
void imprimirTablero(int *t, int f, int c);
void imprimirTableroArchivo(int *t, int f, int c, FILE *pa);
int comprobacionEspacioParaBarco(int *t, int f, int c, int iniFila, int iniCol, int tamBarco, int orientacion);
int compruebaGanador (int *b, int f, int c);
int compruebaDisparo(int *t, int f, int c, int posFila, int posCol);
void juegoManual(int f, int c);
void juegoAutomatico(int f, int c);

int main(int argc, char *argv[]){
//Función principal. 
//	- comprueba que el número de argumentos del main es correcto. 
//		--Si no son correctos, mensaje de error y fin del programa
//		--Si son correctos:
//				--- lee las filas y las columnas del tablero
//				--- mientras la opción leída no sea 3, juega al hundir la flota 

		srand(time(NULL));
		int f = atoi(argv[0]);
		int c = atoi(argv[1]);
		int opcion;
		menu();	
	do
	{
			
			if(opcion != 3)
				{	
				hundirLaFlota(opcion,f,c);
				}	
	}while(argc==2);
	printf("\nEl número de argumentos no es correcto(tiene que ser 2).");
	return 0;
}

int menu(){
//Función menu.
//	- INPUTS: nada
//	- OUTPUTS: la opción leída (1, 2 ó 3)
//  - Presenta el menú por pantalla y lee una opción. Si no es 1, 2 ó 3 da un mensaje de error y vuelve a leerla hasta que sea correcta.
	int opcion;
	printf("\n------------MENU-----------");
	printf("\n---Seleccione una opción---");
	printf("\n-----1.Juego Manual--------");
	printf("\n-----2.Juego Automático----");
	printf("\n-----3.Salir del Juego-----");
	scanf("%d",&opcion);
	do
	{
		printf("\nOpción no válida, inténtelo de nuevo");
	}
while(opcion != 1 || opcion != 2 || opcion != 3);
return opcion;
}

void hundirLaFlota(int opcion, int f,  int c){
//Función hundirLaFlota
//	- INPUTS: opción (1, 2 ó 3), filas y columnas del tablero
//  - OUTPUTS: nada
//  - Según la opción leída llama a jugar manual (opción 1), jugar automático (opción 2) o muestra un mensaje de fin (opción 3)
		if(opcion == 1)
		{
			printf("\nJuego manual seleccionado.");
			juegoManual(f,c);			
		}
		else if(opcion == 2)
		{	
			printf("\nJuego automático seleccionado: ");
		 	juegoAutomatico(f,c);	
		}
		else
		{
		printf("\nFin del juego");
		}

}	
void juegoManual(int f, int c){
//Función juegoManual
// 	- INPUTS: número de filas y número de columnas del tablerro
//	- OUTPUTS: nada
//	- Juega de forma manual:
//		-- Crea los 4 tableros, los inicializa (llamando a la función inicializar tantas veces como tableros haya) y en 2 pone los barcos de forma manual o automática, según indique el usuario
//		-- Escribe por pantalla los tableros y las tiradas al inicio del juego
//		-- Por turnos, cada jugador elige una fila y columna de 1 al número de filas y de 1 al número de columnas. Se comprueba si hay barco indicando agua o tocado (se indica por pantalla).
//		-- Se comprueba si hay ganador. Si lo hay acaba la partida indicando quíén ha ganado por pantalla
//		-- EXTRA: comprobar que no se ha repetido ese disparo

}
void juegoAutomatico(int f, int c){
//Función juegoAutomatico
// 	- INPUTS: número de filas y número de columnas del tablerro
//	- OUTPUTS: nada
//	- Juega de forma automática:
//		-- Abre el archivo para escribir en él todas las salidas
//		-- Crea los 4 tableros, los inicializa (llamando a la función inicializar tantas veces como tableros haya) y en 2 pone los barcos automáticamente
//		-- Escribe en el archivo los tableros y las tiradas al inicio del juego
//		-- Por turnos, cada jugador genera una fila y columna automáticamente (se indica en el archivo). Se comprueba si hay barco indicando agua o tocado (se indica en el archivo).
//		-- Se comprueba si hay ganador. Si lo hay acaba la partida indicando quíén ha ganado en el archivo
//		-- EXTRA: comprobar que no se ha repetido ese disparo
FILE *parchivo;
parchivo = fopen("tiradas.txt","a");
if(parchivo==NULL){
fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
exit(EXIT_FAILURE);
}
int *b1,*t1,*b2,*t2,tam;
tam = f *c;

b1 = (int *)malloc(tam*sizeof(int));
t1 = (int *)malloc(tam*sizeof(int));
b2 = (int *)malloc(tam*sizeof(int));
t2 = (int *)malloc(tam*sizeof(int));

inicializarTablero(b1,f,c);
inicializarTablero(t1,f,c);
inicializarTablero(b2,f,c);
inicializarTablero(t2,f,c);

colocarBarcosAutomaticamente(b1,f,c);
colocarBarcosAutomaticamente(b2,f,c);

imprimirTableroArchivo(b1,f,c,parchivo);
imprimirTableroArchivo(b2,f,c,parchivo);
}


void inicializarTablero(int *t, int f, int c){
//Función inicializarTablero
//INPUTS:
//	- puntero a un tablero (barcos, tiradas o lo que sea)
//	- filas
//	- columnas
//OUTPUS: nada
//Inicializa a 0 la tabla
	for(int n = 0;n<f;n++)
		{
			for(int m = 0;m<c;m++)
				{
				*(t + n * c + m) = 0;
				}
		}
}

void imprimirTableroArchivo(int *t, int f, int c, FILE *pa){
//Función imprimirTableroArchivo
//INPUTS:
//	- puntero a un tablero (barcos, tiradas o lo que sea)
//	- filas
//	- columnas
// 	- puntero a archivo
//OUTPUTs: nada
//Imprime en el archivo la matriz pasada	
FILE *parchivo;
parchivo = fopen("tiradas.txt","a");

if(parchivo==NULL){

fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
exit(EXIT_FAILURE);
}
char linea[80];
sprintf(linea,"%d %d\n",f,c);
fputs(linea,parchivo);
for(int n=0;n<f;n++){
	linea[0] = '\0';
	for(int m=0;m<c;m++){
			char buffer[10];
			sprintf(buffer,"%d ",*(t + n * c + m));
			strcat(linea,buffer);
		}
int len = strlen(linea);
linea[len - 1]='\0';
fputs(linea,parchivo);
}
fclose(parchivo);
}

int compruebaGanador (int *b, int f, int c){
//Función compruebaGanador
//INPUTs:
//	- puntero a un tablero de barcos
//	- filas
//	- columnas
//OUTPUTS: nada
//Busca si quedan barcos por hundir. Si no, devuelve 0. 
	
}

int compruebaDisparo(int *t, int f, int c, int posFila, int posCol){
//Función compruebaDisparo
//INPUTS:
//	- tablero de barcos
//	- filas
//	- columnas
//	- tiro (fila y columna)
//OUTPUTS: 0 si agua, 1 si hay un barco de 1, 2 si hay un barco de 2, 3 si hay un barco de 3
	
}

int comprobacionEspacioParaBarco(int *t, int f, int c, int iniFila, int iniCol, int tamBarco, int orientacion){
//Función comprobacionEspacioParaBarco
//INPUTS:
//	- tablero de barcos
//	- filas
//	- columnas
//	- posición (fila)
//	- posición (columna)
//	- tamaño del barco (1, 2 ó 3)
//	- orientación (0 horizontal, 1 vertical)
//OUTPUTS: 1 si cabe, 0 si no cabe
//Comprueba si cabe un barco a partir de la posición indicada en la orientación indicada. Devuelve 0 si no cabe, 1 si sí.
	
				if(tamBarco = 1){
					if((orientacion == 0) || (orientacion == 1)){
					if(*(t + iniFila * c + iniCol) = 0){
					return 1;
					}else{
					return 0;
			}
		}
	}
				if(tamBarco = 2){
					if(orientacion ==0){
					if(*(t + iniFila * c + iniCol) = 0){
					return 1;
					}else{
					return 0;
			}
		}
					if(orientacion == 0){	
					iniFila = iniFila + 1;
					if(*(t + iniFila * c + iniCol) = 0 && iniFila <= f){
					return 1;
					}else{
					return 0;
			}
		}	
				if(tamBarco = 2){
					if(orientacion == 1){
					if(*(t + iniFila * c + iniCol) = 0){
					return 1;
					}else{
					return 0;
			}
		}
					if(orientacion == 1){	
					iniCol = iniCol + 1;
					if(*(t + iniFila * c + iniCol) = 0 && iniCol <= c){
					return 1;
					}else{
					return 0;
			}
	}
}
				if(tamBarco = 3){
					if(orientacion == 0){
					if(*(t + iniFila * c + iniCol) = 0){
					return 1;
					}else{
					return 0;
			}
		}
					if(orientacion == 0){	
					iniFila = iniFila + 1;
					if(*(t + iniFila * c + iniCol) = 0 && iniFila <= f){
					return 1;
					}else{
					return 0;
			}
		}
					if(orientacion == 0){
					iniFila = iniFila + 2;
					if(*(t + iniFila * c + iniCol) = 0 && iniFila <= f){
					return 1;
					}else{
					return 0;
			}
		}	
	}
				if(tamBarco = 3){
					if(orientacion == 1){
					if(*(t + iniFila * c + iniCol) = 0){
					return 1;
					}else{
					return 0;
			}
		}
					if(orientacion == 1){	
					iniCol = iniCol + 1;
					if(*(t + iniFila * c + iniCol) = 0 && iniCol <= c){
					return 1;
					}else{
					return 0;
			}
	}
					if(orientacion == 1){
					iniCol = iniCol + 2;
					if(*(t + iniFila * c + iniCol) = 0 && iniCol <= c){
					return 1;
					}else{
					return 0;
			}
		}
	}
}

void colocarBarcosAutomaticamente(int *t, int f, int c){
//Función colocarBarcosAutomaticamente
//INPUTS:
//	- Tablero de barcos
//	- filas
//	- columnas	
//OUTPUTS: nada
//Coloca de forma automatica 4 barcos de 1 posición, 2 de 2 posiciones y 1 de 3 posiciones en el tablero
	


do{
	for(int n = rand()%(f-1);n<f;n++)
	{
		for(int m = rand()%(c-1);m<c;m++)
			{
				for(int i1=0;i1<4;i1++)
					{
					int orientacion = rand()%2;
					int tamBarco = 1;
					comprobacionEspacioParaBarco(t,f,c,iniFila,iniCol,tamBarco,orientacion);
					*(t + n * c + m) = 1;				
					}
			}
	}
	for(int n = rand()%(f-1);n<f;n++)
	{
		for(int m = rand()%(c-1);m<c;m++)
			{
				for(int i2=0;i2<2;i2++)
					{
					int orientacion = rand()%2;
					int tamBarco = 2;
					comprobacionEspacioParaBarco(t,f,c,iniFila,iniCol,tamBarco,orientacion);
					if(orientacion = 0){
					*(t + n * c + m) = 2;
					*(t + (n+1)* c + m) = 2;
					}else{
					*(t + n * c + (m+2)) = 2;
					*(t + n * c + (m+2)) = 2;
					}
					}
			}
	}
	for(int n = rand()%(f-1);n<f;n++)
	{
		for(int m = rand()%(c-1);m<c;m++)
			{
				for(int i3=0;i3<1;i3++)
					{
					int orientacion = rand()%2;
					int tamBarco = 3;
					comprobacionEspacioParaBarco(t,f,c,iniFila,iniCol,tamBarco,orientacion);
					if(orientacion == 0){
					*(t + n * c + m) = 3;
					*(t + (n+1)* c + m) = 3;
					*(t + (n+2)* c + m) = 3;
					}
					else{
					*(t + n * c + m) = 3;
					*(t + n * c + (m+1)) = 3;
					*(t + n * c + (m+2)) = 3;
					}
					}	
			}
	}
}while((i1 != 4) && (i2 != 2) && (i3 != 1));
}


void colocarBarcosManualmente(int *t, int f, int c){
//Función colocarBarcosManualmente
//INPUTS:
//	- Tablero de barcos
//	- filas
//	- columnas	
//OUTPUTS: nada
//Coloca de forma manual 4 barcos de 1 posición, 2 de 2 posiciones y 1 de 3 posiciones en el tablero




 }
}
