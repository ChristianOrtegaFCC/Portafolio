// christian Amauri Amador Ortega - 201927821

#include <stdio.h>
#include <math.h>

int main(){
	float total,aux,monedas[20],solucion[20];
	int n,i,j,auxint,cantidad[20];
	
	// obtenemos numero de denominaciones
	printf("Total de denominaciones: ");
	scanf("%d",&n);
	printf("ingresa las denominaciones:\n");
	
	// obtenemos denominaciones y cantidades de esas denominaciones
	for(i=0;i<n;i++){
		printf("Denominacion [%d]:  ",i+1);
		scanf("%f",&monedas[i]);
		printf("Cantidad de monedas de %.0f: ",monedas[i]);
		scanf("%d",&cantidad[i]);
		printf("\n");
	}
	
	//ordenar denominaciones (m�todo burbuja)
	for(i=0;i<n-1;i++){
		j=i;
		while(j != n ){
			if(monedas[i] < monedas[j]){
				aux = monedas[i];
				monedas[i] = monedas[j];
				monedas[j] = aux;
				
				auxint = cantidad[i];
				cantidad[i] = cantidad[j];
				cantidad[j] = auxint;
			}else{
				j++;
			}	
		}
	}
	for(i=0;i<n;i++) printf("\nHay %d monedas de: %.2f",cantidad[i],monedas[i]);
	printf("\n\n\nCambio a devolver: ");
	scanf("%f",&total);
	
	//primero verificamos que tengamos cambio suficiente
	aux = 0;
	for(i=0;i<n;i++) aux=aux+(cantidad[i]*monedas[i]);
	if(aux < total){
		printf("\nLo siento, no tenemos para dispensar tanto dinero :(");
		return 0;
	}
	
	// algoritmo voraz
	for(i=0;i<n;i++){
		if (floor(total/monedas[i]) <= cantidad[i]){
			solucion[i] = floor(total/monedas[i]);
			total = fmod(total,monedas[i]);
			cantidad[i] = cantidad[i] - solucion[i];
		}else{
			total = total - ( monedas[i] * cantidad[i] );
			solucion[i]= cantidad[i];
			cantidad[i] = 0;
		}
		if (solucion[i] >= 1 ) printf("+ %.0f de $%.2f\n",solucion[i],monedas[i]);
	}
	
	printf("\n\nFinalmente...\n");
	for(i=0;i<n;i++) printf("Hay %d monedas de: %.2f\n",cantidad[i],monedas[i]);
	
	// Siempre hay espacio para mejoras, en este caso pude haber puesto la t�pica
	// condici�n de volver a solicitar al usuario el valor de una variable en caso
	// de que el numero dado se salga de nuestros par�metros, o excepciones, o X
	// cosa o blablabla, pero en este caso se ver�a feo y a estas alturas se sobre
	// entiende que podemos hacerlo xd, as� que creo que con esto basta :)

return 0;
}

