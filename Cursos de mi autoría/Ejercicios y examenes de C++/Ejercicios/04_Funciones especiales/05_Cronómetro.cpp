#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main(){
	// de esta forma funciona un cronometro :)
	int h=0,m=0,s=0;
	while(1){
		cout<<h<<":"<<m<<":"<<s<<endl;
		s++;
		if(s==60){
			s=0;
			m++;
			if(m==60){
				m=0;
				h++;
			}
		}
		Sleep(1000);
		system("cls");
	}
return 0;
}
