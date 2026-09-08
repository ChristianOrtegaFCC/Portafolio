#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

// Una clase abstracta es una clase que no se puede instanciar directamente.
// Se utiliza como base para otras clases y puede contener métodos abstractos
// (métodos sin implementación) y métodos concretos (con implementación).

enum Colors { BLACK = 0,BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LGREY = 7, DGREY = 8, LBLUE = 9, LGREEN = 10, LCYAN = 11, LRED = 12, LMAGENTA = 13, YELLOW = 14, WHITE = 15 };
void Color(int Background, int Text);

// ESTO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
typedef struct parametros{
	int lados;
	float area;
	float perimetro;
}P;



// Una clase se considera abstracta si contiene al menos un MÉTODO VIRTUAL PURO.
// Un MÉTODO VIRTUAL PURO es un método que se declara en la clase base y se define
// como tal al agregar = 0 al final de su declaración.
class Figura{
	protected: P datos;
	
	public: Figura(int lados, float area, float perimetro){
		this->datos.lados = lados;
		this->datos.area = area;
		this->datos.perimetro = perimetro;
	}
	
	public: virtual void print_data(){
		cout<<"lados: "<<datos.lados<<endl<<"area: "<<datos.area<<endl<<"perimetro: "<<datos.perimetro<<endl<<endl;
	}
	
	// ATENCIÓN !!!  virtual...() = 0; indica que el método es puro,
	// y por tanto que la clase es abstracta
	public: virtual void existir() = 0;
};

class Triangulo : public Figura{
	
	public: Triangulo(int lados, float area, float perimetro) : Figura(lados, area, perimetro){
	}
	
	// Un triangulo existe con tres lados:
	public: void existir(){
		Color(BLACK, LGREEN);
		printf("     A     \n");
		printf("    AAA    \n");
		printf("   AAAAA   \n");
		printf("  AAAAAAA  \n");
		printf(" AAAAAAAAA \n");
		printf("AAAAAAAAAAA\n\n");
		Color(BLACK, WHITE);
	}
};

class Cuadrado : public Figura{
	
	public: Cuadrado(int lados, float area, float perimetro) : Figura(lados, area, perimetro){
	}

	// Un cuadrado existe con cuatro lados:
	public: void existir(){
		Color(BLACK, BLUE );
		printf("[][][][][][]\n");
		printf("[][][][][][]\n");
		printf("[][][][][][]\n");
		printf("[][][][][][]\n");
		printf("[][][][][][]\n");
		printf("[][][][][][]\n\n");
		Color(BLACK, WHITE);
	}
};

class Pentagono : public Figura{
	
	public: Pentagono(int lados, float area, float perimetro) : Figura(lados, area, perimetro){
	}
	
	// Un pentagono con 5 (Qué pentagono tan feo)
	public: void existir(){
		Color(BLACK, RED );
		printf("     /\\    \n");
		printf("   /����\\   \n");
		printf("  /������\\  \n");
		printf("  \\������/  \n");
		printf("   \\����/   \n\n");
		Color(BLACK, WHITE);
	}
};

class Hexagono : public Figura{
	
	public: Hexagono(int lados, float area, float perimetro) : Figura(lados, area, perimetro){
	}
	
	public: void existir(){
		Color(BLACK, BROWN);
		printf("    _____  \n");
		printf("   /�����\\   \n");
		printf("  /�������\\  \n");
		printf(" /���������\\ \n");
		printf(" \\���������/ \n");
		printf("  \\�������/  \n");
		printf("   \\�����/   \n\n");
		Color(BLACK, WHITE);
	}
};

int main(){
	Triangulo *F1 = new Triangulo(3,3.3,3.3);
	Cuadrado *F2 = new Cuadrado(4,4.4,4.4);
	Pentagono *F3 = new Pentagono(5,5.5,5.5);
	Hexagono *F4 = new Hexagono(6,6.6,6.6);
	
	F1->existir();
	F2->existir();
	F3->existir();
	F4->existir();
	
	// Recordemos que la clase abstracta no se puede instanciar directamente
	Figura *Fn = new Figura(2,3.4,5.6);
	
	
	return 0;
}

void Color(int Background, int Text){ HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);int New_Color= Text + (Background * 16);SetConsoleTextAttribute(Console, New_Color);}

