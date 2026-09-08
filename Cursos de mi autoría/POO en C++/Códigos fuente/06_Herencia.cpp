#include <iostream>
#include <stdio.h>
using namespace std;

// La herencia consiste en la capacidad de una clase de poder reusar los atributos
// y las instancias ya previamente escritas de una clase. Como padres e hijos.

// Primero definimos una clase base (también conocida como clase madre, clase
// padre, o como quieras, siempre y cuando entiendas la idea)
class Persona {
	public: string nombre;
	public: int edad;
	public: double peso;
	public: string direccion;
	
	public: Persona(string nombre, int edad, double peso ,string direccion) {
		this->nombre = nombre;
		this->edad = edad;
		this->peso = peso;
		this->direccion = direccion;
	}
	
	public: virtual void caminar() {
		cout<<nombre<<" camina..."<<endl;
	}
	
	public: virtual void saltar() {
		cout<<nombre<<" salta..."<<endl;
	}
};

// Los payasos son personas, y como personas, tienen las mismas funciones y
// atributos heredados de una persona... (notemos la sintáxis que define la
// existencia de herencia en esta clase)
class Payaso : public Persona{
	public: bool payaso; // Valor agregado de esta sub_clase
	
	public: Payaso(string nombre, int edad, double peso ,string direccion, bool True) : Persona(nombre,edad,peso,direccion) {
		this->payaso = True;// valor agregado del enano
	}
	
	// Notemos que nos encontramos de nuevo la palabra reservada "override"
	public: void caminar() override {
		cout<<nombre<<" camina... pero chistoso"<<endl;
	}
	
	public: void saltar() override {
		cout<<nombre<<" salta... pero chistoso"<<endl;
	}

	void Chiste() {
        cout <<nombre<< "¿que le dijo un cable a otro cable?" << endl;
    }
};

// en Teoría, C++ debería soportar herencia multiple, pero no siempre funciona bien:
/*
class Payaso_Luchador : public Persona, public Payaso { // Herencia múltiple
public:
    bool luchador;

    Payaso_Luchador(string nombre, int edad, double peso, string direccion, bool True, bool Truex2) 
        : Persona(nombre, edad, peso, direccion), Payaso(nombre, edad, peso, direccion, True) {
        this->luchador = Truex2; // valor agregado de payaso luchador
    }

    void caminar() override {
        cout <<nombre<< " camina, con su trajecito de luchador" << endl;
    }

    void saltar() override {
        cout <<nombre<< " salta y hace una tumba rompecuellos, chistosa..." << endl;
    }

    // Método agregado de luchador
    void Luchar() {
        cout <<nombre<< " lucha." << endl;
    }
};*/

int main(){
	// Mira !!!, al parecer en C++ puedes instanciar de este modo también, y la invocación
	// de los métodos cambia, aunque creo que quizá eso ya lo dije hahahahah.
	
	Persona *P1 = new Persona("Marek",25,76.1,"CD.Paraiso calle Resurreccion #12-04 cp:72320");
	Payaso Payaso1("Francisco",21,45.2,"Clavijero",true);
	//Payaso_Luchador Payaso2("Eduardo",21,50.3,"Santa fe, puebla pue",true,true);
	
	P1->caminar();
	Payaso1.caminar();
	//Payaso2.caminar();
	//Payaso2.saltar();

	

	return 0;
}

