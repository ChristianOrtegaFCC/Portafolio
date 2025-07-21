#include <iostream>
using namespace std;

int main(){
	int numeros[30];
	char nombre[]="Higuain";// !!!!!!
	float decimales[10];
	double decimalesotes[10];
	
	// sizeof devuelve el espacio en bytes usado por un objeto
	cout<<"C++"<<endl;
	cout<<"sizeof(numeros) = "<<sizeof(numeros)<<endl;
	cout<<"sizeof(nombre) = "<<sizeof(nombre)<<endl;
	cout<<"sizeof(decimales) = "<<sizeof(decimales)<<endl;
	cout<<"sizeof(decimalesotes) = "<<sizeof(decimalesotes)<<endl;
	/*
	for(int i=0;i < (sizeof(nombre) - 1);i++  ){
		printf("nombre [i]: %c\n",nombre[i]);
	}*/
	
	
	
	return 0;
}





















