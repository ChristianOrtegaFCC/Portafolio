#include <iostream>
#include <stdio.h>
using namespace std;


union abc{
	int a;
	char b;
	float c;
};

int main(){
	int caso = 3;
	abc U1;
	
	U1.a = 100;
	U1.b = 'a';
	U1.c = 3.1416;
	switch(caso){
		case 1:
			printf("U1.a = %d",U1.a);
			break;
		case 2:
			printf("U1.b = %c",U1.b);
			break;
		case 3:
			printf("U1.c = %f",U1.c);
			break;
		default:
			printf("you werent supossed to be here");
			break;
	}
	
	
	return 0;
}

