#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main(){
	int i,buscado = 13;
	for(i=1;i<=20;i++){
		printf("%d\n",i);
		if(i == buscado){
			break;
		}
		Sleep(500);
		system("cls");
	}
	printf("Finalizando...");
	return 0;
}








