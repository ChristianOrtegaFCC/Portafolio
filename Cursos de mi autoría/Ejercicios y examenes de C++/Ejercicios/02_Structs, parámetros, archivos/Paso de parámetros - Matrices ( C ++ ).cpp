// matrices
#include <iostream>
int ModificaMatriz(int Matrix[3][3]);


int main(){
	int Matrix[3][3];
	int i,j;
	ModificaMatriz(Matrix);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Matrix[%d][%d] = %d\n",i,j,Matrix[i][j]);
		}	
	}
	return 0;
}


int ModificaMatriz(int Matrix[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			Matrix[i][j] = 50;
		}	
	}
	return 0;
}
