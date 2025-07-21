#include <iostream>
#include <stdio.h>
using namespace std;

void escribe(...);
void xd(int); // ?????

int main(){
	string t ="True", f = "False";
	//int x = 1,z;
	bool y = false;
	//(void) y; // ?????
	
	//   ()     ?      case true               case false      ;
	//(y == true) ?  printf("y = True\n") : printf("y = false\n"); // operador '?'
	
	//z =	(y == true) ?   1 : 0 ;
	//printf("%d\n",z);
	
	printf("y = %c\n", (y == true)? 't':'f');
	
	//escribe(1,2,3,4); // aparentemente podemos enviar los parámetros que queramos a una función con parámetros "(...);", pero no sé cómo usar eso....
	//xd(x); // ????
	return 0;
}


void escribe(...){
	printf("mhhhhh...");
}

void xd(int){
	printf("\nxd");
}
