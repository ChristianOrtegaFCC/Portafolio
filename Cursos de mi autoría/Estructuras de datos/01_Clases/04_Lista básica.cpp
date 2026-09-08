//EN HONOR A TABOADA
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

// prototipos de funciones
void menu();
void insertarLista(nodo *&,int);
void mostrarLista(nodo *);
void buscarLista(nodo *,int);
void eliminarNodo(nodo*&,int);

nodo *lista = NULL;

int main(){
	menu();	
return 0;
}

void menu(){
	int opc,dato;
	
	do{
		cout<<":::: L I S T A :::::::::::::"<<endl;
		cout<<"1. Insertar elementos."<<endl;
		cout<<"2. mostrar los elementos."<<endl;
		cout<<"3. buscar un elemento."<<endl;
		cout<<"4. Eliminar un elemento"<<endl;
		cout<<"5. salir."<<endl;
		cout<<"   >>> ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"dato a insertar: ";
				cin>>dato;
				insertarLista(lista,dato);
				system("pause");
				break;
			case 2:
				mostrarLista(lista);
				system("pause");
				break;
			case 3:
				cout<<"numero a buscar: ";
				cin>>dato;
				buscarLista(lista, dato);
				system("pause");
				break;
			case 4:
				cout<<"Elemento a eliminar: ";
				cin>>dato;
				eliminarNodo(lista,dato);
				system("pause");
				break;
			case 5:
				system("pause");
				break;
			default:
				cout<<"debes escoger entre 1 y 5"<<endl;
				system("pause");
							
		}
		system("cls");
	}while(opc != 5);
}

void insertarLista(nodo *&lista,int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	
	nodo *aux1 = lista;
	nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}else{
		aux2->sig = nuevo_nodo;
	}
	
	nuevo_nodo->sig = aux1;
}

void mostrarLista(nodo *lista){
	nodo *actual = new nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<"->";
		actual = actual->sig;
	}cout<<endl;
	
}

void buscarLista(nodo *lista,int n){
	bool band = false;
	nodo *actual = new nodo();
	actual = lista;
	
	while((actual != NULL)&&(actual->dato <= n)){
		if(actual->dato == n){
			band = true;
		}
		actual = actual->sig;
	}
	
	if(band == true){
		cout<<n<<" pertenece a la lista"<<endl;
	}else{
		cout<<n<<" no pertenece a la lista"<<endl;
	}
}

void eliminarNodo(nodo*&lista,int n){
	// preguntar si la lista no esta vacia
	if(lista != NULL){
		nodo *aux_borrar;
		nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		//recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->dato != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
		}
		
		// el elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"el elemento no ha sido encontrado"<<endl;
		}else { // el primer elemento es el que vamos a borrar
			if(anterior == NULL){
				lista = lista->sig;
				delete aux_borrar;
			}else{//el elemento esta en la lista pero no es el primero
				anterior->sig = aux_borrar->sig;
				delete aux_borrar;
			}
		}		
	}
}
