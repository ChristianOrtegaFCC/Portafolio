#include <stdio.h>
#define m  50
#define m2 50


int combina();
int cn, cr;
long int tabla[m][m2];

int main(){
	cn =0; cr=0;
	int n, r,c;
	printf("calculo de combinaciones (dinamico)...\n");
	n= 40;
	r= 31;
	c= combina();
	printf("C(%d,%d) = %d\n",n,r,c);
	return 0;
}


int combina(){
	if(cr==0 || cr == cn){
		cn++;cr++;
		tabla[cn][cr] = 1;
		return 1;
	}else{ 
		cn++;cr++;
		//return combina(n-1,r-1) + combina(n-1,r)  ;
		tabla[cn][cr] = tabla[cn-1][cr-1] + tabla[cn-1][cr];
		return tabla[cn][cr];
	}
	return 0;
}
