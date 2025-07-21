#include <stdio.h>

int calculo_recursivo(int i, int j);

int main(){
	int xd;
	printf("(versi%cn recursiva)...\n",418);
	printf("Con (A=0,B=4): ");
	xd = calculo_recursivo(0,4);
	printf("%d",xd);
	return 0;
}

int calculo_recursivo(int i, int j){
	if (i==0) return 1;
	else if(j==0) return 0;
	else return calculo_recursivo(i-1,j) + calculo_recursivo(i,j-1);
}
