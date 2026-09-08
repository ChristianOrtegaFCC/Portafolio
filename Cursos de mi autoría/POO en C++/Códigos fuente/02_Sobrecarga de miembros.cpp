#include <iostream>
using namespace std;

class Fecha{
	private:
		int dia,mes,anio;
	public:
		Fecha(int,int,int);//.......... Constructor 1
		Fecha(long);// C2.............. Constructor 2
		
		// NOTEMOS QUE: Se llaman igual, pero reciben diferentes parámetros, y
		// diferente cantidad, por eso pueden coexistir en la misma clase. Eso
		// los identifica y los hace únicos.
		

		void mostrarFecha();//........ Método 1
		void mostrarFecha(int);//..... Método 2
};



// Aquí tenemos los DOS MÉTODOS Fecha, pero con diferentes
// parámetros y diferentes métodos de trabajar.

Fecha::Fecha(int _dia, int _mes, int _anio){
	anio = _anio;
	mes  = _mes;
	dia  = _dia;
}

Fecha::Fecha(long fecha){
	anio = int(fecha/10000);
	mes = int((fecha-anio*10000)/100);
	dia = int(fecha-anio*10000-mes*100);
}


// Y, los DOS MÉTODOS mostrarFecha, misma lógica:

void Fecha::mostrarFecha(){
	cout<<"La fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::mostrarFecha(int n){
	cout<<"Hace "<<n<<" dias la fecha era: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
	Fecha hoy(10,1,2017);//......... Dia, mes, anio
	Fecha x(20170105);//............ Aniomesdia
	
	
	hoy.mostrarFecha();
	x.mostrarFecha(5);
	
	return 0;
}
