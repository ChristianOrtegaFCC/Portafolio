//Christian Amauri Amador Ortega
//EN HONOR A ALEJANDRO TABOADA 
#include <iostream>
using namespace std;

struct subnodo{
	int dato;
	subnodo *sig;
};

struct nodo{
	int dato;
	nodo *sig;
	subnodo *s;
};

class Grafo{
	public:
		nodo *G;
		
	public:
		Grafo();
		void insertarNodo(int n);
		void insertarSubnodo(int n);
		int eliminarNodo();
		int eliminarSubnodo();
		bool is_empty();
		void mostrar();
		int gradoGrafo();
		int gradoAlgunaArista();
		void info();
		void menu();
};

Grafo::Grafo(){
G = NULL;
return;
}

void Grafo::insertarNodo(int n){
nodo *nuevo_nodo = new nodo();
nuevo_nodo->dato = n;
//nuevo_nodo->s = NULL;
if(is_empty()==true){
	nuevo_nodo->sig = G;
	G = nuevo_nodo;
	cout<<"Insertando "<<n<<" al inicio..."<<endl;
}else{
	nodo *aux1 = G;
	nodo *aux2;
	while(aux1 != NULL){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	aux2->sig = nuevo_nodo;	
	nuevo_nodo->sig = aux1;
	cout<<"Insertando "<<n<<" al final..."<<endl;
}	
return;
}

void Grafo::insertarSubnodo(int n){
int primernodo;
subnodo *nuevo_subnodo = new subnodo();
nuevo_subnodo->dato = n;
if(is_empty()==true){
	return;
}else{
	cout<<endl<<"en que nodo quieres insertar el nuevo Sub-nodo? ";
	cin>>primernodo;
		
	nodo *recorre;
	recorre = G;
	while((recorre != NULL) && (recorre->dato != primernodo)){
		recorre = recorre->sig;
	}
	if(recorre == NULL){
		cout<<"el nodo no ha sido encontrado."<<endl;
	}else{
		subnodo *aux1 = new subnodo();
		subnodo *aux2 = new subnodo();
		
		if (recorre->s == NULL){
			cout<<"insertando ["<<n<<"] como primer subnodo de "<<primernodo<<"..."<<endl;
			aux1->dato = n;
			aux1->sig = recorre->s;
			recorre->s = aux1;
			return;
		}
		
		aux1 = recorre->s;
		aux1->dato = recorre->s->dato;
		while(aux1 != NULL){
			cout<<"["<<aux1->dato<<"]->";
			aux2 = aux1;
			aux2->dato = aux1->dato;
			aux1 = aux1->sig;
		}
		aux2->sig = nuevo_subnodo;	
		nuevo_subnodo->sig = aux1;
		cout<<"Insertando "<<n<<" al final de "<<primernodo<<"..."<<endl;
	}
}
return;
}

int Grafo::eliminarNodo(){
int b=0,n;
if(is_empty() == false){
		cout<<endl<<"Que Nodo quieres borrar? ";
		cin>>n;
	
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = G;
		
		//recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->dato != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
			b=aux_borrar->dato;
		}
		
		// el elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"el nodo no ha sido encontrado"<<endl;
		}else { // el primer elemento es el que vamos a borrar
			if(anterior == NULL){
				G = G->sig;
			}else{//el elemento esta en la lista pero no es el primero
				anterior->sig = aux_borrar->sig;
			}
			delete aux_borrar;
		}		
	}
return b;
}

int Grafo::eliminarSubnodo(){
int b=0,n;
if(is_empty() == false){
		cout<<endl<<"en que nodo esta el Sub-nodo que quieres borrar? ";
		cin>>n;
		
		nodo *recorre;
		recorre = G;
		//recorremos los nodos
		while((recorre != NULL) && (recorre->dato != n)){
			recorre = recorre->sig;
		}
		// el nodo no ha sido encontrado
		if(recorre == NULL){
			cout<<"el nodo no ha sido encontrado"<<endl;
		}else {
			cout<<endl<<"Que Sub-nodo quieres borrar? ";
			cin>>n;
			subnodo *auxborrar;
			subnodo *anterior = NULL;
			auxborrar = recorre->s;
			//recorremos los Sub-nodos
			while((auxborrar != NULL) && (auxborrar->dato != n)){
				anterior = auxborrar;
				auxborrar = auxborrar->sig;
			}
			
			// el elemento no ha sido encontrado
			if(auxborrar == NULL){
				cout<<"el Sub-nodo no ha sido encontrado. "<<endl;
			}else { // el primer elemento es el que vamos a borrar
				if(anterior == NULL){
					recorre->s = recorre->s->sig;
				}else{//el elemento esta en la lista pero no es el primero
					anterior->sig = auxborrar->sig;
				}
				delete auxborrar;
			}
		}		
	}	
return b;
}

bool Grafo::is_empty(){
if(G == NULL){
	cout<<"El grafo esta vacio. "<<endl;
	return true;
}
return false;
}

void Grafo::mostrar(){
if(is_empty() == false){
	nodo *auxrec;
	subnodo *subrec;
	auxrec = G;
	cout<<endl<<"GRAFO: ==========="<<endl;	
	while(auxrec != NULL){
		if(auxrec->s != NULL){
			cout<<"("<<auxrec->dato<<")->";
		}else{
			cout<<"("<<auxrec->dato<<") ";
		}
		subrec = auxrec->s;
		while(subrec != NULL){
			if(subrec->sig != NULL){
				cout<<"["<<subrec->dato<<"]->";
			}else{
				cout<<"["<<subrec->dato<<"] ";
			}
			subrec = subrec->sig;
		}
		cout<<endl;
		auxrec = auxrec->sig;
	}
}	
return;
}

int Grafo::gradoGrafo(){
int gg=0,i=0;
if(is_empty() == false){
	nodo *auxrec;
	subnodo *subrec;
	auxrec = G;	
	while(auxrec != NULL){
		subrec = auxrec->s;
		i=0;
		while(subrec != NULL){
			subrec = subrec->sig;
			i++;
			if(i>gg){
				gg=i; 
			}
		}
		auxrec = auxrec->sig;
	}
}
if(gg==0){
	cout<<"Este grafo no tiene grado (o es de grado cero) porque ningun nodo tiene subnodos."<<endl;	
	return 0;
}
cout<<"El nodo con mas subnodos tiene "<<gg<<" subnodos, por lo tanto:"<<endl<<"EL GRADO DEL GRAFO ES "<<gg<<"."<<endl;
return gg;
}

int Grafo::gradoAlgunaArista(){
int ga=0,primernodo;
if(is_empty()==true){
	return 0;
}else{
	cout<<endl<<"De que nodo quieres ver el grado? ";
	cin>>primernodo;
	nodo *recorre;
	recorre = G;
	while((recorre != NULL) && (recorre->dato != primernodo)){
		recorre = recorre->sig;
	}
	if(recorre == NULL){
		cout<<"el nodo no ha sido encontrado."<<endl<<endl;
		return 0;
	}else{
		subnodo *aux1 = new subnodo();
		if (recorre->s == NULL){
			cout<<"Ese nodo no tiene sub-nodos..."<<endl<<endl;
			return 0;
		}
		aux1 = recorre->s;
		while(aux1 != NULL){
			aux1 = aux1->sig;
			ga++;
		}
	}
}
cout<<"el grado del nodo "<<primernodo<<" es: "<<ga<<endl;
return ga;
}

void Grafo::info(){	
cout<<endl<<"같같� INFO 같같같같같같같같같같같같�";
cout<<endl<<"Aqui nodos = vertices y sub-nodos = adyacencias."<<endl;
cout<<"(esa convencion se utilizo solo para facilitar"<<endl;
cout<<"la codificacion y la lectura del codigo jajaj)"<<endl;
cout<<endl<<"La idea de representar una matriz de adyacencias mediante "<<endl;
cout<<"listas ligadas de listas ligadas es no ocupar espacios en"<<endl;
cout<<"ceros que signifiquen una 'NO adyacencia', por lo que cada"<<endl;
cout<<"sub-nodo de cada nodo representa un uno, es decir, cada nodo"<<endl;
cout<<"tiene adyacencia con cada uno de sus sub-nodos."<<endl;
cout<<endl<<"Por ejemplo:"<<endl;
cout<<"(1)-> [10]->[100]"<<endl<<"(2)"<<endl<<"(3)-> [33]"<<endl<<"(10)-> [1]"<<endl;
cout<<"En este caso 1 tiene adyacencias con 10 y 100, 2 no tiene"<<endl;
cout<<"adyacencias, 3 tiene adyacencia con 33. Y 10 es adyacente"<<endl;
cout<<"con 1."<<endl;
cout<<endl<<"Para insertar un sub-nodo (o adyacencia) debes saber desde el"<<endl;
cout<<"inicio en que nodo quieres insertarlo (o para que vertice)."<<endl;
cout<<"Para insertar un nodo no se necesita nada mas que insertarlo pero"<<endl;
cout<<"procura no repetir nodos (no va a pasar nada pero de esa forma"<<endl;
cout<<"no tiene sentido tener un grafo implementado de esta manera."<<endl;
cout<<endl<<"Al menos eso es lo que yo entendi xdxd"<<endl;
return;
}

void Grafo::menu(){
int opc,n;
mostrar();
do{	
	cout<<endl<<":::: G R A F O ::::::::::"<<endl;
	cout<<"1. Insertar nodo."<<endl;
	cout<<"2. Insertar sub-nodo."<<endl;
	cout<<"3. Eliminar nodo."<<endl;
	cout<<"4. Eliminar sub-nodo."<<endl;
	cout<<"5. Grafo vacio?."<<endl;
	cout<<"6. Mostrar grafo."<<endl;
	cout<<"7. Grado del grafo?."<<endl;
	cout<<"8. Grado de uno de los sub-nodos?."<<endl;
	cout<<"9. INFO."<<endl;
	cout<<"0. salir."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			cout<<endl<<"Dame el nuevo nodo: ";
			cin>>n;
			insertarNodo(n);
			break;
		case 2:
			cout<<endl<<"Dame el nuevo Sub-nodo: ";
			cin>>n;
			insertarSubnodo(n);
			break;
		case 3:
			eliminarNodo();
			break;
		case 4:
			eliminarSubnodo();
			break;
		case 5:
			if (is_empty() != true ){
				cout<<"El grafo no esta vacio. "<<endl;
			}
			break;
		case 6:
			mostrar();
			break;
		case 7:
			gradoGrafo();
			break;
		case 8:
			gradoAlgunaArista();
			break;
		case 9:
			info();
			break;
		case 0:
			for(int xd=1;xd<=50;xd++){
				cout<<"."<<endl;
			}
			cout<<"Adios :^)"<<endl;
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 10"<<endl;	
	}
}while(opc != 0);	
return;
}

int main(){
Grafo *G1 = new Grafo();
 //Datos muestrales
G1->insertarNodo(1); G1->insertarNodo(2);
G1->insertarNodo(3); G1->insertarNodo(4);
G1->insertarNodo(5);
cout<<"help: 1,1,2,2,2,3,4,4,4"<<endl;
G1->insertarSubnodo(10); G1->insertarSubnodo(100);
G1->insertarSubnodo(20); G1->insertarSubnodo(200); G1->insertarSubnodo(2000);
G1->insertarSubnodo(30);
G1->insertarSubnodo(40); G1->insertarSubnodo(4000); G1->insertarSubnodo(40000);


G1->menu();
return 0;
}
