#include <iostream>
#include <stdio.h>
using namespace std;

// El polimorfismo permite que objetos de diferentes clases sean tratados como
// objetos de una clase base común. Y tenemos dos tipos de polimorfismo:

// POLIMORFISMO DE TIEMPO DE COMPILACIÓN (o estático): donde varias funciones
// tienen el mismo nombre pero diferentes parámetros. (sobrecarga)

// POLIMORFISMO DE TIEMPO DE EJECUCIÓN (o dinámico): Se logra a través de la
// herencia y la sobrescritura (override). Esto se usa comúnmente clases abstractas
// e interfaces (veremos interfaces después).

class Persona{
	protected: string nombre;
	protected: int edad;
	
	public: Persona(string nombre, int edad){
		this->nombre = nombre;
		this->edad = edad;
	}
	
	// Podemos usar la palabra: 'virtual' para que sus clases derivadas sobreescriban
	// un método correctamente (override).
	public: virtual void mostrar(){
		cout<<"Nombre: "<<nombre<<endl;
		cout<<"Edad: "<<edad<<endl;
	}
};

class Alumno : public Persona{
	private: float notaFinal;
	
	public: Alumno(string nombre, int edad, float notaFinal) : Persona(nombre, edad){
		this->nombre = nombre;
		this->edad = edad;
		this->notaFinal = notaFinal;
	}
	
	public: void mostrar(){
		Persona::mostrar();
		cout<<"Nota final: "<<notaFinal<<endl<<endl;
	}
};

class Profesor : public Persona{
	private: string materia;
	
	public: Profesor(string nombre, int edad, string materia) : Persona(nombre, edad){
		this->materia = materia;	
	}
	
	public: void mostrar(){
		Persona::mostrar();
		cout<<"Materia: "<<materia<<endl<<endl;
	}
	
};

int main(){
	Persona *personas[3];
	
	// Miren esto, incluso podemos crear una persona que primero sea un alumno (Mapache)...
	personas[0] = new Alumno("Mapache",20,8.99);
	personas[1] = new Profesor("Carmen",50,"Estructuras_de_datos");
	personas[2] = new Persona("Filomeno",30);
	
	
	printf("Dir de personas[0]: %d\n",&personas[0]);
	personas[0]->mostrar();
	personas[1]->mostrar();
	personas[2]->mostrar();
	
	// Y que después 'mute' a profesor:
	printf("\nDir de personas[0]: %d\n",&personas[0]);
	personas[0] = new Profesor("Lic. Mapache",25,"C++");
	personas[0]->mostrar();
	
	return 0;
}

