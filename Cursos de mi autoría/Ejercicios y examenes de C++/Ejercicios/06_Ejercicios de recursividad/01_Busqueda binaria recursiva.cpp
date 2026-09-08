// B�sequeda binaria recursiva
// Amador Ortega Christian Amauri
// 201927821   ||  BUAP - FCC

#include <stdio.h>
#include <math.h>
#define n 10

int busqueda(int A[], int buscar, int izquierda, int derecha);

int main(){
	int A[n],i,search = 512;
	
	printf("elemento a buscar: %d\n",search);
	for(i=0;i<n;i++) A[i] = (i)*(i)*(i);
	for(i=0;i<n;i++) printf("A[%d] = %d\n",i,A[i]);
	
	i = busqueda(A,search, 0, n);
	if (i != -1) printf("\nel elemento (%d) est%c en la posici%cn: [%d] del arreglo",search,416,418,i);
	else printf("\nEl elemento no se encontr%c, ermano",418);
	
	return 0;
}


int busqueda(int A[], int find, int izq, int der){
    if (izq > der) return -1;
    int Mitad = floor((izq + der) / 2);
    int valorEnElMedio = A[Mitad];
    
    if (find == valorEnElMedio) return Mitad;
    if (find < valorEnElMedio)  der = Mitad - 1;
    else izq = Mitad + 1;
    
    return busqueda(A, find, izq, der);
}
