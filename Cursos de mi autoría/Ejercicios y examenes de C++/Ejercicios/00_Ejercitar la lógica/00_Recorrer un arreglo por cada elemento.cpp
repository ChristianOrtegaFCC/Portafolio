#include <stdio.h>
#include <iostream>

int main(){
	int i;
	int A[10];
	int l;
	int p;
for(i=0; i<10; i++){
	A[i] =i*10;
}

for(i=0; i<10; i++){
	printf("%d ,",A[i]);
}	
printf("Dame el lugar en el que quieres empezar \n");
scanf("%d", &l);
printf("%d\n",A[l] );
 while(p>=0 ){
 	printf("escribe 0 si quieres ir hacia atrás o 1 si quieres ir hacia adelante\n 2 para salir. \n 0 para atrás. \n 1 para adelante.");
	scanf("%d",&p);
 	if(p==0){
 		if(l==0){
 			l=9;
 			printf("El lugar es el numero %d. La entrada es %d\n", l, A[l]);
		 }
		else{l--; printf("El lugar es el número %d. La entrada es %d\n", l, A[l]);
		}
	}else{
		if(l==9){
 			l=0;
 			printf("El lugar es el numero %d. La entrada es %d\n", l, A[l]);
		 }
		else{if(p==2){return 0;}
		
		l++; printf("El lugar es el número %d. La entrada es %d\n", l, A[l]);
		}
	}
 } 
 
return 0;
}
