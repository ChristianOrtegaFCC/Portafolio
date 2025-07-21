#include <iostream>
#include <string>
using namespace std;

// Explica qué es o qué podría ser este script...

class generica{
	public: int a;
	public: int b;
	public: int c;
	
	public: generica(){
		a = 1;
		b = 1;
		c = 1;
	}
	
	public: void print(){
		printf("xd\n");
	}
};

void func_generica(int *counter);

int main(){	
	string aver;
	getline(cin,aver);
	cout<<"frase: "<<aver;
	
	return 0;
}

void func_generica (int *counter){
	*counter = 30;
	return;
}

