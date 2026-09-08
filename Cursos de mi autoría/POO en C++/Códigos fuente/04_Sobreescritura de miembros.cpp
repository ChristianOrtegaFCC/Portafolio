#include <iostream>
using namespace std;

// La sobreescritura de miembros es la capacidad de una clase derivada ("Hija")
// para proporcionar una implementación específica de un método que ya ha sido
// definido en su clase base, para poder comportarse de manera diferente.



class Animal {
	public: int esperanza_de_vida;
	public: int peso;
	
	public: Animal(int esperanza_de_vida, int peso) {
		this->esperanza_de_vida = esperanza_de_vida;
		this->peso = peso;
	}
	
	public: virtual void comer() {
		printf("Estoy comeindo...\n");
	}
};

class Perro : public Animal{
	// Atributo único en su clase
	public: string raza_perruna;
	
	public: Perro(int esperanza_de_vida, int peso,string raza_perruna) : Animal( esperanza_de_vida,peso){
		this->raza_perruna = raza_perruna;
	}
	
	// Método comer SOBREESCRITO
	public: void comer()override{
		printf("Estoy comiendo con mi plato en el suelo...\n");
	}
};

class Persona : public Animal{
	// Atributo único en su clase
	public: string apellido;
	
	public: Persona(int esperanza_de_vida, int peso, string apellido) : Animal(esperanza_de_vida, peso){
		this->apellido = apellido;
	}

	// Método comer SOBREESCRITO
	public: void comer()override {
		printf("Estoy comiendo con cubiertos...\n");
	}
};

class Vaca : public Animal{
	// En este universo hipotético, las vacas blancas dan leche normal, las
	// vacas café dan de chocolate, las vacas amarillas dan de vainilla, las
	// rosas de fresa y asi....
	public: string sabor_de_leche_que_produce;
	
	public: Vaca(int esperanza_de_vida, int peso,string sabor_de_leche_que_produce) : Animal(esperanza_de_vida,peso){
		this->sabor_de_leche_que_produce = sabor_de_leche_que_produce;
	}
	
	// Sólo las vacas pueden mujir (sin que se vea raro)....
	public: void comer()override{
		printf("Estoy comiendo pasto, muuuuu.\n");
	}
};



int main(){
	Persona amauri(70,70,"Ortega");
	Perro chispa(20,12,"Schnawzer");
	Vaca pili(60,500,"Chocolate");
	
	// Justo aquí, todos estos ANIMALES comen,
	// pero todos lo hacen de manera diferente.
	// (SOBREESCRIBIMOS su comportamiento).
	amauri.comer();
	chispa.comer();
	pili.comer();
}
