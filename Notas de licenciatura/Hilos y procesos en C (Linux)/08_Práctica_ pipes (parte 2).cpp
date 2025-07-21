// SO PCA4 [Pipes] ÁRBOL A)
// Amador Ortega Christian Amauri - 201927821 - EL MAPACHE
// LOVE ON THE ROCKS 
#include <stdio.h>
#include <stdlib.h>
#include  <unistd.h>
#include  <sys/wait.h>

int main(){
int fd[2],estado;
char var[9];
pipe(fd);
pid_t po_h,pa_o,pa_l,p0_a,p0_m,p0_d,pd_u,pd_n;
    if((p0_a = fork()) == 0){
        if((pa_o = fork()) == 0){
            if((po_h = fork()) == 0){
                printf("PID de [h]: %d, PPID: %d\n",getpid(), getppid());
                var[0] = 'H';
                write(fd[1],var,1);
            }else{
                waitpid(po_h,&estado,0);
                read(fd[0],var,1);
                printf("PID de [o]: %d, PPID: %d\n",getpid(), getppid());
                var[1] = 'o';
                write(fd[1],var,2);
            }
        }else{
            waitpid(pa_o,&estado,0);
            if((pa_l = fork()) == 0){
                printf("PID de [l]: %d, PPID: %d\n",getpid(), getppid());
                read(fd[0],var,2);
                var[2] = 'l';
                write(fd[1],var,3);
            }else{
                waitpid(pa_l,&estado,0);
                printf("PID de [a]: %d, PPID: %d\n",getpid(), getppid());
                read(fd[0],var,3);
                var[3] = 'a';
                write(fd[1],var,4);
            }
        }
    }else{
        waitpid(p0_a,&estado,0);
        waitpid(p0_m,&estado,0);
        if((p0_d = fork()) == 0 ){
            waitpid(p0_m,&estado,0);
            if((pd_u = fork()) == 0){
                printf("PID de [u]: %d, PPID: %d\n",getpid(), getppid());
                read(fd[0],var,5);
                var[5] = 'U';
                write(fd[1],var,6);
            }else{
                waitpid(pd_u,&estado,0);
                if((pd_n = fork()) == 0){
                    printf("PID de [n]: %d, PPID: %d\n",getpid(), getppid());
                    read(fd[0],var,6);
                    var[6] = 'n';
                    write(fd[1],var,7);
                }else{
                    waitpid(pd_n,&estado,0);
                    printf("PID de [d]: %d, PPID: %d\n",getpid(), getppid());
                    read(fd[0],var,7);
                    var[7] = 'd';
                    write(fd[1],var,8);
                }
            }
        }else{
            if((p0_m = fork()) == 0){
                printf("PID de [m]: %d, PPID: %d\n",getpid(), getppid());
                read(fd[0],var,4);
                var[4] = 'M';
                write(fd[1],var,5);
            }else{
                waitpid(p0_d,&estado,0);
                printf("PID de [@]: %d, PPID: %d\n",getpid(), getppid());
                read(fd[0],var,8);
                var[8] = '0';
                printf("Frase: %s",var);
            }
        }
    }
return 0;
}
