#include <iostream>
using namespace std;
# define Cardinalidad_Maxima 10

class Matriz_de_adyacencia{
	public:
		int cardinalidad;
		int M[Cardinalidad_Maxima][Cardinalidad_Maxima];
		
	public:
		Matriz_de_adyacencia();
		void redefinir_matriz();
		void mostrar_matriz_ingresada();
		void mostrar_adyacencias();
		void buscar_adyacencia_particular();
		void menu();
};

Matriz_de_adyacencia::Matriz_de_adyacencia(){
/*
// Datos de muestra rápida, por si quieres hacer pruebas sin tener que llenar manualmente la matriz
cardinalidad=5;
M[0][0]=0;
M[0][1]=1;
M[0][2]=0;
M[0][3]=1;
M[0][4]=1;

M[1][0]=1;
M[1][1]=0;
M[1][2]=1;
M[1][3]=0;
M[1][4]=0;

M[2][0]=0;
M[2][1]=1;
M[2][2]=0;
M[2][3]=1;
M[2][4]=0;

M[3][0]=1;
M[3][1]=0;
M[3][2]=1;
M[3][3]=0;
M[3][4]=1;

M[4][0]=1;
M[4][1]=0;
M[4][2]=0;
M[4][3]=1;
M[4][4]=0;
*/
do{
	cout<<"Cardinalidad de la matriz: ";
	cin>>cardinalidad;
	if((cardinalidad<2)or(cardinalidad>Cardinalidad_Maxima)){
		cout<<"Procura que la cardinalidad no sea mayor a "<<Cardinalidad_Maxima<<" ni menor a 2"<<endl;
	}
}while((cardinalidad<2)or(cardinalidad>Cardinalidad_Maxima));
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		do{
			cout<<"Adyacencia de ("<<i<<","<<j<<") :";
			cin>>M[i][j];
			if((M[i][j] < 0)or(M[i][j]>1)){
				cout<<"Solo puedes escribir 1 o 0"<<endl;
			}
		}while((M[i][j] < 0)or(M[i][j]>1));
	}	
}
return;
}

void Matriz_de_adyacencia::redefinir_matriz(){
do{
	cout<<"Cardinalidad de la matriz: ";
	cin>>cardinalidad;
	if((cardinalidad<2)or(cardinalidad>Cardinalidad_Maxima)){
		cout<<"Procura que la cardinalidad no sea mayor a "<<Cardinalidad_Maxima<<" ni menor a 2"<<endl;
	}
}while((cardinalidad<2)or(cardinalidad>Cardinalidad_Maxima));
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		do{
			cout<<"Adyacencia de ("<<i<<","<<j<<") :";
			cin>>M[i][j];
			if((M[i][j] < 0)or(M[i][j]>1)){
				cout<<"Solo puedes escribir 1 o 0"<<endl;
			}
		}while((M[i][j] < 0)or(M[i][j]>1));
	}	
}	
return;
}

void Matriz_de_adyacencia::mostrar_matriz_ingresada(){
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		cout<<"["<<M[i][j]<<"]" ;	
	}
	cout<<endl;
}	
return;
}

void Matriz_de_adyacencia::mostrar_adyacencias(){
cout<<"   Adyacentes = A"<<endl<<"NO adyacentes = X"<<endl<<endl;
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		if(M[i][j] == 1){
			cout<<"["<<i<<"],["<<j<<"] A"<<endl;
		}else{
			cout<<"["<<i<<"],["<<j<<"] ...X"<<endl;
		}
	}
}	
return;
}

void Matriz_de_adyacencia::buscar_adyacencia_particular(){
int i,j;
do{
	cout<<"Elemento 1: ";
	cin>>i;
	if((i<0)or(i>cardinalidad)){
		cout<<"intenta de nuevo..."<<endl;
	}
}while((i<0)or(i>cardinalidad));
do{
	cout<<"Elemento 2: ";
	cin>>j;
	if((j<0)or(j>cardinalidad)){
		cout<<"intenta de nuevo..."<<endl;
	}
}while((j<0)or(j>cardinalidad));

if(M[i][j] == 1){
	cout<<"["<<i<<"],["<<j<<"] Adyacentes"<<endl;
}else{
	cout<<"["<<i<<"],["<<j<<"] NO Adyacentes"<<endl;
}
return;
}

void Matriz_de_adyacencia::menu(){
int opc,dato;
do{
	cout<<endl<<"::: M A T R I Z   D E   A D Y A C E N C I A S ::::::"<<endl;
	cout<<"1. Ingresar nueva matriz de adyacencias."<<endl;
	cout<<"2. Mostrar Matriz ingresada."<<endl;
	cout<<"3. Mostrar adyacencias."<<endl;
	cout<<"4. Buscar una adyacencia."<<endl;
	cout<<"5. salir."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			redefinir_matriz();
			break;
		case 2:
			mostrar_matriz_ingresada();			
			break;
		case 3:
			mostrar_adyacencias();
			break;
		case 4:
			buscar_adyacencia_particular();
			break;
		case 5:
			cout<<endl<<"Adios"<<endl;
			break;
		default:
			cout<<endl<<"debes escoger entre 1 y 5"<<endl;	
	}
}while(opc != 5);
return;
}

int main(){
Matriz_de_adyacencia *M1 = new Matriz_de_adyacencia;
M1->menu();
return 0;
}
