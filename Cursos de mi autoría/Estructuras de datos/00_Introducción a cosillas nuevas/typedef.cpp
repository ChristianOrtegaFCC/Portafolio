#include <iostream>

using namespace std;

typedef struct Puro{ // con typedef podemos agregar un nombre alternativo, por el cual se har� referencia, en este caso, "P"
	float precio;//MXN 
	float peso;// onzas
	int calidad; // del 1 al 10
}P;

struct Tabaco{ // sin typedef, el nombre al que se debe hacer referencia es este mismo, en este caso: "Tabaco"
	string marca;
	float precio;
	int calidad;
};




int main(){
	typedef bool buleano; // typedef tambi�n te permite re nombrar el tipo de variables ya existentes
	buleano valor1 = true;
	typedef double doblexd;
	doblexd valor2 = 2.71;
	typedef string frase;
	frase f1 = "HolaAmigosComoEstan";
	
	cout<<"valor1 = "; if(valor1 == true) cout<<" true\n"; else cout<<" false\n";
	cout<<"valor2 = "<<valor2<<endl;
	cout<<"f1  = "<<f1<<endl<<endl;
	
	P P1;
	Tabaco T1;
	
	P1.calidad = 10;
	P1.peso = 1.1;
	P1.presio = 100.11;
	printf("typedef struct Puro M1{\n");
	printf("  calidad: %d\n",P1.calidad);
	printf("  peso: %.2f\n",P1.peso);
	printf("  precio: %.2f\n",P1.precio);
	printf("}\n\n");
	
	T1.marca = "Malboro";
	T1.calidad = 6;
	T1.presio = 53.50;
	printf("struct Tabaco T1{\n");
	cout<<"  marca: "<<T1.marca<<endl;
	printf("  calidad: %d\n",T1.calidad);
	printf("  precio: %.2f\n",T1.precio);
	printf("}\n\n");
	
	return 0;
}

