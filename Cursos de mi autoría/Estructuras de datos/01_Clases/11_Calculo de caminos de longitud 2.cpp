#include <iostream>
#define Cardinalidad_Maxima 20
using namespace std;

class Matriz_De_Adyacencia{
	public:
		int cardinalidad;
		int M[Cardinalidad_Maxima][Cardinalidad_Maxima];
		int Caminos_2[Cardinalidad_Maxima][Cardinalidad_Maxima];
		
	public:
		Matriz_De_Adyacencia();
		void Hallar_caminos_de_longitud_2();
		void Mostrar_matriz_de_adyacencia();
		void redefinir_Matriz();
		void menu();	
};

Matriz_De_Adyacencia::Matriz_De_Adyacencia(){
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

void Matriz_De_Adyacencia::Hallar_caminos_de_longitud_2(){
// calculamos la matriz de caminos de longitud 2, elevando M al cuadrado
// (por ahora solo la multiplicamos por sí misma una vez y ya)
// no sé si en un futuro haré una versión a la n.
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		Caminos_2[i][j]=0;
		for(int k=0;k<cardinalidad;k++){
			Caminos_2[i][j]= Caminos_2[i][j] + M[i][k]*M[k][j];	
		}
	}
}
cout<<"Matriz de caminos de longitud 2: "<<endl;
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		cout<<"["<<Caminos_2[i][j]<<"] ";
	}
	cout<<endl;
}

return;
}

void Matriz_De_Adyacencia::Mostrar_matriz_de_adyacencia(){
cout<<"Matriz de adyacencia:"<<endl;
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		cout<<"["<<M[i][j]<<"] ";
	}
	cout<<endl;
}	
return;
}

void Matriz_De_Adyacencia::redefinir_Matriz(){
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

void Matriz_De_Adyacencia::menu(){
int opc,dato;
	
do{
	cout<<":::: M A T R I Z   D E   A D Y A C E N C I A :::::::::::::"<<endl;
	cout<<"1. Mostrar matriz de adyacencia ingresada."<<endl;
	cout<<"2. Calcular caminos de longitud 2."<<endl;
	cout<<"3. ingresar nueva matriz de adyacencia."<<endl;
	cout<<"4. salir."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			Mostrar_matriz_de_adyacencia();
			break;
		case 2:
			Hallar_caminos_de_longitud_2();
			break;
		case 3:
			redefinir_Matriz();
			break;
		case 4:
			cout<<"Adios"<<endl;
			break;
		default:
			cout<<"debes escoger entre 1 y 4"<<endl;
	}
}while(opc != 4);
return;
}

int main(){
Matriz_De_Adyacencia *M1 = new Matriz_De_Adyacencia;
M1->menu();
return 0;
}
