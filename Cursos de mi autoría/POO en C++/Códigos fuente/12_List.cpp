#include <iostream>
#include <list>
using namespace std;

// La magia de los objetos, es que podemos usarlos del mismo modo en que usamos
// objetos en la vida real. Creados con un propósito, ahorrarnos tareas específicas

class A{
	public: int a;
	public: int a2;
	
	public: A(){
		cout<<"---------\na = "; cin>>a;
		cout<<"a2 = "; cin>>a2;
		cout<<"\n";
	}
	
	public: A(int aux){
		cout<<"---------\na = "; cin>>a;
		cout<<"a2 = "; cin>>a2;
		cout<<"\n";	
		
	}
	
	public: void show(){
		cout<<"---------\na = "<<a;
		cout<<"\na2 = "<<a2;
		cout<<"\n\n";
		return;
	}

	
	
	
};

int main(){
	list<A> L;
	L.push_back( 1 );
	L.push_back( 1 );
	L.push_back( 1 );
	L.push_back( 1 );
	L.push_back( 1 );
	
	system("pause>nul"); // Pausa con getch
	
	cout<<"\nShowing:\n";
	list<A>::iterator I = L.begin();
	while(I != L.end() ){
		I->show();
		I++;
	}
	
	return 0;
}

