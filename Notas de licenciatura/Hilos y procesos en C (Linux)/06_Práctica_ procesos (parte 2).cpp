// Amador Ortega Christian Amauri - 201927821
// SO PCA 3b (Arbolote)
// LOVE ON THE ROCKS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t p_pasatiempos, p_videojuegos,p_lectura,p_ejercicio,p_ocupacion,p_estudias,p_trabajas,p_casa_o_auto,p_casa,p_auto;
    int edad, color_int, opc;
    char color_char[6], aux[20];
    
    //printf("\n\nInicio_proceso(){");
    printf("\n\nPID [MAIN]: %d, PPID: %d _(){", getpid(), getppid()); 
    
    do{
        printf("\n| Tu edad?\n|  >>> ");
        scanf("%d", &edad); printf("%d",edad);
        if(edad < 1 || edad > 99) printf("\n| debes elegir entre 1 y 99, intenta de nuevo.");
    }while(edad < 1 || edad > 99);
    
    do{
        printf("\n| Tu color favorito?\n");
        printf("| 1.Rojo\n| 2.Verde\n| 3.Azul\n|  >>> ");
        scanf("%d", &color_int); printf("%d",color_int);
        if (color_int == 1) strcpy(color_char, "Rojo ");
        if (color_int == 2) strcpy(color_char, "Verde");
        if (color_int == 3) strcpy(color_char, "Azul ");
        if ( color_int < 1 || color_int > 3) printf("\n| debes elegir entre 1 y 3, intenta de nuevo."); 
    } while ( color_int < 1 || color_int > 3);
    
    if(edad < 18){
    if((p_pasatiempos = fork()) == 0){ // PASATIEMPOS (edad < 18), HIJO DE MAIN
            printf("\n| PID [pasatiempos]: %d, PPID: %d _(){", getpid(), getppid());
            do{
                printf("\n| | Cual es tu pasatiempo?");
                printf("\n| | 1.Videojuegos\n| | 2.Lectura\n| | 3.Ejercicio\n| |   >>> ");
                scanf("%d", &opc); printf("%d",opc);
                if (opc < 1  || opc > 3) printf("\n| | solo puedes escoger entre 1 y 3, intenta de nuevo...");
            }while(opc < 1  || opc > 3);
            if(opc == 1){
            if((p_videojuegos = fork()) == 0){ //  VIDEOJUEGOS 
                    printf("\n| | PID [videojuegos]: %d, PPID: %d _(){", getpid(), getppid());   
                    printf("\n| | | Edad: %d, Color: %s, Pasatiempo: Videojuegos.", edad, color_char);  
                    printf("\n| | } // fin p_Videojuegos //////////////////////////////"); 
                    printf("\n| }");
                    printf("\n}");
                }else{
                    //printf("main_p...");
                }
            }else{
                waitpid(p_videojuegos,NULL,0); // "ESPERA PROCESO 'VIDEOJUEGOS'"
                if(opc == 2){
                    if((p_lectura = fork()) == 0){ // LECTURA
                        printf("\n| | PID [lectura]: %d, PPID: %d _(){", getpid(), getppid());   
                        printf("\n| | | Edad: %d, Color: %s, Pasatiempo: Lectura.", edad, color_char);    
                        printf("\n| | } // fin p_Lectura //////////////////////////////");
                        printf("\n| }");
                        printf("\n}");
                    }else{
                        //printf("main_p...");
                    }
                }else{
                    waitpid(p_lectura,NULL,0);// "ESPERA PROCESO 'LECTURA'"
                    if(opc == 3){
                    if((p_ejercicio = fork()) == 0){ //  EJERCICIO
                            printf("\n| | PID [Ejercicio]: %d, PPID: %d _(){", getpid(), getppid());   
                            printf("\n| | | Edad: %d, Color: %s, Pasatiempo: Ejercicio.", edad, color_char);
                            printf("\n| | } // fin p_Ejercicio //////////////////////////////");
                            printf("\n| }");
                            printf("\n}");
                        }else{
                            //printf("main_p...");
                        }
                    }else{// PADRE DE TODOS LOS PROCEOS 'PASATIEMPOS' ( edad < 18 )
                        waitpid(p_lectura,NULL,0); // "ESPERA PROCESO 'LECTURA'"
                        printf("\n| } // fin p_Pasatiempos //////////////////////////////");
                    }
                } 
            }    
        }else{
            //printf("main_P...");
        }
    }else{// PROCESOS PARA: ( edad >= 18 )
        waitpid(p_pasatiempos,NULL,0); // "ESPERA A PROCESO 'PASATIEMPOS'"
        if(edad > 17 && edad < 41){
            if((p_ocupacion = fork()) == 0){ //OCUPACION? ( 17 < edad < 41), HIJO DE MAIN
                printf("\n| PID [ocupacion?]: %d, PPID: %d _(){", getpid(), getppid());
                if(color_int == 2 || color_int == 3){ // 2 = verde.     3 = azul.
                    if((p_estudias = fork()) == 0){// ESTUDIAS?
                        printf("\n| | PID [estudias?]: %d, PPID: %d _(){", getpid(), getppid());
                        do{
                            printf("\n| | |Estudias?");
                            printf("\n| | | 1.Si\n| | | 2.No\n| | |    >>> ");
                            scanf("%d", &opc); printf("%d",opc);
                            if (opc < 1 || opc > 2) printf("\n| | | Solo puedes escoger entre 1 y 2\n");
                        } while (opc < 1 || opc > 2);
                        if(opc == 1){
                            printf("\n| | | Que Estudias?\n| | | >>> ");
                            scanf("%s", aux); printf("%s",aux);
                            printf("\n| | | Edad: %d,  Color: %s,  Estudias: %s", edad, color_char, aux);
                        }else{
                            printf("\n| | | Edad: %d,  Color: %s,  No estudias", edad, color_char);        
                        }
                        printf("\n| | }// fin p_estudias //////////////////////////////// ");
                        printf("\n| }");
                        printf("\n} ");  
                    }else{
                        //printf("\nmain_p....");
                    }
                }else{
                    waitpid(p_estudias,NULL,0); // "ESPERA PROCESO 'ESTUDIAS?'"
                    if(color_int == 1){ // 1 = Rojo.
                    if((p_trabajas = fork()) ==0){ // TRABAJAS?
                            printf("\n| | PID [trabajas?]: %d, PPID: %d _(){", getpid(), getppid());
                                do{
                                    printf("\n| | | Trabajas?");
                                    printf("\n| | | 1.Si\n| | | 2.No\n| | |   >>> ");
                                    scanf("%d", &opc); printf("%d",opc);
                                    if (opc < 1 || opc > 2) printf("\n| | | Solo puedes escoger entre 1 y 2, intenta de nuevo...");
                                } while (opc < 1 || opc > 2);
                                if(opc == 1){
                                    printf("\n| | | En que Trabajas?\n| | |   >>>");
                                    scanf("%s", aux); printf("%s",aux);
                                    printf("\n| | | Edad: %d,  Color: %s,  Trabajas en: %s", edad, color_char, aux);
                                }else{
                                    printf("\n| | | Edad: %d,  Color: %s,  No Trabajas", edad, color_char);        
                                }
                            printf("\n| | }// fin p_trabajas //////////////////////////////// ");
                            printf("\n| }");
                            printf("\n} "); 
                        }else{
                            //printf("main_p...");
                        }
                          
                    } 
                }  
            }else{
                waitpid(p_trabajas,NULL,0); // "ESPERA PROCESO 'TRABAJAS'"
                printf("\n| } // fin p_ocupacion //////////////////////////////");  
            }
        }else{
            waitpid(p_ocupacion,NULL,0); // "ESPERA A PROCESO 'OCUPACION'"
            if(edad > 40){
            if((p_casa_o_auto = fork()) ==0){ // CASA_O_AUTO? (edad > 40), HIJO DE MAIN
                    printf("\n| PID [casa_o_auto?]: %d, PPID: %d _(){", getpid(), getppid());    
                    if(color_int == 2 ){
                        if((p_auto = fork()) == 0){ // AUTO? (color VERDE)
                            printf("\n| | PID [auto?]: %d, PPID: %d _(){", getpid(), getppid()); 
                            do{
                                printf("\n| | | Tienes auto?");
                                printf("\n| | | 1.Si\n| | | 2.No\n| | |   >>> ");
                                scanf("%d", &opc); printf("%d",opc);
                                if (opc < 1 || opc > 2) printf("\n| | | solo puedes elegir entre 1 y 2, intenta de nuevo...");
                            } while (opc < 1 || opc > 2);
                            if(opc == 1){
                                printf("\n| | | Que auto tienes?\n| | |   >>> ");
                                scanf("%s", aux); printf("%s",aux);
                                printf("\n| | | Edad: %d,  Color: %s,  Tu auto es un: %s.", edad, color_char, aux);
                            }else{
                                printf("\n| | | Edad: %d,  Color: %s,  No tienes auto.", edad, color_char);        
                            }
                            printf("\n| | } // fin p_auto? //////////////////////////////");
                            printf("\n| } ");
                            printf("\n}");
                        }else{
                            //printf("\nmain_p...");
                        }   
                    }else{
                        waitpid(p_auto,NULL,0);// "ESPERA PROCESO 'AUTO?'"
                        if(color_int == 1 || color_int == 3){
                            if((p_casa = fork()) ==0){ // CASA? (color ROJO, AZUL)
                                printf("\n| | PID [casa?]: %d, PPID: %d _(){", getpid(), getppid());  
                                do{
                                    printf("\n| | | Tienes casa?");
                                    printf("\n| | | 1.Si\n| | | 2.No\n| | |   >>> ");
                                    scanf("%d", &opc); printf("%d",opc);
                                    if (opc < 1 || opc > 2) printf("\n| | | Solo puedes escoger entre 1 y 2, intenta otra vez...");
                                } while (opc < 1 || opc > 2);
                                if(opc == 1){
                                    printf("\n| | | Edad: %d,  Color: %s,  Tienes casa", edad, color_char);
                                }else{
                                    printf("\n| | | Edad: %d,  Color: %s,  NO tienes casa", edad, color_char);        
                                }
                                printf("\n| | } // fin p_casa? //////////////////////////////");
                                printf("\n| } ");
                                printf("\n}"); 
                            }else{
                                ///printf("\nmain_p...");
                            }    
                        }else{
                               //printf("\nmain_p...");
                        }    
                    }    
            }else{ // PADRE DE " CASA_O_AUTO" (para > 41)
                waitpid(p_casa,NULL,0);// "ESPERA PROCESO 'CASA?'"
                printf("\n| } // fin p_casa_o_auto //////////////////////////////");
            }
                
            }else{// MAIN
                waitpid(p_casa_o_auto,NULL,0);// "ESPERA PROCESO 'casa_o_auto'"
                printf("\nfin main....?");
                //printf("\n\nPID [MAIN]: %d, PPID: %d\n\n", getpid(), getppid());    
            }
        }
        
    }
    
    return 0;
}
