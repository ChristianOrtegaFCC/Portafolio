// esta es la mejor version...
#include <stdio.h>
#define m  100
#define m2 100

int combina(int n, int r);
int tabla[m][m2];

int main(){
	int n, r,c,i,j;
	printf("calculo de combinaciones (dinamico) (con programacion dinamica)...\n");
	printf("generacion del triangulo de pascal\n");
	n= 10;
	r= 5;
	c= combina(n,r);
	
	for(i=0;i<=n;i++){
		for(j=0;j<=i;j++){
			printf("%d\t", combina(i,j));
		}
		printf("\n");
	}
	printf("C(%d,%d) = %d\n",n,r,c);
	return 0;
}

int combina(int n, int r){
	if(tabla[n][r] == 0)
		if(r==0 || r == n)	tabla[n][r] = 1; 
		else tabla[n][r] = combina(n-1,r-1) + combina(n-1,r);
	return tabla[n][r];	
}
