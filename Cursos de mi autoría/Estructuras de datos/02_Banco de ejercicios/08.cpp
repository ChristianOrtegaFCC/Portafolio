// 8. Diseñe un método que compare si dos listas son iguales
#include <iostream>
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
//cout<<endl<<"Insertando "<<n<<" al inicio..."<<endl;
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
	//cout<<endl<<"Insertando "<<n<<" al final..."<<endl;
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
		//cout<<endl<<"Borrar al inicio.";
		nodo *aux_borrar;
		aux_borrar = L;
		b = aux_borrar->dato;
		//cout<<endl<<"dato a borrar: "<<b<<endl;
		L = L->sig;
		delete aux_borrar;
		//cout<<"dato borrado..."<<endl;
	}
return b;
}

int lista::borrarFinal(){
int b = 0;
if(is_empty() == false){
//	cout<<endl<<"Borrar al final. ";
	if(L->sig == NULL){
//		cout<<"La lista solo tiene un elemento."<<endl;
		borrarinicio();
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
//		cout<<endl<<"dato a borrar: "<<b<<endl;
		delete aux_borrar;
//		cout<<"dato borrado..."<<endl;
	}
}
return b;
}

bool lista::is_empty(){
if (L == NULL){
//	cout<<endl<<"La Lista esta vacia."<<endl;
	return true;
}
return false;
}

void lista::mostrar(){
int i = 1;
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

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void function08(lista *&L1,lista *&L2); // <---------- FUNCION ESTELAR

void function08(lista *&L1,lista *&L2){ // <---------- FUNCION ESTELAR
int aux1,aux2;
bool band = true;

nodo *auxrec1;
nodo *auxrec2;
auxrec1 = L1->L;
auxrec2 = L2->L;

if((auxrec1 == NULL)or(auxrec2 == NULL)){
	cout<<"una de las listas o ambas estan vacias..."<<endl;
	return;
}

while((auxrec1 != NULL)&&(auxrec2 != NULL)&&(band == true)){
	aux1 = auxrec1->dato;
	aux2 = auxrec2->dato;
	if(aux1 != aux2)
		band = false;
	if(((auxrec1->sig == NULL)&&(auxrec2->sig != NULL))or((auxrec1->sig != NULL)&&(auxrec2->sig == NULL))){
		band = false;
	}
	if(band == false){
		break;
	}
	auxrec1 = auxrec1->sig;
	auxrec2 = auxrec2->sig;
}

if (band == true){
	cout<<"Listas iguales!!!"<<endl;
}else{
	cout<<"Listas diferentes!!!"<<endl;
}
return;
}


int main(){
int i;
lista* L1 = new lista;
lista *L2 = new lista;

for(i=0;i<9;i++){
	L1->insertarFinal(i);
	L2->insertarInicio(i);	
}
L1->mostrar();
L2->mostrar();
cout<<endl<<"CHECK 1:"<<endl;
function08(L1,L2); // en este punto son diferentes

while((L1->is_empty() == false) && (L2->is_empty() == false)){
	L1->borrarFinal();
	L2->borrarFinal();
}
L1->mostrar();
L2->mostrar();
cout<<endl<<"CHECK 2:"<<endl;
function08(L1,L2); // en este punto están vacías

for(i=0;i<9;i++){
	L1->insertarFinal(i);
	L2->insertarFinal(i);	
}
L1->mostrar();
L2->mostrar();
cout<<endl<<"CHECK 3:"<<endl;
function08(L1,L2);  // en este punto son iguales


L2->borrarFinal();
//L2->borrarFinal();
L1->mostrar();
L2->mostrar();
cout<<endl<<"CHECK 4:"<<endl;
function08(L1,L2);  // en este punto a L2 le falta el ultimo nodo


}
