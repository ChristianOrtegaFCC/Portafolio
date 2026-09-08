/*
Algoritmo:
Lee N pares de puntos y colócalos en la matriz M

DESDE QUE i=1 HASTA N
 DESDE QUE j=0 HASTA (N-i)
   M[j][i+1]=(M[j+1][i]-M[j][i])/M[j+i][0]-M[j][0];
 FIN
FIN
imprime en pantalla la tabla de las diferencias caculadas.


*/

#include<stdio.h>

int main(){
	int N, i, j;
	float  M[20][20]={0}, X;

	printf("Ingresa el numero de puntos");
	scanf("%d", &N);
	printf("Ingresa X a evaluar: ");
	scanf("%f", &X);

	for(i=0; i<N; i++){
		for(j=0; j<2; j++){
			printf("x = "); scanf("%f", M[i][j]);
			}
		printf("f(x) = "); scanf("%f", M[i+1][j+1]);
		}
	for(i=1; i<N; i++){
		for(j=0; j<N-i; j++)
   			M[j][i+1]=(M[j+1][i]-M[j][i])/M[j+i][0]-M[j][0];
		}

	for(i=0; i<N; i++){
		for(j=0; j<N+1; j++){
			printf("%f", M[i][j]);
			}
		printf("\n");
		}
	return 0;
}
