#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
int c11[2], c12[2], c21[2],c22[2];
char matrizA[2][3], matrizB[2][3];
char r11[3],r12[3],r21[3],r22[3],caux;
pid_t h00,h01,h10,h11;

// Tuberias
pipe(c11);
pipe(c12);
pipe(c21);
pipe(c22);

printf("matrizA[0][0]: "); scanf("%c",&matrizA[0][0]); fflush(stdin);  printf(" %c\n",matrizA[0][0]);
printf("matrizA[0][1]: "); scanf("%c",&matrizA[0][1]); fflush(stdin);  printf(" %c\n",matrizA[0][1]);
printf("matrizA[1][0]: "); scanf("%c",&matrizA[1][0]); fflush(stdin);  printf(" %c\n",matrizA[1][0]);
printf("matrizA[1][1]: "); scanf("%c",&matrizA[1][1]); fflush(stdin);  printf(" %c\n",matrizA[1][1]);
matrizA[0][2]='\0'; matrizA[1][2]='\0';
    
printf("matrizB[0][0]: "); scanf("%c",&matrizB[0][0]); fflush(stdin);  printf(" %c\n",matrizB[0][0]);
printf("matrizB[0][1]: "); scanf("%c",&matrizB[0][1]); fflush(stdin);  printf(" %c\n",matrizB[0][1]);
printf("matrizB[1][0]: "); scanf("%c",&matrizB[1][0]); fflush(stdin);  printf(" %c\n",matrizB[1][0]);
printf("matrizB[1][1]: "); scanf("%c",&matrizB[1][1]); fflush(stdin);  printf(" %c\n",matrizB[1][1]);
matrizB[0][2]='\0'; matrizB[1][2]='\0';
r11[2] = '\0';
r12[2] = '\0';
r21[2] = '\0';
r22[2] = '\0';
    
    
    
printf("\n");

printf("matriz A: \n [%s] \n [%s]\n",matrizA[0], matrizA[1]);
printf("matriz B: \n [%s] \n [%s]\n",matrizB[0], matrizB[1]);
// --.--
write(c11[1],matrizA[0],1);
write(c11[1],matrizB[0],1);
if((h00 = fork()) == 0){// M[0][0] <------------------------------------------
    char aux[2];
    read(c11[0],aux,2);
    //printf("matrizC[0][0]: %s PID:%d, PPID:%d\n",aux,getpid(),getppid());
    write(c11[1],aux,2);
}else{// padre
    sleep(3);
    read(c11[0],r11,2);
    //printf("\n[ %s ",r11);
    
    char x[2],y[2];
    x[0] = matrizA[0][1];  x[1] = '\n';
    y[0] = matrizB[0][1];  y[1] = '\n';
        
    write(c12[1],x,1);
    write(c12[1],y,1);
    if((h01 = fork()) == 0){ // M[0][1] <---------------------------------------------
        char aux[2];
        read(c12[0],aux,2);
        //printf("matrizC[0][1]: %s PID:%d, PPID:%d\n",aux,getpid(),getppid());
        write(c12[1],aux,2);
    }else{
        sleep(3);
        read(c12[0],r12,2);
        //printf(" %s ]\n",r12);
        
        write(c21[1],matrizA[1],1);
        write(c21[1],matrizB[1],1);
        if((h10 = fork()) == 0){// M[1][0] <--------------------------------------------------
            char aux[2];
            read(c21[0],aux,2);
            //printf("matrizC[1][0]: %s PID:%d, PPID:%d\n",aux,getpid(),getppid());
            write(c21[1],aux,2);
        }else{
            sleep(3);
            read(c21[0],r21,2);
            //printf("[ %s ",r21);
            
            char w[2],z[2];
            w[0] = matrizA[1][1];  w[1] = '\n';
            z[0] = matrizB[1][1];  z[1] = '\n';
            
            write(c22[1],w,1);
            write(c22[1],z,1);
            if((h11 = fork())==0){// M[1][1] <---------------------------------------------------
                char aux[2];
                read(c22[0],aux,2);
                //printf("matrizC[1][1]: %s PID:%d, PPID:%d\n",aux,getpid(),getppid());
                write(c22[1],aux,2);
            }else{
                read(c22[0],r22,2);
                //printf(" %s ]\n",r22);
            }
        }
    }
}

// finalmente escribimos todos los resultados
    printf("\n[ %s ",r11);  printf(" %s ]\n",r12);
    printf(  "[ %s ",r21);  printf(" %s ]\n",r22);
    
}
