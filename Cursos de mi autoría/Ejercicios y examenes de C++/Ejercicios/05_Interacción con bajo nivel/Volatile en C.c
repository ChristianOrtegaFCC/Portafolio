// Volátile en C
// Bibliografía: https://programmerclick.com/article/57611463145/

#include <stdio.h>
int square(volatile int *ptr);

int main(){
	int res;
	res = square(3);
	printf("square(3) = %d",res);
	return 0;
}

int square(volatile int *ptr){
	int a, b;
	a = *ptr;
	b = *ptr; // En este momento puede haber cambiado en otras funciones o subprocesos
	return a * b;
}

