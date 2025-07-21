//7. Diseña un método que ante un arreglo como entrada devuelva una lista.
#include <iostream>
using namespace std;

class lista{
	public:
		struct nodo{
			int dato;
			nodo *sig;	
		};
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

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void function07(int array[]);

void function07(int array[]){
int i;
lista* L = new lista;
for(i=0;i<15;i++){
	L->insertarFinal(array[i]);
}	
L->mostrar();
return;
}


int main(){
int i,max =15;
int arr[max];
for(i=0;i<max;i++){
	arr[i] = i+101;
}
for(i=0;i<max;i++){
	cout<<arr[i]<<endl;
}
function07(arr);

return 0;
}
