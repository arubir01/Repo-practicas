#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cuenta(char *cadena,int *num,char *letras,int tam,int entero);

int main(){

char *cadena;
int tam;
char *letras;
int *num;
int entero;
char let;

cadena=(char*)malloc(sizeof(char)*tam);

printf("Introduzca una cadena(máximo 100): ");
while(let=getchar() != '\n');
fgets(cadena,tam,stdin);

printf("\nEscribe cuantas letras quiere leer: ");

do{
scanf("%d",&entero);
if(entero <=0)
	{
	printf("\nIntroduzca un valor positivo.");
	}

}while(entero <=0);

letras=(char*)malloc(sizeof(char)*entero);


for(int n=0;n<entero;n++){

printf("\nEscriba %d letras(%d restantes): ",entero,(entero-1));
scanf("%c",&*(letras+n));

	while(let=getchar() != '\n');
}
printf("\nCadena leida: %s",cadena);
printf("\nNumero de letras a leer: %d",entero);

num = (int*)malloc(sizeof(int)*tam);
cuenta(cadena,num,letras,tam,entero);

for(int n=0;n<entero;n++){

	printf("\nHay %d %c\n",*(num+n),*(letras+n));

	}
return 0;
}

void cuenta(char *cadena,int *num,char *letras,int tam,int entero){
	for(int n=0;n<tam;n++){

	if(*(cadena+n) = *(letras+n)){

	*(num+n) = *(num+n)+1;

	}
	}

}
