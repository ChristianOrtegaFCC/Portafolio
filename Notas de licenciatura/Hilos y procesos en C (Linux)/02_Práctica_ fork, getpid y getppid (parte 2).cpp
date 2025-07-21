// B) (Ahora sí creado por el mapachito)
#include <stdio.h>
#include <stdlib.h>

int main(){
int po_h,pa_o,pa_i,p0_a,p0_m,p0_d,pd_u,pd_n;
    if((p0_a = fork()) == 0){
        if((pa_o = fork()) == 0){
            if((po_h = fork()) == 0){
                printf("PID de [h]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                sleep(2);
                printf("PID de [o]: %d, PPID: %d\n",getpid(), getppid());
            }
        }else{
            if((pa_i = fork()) == 0){
                printf("PID de [i]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                sleep(2);
                printf("PID de [a]: %d, PPID: %d\n",getpid(), getppid());
            }
        }
    }else{
        if((p0_d = fork()) == 0 ){
            if((pd_n = fork()) == 0){    
                printf("PID de [n]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                if((pd_u = fork()) == 0){ 
                    printf("PID de [u]: %d, PPID: %d\n",getpid(), getppid());
                }else{
                    sleep(2);
                    printf("PID de [d]: %d, PPID: %d\n",getpid(), getppid());
                }
            }
        }else{
            if((p0_m = fork()) == 0){
                printf("PID de [m]: %d, PPID: %d\n",getpid(), getppid());    
            }else{
                sleep(4);
                printf("PID de [0]: %d, PPID: %d\n",getpid(), getppid());
            }
        }
    }
return 0;
}
