#include <iostream>
using namespace std;

// Los miembros estáticos (atributos y métodos) pertenecen a la clase en sí,
// no a instancias individuales de la clase. Esto significa que hay un solo
// valor o implementación compartida entre todas las instancias.

// Pensemos en el UNIFORME de una escuela, todos los alumnos deben usar el mismo.

class Estudiante_de_primaria {
	public:	int grado;
	public:	string nombre;
	public:	static string uniforme; // ATENCIÓN, En esta clase, el uniforme
									// será un atributo estático.
	
	public:	Estudiante_de_primaria() {
		this->grado = 0;
		this->nombre = "-";
		this->uniforme = "-";
	}
	
	void pasar_lista() {
		cout<<"'Presente'";
		return;
	}

	void modelar_uniforme() {
		cout<<"Me llamo "<<nombre<<", "<<grado<<"to grado, mira mi "<<uniforme<<". Es bonito, ¿No?\n";
		return;
	}
	
	public: static void leer() {// ATENCIÓN, Aquí tenemos un método estático, el
		cout<<"Un alumno lee";//.. chiste de estos es que pueden ser utilizados 
		return;//................. incluso sin instancias creadas.
	}
	
	// Métodos setter...

	public: void setGrado(int grado){
		this->grado = grado;
		return;
	}
	
	public: void setNombre(string nombre){
		this->nombre = nombre;
		return;
	}
	
	public: void setUniforme(string uniforme){
		this->uniforme = uniforme;
		return;
	}
	
	// Métodos getter...

	public: int getGrado(){
		return grado;
	}
	
	public: string getNombre(){	
		return nombre;
	}
	
	public: string getUniforme(){
		return uniforme;
	}	
};

// Sin esta línea, el programa no compilaría correctamente porque el compilador
// no tendría información sobre el miembro estático, es como una constante que
// el compilador necesita saber de antemano.
string Estudiante_de_primaria::uniforme = "-";

int main(){
	const int cupo = 10; int i;
		
    // Instanciamos un array de objetos:
	Estudiante_de_primaria Alumnado[cupo] = Estudiante_de_primaria();
	for(i=0; i<10 ;i++){
		Alumnado[i].setGrado(5);
	}
	
	// Los nombres de los niños, no tienen por qué ser el mismo....
	Alumnado[0].setNombre("Stan");    Alumnado[1].setNombre("Kyle");  Alumnado[2].setNombre("Erik");   Alumnado[3].setNombre("Kenny");  
	Alumnado[4].setNombre("Butters"); Alumnado[5].setNombre("Wendy"); Alumnado[6].setNombre("Token");  Alumnado[7].setNombre("Timmy");  
	Alumnado[8].setNombre("Jimmy");   Alumnado[9].setNombre("Tweek");
	
	// Pero aunque intentemos darle ropa diferente a cada uno.... (a)
	Alumnado[0].setUniforme("Ropa azul");  Alumnado[1].setUniforme("Ropa naranja");  Alumnado[2].setUniforme("Ropa roja");  Alumnado[3].setUniforme("sueter naranja");  
	Alumnado[4].setUniforme("Ropa cyan");  Alumnado[5].setUniforme("Ropa rosa");  Alumnado[6].setUniforme("Ropa morada");  Alumnado[7].setUniforme("silla de ruedas");  
	Alumnado[8].setUniforme("playera amarilla"); Alumnado[9].setUniforme("Ropa cafe");  // <- Last declarate
	
	// (a)...... Si su escuela quiere que usen uniforme, todos deberán seguir esa
	// constante (Con esta única linea, cambiamos el valor de "uniforme" de todos
	// los niños) porque "uniforme" es un atributo estático.
	Estudiante_de_primaria::uniforme = "Pantalon gris, camisa blanca y sueter color verde feo";



	
	// Modelan sus uniformes...
	for(i=0;i<10;i++) Alumnado[i].modelar_uniforme();
	
	// Método estático (notar que no requiere que una instancia lo llame)
	Estudiante_de_primaria::leer();
	return 0;
}


	// Podríamos pensar en crear una clase llamada "Operaciones", que tenga muchos métodos
	// estáticos diseñados para obtener cálculos rápido, sin necesidad de crear instancias
	// de la clase.
