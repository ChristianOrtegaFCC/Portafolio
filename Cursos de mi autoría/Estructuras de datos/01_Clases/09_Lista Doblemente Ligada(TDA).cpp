#include <iostream>
using namespace std;

class listaDoblementeLigada{
	public:
		struct nodo{
			int dato;
			nodo *sig;
			nodo *ant;	
		};
		nodo *L;
	
	public:
		listaDoblementeLigada();
		void insertarInicio(int n);
		void insertarFinal(int n);
		int borrarinicio();
		int borrarFinal();
		bool is_empty();
		void mostrar();
		int top();
		void recorrerUnoaUno();
		void menu();
};

listaDoblementeLigada::listaDoblementeLigada(){
	L = NULL;	
}

void listaDoblementeLigada::insertarInicio(int n){
cout<<endl<<"Insertando "<<n<<" al inicio..."<<endl;
nodo *nuevo_nodo = new nodo();
nuevo_nodo->dato = n;
nuevo_nodo->sig = L;
L = nuevo_nodo;
if(L->sig != NULL){
	L->sig->ant = L;
}
return ;
}

void listaDoblementeLigada::insertarFinal(int n){
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
	nuevo_nodo->sig = NULL;
	nuevo_nodo->ant = aux2;
}
return ;
}

int listaDoblementeLigada::borrarinicio(){
int b = 0;
	if(is_empty() == false){
		cout<<endl<<"Borrar al inicio.";
		nodo *aux_borrar;
		aux_borrar = L;
		b = aux_borrar->dato;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		if(L->sig == NULL){
			L = NULL;
			cout<<"dato borrado..."<<endl;
			return b;
		}
		L = L->sig;
		delete aux_borrar;
		if(L->sig == NULL) L->ant = NULL;
		else L->sig->ant = L;
		cout<<"dato borrado..."<<endl;
	}
return b;
}

int listaDoblementeLigada::borrarFinal(){
int b = 0;
if(is_empty() == false){
	cout<<endl<<"Borrar al final. ";
	if(L->sig == NULL){
		cout<<"La lista solo tiene un elemento."<<endl;
		b = borrarinicio();
	}else{
		b = L->dato;
		if(L->sig == NULL){
			cout<<endl<<"dato a borrar: "<<b<<endl;
			L = NULL;
			cout<<"dato borrado..."<<endl;
			return b;
		}
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

bool listaDoblementeLigada::is_empty(){
if (L == NULL){
	cout<<endl<<"La Lista esta vacia."<<endl;
	return true;
}
return false;
}

void listaDoblementeLigada::mostrar(){
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

int listaDoblementeLigada::top(){
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

void listaDoblementeLigada::recorrerUnoaUno(){
if(is_empty() != true){
	cout<<endl<<"°°°°°°° Recorrer la lista elemento por elemento °°°°°°°°";
	int i=0;
	char opc = 'q';
	nodo *rec = L;
	bool hide = false;
	while(((opc == 'x')or(opc == 'X')) == false){
		cout<<endl<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
		if(hide == false)
			cout<<"L["<<i<<"] = "<<rec->dato<<endl<<endl;
		else
			if(rec == L)
				cout<<"No hay nodos anteriores a L["<<i<<"] = "<<rec->dato<<endl<<endl;
			else
				cout<<"No hay nodos siguientes a L["<<i<<"] = "<<rec->dato<<endl<<endl;
		cout<<"Presiona 'a' para ver el elemento anterior."<<endl;
		cout<<"Presiona 's' para ver el elemento siguiente."<<endl;
		cout<<"Presiona 'x' para salir del recorrido 1a1."<<endl;
		cout<<"   >>> ";
		cin>>opc;
		hide = false;
		if((opc == 's')or(opc == 'S')){
			if(rec->sig == NULL) hide = true;
			else{
				rec=rec->sig;
				i++;
			}
		}
		if((opc == 'a')or(opc == 'A')){
			if(rec == L) hide = true;
			else{
				rec=rec->ant;
				i--;
			}
			
		}
		if((opc == 'x')or(opc == 'X'))	cout<<endl<<"°°°°°°°°°°°° FIN VISUALIZACION 1a1 °°°°°°°°°°°°°°°°°°°°°"<<endl;
	}
}
return;
}

void listaDoblementeLigada::menu(){
int opc,dato;
do{
	cout<<endl<<"°°°° L I S T A   D O B L E M E N T E   L I G A D A °°°°°"<<endl;
	cout<<"1. insertar al inicio."<<endl;
	cout<<"2. insertar al final."<<endl;
	cout<<"3. eliminar al inicio."<<endl;
	cout<<"4. eliminar al final."<<endl;
	cout<<"5. vacia?"<<endl;
	cout<<"6. mostrar lista."<<endl;
	cout<<"7. top."<<endl;
	cout<<"8. recorrer lista elemento por elemento."<<endl;
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
			recorrerUnoaUno();
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
listaDoblementeLigada* L1 = new listaDoblementeLigada;
// nodos muestrales
L1->insertarInicio(0);
L1->insertarFinal(1);
L1->insertarFinal(2);
L1->insertarFinal(3);
L1->insertarFinal(4);
L1->insertarFinal(5);

L1->menu();
return 0;
}
