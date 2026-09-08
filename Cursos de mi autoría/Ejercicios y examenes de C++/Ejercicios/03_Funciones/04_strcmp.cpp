#include <iostream>
#include <string.h>
using namespace std;
// !!!! menciona lo de las may�sculas y min�sculas
// !!!! da una nocion de como funcionan los chars

int main(){
	char cad1[] = "chispa";
	char cad2[] = "pinina";
	// verificar si dos cadenas son iguales o no
	
	if(strcmp(cad1,cad2) == 0){
		cout<<"las cadenas son iguales"<<endl;
	}else{
		cout<<"las cadenas son diferentes"<<endl;
	}
	
	 /*comparar la posicion alfab�tica de una cadena respecto a otra
	if (strcmp(cad1,cad2) > 0){
		cout<<"cad1"<<"("<<cad1<<") va despues que cad2 ("<<cad2<<")"<<endl;	
	}else{
		cout<<"cad1"<<"("<<cad1<<") va antes que cad2 ("<<cad2<<")"<<endl;	
	}*/
	
	return 0;
}





