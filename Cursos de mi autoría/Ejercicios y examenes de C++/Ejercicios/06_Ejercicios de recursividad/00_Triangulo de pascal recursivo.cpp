#include <stdio.h>

int combina(int n, int r);

int main(){
	int n, r,c;
	printf("calculo de combinaciones (recursivo)...\n");
	n= 40;
	r= 31;
	c= combina(n,r);
	printf("C(%d,%d) = %d\n",n,r,c);
	return 0;
}


int combina(int n, int r){
	if(r==0 || r == n) return 1;	
	else return combina(n-1,r-1) + combina(n-1,r)  ;
	return 0;
}
