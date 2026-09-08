#include <stdio.h>
using namespace std;

enum constantes{ // b�sicamente, un enum, es un conjunto de constantes, que deben ser de tipo int o bool
	numero_de_manos = 2,// debes poner comas para separar cada elemento
	vidas = true, // true == 1, false == 0
	dias_en_el_anio = 365,
	dias_en_la_semana = 7,
	meses_en_el_anio = 12,
	tres = 3, //phi = 3.1416, // float's, double's o m�s, no se admiten en el enum
	
};


int main(){
	// printf("aver: %d",constantes.vidas); // esta invovaci�n est� mal
	printf("mostrar: %d",numero_de_manos);
	return 0;
}

// realmente no le encuentro una utilidad a esto, pero segurmente la tiene....
