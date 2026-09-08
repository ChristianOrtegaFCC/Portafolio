#include <iostream>
using namespace std;

class listaCircular{
	public:
		struct nodo{
			int dato;
			nodo *sig;
		};
		nodo *L;
		nodo *Lf;
	
	public:
		listaCircular();
		void insertarInicio(int n);
		void insertarFinal(int n);
		int borrarinicio();
		int borrarFinal();
		bool is_empty();
		void mostrar();
		void mostrarEnLoop();
		int top();
		void menu();
};

listaCircular::listaCircular(){
	L = NULL;
	Lf = NULL;	
}

void listaCircular::insertarInicio(int n){
cout<<endl<<"Insertando "<<n<<" al inicio..."<<endl;
nodo *nuevo_nodo = new nodo();
nodo *rec = new nodo;
nuevo_nodo->dato = n;
nuevo_nodo->sig = L;
L = nuevo_nodo;
if(L->sig == NULL) Lf = L;
else if(L->sig == Lf) Lf = L->sig;	
Lf->sig = L;
return ;
}

void listaCircular::insertarFinal(int n){
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
		if(aux1 == Lf){
			aux1->sig = nuevo_nodo;
			Lf = nuevo_nodo;
			Lf->sig = L;
		break;
		}
	}
}
return ;
}

int listaCircular::borrarinicio(){
int b = 0;
	if(is_empty() == false){
		cout<<endl<<"Borrar al inicio.";
		nodo *aux_borrar;
		aux_borrar = L;
		b = aux_borrar->dato;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		if(Lf == L){
			L = NULL;
			Lf = NULL;
			cout<<"dato borrado..."<<endl;
			return b;
		}
		L = L->sig;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;	
	}
return b;
}

int listaCircular::borrarFinal(){
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
		if(Lf == L){
			cout<<endl<<"dato a borrar: "<<b<<endl;
			L = NULL;
			Lf = NULL;
			cout<<"dato borrado..."<<endl;
			return b;
		}
		while(aux_borrar->sig != NULL) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
			b = aux_borrar->dato;
			if(aux_borrar == Lf) break;
		}
		anterior->sig = L;
		Lf = anterior;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;
	}
}
return b;
}

bool listaCircular::is_empty(){
if (L == NULL){
	cout<<endl<<"La Lista esta vacia."<<endl;
	return true;
}
return false;
}

void listaCircular::mostrar(){
int i = 1;
if(is_empty() == false){
	nodo *auxrec;
	nodo *ant = NULL;
	auxrec = L;
	cout<<endl<<"LISTA: ==============="<<endl;	
	while(auxrec != NULL){
		if(Lf == L){
			cout<<"L["<<i<<"]: "<<auxrec->dato<<" <---- Primer y ultimo elemento."<<endl;
			return;
		}else{
			if((ant == NULL) or (ant == Lf)) cout<<"L["<<i<<"]: "<<auxrec->dato<<" <---- Primer elemento."<<endl;
			else if(auxrec == Lf){
				cout<<"L["<<i<<"]: "<<auxrec->dato<<" <---- Ultimo elemento."<<endl;
				break;	
			}else{
				cout<<"L["<<i<<"]: "<<auxrec->dato<<endl;
			}
			ant = auxrec;
			auxrec = auxrec->sig;
			i++;
		}
	}
}
return ;
}

void listaCircular::mostrarEnLoop(){
int i = 1,j=0;
if(is_empty() == false){
	nodo *auxrec;
	nodo *ant = NULL;
	auxrec = L;
	cout<<endl<<"LISTA (en loop): ==============="<<endl;	
	while(j<50){
		if(Lf == L){
			cout<<"L["<<i<<"]: "<<auxrec->dato<<" <---- Primer y ultimo elemento."<<endl;
			cout<<"(esta vaina esta en loop pero no se nota mucho porque es un solo elemento)"<<endl;
			return;
		}else{
			if((ant == NULL) or (ant == Lf)) cout<<"L["<<i<<"]: "<<auxrec->dato<<" <---- Primer elemento."<<endl;
			else if(auxrec == Lf){
				cout<<"L["<<i<<"]: "<<auxrec->dato<<" <---- Ultimo elemento."<<endl;
				i=0;	
			}else{
				cout<<"L["<<i<<"]: "<<auxrec->dato<<endl;
			}
			ant = auxrec;
			auxrec = auxrec->sig;
			i++;
		}
		j++;
	}
	cout<<"Podriamos seguir asi todo el dia pero ya se entendio que esta vaina al estar en loop"<<endl;
	cout<<"es una lista circular (el resto de la evidencia de eso es el codigo)."<<endl;
}
}

int listaCircular::top(){
int top = 0,i = 1;
	if(is_empty() == false){
		top = L->dato;
		nodo *aux_top;
		aux_top = L;
		
		while(aux_top->sig != NULL) {
			aux_top = aux_top->sig;
			top = aux_top->dato;
			i++;
			if(aux_top == Lf){
				break;
			}
		}
		
		cout<<endl<<"Top: L["<<i<<"] = "<<top<<endl;
	}
return top;
}

void listaCircular::menu(){
int opc,dato;
do{
	cout<<endl<<"같같 T D A   L I S T A   C I R C U L A R 같같같같같"<<endl;
	cout<<"1. insertar al inicio."<<endl;
	cout<<"2. insertar al final."<<endl;
	cout<<"3. eliminar al inicio."<<endl;
	cout<<"4. eliminar al final."<<endl;
	cout<<"5. vacia?"<<endl;
	cout<<"6. mostrar lista."<<endl;
	cout<<"7. top."<<endl;
	cout<<"8. mostrar en loop."<<endl;
	cout<<"9. salir"<<endl;
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
			mostrarEnLoop();
			break;
		case 9:
			cout<<endl<<"Adios"<<endl;
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 9"<<endl;	
	}
}while(opc != 9);
return ;
}

int main(){
listaCircular* L1 = new listaCircular;
// Datos muestrales
L1->insertarInicio(500000);
L1->insertarInicio(40000);
L1->insertarInicio(3000);
L1->insertarInicio(200);
L1->insertarInicio(10);
L1->insertarInicio(0);
//*/
L1->menu();
return 0;
}
