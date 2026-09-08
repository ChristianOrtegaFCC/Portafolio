#include <iostream>
#include <stdio.h>
using namespace std;

// El manejo de excepciones simplemente consiste en la gestión de errores en la
// ejecución, esa es toda la teoría. Para un ejemplo práctico, intentemos dividir
// entre cero:

int main(){
	int x = 10, y = 1, z;

	try{

		// Dentro del bloque try, meteremos el bloque de código que sabemos que
		// puede fallar en algun momento. 


		// En esta línea podemos anticiparnos de manera natural a que va a haber
		// un error, y "lanzar" es error, para atraparlo en su bloque catch
		// correspondiente, 
		if (y == 0) throw "Division entre cero";
		else cout<<"x/y = "<<x<<"/"<<y<<" = "<<x/y<<endl;
		
		// Aquí no podemos controlar que el usuario no meta caracteres invalidos
		// antes de usarlos, así que debemos estar preparados con un catch.
		cout<<"ahora dame un numero: ";
		if ( scanf("%d",&z) == 0 ) throw 100;
		
	// En lugar de permitir que la ejecución se rompa, mantenemos el flujo de la
	// ejecución usando los catch's correspondientes:
	}catch(const char *error){
		cout<<"No puedes dividir entre cero"<<endl;
	}catch(int error2){
		cout<<"Te he pedido un numero, y me diste otra cosa"<<endl;
	}
	
	return 0;
}