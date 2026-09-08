#include <iostream>
# define lim 10
using namespace std;

class pila{
	public:
		int nf;
		int elementos[lim];
	
	public:
		pila();// constructor
		int top(); // mostrar la cima sin eliminarla
		void push(int p);// introducir elemento
		int pop();// quitar elemento
		bool is_empty();
		bool is_full();
		void MostrarPila();
		void menu();

};

pila::pila(){
int i;	
nf = 0;	
for(i = 0;i<lim;i++){
	elementos[i] = 0;
}
cout<<"pila de limite "<<lim<<" construida con exito !!!"<<endl;
 exit(0);
};

int pila::top(){
if(is_empty() == false){
	cout<<"Top: ["<<elementos[nf-1]<<"]"<<endl;
return elementos[nf-1];
}
};

void pila::push(int p){
if ( is_full() == false){	
	elementos[nf] = p;
	nf ++;
}
return;
}

int pila::pop(){
int r;
if( is_empty() == false){
	r = elementos[nf-1];
	elementos[nf-1] = 0;
	nf = nf-1;
	cout<<"Pop: ["<<r<<"]"<<endl;
	return r;
}
return 0;
}

bool pila::is_empty(){
if (nf == 0){
	cout<<"Pila vacia !!!"<<endl;
	return true;
}
return false;
}

bool pila::is_full(){
if (nf == lim){
	cout<<"Pila llena !!!"<<endl;
	return true;
}
return false;	
}

void pila::MostrarPila(){
int i;
if (is_empty() == false){
	cout<<"Pila: "<<endl;
	for(i=0;i<nf;i++){
		cout<<"p["<<i<<"] = "<<elementos[i]<<endl;
	}
	cout<<endl;
}
return;
}

void pila::menu(){
int opc,dato;
do{
	cout<<":::::::::: P I L A S :::::::::::: LIM ["<<lim<<"]"<<endl;
	cout<<"0. Top"<<endl;
	cout<<"1. push"<<endl;
	cout<<"2. pop"<<endl;
	cout<<"3. vacia?"<<endl;
	cout<<"4. llena?"<<endl;
	cout<<"5. mostrar pila"<<endl;
	cout<<"6. salir"<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 0:
			top();
			break;
		case 1:
			if( is_full() == false){
				cout<<"Push: ";
				cin>>dato;
				push(dato);
			}
			break;
		case 2:
			pop();
			break;
		case 3:
			if( is_empty() == false)
				cout<<"La pila no esta vacia"<<endl;
			break;
		case 4:
			if( is_full() == false)
				cout<<"La pila no esta llena"<<endl;
			break;
		case 5:
			MostrarPila();
			break;
		case 6:
			cout<<"Adios"<<endl;
			break;
		default:
			cout<<"debes escoger entre 0 y 6"<<endl;	
	}
}while(opc != 6);
}

int main(){
pila* p1 = new pila;
p1->menu();
}
