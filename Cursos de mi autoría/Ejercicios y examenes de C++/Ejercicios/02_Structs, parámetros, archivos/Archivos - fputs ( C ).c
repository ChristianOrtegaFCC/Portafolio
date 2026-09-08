#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// aquí explicamos el uso de fputs para archivos
// >  fputs escribe un string en el archivo, pero reescribe el archivo primero
//    es decir, primero borra todo lo que el archivo ten�a y luego ya escribe lo que debe
// 
// >  si el archivo referenciado en el descriptor de archivos no existe en la carpeta 
//    en la que el code se encuentra (en este caso, este mismo c�digo), el archivo se crear�
//    con el nombre indicado

int main(){
	char mensaje[50];
	strcpy(mensaje,"xdxd...");
	
	FILE* temp = fopen("temporal.txt","w"); // !!!!!!
	if(!temp){
		printf("Error al abrir el archivo\n");
		return 1;
	}
	
	
	/* forma 1
	int result = fputs(mensaje,temp); // !!!!!!
	if(result == EOF){ // !!!!!!
		printf("xd, algo sali� mal");
	}else{
		printf("Hemos escrito: %s\n",mensaje);
	}*/
	
	// forma 2 // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		fputs(mensaje,temp);
	printf("Hemos escrito: \n%s\n",mensaje);
	strcpy(mensaje,"una vez mas...");
		fputs(mensaje,temp);
	printf("%s\n",mensaje);
	
	
	
	// hay n formas...
	
	fclose(temp); // !!!!!!
	
	return 0;
}
