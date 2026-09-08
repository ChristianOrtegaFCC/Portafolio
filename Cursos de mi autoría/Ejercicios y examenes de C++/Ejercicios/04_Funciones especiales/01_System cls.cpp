#include <stdio.h>
#include <stdlib.h> // <---- responsable de la funcion system();

 int main(void){
 	// dejamos un cochinero de caracteres ;)
     for(int i=0;i<30;i++){
     	printf("-");
	 	for(int j=0;j<30;j++){
		   printf("/");
		   for(int k=0;k<3;k++) printf("°");
		   printf("#");
		}
		printf("+");
	 }
	 printf("\nSu programa ha dejado un cochinero de caracteres?\n");
     system("pause");
     system("cls");// Clear screen ;)
     printf("system('cls') te puede ayudar ;)");
	 return 0;
 }
