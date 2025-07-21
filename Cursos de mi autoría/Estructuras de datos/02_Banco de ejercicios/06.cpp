//6. Implementar un procedimiento que una dos listas circulares.

#include <iostream>
using namespace std;

struct nodo{
	int dato;
	bool inicio;
	bool final;
	nodo *sig;	
};

class listaCircular{
	public:
		nodo *L;
		
		
	public:
		listaCircular();
		void insertarInicio(int n);
		void insertarFinal(int n);
		int borrarinicio();
		int borrarFinal();
		bool is_empty();
		void mostrar();
		int top();
		void menu();
		void mostrarenloop();
};

listaCircular::listaCircular(){
	L = NULL;
}

void listaCircular::insertarInicio(int n){
cout<<endl<<"Insertando "<<n<<" al inicio..."<<endl;
nodo *nuevo_nodo = new nodo();
nuevo_nodo->dato = n;
nuevo_nodo->sig = L;
if(is_empty() == true){// se esta agregando el primer nodo
	nuevo_nodo->final=true;
}else{
	nuevo_nodo->final=false;// se esta agregando el segundo nodo
	if((L->final == true)&&(L->inicio == true)){
		L->final=true;
		L->sig = L;
	}
}
nuevo_nodo->inicio = true;
L = nuevo_nodo;
// una vez agregado el nodo...
if(((L->final == true)&&(L->inicio == true)) == false){// si hay m�s de un nodo
	nodo *rec;
	rec = L;
	while(rec->final == false){
		rec = rec->sig;
	}
	rec->sig = L;
	
	L->sig->inicio = false; // esto es lo que teniamos desde un inicio
}else{// si solo hay un nodo
	L->sig = L;
}
return ;
}

void listaCircular::insertarFinal(int n){
bool ready_for_insert,insert;
ready_for_insert=false;
insert=false;
if(is_empty() == true){
	insertarInicio(n);	
}else{
	cout<<endl<<"Insertando "<<n<<" al final..."<<endl;
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->final= true;
	nodo *aux1 = L;
	nodo *aux2;
	if((L->inicio == true)&&(L->final == true)){
		L->sig = nuevo_nodo;
		nuevo_nodo->sig = L;
		L->final = false;
		return;
	}
	if(L->sig->final == true){
		L->sig->final = false;
		L->sig->sig = nuevo_nodo;
		nuevo_nodo->sig = L;
		return;
	}
	while(insert == false){
		if(ready_for_insert == true){
			insert = true;
		}
		aux2 = aux1;
		aux2->final = false;
		aux1 = aux1->sig;
		if(aux1->final == true){
			ready_for_insert = true;
		}
	}
	aux2->sig = nuevo_nodo;
	nuevo_nodo->sig = L;
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
		if((L->inicio == true)&&(L->final == true)){
			L=NULL;
			return b;
		}else{
			L = L->sig;
			L->inicio=true;
			delete aux_borrar;
			cout<<"dato borrado..."<<endl;
		}
		nodo *rec;
		rec = L;
		while(rec->final == false){
			rec = rec->sig;
		}
		rec->sig = L;
	}
return b;
}

int listaCircular::borrarFinal(){
int b = 0;
bool ready_for_delete = false;
if(is_empty() == false){
	cout<<endl<<"Borrar al final. ";
	if(L->final == true){
		cout<<"La lista solo tiene un elemento."<<endl;
		b = borrarinicio();
	}else{
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = L;
		if(L->sig->final == true){
			b = L->sig->dato;
			aux_borrar = L->sig;
			delete aux_borrar;
			L->final = true;
			L->sig = L;
			return b;
		}else{
			while(ready_for_delete == false) {
				if(aux_borrar->final == true){
					ready_for_delete = true;
				}else{
					anterior = aux_borrar;
					aux_borrar = aux_borrar->sig;
					b = aux_borrar->dato;
				}
			}
		}
			anterior->sig = L;
			anterior->final= true;
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
int i = 0;
bool mostrar_ultimo = false;
if(is_empty() == false){
	nodo *auxrec;
	auxrec = L;
	cout<<endl<<"LISTA: ========"<<endl;	
	while(mostrar_ultimo == false){
		cout<<"L["<<i<<"]: "<<auxrec->dato;
		if((auxrec->final == true)&&(auxrec->inicio == true)){
			cout<<" <--- Elemento inicial y final"<<endl;
		}else{
			if(auxrec->inicio == true)
				cout<<" <--- Elemento inicial";
			if(auxrec->final == true)
				cout<<" <--- Elemento final"<<endl;	
		}
		if(auxrec->final == true){
			mostrar_ultimo = true;
		}
		cout<<endl;
		auxrec = auxrec->sig;
		i++;
	}
}
return ;
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
			if(aux_top->final == true){
				break;
			}
		}
		cout<<endl<<"Top: L["<<i<<"] = "<<top<<endl;
	}
return top;
}

void listaCircular::mostrarenloop(){
int i = 0,j=0;
bool mostrar_ultimo = false;
if(is_empty() == false){
	nodo *auxrec;
	auxrec = L;
	cout<<endl<<"LISTA (impresa en loop): ========"<<endl;	
	while(j<=55){
		cout<<"L["<<i<<"]: "<<auxrec->dato;
		if((auxrec->final == true)&&(auxrec->inicio == true)){
			cout<<" <--- Elemento inicial y final"<<endl;
		}else{
			if(auxrec->inicio == true)
				cout<<" <--- Elemento inicial";
			if(auxrec->final == true){
				cout<<" <--- Elemento final";
				mostrar_ultimo = false;
				i=-1;	
			}
		}
		if(auxrec->final == true){
			mostrar_ultimo = true;
		}
		cout<<endl;
		auxrec = auxrec->sig;
		i++;
		j++;
	}
	cout<<"podriamos seguir asi todo el dia pero ya se entendio que este desmadre esta en loop"<<endl;
}
return;
}

void listaCircular::menu(){
int opc,dato;
do{
	cout<<endl<<":::: T D A   L I S T A   C I R C U L A R ::::::::::"<<endl;
	cout<<"1. insertar al inicio."<<endl;
	cout<<"2. insertar al final."<<endl;
	cout<<"3. eliminar al inicio."<<endl;
	cout<<"4. eliminar al final."<<endl;
	cout<<"5. vacia?"<<endl;
	cout<<"6. mostrar lista."<<endl;
	cout<<"7. top."<<endl;
	cout<<"8. salir"<<endl;
	cout<<"9. Mostrar la lista en loop"<<endl;
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
		case 9:
			mostrarenloop();
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 8"<<endl;	
	}
}while(opc != 8);
return ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//6. Implementar un procedimiento que una dos listas circulares.
void function06(listaCircular *&L1,listaCircular *&L2);

void function06(listaCircular *&L1,listaCircular *&L2){
if((L1->is_empty() == true)or(L2->is_empty() == true)){
	cout<<endl<<"Para este procedimiento necesitamos que ambas "<<endl<<"listas tengan al menos un elemento."<<endl;
	return;
}

listaCircular *L3 = new listaCircular;
nodo *rec;
rec = L1->L;
if((L1->L->inicio == true)&&(L1->L->final == true)){
	L3->insertarFinal(L1->L->dato);	
}else{
	while(rec!=NULL){
		L3->insertarFinal(rec->dato);
		rec=rec->sig;
		if(rec->final == true){
			L3->insertarFinal(rec->dato);
			break;
		}
	}	
}
rec = L2->L;
if((L2->L->inicio == true)&&(L2->L->final == true)){
	L3->insertarFinal(L2->L->dato);	
}else{
	while(rec!=NULL){
		L3->insertarFinal(rec->dato);
		rec=rec->sig;
		if(rec->final == true){
			L3->insertarFinal(rec->dato);
			break;
		}
	}
}
cout<<"Lista 1: ";
L1->mostrar();
cout<<"Lista 2: ";
L2->mostrar();
cout<<"Lista 3: ";
L3->mostrar();
L3->mostrarenloop();
}

int main(){
listaCircular *L1 = new listaCircular;
listaCircular *L2 = new listaCircular;

L1->insertarFinal(0);
L1->insertarFinal(1);
L1->insertarFinal(2);
L1->insertarFinal(3);
L1->insertarFinal(4);

L2->insertarFinal(5);
L2->insertarFinal(6);
L2->insertarFinal(7);
L2->insertarFinal(8);
L2->insertarFinal(9);

function06(L1,L2);

return 0;
}
