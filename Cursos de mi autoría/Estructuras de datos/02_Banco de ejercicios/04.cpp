// 4. Implementar un procedimiento que guarde
// en una cola dinámica el contenido de una pila 
// dinámica.
#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};
		
class pilaDinamica{
	public:
		nodo *PD;
	
	public:
		pilaDinamica();// constructor
		int top(); // mostrar la cima sin eliminarla
		void push(int n);// introducir elemento
		int pop();// quitar elemento
		bool is_empty();
		void MostrarPila();
		void menu();

};

pilaDinamica::pilaDinamica(){
	PD = NULL;
return;
}

int pilaDinamica::top(){
int top = 0;
	if(is_empty() == false){
		top = PD->dato;
		nodo *aux_top;
		aux_top = PD;
		
		while(aux_top->sig != NULL) {
			aux_top = aux_top->sig;
			top = aux_top->dato;
		}
		
		cout<<endl<<"top: "<<top<<endl;
	}
return top;	
return 0;
}

int pilaDinamica::pop(){
int pop = 0;
	if(is_empty() == false){
		pop = PD->dato;
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = PD;
		
		while(aux_borrar->sig != NULL) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
			pop = aux_borrar->dato;
		}
		
		anterior->sig = NULL;
		
		cout<<endl<<"dato a borrar: "<<pop<<endl;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;
	}
return pop;	
}

void pilaDinamica::push(int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	
	nodo *aux1 = PD;
	nodo *aux2;
	
	while(aux1 != NULL){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	
	if(PD == aux1){
		PD = nuevo_nodo;
	}else{
		aux2->sig = nuevo_nodo;
	}
	
	nuevo_nodo->sig = aux1;
return;
}

bool pilaDinamica::is_empty(){
if (PD == NULL){
	cout<<endl<<"La pila esta vacia."<<endl;
	return true;
}
return false;	
}

void pilaDinamica::MostrarPila(){
int i = 1;
if(is_empty() == false){
	nodo *auxrec;
	auxrec = PD;
	cout<<endl<<"PILA: ========"<<endl;	
	while(auxrec != NULL){
		cout<<"P["<<i<<"]: "<<auxrec->dato<<endl;
		auxrec = auxrec->sig;
		i++;
	}
}
return;
}

void pilaDinamica::menu(){
int opc,dato;
do{
	cout<<endl<<":::: P I L A   D I N A M I C A ::::::"<<endl;
	cout<<"0. Top"<<endl;
	cout<<"1. push"<<endl;
	cout<<"2. pop"<<endl;
	cout<<"3. vacia?"<<endl;
	cout<<"4. mostrar pila"<<endl;
	cout<<"5. salir"<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 0:
			top();
			break;
		case 1:
			cout<<endl<<"Elemento a agregar: ";
			cin>>dato;
			push(dato);
			break;
		case 2:
			pop();
			break;
		case 3:
			if( is_empty() == false)
				cout<<endl<<"La pila no esta vacia"<<endl;
			break;
		case 4:
			MostrarPila();
			break;
		case 5:
			cout<<endl<<"Adios"<<endl;
			break;
		default:
			cout<<"debes escoger entre 0 y 5"<<endl;	
	}
}while(opc != 5);
return;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

class colaDinamica{
	public:
		struct nodo{
			int dato;
			nodo *sig;
		};
		nodo *CD;
	
	public:
		colaDinamica();// constructor
		int bottom();
		int top(); // mostrar la cima sin eliminarla
		void push(int n);// introducir elemento
		int pop();// quitar elemento
		bool is_empty();
		void MostrarCola();
		void menu();

};
colaDinamica::colaDinamica(){
	CD = NULL;
return;
}

int colaDinamica::bottom(){
int bottom= 0;
if(is_empty() == false){
	nodo *aux_bottom;
	aux_bottom = CD;
	
	bottom = aux_bottom->dato;
	cout<<endl<<"bottom: "<<bottom<<endl;
}
return bottom;
}

int colaDinamica::top(){
int top = 0;
	if(is_empty() == false){
		top = CD->dato;
		nodo *aux_top;
		aux_top = CD;
		
		while(aux_top->sig != NULL) {
			aux_top = aux_top->sig;
			top = aux_top->dato;
		}
		
		cout<<endl<<"top: "<<top<<endl;
	}
return top;	
return 0;
}

int colaDinamica::pop(){
int pop = 0;
	if(is_empty() == false){
		nodo *aux_borrar;
		aux_borrar = CD;
		
		pop = aux_borrar->dato;
		cout<<endl<<"dato a borrar: "<<pop<<endl;
		CD = CD->sig;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;
	}
return pop;	
}

void colaDinamica::push(int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	
	nodo *aux1 = CD;
	nodo *aux2;
	
	while(aux1 != NULL){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	
	if(CD == aux1){
		CD = nuevo_nodo;
	}else{
		aux2->sig = nuevo_nodo;
	}
	
	nuevo_nodo->sig = aux1;
return;
}

bool colaDinamica::is_empty(){
if (CD == NULL){
	cout<<endl<<"La cola esta vacia."<<endl;
	return true;
}
return false;	
}

void colaDinamica::MostrarCola(){
int i = 1;
if(is_empty() == false){
	nodo *auxrec;
	auxrec = CD;
	cout<<endl<<"COLA: ========"<<endl;	
	while(auxrec != NULL){
		cout<<"C["<<i<<"]: "<<auxrec->dato<<endl;
		auxrec = auxrec->sig;
		i++;
	}
}
return;
}

void colaDinamica::menu(){
int opc,dato;
do{
	cout<<endl<<":::: C O L A   D I N A M I C A ::::::"<<endl;
	cout<<"1. bottom"<<endl;
	cout<<"2. Top"<<endl;
	cout<<"3. push"<<endl;
	cout<<"4. pop"<<endl;
	cout<<"5. vacia?"<<endl;
	cout<<"6. mostrar cola"<<endl;
	cout<<"7. salir"<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			bottom();
			break;
		case 2:
			top();
			break;
		case 3:
			cout<<endl<<"Elemento a agregar: ";
			cin>>dato;
			push(dato);
			break;
		case 4:
			pop();
			break;
		case 5:
			if( is_empty() == false)
				cout<<endl<<"La cola no esta vacia"<<endl;
			break;
		case 6:
			MostrarCola();
			break;
		case 7:
			cout<<endl<<"Adios"<<endl;
			break;
		default:
			cout<<"debes escoger entre 0 y 5"<<endl;	
	}
}while(opc != 7);
return;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void function04(colaDinamica *&c1, pilaDinamica *&p1);// funcion estelar

void function04(colaDinamica *&c1, pilaDinamica *&p1){// funcion estelar
nodo *aux_top;
aux_top = p1->PD;
while(aux_top->sig != NULL){
	c1->push(aux_top->dato);
	aux_top = aux_top->sig ;
}
return;
}

int main(){
int i,n=15;
colaDinamica* c1 = new colaDinamica;
pilaDinamica* p1 = new pilaDinamica;
c1->MostrarCola();
for(i=0;i<n;i++){
	p1->push(i*10);
}
function04(c1,p1);
c1->MostrarCola();
return 0;
}
