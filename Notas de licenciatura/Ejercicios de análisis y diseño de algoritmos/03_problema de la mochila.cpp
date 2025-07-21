// problema de la mochila
// Amador Ortega Christian Amauri

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#define n 100

typedef struct{
	float peso;
	float valor;
	float VpU;
}cosa;

int show_data(cosa cosas[n],int lim);
void animacion_chula();

int main(){
	float W=0,aux,solucion[n],peso_acumulado;
	int i,j,lim;
	cosa cosas[n];
	
	// obtenemos los datos...
	printf("cual es el limite maximo de peso?... ");
	scanf("%f",&W);
	
	printf("Cuantos objetos?... ");
	scanf("%d",&lim);
	
	animacion_chula();
	system("cls");
	
	for(i=0;i<lim;i++){
		printf("objeto...........[%d]\n",i);
		do{
			printf("peso: ");
			scanf("%f",&cosas[i].peso);	
			if(cosas[i].peso > W) printf("\n  >> Por motivos didacticos, no te dejaremos meter algo con un peso\n     mayor a %.2f, ni aunque sea un porcentaje, intenta de nuevo...\n\n",W);
		}while(cosas[i].peso > W);
		printf("valor: ");
		scanf("%f",&cosas[i].valor);
		printf("\n");
		cosas[i].VpU = cosas[i].valor / cosas[i].peso;
	}
	
	animacion_chula();
	system("cls");
	printf("mostrando (desordenado)...\n");
	show_data(cosas,lim);
	
	for(i=0;i<lim-1;i++){ // ordenamiento m�todo burbuja
		j=i;
		while(j != lim ){
			if(cosas[i].VpU < cosas[j].VpU){ // los que m�s valen por unidad0 ser�n considerados primero
				aux = cosas[i].peso;
				cosas[i].peso = cosas[j].peso;
				cosas[j].peso = aux;
				
				aux = cosas[i].valor;
				cosas[i].valor = cosas[j].valor;
				cosas[j].valor = aux;
				
				aux = cosas[i].VpU;
				cosas[i].VpU = cosas[j].VpU;
				cosas[j].VpU = aux;
				
			}else{
				j++;
			}	
		}
	}
	
	animacion_chula();
	printf("\n\nmostrando (ordenado de mayor a menor por valor p/u)...\n");
	show_data(cosas,lim);
	
	// algoritmo voraz ...
	peso_acumulado = 0;
	for(i=0;i<lim;i++) solucion[i] = 0;// inicializar todas las soluciones como 0
	for(i=0;i<lim;i++){
		if( peso_acumulado + cosas[i].peso <= W ){//a�adir peso completo de cosas[i]
			peso_acumulado = peso_acumulado + cosas[i].peso; 
			solucion[i] = 1;
		}else{ //a�adir una fracci�n del peso de cosas[i]
			solucion[i] = (W-peso_acumulado)/cosas[i].peso;
			peso_acumulado = W;
			break;
		}
		if(peso_acumulado >= W) break;
	}
	
	// mostramos los resultados...
	animacion_chula();
	for(i=0;i<lim;i++) printf("\nDel objeto [%d], vamos a llevar... %.2f",i,solucion[i]);
	
	return 0;
}


int show_data(cosa cosas[n],int lim){
	/*		valor/peso   =>   $/kg		*/
	int i;
	for(i=0;i<lim;i++){
		printf("cosa.............[%d]\n",i);
		printf(" peso: %.2f\n",cosas[i].peso);
		printf(" valor: %.2f\n",cosas[i].valor);
		printf(" valor por unidad: %.2f\n\n",cosas[i].VpU);
	}
	printf("\n");
	return 0;
}


void animacion_chula(){
	printf("Wait");
	Sleep(400);	printf(". ");
	Sleep(300);	printf(". ");
	Sleep(300);	printf(".   ");
	Sleep(800);
	return;
}
