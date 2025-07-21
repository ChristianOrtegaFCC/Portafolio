#include <stdlib.h>
#include <stdio.h>
#define max 50

int write();
int read();
int mostrar();


typedef struct {
	int largo;
	int ancho;
	int altura;	
}prisma;

prisma prismas[max];  // !!!!! Dime qué está sucediedo aquí
int next_free = 0;

int main(){
	int op = 0;
	read();
	do{
		printf("___MENU_________________\n");
		printf("1. agregar prisma\n");
		printf("2. mostrar los datos\n");
		printf("3. salir\n");
		printf(" >> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				write();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				printf("\nadios");
				return 0;
				break;
			default:
				printf("esa opcion no existe pa\n");
				break;		
		}
	}while(1);
	return 0;
}

int write(){
    FILE *arch; // !!!!! Dime qué está sucediedo aquí
    arch=fopen("Prismas.dat","ab"); // !!!!! Dime qué está sucediedo aquí
    if (arch==NULL){  // !!!!! Dime qué está sucediedo aquí
        printf("No se pudo abrir el archivo");
        return 0;
    }else{
    	prisma prisma_aux;
    	printf("Guardando nuevo prisma...\n");
        printf("Largo: ");
        scanf("%d",&prisma_aux.largo);
        fflush(stdin);
        printf("Ancho: ");
        scanf("%d",&prisma_aux.ancho);
        fflush(stdin);
        printf("Altura: ");
        scanf("%d",&prisma_aux.altura);
        fflush(stdin);
        
        fwrite(&prisma_aux, sizeof(prisma), 1, arch);  // !!!!! Dime qué está sucediedo aquí
        
        prismas[next_free].largo  = prisma_aux.largo;
        prismas[next_free].ancho  = prisma_aux.ancho;
        prismas[next_free].altura = prisma_aux.altura;
        next_free ++;
        
        fclose(arch);  // !!!!! Dime qué está sucediedo aquí
        
        
    }
    printf("\nLa proxima vez recordare este :^)\n\n");
	return 0;
}

int read(){
	int i =0;
	FILE *arch; // !!!!! Dime qué está sucediedo aquí
    arch=fopen("Prismas.dat","rb"); // !!!!! Dime qué está sucediedo aquí
    if (arch==NULL){
        printf("\nNo se pudo abrir el archivo\n\n"); 
        return 0;
    }else{
    	prisma prisma_aux;
    	fread(&prisma_aux, sizeof(prisma), 1, arch); // !!!!! Dime qué está sucediedo aquí
    	while(!feof(arch)){
        	prismas[i].largo  = prisma_aux.largo;
        	prismas[i].ancho  = prisma_aux.ancho;
        	prismas[i].altura = prisma_aux.altura;
			fread(&prisma_aux, sizeof(prisma), 1, arch);
			i++;
			next_free=i+1;;
    	}
    fclose(arch); // !!!!! Dime qué está sucediedo aquí
    }
	return 0;
}

int mostrar(){
	int i;
	for(i=0;i<next_free-1;i++){
		printf("\nPrisma____________[%d]:\n",i);
		printf("Largo: %dcm\n",prismas[i].largo);
		printf("Ancho: %dcm\n",prismas[i].ancho);
		printf("Altura: %dcm\n",prismas[i].altura);
		printf("Volumen: %dcm^2\n", (prismas[i].largo*prismas[i].ancho)*prismas[i].altura );	
	}
	printf("\n\n");
	return 0;
}

