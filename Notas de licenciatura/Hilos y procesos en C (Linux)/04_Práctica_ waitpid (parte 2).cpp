// SO PCA2 ÁRBOL B) [versión waitpid()]
// Amador Ortega Christian Amauri - 201927821 - EL MAPACHE
// LOVE ON THE ROCKS 
#include <stdio.h>
#include <stdlib.h>
#include  <unistd.h>
#include  <sys/wait.h>

int main(){
int estado;
pid_t po_h,pa_o,pa_l,p0_a,p0_m,p0_d,pd_u,pd_n;
    if((p0_a = fork()) == 0){
        if((pa_o = fork()) == 0){
            if((po_h = fork()) == 0){
                printf("PID de [h]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                waitpid(po_h,&estado,0);
                printf("PID de [o]: %d, PPID: %d\n",getpid(), getppid());
            }
        }else{
            waitpid(pa_o,&estado,0);
            if((pa_l = fork()) == 0){
                printf("PID de [l]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                waitpid(pa_l,&estado,0);
                printf("PID de [a]: %d, PPID: %d\n",getpid(), getppid());
            }
        }
    }else{
        waitpid(p0_a,&estado,0);
        waitpid(p0_m,&estado,0);
        if((p0_d = fork()) == 0 ){
            waitpid(p0_m,&estado,0);
            if((pd_u = fork()) == 0){
                printf("PID de [u]: %d, PPID: %d\n",getpid(), getppid());
            }else{
                waitpid(pd_u,&estado,0);
                if((pd_n = fork()) == 0){
                    printf("PID de [n]: %d, PPID: %d\n",getpid(), getppid());
                }else{
                    waitpid(pd_n,&estado,0);
                    printf("PID de [d]: %d, PPID: %d\n",getpid(), getppid());
                }
            }
        }else{
            if((p0_m = fork()) == 0){
                printf("PID de [m]: %d, PPID: %d\n",getpid(), getppid());    
            }else{
                waitpid(p0_d,&estado,0);
                printf("PID de [@]: %d, PPID: %d\n",getpid(), getppid());
            }
        }
    }
return 0;
}
