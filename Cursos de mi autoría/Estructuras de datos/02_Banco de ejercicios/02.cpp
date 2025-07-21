// 2. Escriba la especificación lógica del TDA CRONOMETRO para cronometrar, valga la redundancia, 
// el tiempo que tarda un usuario en realizar una tarea cualquiera. El CRONOMETRO deberá tener 
// una función de arranque(), una función de paro(), una función de ReArranque(), una función de 
//inicio() y una función de muestra(). El CRONOMETRO deberá trabajar el formato hh:mm:ss para 
// cronometrar el tiempo
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class cronometro{
	public:
		int h;
		int m;
		int s;
		bool run;
		
	public:
		cronometro();
		void arranque();
		void paro();
		void ReArranque();
		void inicio();
		void muestra();
		void menu();	
};

cronometro::cronometro(){
h=0;
m=0;
s=0;
run = false;
return;
}

void cronometro::arranque(){
run = true;
return;
}

void cronometro::paro(){
run = false;
muestra();
return;
}

void cronometro::ReArranque(){
run = true;
return;
}

void cronometro::inicio(){
run = true;
while(1 and run == true){
	muestra();
	s++;
	if(s==60){
		s=0;
		m++;
		if(m==60){
			m=0;
			h++;
		}
	}
	Sleep(1000);
	system("cls");
}
return;
}

void cronometro::muestra(){
cout<<h<<":"<<m<<":"<<s<<endl;
return;
}

void cronometro::menu(){
int opc;
do{
	cout<<endl<<":::: T D A   C R O N O M E T R O ::::::::::"<<endl;
	cout<<"1. Arranque."<<endl;
	cout<<"2. Paro."<<endl;
	cout<<"3. Rearranque."<<endl;
	cout<<"4. Inicio."<<endl;
	cout<<"5. salir"<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			arranque();
			break;
		case 2:
			paro();
			break;
		case 3:
			ReArranque();
			break;
		case 4:
			inicio();
			break;
		case 5:
			cout<<endl<<"Adios"<<endl;
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 8"<<endl;	
	}
}while(opc != 5);
return;
}


int main(){
cronometro *c1 = new cronometro;
c1->menu();
return 0;
}
