#include <iostream>
#include <stdlib.h>
#include <windows.h> // <--- responsable de la funcion Sleep();

int main(){
	printf("Ho");
	Sleep(2500); // 2500 milisegundos de espera = 2,5 segundos
	printf("la ");
	Sleep(2500);
	printf("Mal");
	Sleep(2500);
	printf("com");
	Sleep(2500);
	printf(".");
	Sleep(3000); // 3000 milisegundos de espera = 3 segundos
	printf(" co");
	Sleep(3000);
	printf("mo");
	Sleep(3000);
	printf(" es");
	Sleep(6000);
	printf("tas?");
return 0;
}
