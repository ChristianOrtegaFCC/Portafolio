/*
 crea un programa que:
 > tenga un array de enteros de tamaño 10 (llénalo con los datos que quieras, da igual)
 > tenga un array de punteros a enteros de tamaño 10
 > guárda las direccones de memoria de a[i] en a_pointers[i]
 > imrpime:
 	( primero dime qué es esto, para que mas o
 	  menos sepas lo que te encontrarás ):
 	> a[i]
	> &a[i]
	> a_pointers[i]
	> a_pointers[0] + i
	> &a_pointers[i]
	> *a_pointers[i]
		
	al finalizar copia el codigo y pegalo en un nuevo archivo y repite el proceso con 
	valores tipo char y punteros a char. observa la diferencia	
	y luego con floats y luego con doubles y luego con booleans
*/


#include <iostream>

int main(){
int a[10];
int *a_pointers[10];
int i;

for(i=0;i<10;i++){ // llenas A[i] y a_pointers[i]
	a[i] = (i+1)*10;
	a_pointers[i] = &a[i];
}

// imprimes a[i]
for(i=0;i<10;i++) printf("a[%d] = %d\n",i,a[i]); printf("\n");

// imprimes &a[i]
for(i=0;i<10;i++) printf("&a[%d] = %d\n",i,&a[i]); printf("\n");

// imprimes a_pointers[i]
for(i=0;i<10;i++) printf("a_pointers[%d] = %d\n",i,a_pointers[i]); printf("\n");

// imprimes a_pointers[0] + i
for(i=0;i<10;i++) printf("a_pointers[0] + %d = %d\n",i,a_pointers[0]+i); printf("\n");

// imprimes &a_pointers[i]
for(i=0;i<10;i++) printf("&a_pointers[%d] = %d\n",i,&a_pointers[i]); printf("\n");

// imprimes *a_pointers[i]
for(i=0;i<10;i++) printf("*a_pointers[%d] = %d\n",i,*a_pointers[i]); printf("\n");

return 0;
}

















