// B�sequeda binaria recursiva
// Amador Ortega Christian Amauri - El mapache
// 201927821   ||  BUAP - FCC

#include <stdio.h>
#include <math.h>
#define n 10

int busqueda(int A[], int buscar, int izquierda, int derecha);

int main(){
	int A[n],i,search = 512;// en este caso el elemento que estamos buscando, ya est� inicializado en el c�digo
	
	printf("elemento a buscar: %d\n",search);
	for(i=0;i<n;i++) A[i] = (i)*(i)*(i); // el arreglo tambi�n se llena autom�ticamente
	for(i=0;i<n;i++) printf("A[%d] = %d\n",i,A[i]); // mostramos el arreglo
	
	// por motivos did�cticos se dej� esta configuraci�n autom�tica
	// pero claro, si me piden cambiarlo a una en la que ingresemos
	// los datos manualmente, lo har� ^-^
	
	i = busqueda(A,search, 0, n);// primer llamado
	if (i != -1) printf("\nel elemento (%d) est%c en la posici%cn: [%d] del arreglo",search,416,418,i);
	else printf("\nEl elemento no se encontr%c, ermano",418);
	
	return 0;
}

/*
	NOTA !!!
	  Realmente no encontr� una parte en la que la caracter�stica
	  (o parte): "Unir" encajara como me hubiera gustado :( as� que
	  hice especulaciones....

*/

// Algoritmo recursivo <3
int busqueda(int A[], int find, int izq, int der){
    if (izq > der) return -1;
    int Mitad = floor((izq + der) / 2);// unir (porque identificamos elpar�metro en base al que trabajaremos (mitad))
    int valorEnElMedio = A[Mitad];
    
    if (find == valorEnElMedio) return Mitad; // resolver (si esta condici�n se cumple, entonces el problema est� resuelto)
    if (find < valorEnElMedio)  der = Mitad - 1; // unir (porque identificamos elpar�metro en base al que trabajaremos (mitad))
    else izq = Mitad + 1;
    
    return busqueda(A, find, izq, der); // descomponer (llamado recursivo para trabajar s�lo una fracci�n del problema)
}
