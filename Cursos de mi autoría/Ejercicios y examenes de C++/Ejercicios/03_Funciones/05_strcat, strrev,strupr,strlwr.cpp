#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
int main(){
	char cad1[] = "chi";
	char cad2[] = "spa";
	char cad3[30];
	
	cout<<"1.- strcat(cad3,cad2); //concatena ca3+cad2: "<<endl;
	strcpy(cad3,cad1); // cad3 = "chi";
	strcat(cad3,cad2); // cad3 = cad3 + "spa";
	cout<<cad3<<endl<<endl;
	
	cout<<"2.- strrev(cad3); //invierte cad3: "<<endl;
	strrev(cad3); // reverse cad3
	cout<<cad3<<endl<<endl;
	
	cout<<"3.- strupr(cad3); // toda cad3 a mayusculas: "<<endl;
	strupr(cad3); // toda cad3 a mayúsculas
	cout<<cad3<<endl<<endl;
	
	cout<<"4.- strlwr(cad3); // toda cad3 a minusculas: "<<endl;
	strlwr(cad3); // toda cad3 a minusculas
	cout<<cad3<<endl<<endl;
	
	
	
	return 0;
}
