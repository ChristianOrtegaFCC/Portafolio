#include <iostream>
#include <conio.h>   // getch();
#include <string.h>
using namespace std;

int main(){
	char cadena1[] = "Chispa";
	char cadena2[20];
	strcpy(cadena2,cadena1);
	cout<<cadena2<<endl;			
	getch();
	return 0;
}

/* 1
si al momento declarar un arreglo de char
le asignas su valor, como en la línea 7,
no es necesario declarar entre los corchetes
el número de chars que usará el arreglo, se
detectan automáticamente char cadena2[20];
*/

/* 2
si borras el strcpy de esta línea, se imprimirá
un emoji, eso no es "basura", es un char aleatorio
(así como todas las letras o los dígitos, símbolos
y demás...)

*/
