#include <iostream>
using namespace std;

// El método destructor simplemente elimina una instancia creada. Aunque esto
// se hace automáticamente al finalizar la ejecución, así que no es necesario
// implementarlo manualmente, pero es algo curioso de ver :)

class Perro{
	public:
		string nombre, raza;
		
	public:
		Perro(string,string);
		~Perro();//.................. destructor
		void mostrarDatos();
		void jugar();
};

Perro::Perro(string _nombre, string _raza){
	nombre = _nombre;
	raza = _raza;
}

Perro::~Perro(){//.................. destructor !!!!!
}//................................. (tiene la '~' antes del Nombre de la clase)

void Perro::mostrarDatos(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Raza: "<<raza<<endl;
}

void Perro::jugar(){
	cout<<"El perro "<<nombre<<" esta jugando "<<endl;
}

int main(){
	Perro Hachi("Hachi","Pug");
	
	Hachi.mostrarDatos();
	Hachi.jugar();
	
	Hachi.~Perro();
	cout<<"El perro murio xd"<<endl;
}
