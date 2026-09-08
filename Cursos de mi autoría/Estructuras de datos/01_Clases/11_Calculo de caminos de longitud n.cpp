#include <iostream>
#define Cardinalidad_Maxima 20
using namespace std;

class Matriz_De_Adyacencia{
	public:
		int cardinalidad;
		int M[Cardinalidad_Maxima][Cardinalidad_Maxima];
		int Caminos_n[Cardinalidad_Maxima][Cardinalidad_Maxima];
		
	public:
		Matriz_De_Adyacencia();
		void Hallar_caminos_de_longitud_n();
		void Mostrar_matriz_de_adyacencia();
		void redefinir_Matriz();
		void menu();	
};

Matriz_De_Adyacencia::Matriz_De_Adyacencia(){
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

void Matriz_De_Adyacencia::Hallar_caminos_de_longitud_n(){
// primero obtenemos el numero al que se desea elevar la matriz:
int n;
do{
	cout<<"a que numero deseas elevar la matriz?... ";
	cin>>n;
	//verificamos que el usuario no haga mamadas
	if(n<1)
		cout<<"No diga mamadas mi buen"<<endl<<endl;
	if(n==1){
		cout<<"La matriz M elevada a la 1 es la misma matriz, ";
		Matriz_De_Adyacencia::Mostrar_matriz_de_adyacencia();
		cout<<endl;
		return;
	}
	if(n>30){
		cout<<"No creo que eso sea buena idea..."<<endl<<endl;
		return;
	}
}while((n<1)or(n>30));

// tenemos que M^n = (M^(n-1))x(M)...
// entonces primero obtenemos M^2 multiplicando MxM, y el resultado lo guardamos en aux1:
int aux1[Cardinalidad_Maxima][Cardinalidad_Maxima];
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		aux1[i][j]=0;
		for(int k=0;k<cardinalidad;k++){
			aux1[i][j]= aux1[i][j] + M[i][k]*M[k][j];	
		}
	}
}
if(n==2){
	cout<<"Matriz de caminos de longitud "<<n<<": "<<endl;
	for(int i=0;i<cardinalidad;i++){
		for(int j=0;j<cardinalidad;j++){
			cout<<"["<<aux1[i][j]<<"] ";
		}
		cout<<endl;
	}
return;	
}
// ahora para obtener M^n multiplicamos ((aux1=M^2)x(M)) n-1 veces
for(int h = 1;h<n-1;h++){
	for(int i=0;i<cardinalidad;i++){
		for(int j=0;j<cardinalidad;j++){
			Caminos_n[i][j]=0;
			for(int k=0;k<cardinalidad;k++){
				Caminos_n[i][j]= Caminos_n[i][j] + aux1[i][k]*M[k][j];//M[k][j]*Caminos_3[i][k];	
			}
		}
	}
	// guardamos M^h en aux1
	for(int i=0;i<cardinalidad;i++)
		for(int j=0;j<cardinalidad;j++)
			aux1[i][j]= Caminos_n[i][j];
}

// imprimimos M^n
cout<<"Matriz de caminos de longitud "<<n<<": "<<endl;
for(int i=0;i<cardinalidad;i++){
	for(int j=0;j<cardinalidad;j++){
		cout<<"["<<Caminos_n[i][j]<<"] ";
	}
	cout<<endl;
}
cout<<endl;
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
	cout<<"2. Calcular caminos de longitud n."<<endl;
	cout<<"3. ingresar nueva matriz de adyacencia."<<endl;
	cout<<"4. salir."<<endl;
	cout<<"   >>> ";
	cin>>opc;
	switch(opc){
		case 1:
			Mostrar_matriz_de_adyacencia();
			break;
		case 2:
			Hallar_caminos_de_longitud_n();
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
//M1->Mostrar_matriz_de_adyacencia();
//M1->Hallar_caminos_de_longitud_n();
M1->menu();
return 0;
}
