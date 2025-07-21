#include <iostream>
#include <stdio.h>
using namespace std;

// En términos simples, una interfaz funge como una lista de métodos que una clase
// debe implementar. Es como una lista de requisitos, si una clase implementa una
// interfaz, pero no tiene definidos todos los métodos que pide, hay error.

// La interfaz no te pide que implementes los métodos de un modo específico, sólo
// te lo pide.

// (En Java hay palabra reservada para interfaz, pero en c++ tenemos que declarar
// una clase abstracta)

void spaces();

class Matematica{//................ Definimos la interfaz matemática
	// LISTA DE MÉTODOS A CUMPLIR PARA ESTA INTERFAZ:
	public: virtual void derivar() = 0;
};

class Programacion{//.............. Y la interfaz programación
	public: int anios;
	
	// LISTA DE MÉTODOS A CUMPLIR PARA ESTA INTERFAZ:
	public: virtual void C() = 0;
	public: virtual void CPlusPlus() = 0;
	public: virtual void Java() = 0;
	public: virtual void Python() = 0;
	public: virtual void Ensamblador() = 0;
};

// Un ingeniero en ciencias de la computación, debería implementar ambas
// interfaces.... (notemos la sintáxis para pedirle esto a una clase)
class Ing_en_informatica : public Programacion, Matematica{
	public: string nombre;
	
	public: Ing_en_informatica(int anios, string nombre){
		this->anios = anios;
		this->nombre = nombre;
	}
	
	public: void C(){
		printf("Chequ%cate mis conocimientos en C:\n\n",386);
		printf("#include <stdio.h>\n\n");
		printf("int main(){\n");
		printf("  int i;\n");
		printf("  for(i=1;i<=10;i++){\n");
		printf("    printf(\"Hola mundo :)\\n\");\n");
		printf("  }\n");
		printf("  return 0;\n");
		printf("}\n\n");
	}
	
	public: void CPlusPlus(){
	   printf("Chequ%cate mis conocimientos en C++:\n\n",386);
		cout<<"#include <iostream>\n"<<endl;
		cout<<"int main(){"<<endl;
		cout<<"  for(int i=1;i<=10;i++)"<<endl;
		cout<<"    cout<<\"Hola mundo :)\"<<endl;"<<endl;
	   printf("}// ya soy toda una prominencia en programaci%cn y en optimizaci%cn\n\n",418,418);
		
	}
	
	public: void Java(){
	   printf("Chequ%cate mis conocimientos en Java:\n\n",386);
		cout<<"public class Main(){"<<endl;
		cout<<"  public static void main(String[] args){"<<endl;
		cout<<"    for(int i=1;i<=10;i++)"<<endl;
		cout<<"      System.out.println(\"Hola mundo :)\");"<<endl;
		cout<<"  }// ya soy toda una prominencia en objetos"<<endl;
		cout<<"}"<<endl<<endl;
	}
	
	public: void Python(){
	   printf("Chequ%cate mis conocimientos en Python:\n\n",386);
		cout<<"for i in range(30):        # ya soy toda una prominencia en software development hahahaha"<<endl;
		cout<<"  print(\"Hola mundo :)\""")"<<endl<<endl;
	}
	
	public: void Ensamblador(){
		cout<<".MODEL SMALL"<<endl;
		cout<<".STACK"<<endl;
		cout<<".DATA"<<endl;
		cout<<"CADENA DB 'HOLAMUNDO $'"<<endl;
		cout<<".CODE"<<endl;
		cout<<"MAIN:"<<endl;
		cout<<"  MOV AX,@DATA"<<endl;
		cout<<"  MOV DS,AX"<<endl;
		cout<<"  MOV DX,OFFSET CADENA"<<endl;
		cout<<"  MOV AH,9"<<endl;
	   printf("  INT 21H ;\n");
		cout<<"END MAIN"<<endl<<endl;
	}
	
	public: void derivar(){
		//printf("Ah s%c, y adem%cs tambi%cn s%c derivar, chequ%cate:\n\n",417,416,386,386,386);
		printf("Ah s%c, y tambi%cn soy bueno derivando, chequ%cate:\n\n",417,386,386);
		printf("  %c(x) =  2x%c\n  %c(x)'=  6x%c\n\n",415,252,415,253);	
	}
	
};

int main(){
	// Implementamos todos los requerimientos....
	Ing_en_informatica *I1 = new Ing_en_informatica(3,"Ortega");
	
	I1->C();			spaces();
	I1->CPlusPlus();	spaces();
	I1->Java();			spaces();
	I1->Python();		spaces();
	I1->Ensamblador();	spaces();
	I1->derivar();
	return 0;
}

void spaces(){
	for(int i=1;i<=30;i++) cout<<endl;
}

