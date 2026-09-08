#include <iostream> // basada en la circular
using namespace std; //que miedo XD

class listaDoblementeLigadaCircular{
	public:
		struct nodo{
			int dato;
			nodo *sig;
			nodo *ant;
		};
		nodo *L;
		nodo *Lf;
	
	public:
		listaDoblementeLigadaCircular();
		void insertarInicio(int n);
		void insertarFinal(int n);
		int borrarinicio();
		int borrarFinal();
		bool is_empty();
		void mostrar();
		void recorrerUnoaUno();
		void mostrarEnLoop();
		int cuentanodos();
		int top();
		void menu();
};

listaDoblementeLigadaCircular::listaDoblementeLigadaCircular(){
	L = NULL;
	Lf = NULL;	
}

void listaDoblementeLigadaCircular::insertarInicio(int n){
cout<<endl<<"Insertando "<<n<<" al inicio..."<<endl;
nodo *nuevo_nodo = new nodo();
nodo *rec = new nodo;
nuevo_nodo->dato = n;
nuevo_nodo->sig = L;
L = nuevo_nodo;
if(L->sig == NULL) Lf = L;
else{
	L->sig->ant = L;
	if(L->sig == Lf){	
		Lf = L->sig;
	}
}
L->ant = Lf;
Lf->sig = L;
return ;
}

void listaDoblementeLigadaCircular::insertarFinal(int n){
if(is_empty() == true){
	insertarInicio(n);	
}else{
	cout<<endl<<"Insertando "<<n<<" al final..."<<endl;
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nodo *aux1 = L;
	nodo *aux2;
	if(Lf == L){
		Lf=nuevo_nodo;
		L->ant=Lf;
		L->sig=Lf;
		Lf->ant=L;
		Lf->sig=L;
		return;
	}
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
	Lf->ant = aux2->sig;
	L->ant = Lf;
}
return ;
}

int listaDoblementeLigadaCircular::borrarinicio(){
int b = 0;
	if(is_empty() == false){
		cout<<endl<<"Borrar al inicio.";
		nodo *aux_borrar;
		aux_borrar = L;
		b = aux_borrar->dato;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		if(Lf == L){ // unico nodo (vaciar la lista)
			cout<<"(de unico nodo)"<<endl;
			L->ant = NULL;
			L->sig = NULL;
			Lf = NULL;
			L = NULL;
			delete aux_borrar;
			cout<<"dato borrado..."<<endl;
			return b;
		}
		L = L->sig;
		Lf->sig = L;
		L->ant = Lf;
		L->sig->ant = L;
		if(L->sig == L){
			Lf->ant = L;
		}
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;	
	}
return b;
}/////// ////////// //////////7 /////////// //////////

int listaDoblementeLigadaCircular::borrarFinal(){
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
		L->ant = Lf;
		cout<<endl<<"dato a borrar: "<<b<<endl;
		delete aux_borrar;
		cout<<"dato borrado..."<<endl;
	}
}
return b;
}

bool listaDoblementeLigadaCircular::is_empty(){
if (L == NULL){
	cout<<endl<<"La Lista esta vacia."<<endl;
	return true;
}
return false;
}

void listaDoblementeLigadaCircular::mostrar(){
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

void listaDoblementeLigadaCircular::recorrerUnoaUno(){
if(is_empty() != true){
	cout<<endl<<"같같같� Recorrer la lista elemento por elemento 같같같같";
	int i=0;
	char opc = 'q';
	nodo *rec = L;
	bool inicio = true, final = false;
	while(((opc == 'x')or(opc == 'X')) == false){
		cout<<endl<<"같같같같같같같같같같같같같같같같같같같같같같같같같같같같"<<endl;
		if(Lf == L){
			cout<<"L["<<i<<"] = "<<rec->dato<<"   <---- Elemento inicial y final"<<endl<<endl;
		}else{
			if((inicio == false) && (final == false)) cout<<"L["<<i<<"] = "<<rec->dato<<endl<<endl;
			else{
				if(inicio == true) cout<<"L["<<i<<"] = "<<rec->dato<<"   <---- Elemento inicial"<<endl<<endl;
				if(final == true) cout<<"L["<<i<<"] = "<<rec->dato<<"   <---- Elemento final"<<endl<<endl;
			}
		}
		cout<<"Presiona 'a' para ver el elemento anterior."<<endl;
		cout<<"Presiona 's' para ver el elemento siguiente."<<endl;
		cout<<"Presiona 'x' para salir de (recorrido 1a1)."<<endl;
		cout<<"   >>> ";
		cin>>opc;
		inicio = false; final = false;
		if((opc == 's')or(opc == 'S')){ rec=rec->sig;  i++;}
		if((opc == 'a')or(opc == 'A')){ rec=rec->ant;  i--;}
		if((opc == 'x')or(opc == 'X'))	cout<<endl<<"같같같같같같같같 FIN VISUALIZACION 1a1 같같같같같같같같�"<<endl;
		
		if(rec == L){
			i = 0;
			inicio = true;
		}
		
		if(rec == Lf){
			i = cuentanodos();
			final = true;
		}
	}
}
return;
}

void listaDoblementeLigadaCircular::mostrarEnLoop(){
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
	return;
}
return;
}

int listaDoblementeLigadaCircular::top(){
int top = 0,i = 1;
	if(is_empty() == false){
		top = L->dato;
		nodo *aux_top;
		aux_top = L;
		
		if(Lf == L){
			top = Lf->dato;
			cout<<endl<<"Top: L["<<i<<"] = "<<top<<endl;
			return top;
		}
		
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

int listaDoblementeLigadaCircular::cuentanodos(){
int nds = 0;
if(is_empty() == false){
	nodo *auxrec;
	nodo *ant = NULL;
	auxrec = L;
	while(auxrec != NULL){
		if(auxrec == Lf)
			break;	
		auxrec = auxrec->sig;
		nds++;
	}
}
return nds;
}

void listaDoblementeLigadaCircular::menu(){
int opc,dato;
do{
	cout<<endl<<"같같같같같 LISTA DOBLEMENTE LIGADA CIRCULAR 같같같같같같"<<endl;
	cout<<"1. insertar al inicio."<<endl;
	cout<<"2. insertar al final."<<endl;
	cout<<"3. eliminar al inicio."<<endl;
	cout<<"4. eliminar al final."<<endl;
	cout<<"5. vacia?"<<endl;
	cout<<"6. top."<<endl;
	cout<<"7. mostrar lista."<<endl;
	cout<<"8. Mostrar lista elemento por elemento."<<endl;
	cout<<"9. mostrar lista en loop."<<endl;
	cout<<"0. salir."<<endl;
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
			top();
			break;
		case 7:
			mostrar();
			break;
		case 8:
			recorrerUnoaUno();
			break;
		case 9:
			mostrarEnLoop();
			break;
		case 0:
			for(int xd;xd<30;xd++)
				cout<<"."<<endl;
			cout<<"Adios :^)"<<endl;
			break;
		default:
			cout<<endl<<"debes escoger entre 0 y 9"<<endl;	
	}
}while(opc != 0);
return ;
}

int main(){
listaDoblementeLigadaCircular* L1 = new listaDoblementeLigadaCircular;
// Datos muestrales

L1->insertarInicio(500000);
L1->insertarInicio(40000);
L1->insertarInicio(3000);
L1->insertarInicio(200);
L1->insertarInicio(10);
L1->insertarInicio(0);
//
L1->menu();
return 0;
}
