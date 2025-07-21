// 10. Implemente un método en una lista simplemente
// ligada que reciba como parámetros una pila. El método
// modificará la lista, eliminando las posiciones indicadas
// por la pila.
#include <iostream>
#define lim 15
using namespace std;

struct nodo{
	int dato;
	nodo *sig;	
};

class lista{
	public:
		nodo *L;
	
	public:
		lista();
		void insertarInicio(int n);
		void insertarFinal(int n);
		int borrarinicio();
		int borrarFinal();
		bool is_empty();
		void mostrar();
		int top();
		void menu();
};

lista::lista(){
	L = NULL;	
}

void lista::insertarInicio(int n){
cout<<endl<<"Insertando "<<n<<" al inicio..."<<endl;
nodo *nuevo_nodo = new nodo();
nuevo_nodo->dato = n;
nuevo_nodo->sig = L;
L = nuevo_nodo;
return ;
}

void lista::insertarFinal(int n){
if(is_empty() == true){
	insertarInicio(n);	
}else{
	cout<<endl<<"Insertando "<<n<<" al final..."<<endl;
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nodo *aux1 = L;
	nodo *aux2;
	while(aux1 != NULL){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	aux2->sig = nuevo_nodo;	
	nuevo_nodo->sig = aux1;
}
return ;
}

int lista::borrarinicio(){
int b = 0;
	if(is_empty() == false){
		cout<<endl<<"Borrar al inicio.";
		nodo *aux_borrar;
		aux_borrar = L;
		b = aux_borrar->dato;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		L = L->sig;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;
	}
return b;
}

int lista::borrarFinal(){
int b = 0;
if(is_empty() == false){
	cout<<endl<<"Borrar al final. ";
	if(L->sig == NULL){
		cout<<"La lista solo tiene un elemento."<<endl;
		b = borrarinicio();
	}else{
		b = L->dato;
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = L;
		while(aux_borrar->sig != NULL) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
			b = aux_borrar->dato;
		}
		anterior->sig = NULL;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;
	}
}
return b;
}

bool lista::is_empty(){
if (L == NULL){
	cout<<endl<<"La Lista esta vacia."<<endl;
	return true;
}
return false;
}

void lista::mostrar(){
int i = 0;
if(is_empty() == false){
	nodo *auxrec;
	auxrec = L;
	cout<<endl<<"LISTA: ========"<<endl;	
	while(auxrec != NULL){
		cout<<"L["<<i<<"]: "<<auxrec->dato<<endl;
		auxrec = auxrec->sig;
		i++;
	}
}
return ;
}

int lista::top(){
int top = 0,i = 1;
	if(is_empty() == false){
		top = L->dato;
		nodo *aux_top;
		aux_top = L;
		
		while(aux_top->sig != NULL) {
			aux_top = aux_top->sig;
			top = aux_top->dato;
			i++;
		}
		
		cout<<endl<<"Top: L["<<i<<"] = "<<top<<endl;
	}
return top;
}

void lista::menu(){
int opc,dato;
do{
	cout<<endl<<":::: T D A   L I S T A ::::::::::"<<endl;
	cout<<"1. insertar al inicio."<<endl;
	cout<<"2. insertar al final."<<endl;
	cout<<"3. eliminar al inicio."<<endl;
	cout<<"4. eliminar al final."<<endl;
	cout<<"5. vacia?"<<endl;
	cout<<"6. mostrar lista."<<endl;
	cout<<"7. top."<<endl;
	cout<<"8. salir"<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			cout<<endl<<"Dato a insertar: ";
			cin>>dato;
			insertarInicio(dato);
			break;
		case 2:
			cout<<endl<<"Dato a insertar: ";
			cin>>dato;
			insertarFinal(dato);
			break;
		case 3:
			borrarinicio();
			break;
		case 4:
			borrarFinal();
			break;
		case 5:
			if (is_empty() == false)
				cout<<endl<<"La lista no esta vacia"<<endl;
			break;
		case 6:
			mostrar();
			break;
		case 7:
			top();
			break;
		case 8:
			cout<<endl<<"Adios"<<endl;
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 8"<<endl;	
	}
}while(opc != 8);
return ;
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

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
//cout<<"pila de limite "<<lim<<" construida con exito !!!"<<endl;

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

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void function10(lista *&L1,pila *&P1);// <---- FUNCIONES ESTELARES
void function10_1(lista *&L1,int n);// <---- FUNCIONES ESTELARES

void function10_1(lista *&L1,int n){// <---- FUNCION ESTELAR
int i=0;
	if(L1->is_empty() == false){
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = L1->L;
		
		//recorrer la lista
		while((aux_borrar != NULL) && (i != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
			i++;
		}
		if(anterior == NULL){
			L1->L = L1->L->sig;
			delete aux_borrar;
		}else{//el elemento esta en la lista pero no es el primero
			anterior->sig = aux_borrar->sig;
			delete aux_borrar;
		}
	}
return;
}

void function10(lista *&L1,pila *&P1){  // <---- FUNCION ESTELAR
int i,j,k,aux,nds=0;
bool band;
nodo *count;
pila *P2 = new pila();// creamos una pila auxiliar  para crear una versión de
for(i=0;i<P1->nf;i++){// la pila que podamos usar para este ejercicio.
	P2->push(P1->elementos[i]);
}

for(j=0;j<P2->nf-1;j++){ // supongamos un ordenamiento por burbuja para ordenar la pila auxiliar
	for(i=0;i<P2->nf-1;i++){
		if(P2->elementos[i] > P2->elementos[i+1]){
			aux = P2->elementos[i];
			P2->elementos[i] = P2->elementos[i+1];
			P2->elementos[i+1] = aux;
		}
	}	
}

count = L1->L;//contamos el numero de nodos que hay en la lista, para salir cuando sea necesario
while(count != NULL){
	nds++;
	count = count->sig;
}

i=0; j=0;
while(i<P2->nf){
	j=i+1;
	if(P2->elementos[i] == P2->elementos[j]){
		for(k=i;k<P2->nf-1;k++){
			P2->elementos[k] = P2->elementos[k+1];
		}
		P2->elementos[P2->nf-1] = 0;
		P2->nf--;
		i=0;
	}
	i++;
}

i=0;
while(i<P2->nf){//eliminamos los numeros negativos y los mayores al numero de nodos
	if((P2->elementos[i] > nds)or(P2->elementos[i] < 0)){
		for(k=i;k<P2->nf-1;k++){
			P2->elementos[k] = P2->elementos[k+1];
		}
		P2->elementos[P2->nf-1] = 0;
		P2->nf--;
		i=0;
	}else{
		i++;
	}
}

cout<<endl<<endl<<"Posiciones a eliminar en la Lista segun la ";
P2->MostrarPila();

// llamamos una función de borrar nodo que borra el nodo según si índice i
// el índice i es como dice el ejercicio, el elemento n de la pila.
for(i=0;i<P2->nf;i++){
	function10_1(L1,P2->elementos[i]);
	for(k=0;k<P2->nf;k++)
		P2->elementos[k] = P2->elementos[k]-1;
}
delete P2;//<---- Borramos la pila auxiliar
return;
}

int main(){
lista* L1 = new lista;
pila* P1 = new pila;

// elementos de la lista
L1->insertarFinal(0);
L1->insertarFinal(10);
L1->insertarFinal(20);
L1->insertarFinal(30);
L1->insertarFinal(40);
L1->insertarFinal(50);
L1->insertarFinal(60);
L1->insertarFinal(70);
L1->insertarFinal(80);

// posiciones a borrar
P1->push(10);
P1->push(10);
P1->push(-2);
P1->push(-2);//<---ignora posiciones negativas
P1->push(1);
P1->push(1); //<---si hay posiciones repetidas las toma en cuenta una sola vez
P1->push(6);
P1->push(8);
P1->push(2);
P1->push(8);
P1->push(10);
P1->push(10);
P1->push(-10);
P1->push(19);
P1->push(19); //<---ignora posiciones que no existen en la lista (mayores al numero de nodos)

cout<<endl<<"Lista original: ";
L1->mostrar();
function10(L1,P1);
cout<<endl<<"Lista con las posiciones indicadas por la pila eliminadas:";
L1->mostrar();
return 0;
}

