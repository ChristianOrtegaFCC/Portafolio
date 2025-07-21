#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void pedirNotas();
void mostrarNotas();
int numCalif, *calif;

int main(){
	pedirNotas();
	mostrarNotas();
	delete[] calif;
	
	return 0;
}

void pedirNotas(){
	cout<<"Dame el numero de calificaciones: ";
	cin>>numCalif;
	
	calif = new int[numCalif];
	
	for(int i=0;i<numCalif;i++){
		cout<<"nota["<<i<<"]: ";
		cin>>calif[i];
	}
	
}

void mostrarNotas(){
	cout<<"\n\nMostrando las notas:\n";
	for(int i=0;i<numCalif;i++){
		cout<<calif[i]<<endl;
	}
	return;
}
