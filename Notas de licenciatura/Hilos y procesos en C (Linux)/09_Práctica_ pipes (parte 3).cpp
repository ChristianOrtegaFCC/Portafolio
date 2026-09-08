// Amador Ortega Christian Amauri - 201927821 - EL MAPACHE
// SO PCA_Pipes B)
// LOVE ON THE ROCKS

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(){
int fd[2],estado,color;
char buffer[12];
pid_t fruta, vehiculo, ropa;
pipe(fd);
    printf("\n\nPID de [MAIN]: %d, PPID: %d___(){\n",getpid(), getppid());
    do{
        printf("| escoge un color, pana:\n| 1.- rojo\n| 2.- verde\n| 3.- azul\n|    >>> ");
        scanf("%d",&color); printf("%d\n",color);
        if(color < 1 || color > 3) printf("| Solo puedes escoger entre 1 y 3\n") ;
    }while(color < 1 || color > 3);
    
    if(color == 1){ // rojo = fruta <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        if((fruta = fork()) == 0){
            char auxfruta[12];
            for(int i=0; i <12;i++ ) auxfruta[i] = '\0';
            printf("| PID de [fruta]: %d, PPID: %d___(){\n",getpid(), getppid());
            printf("| | Dame el nombre de una fruta:\n| |   >>> ");
            scanf("%s",&auxfruta); printf("%s\n",auxfruta);
            for(int i = 0;i < sizeof(auxfruta);i++) buffer[i] = auxfruta[i];
            write(fd[1],buffer,12);
            printf("| }\n}");
        }else{// main...
            waitpid(fruta,&estado,0);
            read(fd[0],buffer,12);
            printf("| Resultado del hijo (en este caso, fruta): %s\n",buffer);
            printf("}\n");
        }   
    }else{// el mero mero main se encuentra en algun lugar de aquí...
        if(color == 2){ // verde = ropa <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            if(( ropa = fork()) == 0){
                char auxropa[12];
                for(int i=0; i <12;i++ ) auxropa[i] = '\0';
                printf("| PID de [ropa]: %d, PPID: %d___(){\n",getpid(), getppid());
                printf("| | Dame el nombre de una prenda de ropa:\n| |   >>> ");
                scanf("%s",auxropa); printf("%s\n",auxropa);
                for(int i = 0;i < sizeof(auxropa);i++) buffer[i] = auxropa[i];
                write(fd[1],buffer,12);
                printf("| }\n}");
            }else{// main...
                waitpid(ropa,&estado,0);
                read(fd[0],buffer,12);
                printf("| Resultado del hijo (en este caso, ropa): %s\n",buffer);
                printf("}\n");
            }
        }else{
            if(color == 3){ // azul = vehiculo <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                if((vehiculo = fork()) == 0){
                    char auxvehiculo[12];
                    for(int i=0; i <12;i++ ) auxvehiculo[i] = '\0';
                    printf("| PID de [vehiculo]: %d, PPID: %d___(){\n",getpid(), getppid());
                    printf("| | Dame el nombre de una vehiculo:\n| |   >>> ");
                    scanf("%s",auxvehiculo); printf("%s\n",auxvehiculo);
                    for(int i = 0;i < sizeof(auxvehiculo);i++) buffer[i] = auxvehiculo[i];
                    write(fd[1],buffer,12);
                    printf("| }\n");
                }else{// main...
                    waitpid(vehiculo,&estado,0);
                    read(fd[0],buffer,12);
                    printf("| Resultado del hijo (en este caso, vehiculo): %s\n",buffer);
                    printf("}\n");
                }
            }else{// main, pero al parecer es unreachable
                printf("\n\n°°° You werent supposed to be able to get here, ¿you know?.... °°°\n\n");
            }
        }
    }
return 0;
}
