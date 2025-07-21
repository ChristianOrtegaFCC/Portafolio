#include <iostream>
using namespace std;

// La programación genérica consiste en escribir código que funcione con diferentes
// tipos de datos utilizando plantillas (templates), permitiendo mayor flexibilidad
// y reutilización. (Este tema ya no es tan propio de POO, pero es una buena extensión)

// Declaración de plantillas para funciones genéricas
template <class T> void mostrarAbs(T numero);
template <class T> void numeroMasUno(T numero);

int main(){// observa detenidamente todo esto y dime qué concluyes
	short int num0 = 1;
	int num1 = -123456789;
	float num2 = -2.71828;
	double num3 = -3.1415926535;
	bool valor = -true; // 'true' equivale a 1, por lo que -true se convierte en -1
	char letra = 'e';
	string letras = "Hola_amigos_como_estan?";
	
	// Llamamos a la función para mostrar el valor absoluto
	mostrarAbs(num0);
	mostrarAbs(num1);
	mostrarAbs(num2);
	mostrarAbs(num3);
	mostrarAbs(valor);
	mostrarAbs(letra); // Incluso funciona para casos un poquito extremos para lo que
					   // fue diseñada, es flexible (aunque tiene sus limites)
	
	cout<<endl;
	
	// Llamamos a la función para sumar uno al número
	numeroMasUno(num0);
	numeroMasUno(num1);
	numeroMasUno(num2);
	numeroMasUno(num3);
	numeroMasUno(valor);
	numeroMasUno(letra);
	return 0;
}

template <class T> void mostrarAbs(T numero){
	if(numero<0) numero = numero * (-1);
	cout<<"El valor absoluto del numero es: "<<numero<<endl;
	
}

template <class T> void numeroMasUno(T numero){
	cout<<"numero + 1 = "<<numero+1<<endl;
}
