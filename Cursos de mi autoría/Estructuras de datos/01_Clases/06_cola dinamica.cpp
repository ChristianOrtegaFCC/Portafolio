#include <iostream>
using namespace std;

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

int main(){
	colaDinamica* c1 = new colaDinamica;
	c1->menu();
return 0;
}
