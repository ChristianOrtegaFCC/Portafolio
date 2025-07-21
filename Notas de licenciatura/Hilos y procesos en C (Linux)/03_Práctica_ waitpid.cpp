// SO PCA2 ÁRBOL A) [versión waitpid()]
// Amador Ortega Christian Amauri - 201927821 - EL MAPACHE
#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <sys/wait.h>

int main(){
int estado;
pid_t p2a1, p4a2,p4a3,p0a4,p0a9,p9a5,p9a6,p9a8,p8a7;
    if((p0a4 = fork()) == 0){
        if((p4a2 = fork()) == 0){
            if((p2a1 = fork()) == 0){
                printf("PID de [1]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                waitpid(p2a1,&estado,0);
                printf("PID de [2]: %d, PPID: %d\n",getpid(), getppid());
            }
        }else{
            waitpid(p4a2,&estado,0);
            if((p4a3 = fork()) == 0){
                printf("PID de [3]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                waitpid(p4a3,&estado,0);
                printf("PID de [4]: %d, PPID: %d\n",getpid(), getppid());
            }
        }
    }else{    
        waitpid(p0a4,NULL,0);
        if((p0a9 = fork()) == 0){
            if((p9a5 = fork()) == 0){
                printf("PID de [5]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                if((p9a6 = fork()) == 0){
                    printf("PID de [6]: %d, PPID: %d\n",getpid(), getppid());
                }else{
                    if((p9a8 = fork()) == 0){
                        if((p8a7 = fork()) == 0){
                            printf("PID de [7]: %d, PPID: %d\n",getpid(), getppid());
                        }else{
                            waitpid(p8a7,&estado,0);
                            printf("PID de [8]: %d, PPID: %d\n",getpid(), getppid());
                        }
                    }else{
                        waitpid(p9a8,&estado,0);
                        printf("PID de [9]: %d, PPID: %d\n",getpid(), getppid());
                    }
                }
            }
        }else{
            waitpid(p0a9,&estado,0);
            printf("PID de [@]: %d, PPID: %d\n",getpid(), getppid());
        }
    }
return 0;
}
