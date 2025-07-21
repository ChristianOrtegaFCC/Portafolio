// SO PCA3 PARTE A)
// Amador Ortega Christian Amauri - 201927821 - EL MAPACHE
// LOVE ON THE ROCKS
#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <sys/wait.h>

int main(){
    int x=2,y=3,z=1,aux,i,estado,opc;
    pid_t ordasc,orddesc,sumatoria,producto;
    printf("\n\nPID[MAIN]: %d, PPID: %d _(){\n",getpid(), getppid());
    printf("| x >>> ");
    scanf("%d",&x); printf("%d\n",x);
    printf("| y >>> ");
    scanf("%d",&y); printf("%d\n",y);
    printf("| z >>> ");
    scanf("%d",&z); printf("%d\n",z);
    do{
        printf("| :::: M E N U ::::\n");
        printf("| 1.- Orden Ascendente\n");
        printf("| 2.- Orden Descendente\n");
        printf("| 3.- Sumatoria\n");
        printf("| 4.- Producto\n");
        printf("| opc >>> ");
        scanf("%d",&opc); printf("%d\n",opc);
        if (opc < 1 || opc > 4) printf("| \n| Solo puedes elegir entre 1 y 4, intenta de nuevo...\n");
    }while(opc < 1 || opc > 4);
    
    // P R O C E S O S
    if (opc == 1){
    if((ordasc = fork()) == 0){
        printf("| PID[ORDASC]: %d, PPID: %d _(){\n",getpid(), getppid());
        printf("| | Orden Ascendente:\n");
        for(i=1;i<=2;i++){// este algoritmito se veia menos deficiente en mi mente jajajajaj
            if(x>y){
                aux = x;
                x = y;
                y = aux;
            }
            if(y>z){
                aux = y;
                y = z;
                z = aux;
            }
        }
        printf("| | %d  %d  %d\n",x,y,z);
        printf("| } -- fin p_ascendente --------------\n");
        printf("}\n\n\n");
    }else{
        printf("}\n\n\n");// no sé cómo, pero esto es el 'main', y cada hijo de main puede tener un padre main personalizado.... no entiendo!!!!
    }  
    }else{
        waitpid(ordasc,&estado,0);
        if(opc == 2){
        if((orddesc = fork()) == 0){
            printf("| PID[ORDESC]: %d, PPID: %d _(){\n",getpid(), getppid());
            printf("| | Orden Descendente:\n");
            for(i=1;i<=2;i++){// este algoritmito se veia menos deficiente en mi mente jajajajaj
                if(x<y){
                    aux = x;
                    x = y;
                    y = aux;
                }
                if(y<z){
                    aux = y;
                    y = z;
                    z = aux;
                }
            }
            printf("| | %d  %d  %d\n",x,y,z);
            printf("| } -- fin p_descendente ------------------\n");
            printf("}\n\n\n");
        }else{
            printf("}\n\n\n"); // no sé cómo, pero esto es el 'main', y cada hijo de main puede tener un padre main personalizado.... no entiendo!!!!
        }
        }else{
            waitpid(orddesc,&estado,0);
            if(opc == 3 || opc == 4){
                if(opc == 3){
                if((sumatoria = fork()) == 0){
                    printf("| PID[SUMATORIA]: %d, PPID: %d _(){\n",getpid(), getppid());
                    printf("| | X + Y + Z = %d\n",x+y+z);
                    printf("| } -- fin p_sumatoria ------------------\n");
                    printf("}\n\n\n");
            
                }else{
                    waitpid(orddesc,&estado,0); 
                    printf("}\n\n\n");
                }
        
                }else{
                    waitpid(sumatoria,&estado,0);
                    if(opc == 4){
                    if((producto = fork()) == 0){
                        printf("| PID[PRODUCTO]: %d, PPID: %d _(){\n",getpid(), getppid());
                        printf("| | X * Y * Y = %d\n",x*y*z);
                        printf("| } -- fin p_producto -------------------\n");
                        printf("}\n\n\n");
                    }else{
                        waitpid(producto,&estado,0); 
                        printf("}\n\n\n"); // no sé cómo, pero esto es el 'main', y cada hijo de main puede tener un padre main personalizado.... no entiendo!!!!
                    }
                    }
                }
            }
        }
    }
    
    return 0;
}  
