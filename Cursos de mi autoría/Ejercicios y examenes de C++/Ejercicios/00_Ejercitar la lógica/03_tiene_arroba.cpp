#include <stdio.h>
#include <string.h>
#define max 50

// b1 -> no hay @
// b2 -> no hay .
// b3 -> no hay ni @ ni .
// b4 -> hay @ y . pero no donde deber�an

void verifica(char correo_a_verificar[],bool *b1,bool *b2,bool  *b3,bool  *b4);

int main(){
	char correo[100];// = "perrinperranchis@gmail.com";
	bool b1,b2,b3,b4;
	int xd = 1;
	do{
		b1 = true;b2=true;b3=true;b4=false;
		printf("\nDame un correo: ");
		scanf("%s",&correo);
		
		if(xd == 1) strcpy(correo,"Perrin");
		if(xd == 2) strcpy(correo,"perrin.com");
		if(xd == 3) strcpy(correo,"perrin@gmail");
		if(xd == 4) strcpy(correo,"perrin.com@gmail");
		if(xd == 5) strcpy(correo,"perrin@gmail.com");
		
		xd++;
		printf("%s\n",correo);
		
		
		verifica(correo,&b1,&b2,&b3,&b4);
		if(b1 == true) printf("Correo inv%clido, no hay @\n",416);
		if(b2 == true) printf("Correo inv%clido, no hay .\n",416);
		if(b3 == true) printf("Correo inv%clido, no hay ni @ ni .\n",416);
		if(b4 == true) printf("Correo inv%clido, hay @ y . pero no en el orden correcto\n",416);
	}while(b1 == true ||b2 == true ||b3 == true ||b4 == true);
	printf("Correo v%clido !!!\n",416);
	return 0;
}

void verifica(char correo_a_verificar[],bool *b1,bool *b2,bool  *b3,bool  *b4){
	int i=0,j;
	do{
		if(correo_a_verificar[i] == '@'){
			*b1 = false;
			*b3 = false;
		}
		if(correo_a_verificar[i] == '.'){
			*b2 = false;
			*b3 = false;
		}
		i++;
	}while(correo_a_verificar[i] != '\0');
	if(*b3 == true){
		*b1 = false;
		*b2 = false;
		*b4 = false;
	}else{
		*b4 = true;
		j=0;
			do{
				if(correo_a_verificar[j] == '@'){
					*b4 = false;
					break;
				}
				if(correo_a_verificar[j] == '.'){
					if(*b1 == true){
						*b4 = false;	
					}
					break;
				}
				j++;
			}while(correo_a_verificar[j] != '\0');
	}
	return;
}
