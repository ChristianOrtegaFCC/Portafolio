#include <stdio.h>
#define m  100
#define m2 100


int combina(int n, int r);
int tabla[m][m2];

int main(){
	int n, r,c;
	printf("calculo de combinaciones (dinamico)...\n");
	n= 40;
	r= 31;
	c= combina(n,r);
	printf("C(%d,%d) = %d\n",n,r,c);
	return 0;
}


int combina(int n, int r){
	if(tabla[n][r] == 0){
		if(r==0 || r == n){
			tabla[n][r] = 1;
			return tabla[n][r];
		}else{
			tabla[n][r] = combina(n-1,r-1) + combina(n-1,r);
			return tabla[n][r] ;
		}
	}else{
		return tabla[n][r];
	}
	return 0;
}
