#include <iostream>
using namespace std;

class pilaDinamica{
	public:
		struct nodo{
			int dato;
			nodo *sig;
		};
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

int main(){
	pilaDinamica* p1 = new pilaDinamica;
	p1->menu();
return 0;
}
