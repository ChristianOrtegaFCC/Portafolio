// paso de parámetros:
// int funcion_asignacion (int a);   <--- por valor       <--- (copia del valor)
// int funcion_asignacion (int *a);   <--- por referencia  <--- (dirección del valor) (equivalente a mandar LA variable)


////////////////////////////////////////////////////////////////[1]
#include <stdio.h>
int funcion_asignacion (int *a);//!!!!!

int b = 20;

int main(){
int a=10;
printf("[Main] valor de b: %d\n",b);
printf("[Main] valor de a: %d\n",a);
funcion_asignacion(&a);// !!!!
printf("[Main] valor de a: %d\n",a);
printf("[Main] direccion de a: %d\n",&a);
return 0;
}

int funcion_asignacion (int *a){// !!!!
*a = 500;// !!!!
printf("[Main] valor de b: %d\n",b);
printf("[funcion_asignacion] valor de a: %d\n",*a);
return 0;
}



/*
////////////////////////////////////////////////////////////////[2]
#include <stdio.h>
int asignacion (int *a);

int main(){
int a;
asignacion(&a);
printf("valor de a: %d",a);
return 0;
}

int asignacion (int *a){
*a = 10;
return 0;
}
*/
