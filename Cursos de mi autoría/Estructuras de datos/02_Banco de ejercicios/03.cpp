// 3. Implementar una función que guarde en una lista el contenido
//de una cola en orden inverso, es decir, el elemento del frente de
//la cola debe ser el último de la lista.
#include <iostream>
# define lim 10
using namespace std;

class cola{
	public:
		int nf;
		int elementos[lim];
	
	public:
		cola();
		void encolar();
		int desencolar();
		int top_sig();
		int top_ultimo_formado();
		bool is_empty();
		bool is_full();
		void MostrarCola();
		void menu();
};

cola::cola(){
int i;
nf = 0;
for(i=0;i<lim;i++){
	elementos[i] = 0;
}
cout<<"Cola de limite "<<lim<<" creada con exito."<<endl;
return;	
};

void cola::encolar(){
int e;
if( is_full() == false){
	cout<<"Elemento a encolar: ";
	cin>>e;
	elementos[nf] = e;
	nf++;
}
return;
};

int cola::desencolar(){
int d,i;
if( is_empty()== false){
	d = elementos[0];
	for(i=0;i<nf;i++){
		elementos[i] = elementos[i+1];
	}
	nf = nf-1;
	cout<<"Des-encolando: cola[0] = "<<d<<endl;
}else{
	return 0;
}
return d;
};

int cola::top_sig(){
if( is_empty() == false){
	cout<<"Siguiente en salir: cola[0] = "<<elementos[0]<<endl;
	return elementos[0];
}
return 0;
};

int cola::top_ultimo_formado(){
if(is_empty() == false){
	cout<<"Ultimpo elemento en integrarse: cola["<<nf-1<<"] = "<<elementos[nf-1]<<endl;
	return elementos[nf-1];	
}
return 0;	
};

bool cola::is_empty(){
if (nf == 0){
	cout<<"Cola vacia !!!"<<endl;
	return true;
}
return false;	
};

bool cola::is_full(){
if (nf == lim){
	cout<<"Cola llena !!!"<<endl;
	return true;
}
return false;	
};

void cola::MostrarCola(){
int i;
if( is_empty() == false){
	for(i=0;i<nf;i++){
		cout<<"elemento ["<<i<<"]: "<<elementos[i]<<endl;
	}
}
return;
};

void cola::menu(){
int opc;
do{
	cout<<"::::: C O L A S ::::::::::::: LIM ["<<lim<<"]"<<endl;
	cout<<"1.Encolar."<<endl;
	cout<<"2.Des-encolar."<<endl;
	cout<<"3.Proximo en salir?"<<endl;
	cout<<"4.Ultimo en entrar?"<<endl;
	cout<<"5.Cola vacia?"<<endl;
	cout<<"6.Cola llena?"<<endl;
	cout<<"7.Mostrar cola."<<endl;
	cout<<"8.Salir."<<endl;
	cout<<"  >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			encolar();
			break;
		case 2:
			desencolar();
			break;
		case 3:
			top_sig();
			break;
		case 4:
			top_ultimo_formado();
			break;
		case 5:
			if( is_empty() == false)
				cout<<"La cola no esta vacia."<<endl;
			break;
		case 6:
			if( is_full() == false)
				cout<<"La cola no esta llena."<<endl;
			break;
		case 7:
			MostrarCola();
			break;
		case 8:
			cout<<"Adios."<<endl;
			break;
		default:
			cout<<"debes escoger entre 1 y 8."<<endl;
	}	
}while(opc != 8);	
return;
};

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

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


/////////////////////////////////////////////////////////////////////////////////////////
//////////////////// F U N C I O N   E S T E L A R //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

int function03(lista *&L1,cola *&c1); // <----- Funcion estelar

int function03(lista *&L1,cola *&c1){ // <----- Funcion estelar
int i;
for(i=0;i<c1->nf;i++){
	L1->insertarInicio(c1->elementos[i]);
}
return 0;
}

int main(){
lista* L1 = new lista;
cola* c1 = new cola;

L1->mostrar();
c1->encolar(); // 2  // frente (ultimo en la lista)
c1->encolar(); // 4
c1->encolar(); // 1
c1->encolar(); // 10
c1->encolar(); // 7  //cola (primero en la lista)
function03(L1,c1);

L1->mostrar();
return 0;
}
