#include <stdio.h>
#include <stdlib.h> // <---- responsable de la funcion system();

 int main(void){
     printf("Hola\n ");
     system("pause");// Note que System pause escribe en ejecuci�n el mensaje: "Presione una tecla para continuar. . ."
     printf("Mundo\n");
	 return 0;
 }
