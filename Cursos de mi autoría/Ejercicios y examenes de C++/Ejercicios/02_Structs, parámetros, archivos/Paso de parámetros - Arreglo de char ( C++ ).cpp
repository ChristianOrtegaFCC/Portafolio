//arreglo
#include <iostream>
#include <windows.h>  //sleep
#include <stdlib.h>   // cls
int Cambio_de_sexo(char name[]);

int main(){
	char name[20];
	name[0] = 'J';	name[1] = 'u';	name[2] = 'r';
	name[3] = 'g';	name[4] = 'e';	name[5] = 'n';
	
	printf("nombre: %s\n",name);
	Cambio_de_sexo(name);
	printf("nombre: %s\n",name);
	
	return 0;
}

int Cambio_de_sexo(char name[]){
	printf("Cambiando sexo :^)");
	Sleep(650); printf(".");
	Sleep(500); printf(".");
	Sleep(500);	printf(".");
	Sleep(500); system("cls");
	
	
	
	for(int i=0;i<(sizeof(name));i++){
		if(name[i] == '\0'){
			name[i] = 'a';			
			break;
		}
	}
	
	printf("%d",i);
	
	
	return 0;
}





