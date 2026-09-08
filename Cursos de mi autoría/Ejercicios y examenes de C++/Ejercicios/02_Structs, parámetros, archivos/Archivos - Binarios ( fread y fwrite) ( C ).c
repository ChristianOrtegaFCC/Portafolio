#include <stdio.h>
#include <string.h>

int mosttodo();
int alta();
int buscar();


typedef struct {
	char nombre[25];
	char direc[25];
	int num;
	char espec[25];
}dent;

int main (){
     int opc;
     
     do{
        system("cls");
        printf("*****Men%c de agenda*****",163);
        printf("\n[1] Alta de un dato.");
        printf("\n[2] Mostrar dentista en particular.");
        printf("\n[3] Mostrar todo.");
        printf("\n[4] Fin");
        printf("\nOPCION: ");
        scanf("%i", &opc);
        fflush(stdin);
        switch(opc)
        {
            case 1: system("cls");
                    alta();
                    break;
                
            case 2: system("cls");
                    buscar();
                    break;
                
            case 3: system("cls");
                    mosttodo();
                    break;
                
            /*default: system("cls");
                     printf("Opci%cn invalida...",162);
                     system("pause");
                     break; */
        }
        if(opc < 1 || opc > 4){
            printf("\nesa opcion no existe en el menu, intenta de nuevo\n");
        	system("pause");
		}
       
    }while(opc!=4);
    system("pause");
    
    return 0;
}

int alta(){   
    int cont=0;
    FILE *arch; // !!!!!
    arch=fopen("Agenda.dat","ab"); // !!!!!
    if (arch==NULL){  // !!!!!
        printf("No se pudo abrir el archivo");
        return 0;
    }else{
        dent dentistas;  // !!!!!
        printf("Ingrese el nombre del dentista %d: ",cont+1);
        gets(dentistas.nombre);
        fflush(stdin);
        
        printf("Ingrese la direcci%cn: ",162);
        gets(dentistas.direc);
        fflush(stdin);
        
        printf("Ingrese n%cmero telef%cnico: ",163,162);
        scanf("%d",&dentistas.num);
        fflush(stdin);
        
        printf("Ingrese la especialidad: ");
        gets(dentistas.espec);
        fflush(stdin);
        
        fwrite(&dentistas, sizeof(dent), 1, arch);  // !!!!!
        fclose(arch);  // !!!!!
    }
    printf("\n");
    system("pause");
}

int buscar(){
    int num;
    dent dentistas; // !!!!!
    FILE *arch; // !!!!!
    arch=fopen("Agenda.dat","rb"); // !!!!!
    if (arch==NULL){
        printf("No se pudo abrir el archivo");
        return 0;
    }else{
    printf("Ingrese el n%cmero telef%cnico del dentista: ",163,162);
    scanf("%d", &num);
    
    int existe=0;
    fread(&dentistas, sizeof(dent), 1, arch); // !!!!!
    while(!feof(arch))
    {
        if (num==dentistas.num)
        {
            printf("\nNombre: %s\nDirecci%cn: %s\nN%cmero telef%cnico: %d\nEspecialidad:%s\n",dentistas.nombre,162,dentistas.direc,163,162,dentistas.num,dentistas.espec);
           existe=1;
           break;
        }
        fread(&dentistas, sizeof(dent), 1, arch); // !!!!!
    }
    if (existe==0)
        printf("No se encontro al dentista...\n");
    fclose(arch); // !!!!!
   }
    printf("\n");
    system("pause");
}


int mosttodo(){
    FILE *arch; // !!!!!
    arch=fopen("Agenda.dat","rb"); // !!!!!
    if (arch==NULL){
        printf("No se pudo abrir el archivo\n"); 
        return 0;
    }
    else{
    dent dentistas; // !!!!!
    fread(&dentistas, sizeof(dent), 1, arch); // !!!!!
    printf("Nombre:\t\tDireccion:\t\tNumero telefonico\t\tEspecialidad:");
    while(!feof(arch)){
        printf("\n%s\t\t%s\t\t%d\t\t%s\n", dentistas.nombre,dentistas.direc,dentistas.num,dentistas.espec);
        fread(&dentistas, sizeof(dent), 1, arch);
	}
    fclose(arch); // !!!!!
    }
    printf("\n");
    system("pause");
}
