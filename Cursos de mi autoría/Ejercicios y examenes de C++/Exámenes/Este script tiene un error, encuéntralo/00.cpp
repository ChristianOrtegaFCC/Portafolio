#include <stdio.h>
#define max 10

int main(){
int A[max],i,j,aux;
A[0] = 12; A[1] = 23; A[2] = 1; A[3] = 0; A[4] = 16; A[5] = 78; A[6] = 89; A[7] = 3; A[8] = 33; A[9] = 104;
printf("Array: \n");
for(i = 0;i<max;i++) printf("A[%d] = %d\n",i,A[i]);

for(i=0;i<max-1;i++){
	j=i;
	while(j != max ){
		if(A[i] > A[j]){
			j++;
		}else{
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}	
	}
}
return 0;
}
