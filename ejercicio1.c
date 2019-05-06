#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

srand(time(NULL));
int *m,tam;
int f,c,i,j;
f = atoi(argv[1]);
c = atoi(argv[2]);
tam = f * c;


m = (int *)malloc(tam*sizeof(int));

for(i=0;i<f;i++){
	for(j=0;j<c;j++){
		*(m + i * c + j) = (rand()%5) + 5;
		if(i == j){
		*(m + i * c + j) = 0;
		}else if(i==f && j==0){
				i--;
				j++;
				*(m + i * c + j	) = 1;
		}
		printf("%d ",*(m + i * c + j));
		}
		printf("\n");
}
return 0;		
}
					
