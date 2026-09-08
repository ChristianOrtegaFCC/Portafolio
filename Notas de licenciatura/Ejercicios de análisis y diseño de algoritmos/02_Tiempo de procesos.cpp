// Tiempo de procesos
// Amador Ortega Christian Amauri

#include <stdio.h>

struct A{
	int time;
	int number;
};

int main(){
	int N,i,j,tot,subtot,aux;
	A Array[20];
	
	// obtener total de clientes
	do{
		printf("Total de clientes: ");
		scanf("%d",&N);
		if(N < 2 || N > 20) printf("El rango para este dato es de 2 a 20, intentalo de nuevo...\n");
	}while(N < 2 || N > 20);
	printf("\n");
	
	// obtener los tiempos y los numeros de los clientes (el numero se asigna automatcamente)
	for(i=0;i<N;i++){
		Array[i].number = i+1;
		printf("Tiempo del cliente[%d]: ",i+1);
		scanf("%d",&Array[i]);	
	}
	
	// ordenar los tiempos de menor a mayor (junto con su numero de cliente) (mediante m�todo burbuja)
	for(i=0;i<N-1;i++){
		j=i;
		while(j != N ){
			if(Array[i].time > Array[j].time){
				aux = Array[i].time;
				Array[i].time = Array[j].time;
				Array[j].time = aux; // Array[].time <--- conjunto de candidatos
				aux = Array[i].number;
				Array[i].number = Array[j].number;
				Array[j].number = aux;
			}else{
				j++;
			}	
		}
	}
	
	// calcular suma de tiempos
	tot = 0;
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			tot = tot + Array[j].time;
		}	
	}
	// mostrar el resultado:
	printf("\n\n C[i] / t(C[i])\n");
	for(i=0;i<N;i++){
		printf("   %d  ,   %d\n",Array[i].number, Array[i].time);
	}
	printf("\nTiempo total: %d",tot); // tot <--- solucion
	
	return 0;
}
