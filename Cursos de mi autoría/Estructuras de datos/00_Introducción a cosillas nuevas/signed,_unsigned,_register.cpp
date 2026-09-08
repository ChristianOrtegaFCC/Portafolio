#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	// agregando la palabra register simplemente le dices al compilador que
	// guarde "i" (en este caso) como si fuera un registro de ensamblador. esto
	// haría que el acceso a "i" sea más rápido pero ultimadamente al compilador
	// le vale verga que pongas "register", y será él quien decida si guarda esa
	// variable como registro o no (es en serio jajajaj). de todas formas es algo
	// un poco irrelevante, no le veo mucho uso. Cosas como esta o "volatile" o
	// "goto" se usan relmente poco, nada, o las implementa el compilador por sí
	// mismo así que... meh... :)
	
	// "Oye compilador, si quieres guarda "i" como registro eh, si quieeeeres xd"
	register int i;
	
	// ahora, para signed y unsigned, la ejecución se explica mejor sola :)
	signed char   num;
	unsigned char num2;

	for(i=0;i<=256;i++){
		num = i;
		num2 = i;
		printf("for(%d):   ",i);
		printf("num =  %d    |   ",num);
		printf("num2 = %d",num2);
		
		if(i==0) printf("    !!!! 0");
		if(i==2) printf("    !!!! 2^1");
		if(i==4) printf("    !!!! 2^2");
		if(i==8) printf("    !!!! 2^3");
		if(i==16) printf("    !!!! 2^4");
		if(i==32) printf("    !!!! 2^5");
		if(i==64) printf("    !!!! 2^6");
		if(i==127) printf("    !!!! 127 = (256/2)-1 !!!! <- unsigned !!!!!");
		if(i==128) printf("    !!!! 2^7");
		if(i==255) printf("    !!!! 255 = (2^8)-1");
		if(i==256) printf("    !!!! 2^8 (o mas, fuera del rango estandar)");
		
		
		printf("\n");
	}
	
	// tiempo de ejecución con:
	//   register int i;			 int i;
	//		 0.4827			 >		0.4362
	//		 0.4588			 >		0.4543
	//		 0.4662			<		0.4923
	//		 0.4925			 >		0.4652
	//		 0.4995			 >		0.4316
	//		 0.4376			<		0.4992
	//		 0.4846			<		0.4953
	//		 0.4287			<		0.4707
	//		 0.4384			<		0.5231
	
	return 0;
}

