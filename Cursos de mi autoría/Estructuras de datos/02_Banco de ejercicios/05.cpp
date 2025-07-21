// 5. Implementar una función que reciba una Pila y que resguarde
// sus valores pares en una Cola y  los impares en una Pila.
#include <iostream>
# define lim 15
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


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



class cola{
	public:
		int nf;
		int elementos[lim];
	
	public:
		cola();
		void encolar(int e);
		int desencolar();
		int top_sig();
		int top_ultimo_formado();
		bool is_empty();
		bool is_full();
		void MostrarCola();
		void menu();
};

cola::cola(){
int i;
nf = 0;
for(i=0;i<lim;i++){
	elementos[i] = 0;
}
cout<<"Cola de limite "<<lim<<" creada con exito."<<endl;
return;	
};

void cola::encolar(int e){
if( is_full() == false){
	elementos[nf] = e;
	nf++;
}
return;
};

int cola::desencolar(){
int d,i;
if( is_empty()== false){
	d = elementos[0];
	for(i=0;i<nf;i++){
		elementos[i] = elementos[i+1];
	}
	nf = nf-1;
	cout<<"Des-encolando: cola[0] = "<<d<<endl;
}else{
	return 0;
}
return d;
};

int cola::top_sig(){
if( is_empty() == false){
	cout<<"Siguiente en salir: cola[0] = "<<elementos[0]<<endl;
	return elementos[0];
}
return 0;
};

int cola::top_ultimo_formado(){
if(is_empty() == false){
	cout<<"Ultimpo elemento en integrarse: cola["<<nf-1<<"] = "<<elementos[nf-1]<<endl;
	return elementos[nf-1];	
}
return 0;	
};

bool cola::is_empty(){
if (nf == 0){
	cout<<"Cola vacia !!!"<<endl;
	return true;
}
return false;	
};

bool cola::is_full(){
if (nf == lim){
	cout<<"Cola llena !!!"<<endl;
	return true;
}
return false;	
};

void cola::MostrarCola(){
int i;
if( is_empty() == false){
	cout<<"Cola: "<<endl;
	for(i=0;i<nf;i++){
		cout<<"C["<<i<<"]: "<<elementos[i]<<endl;
	}
	cout<<endl;
}
return;
};

void cola::menu(){
int opc,dato;
do{
	cout<<"::::: C O L A S ::::::::::::: LIM ["<<lim<<"]"<<endl;
	cout<<"1.Encolar."<<endl;
	cout<<"2.Des-encolar."<<endl;
	cout<<"3.Proximo en salir?"<<endl;
	cout<<"4.Ultimo en entrar?"<<endl;
	cout<<"5.Cola vacia?"<<endl;
	cout<<"6.Cola llena?"<<endl;
	cout<<"7.Mostrar cola."<<endl;
	cout<<"8.Salir."<<endl;
	cout<<"  >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			if( is_full() == false){
				cout<<"Elemento a encolar: ";
				cin>>dato;
				encolar(dato);
			}
			break;
		case 2:
			desencolar();
			break;
		case 3:
			top_sig();
			break;
		case 4:
			top_ultimo_formado();
			break;
		case 5:
			if( is_empty() == false)
				cout<<"La cola no esta vacia."<<endl;
			break;
		case 6:
			if( is_full() == false)
				cout<<"La cola no esta llena."<<endl;
			break;
		case 7:
			MostrarCola();
			break;
		case 8:
			cout<<"Adios."<<endl;
			break;
		default:
			cout<<"debes escoger entre 1 y 8."<<endl;
	}	
}while(opc != 8);	
return;
};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void function04(pila *&p1);// funcion estelar

void function04(pila *&p1){// funcion estelar
int i;
cola* c1 = new cola;
pila* p2 = new pila;
c1->MostrarCola();
p2->MostrarPila();

for(i=0;i<p1->nf;i++){
	if(p1->elementos[i]%2 == 0){
		c1->encolar(p1->elementos[i]);
	}else{
		p2->push(p1->elementos[i]);
	}
}

c1->MostrarCola();
p2->MostrarPila();
return;
}


int main(){
int i,n=13;
pila* p1 = new pila;
for(i=0;i<n;i++){
	p1->push(i);
}
function04(p1);
return 0;
}
