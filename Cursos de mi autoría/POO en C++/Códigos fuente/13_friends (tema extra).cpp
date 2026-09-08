#include <iostream>
#include <stdio.h>
using namespace std;

//  Las clases amigas permiten que una clase tenga acceso a los miembros privados
//  y protegidos de otra clase.

class Usuario{ 
	private:
		string nombre;
		int IDE;
		int edad;
	
	public:
		Usuario(string nombre, int IDE, int edad) {
			this->nombre = nombre;
			this->IDE = IDE;
			this->edad = edad;	
		}
		
	friend void seguro_medico(const Usuario &U);// [!] Funcion que puede usar mis datos (palabra reservada friend)
	friend class Gotica_bonita;//................. [!] Clase que puede usar mis datos (palabra reservada friend)
	
	void existir() {
		cout<<"Me llamo "<<nombre<<"("<<IDE<<") y tengo "<<edad<<" anios\n";
	}
	

	private://.................................... [!] La clase Gotica_bonita tiene acceso a esto
		void operacion_privada() {
			printf("Realizando operacion privada...\n");
		}
};

void seguro_medico(const Usuario &U){ 
	cout<<"Yo soy el seguro medico de >"<< U.nombre<<"< puedo acceder a tus datos privados:\n";
	cout<<"IDE: "<< U.IDE<<endl;
	cout<<"Edad: "<< U.edad<<endl<<endl;
};

class Gotica_bonita{
	private:
		string nombre;
		string banda_fav;
		int edad;
		
	public: Gotica_bonita(string nombre, string banda_fav, int edad){
		this->nombre = nombre;
		this->banda_fav = banda_fav;
		this->edad = edad;
	}
	
	friend class Guitarrista;// .................. [!] Clase que puede usar mis datos de Gótica
	
	void existir() {
		cout<<"Me llamo "<<nombre<<", "<<" tengo "<<edad<<" anios y soy gotica bonita\n";
	}
	
	// [!] Como amiga de usuario, puede acceder a sus métodos
	void carisma_de_bonita(const Usuario &U){
		cout<<"Yo soy amiga de >"<< U.nombre<<"< tengo acceso a sus datos, mira:\n";
		cout<<"IDE: "<< U.IDE<<endl;
		cout<<"Edad: "<< U.edad<<endl<<endl;
	}
	
};

class Guitarrista{
	private:
		int edad;
		string cancion_favorita;
		
	public: Guitarrista(int edad, string cancion_favorita){
		this->edad = edad;
		this->cancion_favorita = cancion_favorita;
	}
	
	void existir() {
		cout<<"Tengo "<<edad<<" anios y me gusta "<<cancion_favorita<<"\n";
	}
	
	// [!] Como amigo de Gótica, puede acceder a sus métodos
	void encanto_de_guitarrista(const Gotica_bonita &G){
		cout<<"Yo soy amigo de "<< G.nombre<<endl;
		cout<<"Me dijo que le gusta \""<< G.banda_fav<<"\" y que tiene "<<G.edad<<" anios";
	}
	
	
};

int main(){
	Usuario *U1 = new Usuario("Horacio",201923232,21);
	Gotica_bonita *G1 = new Gotica_bonita("TI","Ghost",21);
	Guitarrista *canalla = new Guitarrista(22,"Thriller");
	
	seguro_medico(*U1);//..................... Funcion amiga de usuario......... (El seguro médico tiene acceso a la información de los usuarios)
	G1->carisma_de_bonita(*U1); //............ Clase amiga de usuario........... (Las goticas bonitas tienen acceso a los datos de los usuarios
	canalla->encanto_de_guitarrista(*G1); //.. Clase amiga de Gotica_bonita..... (Los guitarristas tienen acceso a las goticas bonitas)
	
	return 0;
}

