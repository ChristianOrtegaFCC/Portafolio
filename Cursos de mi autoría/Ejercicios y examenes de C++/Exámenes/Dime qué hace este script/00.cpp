#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Explica qué es o qué podría ser este script....

int main(){
	int A=1,B=15,C=45;
	while(true){
		C--;
		if(C==-1){
			if(B!=-1){
				C=59;
				B--;
			}
			if(B==-1){
				if(A!=0){
					B=59;
					A--;
				}
			}
		}
		if (A>9)cout<<A<<":";
		else cout<<"0"<<A<<":";
		
		if (B>9)cout<<B<<":";
		else cout<<"0"<<B<<":";
		
		if (C>9)cout<<C<<endl;
		else cout<<"0"<<C<<endl;
		
		if(A == 0 && B == 0 && C == 0){
			//digitalWrite(pin,1);
			printf("\n  digitalWrite(pin,HIGH);\n\n");
			return 0;
		}

		Sleep(1000);
		system("cls");
	}
return 0;
}
