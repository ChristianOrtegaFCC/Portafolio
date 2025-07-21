// Un puntero es una variable que almacena la dirección de memoria de una variable 
#include <stdio.h>

int main(){
char letra = 'B';  // ya sabes cómo funciona esto
char *puntero_a_letra;  // la variable *puntero_a_letra es de tipo entero aunque dicha variable esté referenciando a un valor tipo char
puntero_a_letra = &letra; // "puntero_a_letra = la dirección de la variable letra"

printf("El contenido de la variable [char] letra es: %c\n",letra);  // valor de 'letra'
printf("La direccion de la variable [char] letra es: %d\n",&letra); // "dirección de 'letra'"
printf("La direccion de la variable [char] letra es: %d\n",puntero_a_letra); //  dirección de 'letra' = valor de 'puntero_a_letra'
return 0;
}
