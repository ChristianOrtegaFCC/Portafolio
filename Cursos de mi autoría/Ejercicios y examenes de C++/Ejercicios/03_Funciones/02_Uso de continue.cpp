#include <stdio.h>
#include <windows.h>  //sleep
#include <stdlib.h>   // cls

int main(){
	int i;
	for(i=1;i<=20;i++){
		if ((i == 6) || (i==13)){
			continue;
		}
		printf("%d ",i);
		Sleep(650);
		printf(".");
		Sleep(100);
		printf(".");
		Sleep(100);
		printf(".");
		Sleep(100);
		if((i%2) == 0){
			printf(" Par");
		}else{
			printf(" Impar");
		}
		Sleep(400);
		system("cls");
		
	}
	
}
