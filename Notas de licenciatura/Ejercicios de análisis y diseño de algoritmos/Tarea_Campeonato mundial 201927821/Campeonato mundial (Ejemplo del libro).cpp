#include <stdio.h>
#define mx 20

int funcion(int n,int p);

int main(){
	int xd;
	printf("(versi%cn din%cmica original)...\n",418,416);
	printf("Con (A=4,B=0): ");
	xd = funcion(4,0);
	printf("%d",xd);
	return 0;
}

int funcion(int n, int p){
	int datos[mx][mx];
	int q,s,k;
	q=1-p;
	for(s=1;s<=n;s++){
		datos[0][s] = 1;
		datos[s][0] = 0;
		for(k=1;k <= s-1;k++){
			datos[k][s-k] = datos[k-1][s-k] + datos[k][s-k-1];
		}
	}
	
	for(s=1;s<=n;s++){
		for(k=0;k<=n-s;k++){
			datos[s+k][n-k] = datos[s+k-1][n-k] + datos[s+k][n-k-1] ;
		}
	}
	return datos[n][n];
}
