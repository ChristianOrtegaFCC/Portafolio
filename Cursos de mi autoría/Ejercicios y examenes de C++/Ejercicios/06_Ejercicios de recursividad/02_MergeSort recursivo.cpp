// Merge sort recursivo
// Amador Ortega Christian Amauri
// 201927821   ||  BUAP - FCC

#include <stdio.h>
#define max 500

void ordenando(int *A, int b, int e);
void MERGE(int *A, int b, int m, int e);

int main(){
        int A[max],lens, i;
        do{
        	printf("tama%co del arreglo: ",420);
        	scanf("%d", &lens);
        	if(lens > max) printf("No puedes dar un n%cmero mayor a %d, ermanito, intenta de nuevo...\n",419,max);
        }while(lens > max);
        
        printf("Dame los elementos:\n");
        for(i=0; i< lens; i++){ printf("A[%d]: ",i); scanf("%d",&A[i]); }

        ordenando(A, 0, lens-1); 

        printf("\n\nArreglo ordenado:\n");
        for(i=0; i< lens; i++) printf("A[%d]: %d\n",i, A[i]);
        return 0;

}


void ordenando(int *A, int b, int e){
        if(b < e){
            int m = (b + e) / 2;
            ordenando(A, b, m);
            ordenando(A, m+1, e);
            MERGE(A, b, m, e);
        }
}


void MERGE(int *A, int b, int m, int e){       
		int l=m-b+1,  r=e-m,  i,  L[l+1],  R[r+1];
        for(i=0; i< l; i++) L[i] = A[b+i];
        for(i=0; i< r; i++) R[i] = A[m+i+1];
        
        L[l] = 32767;
        R[r] = 32767;
        l = 0;
        r = 0;
		
		// resolver (esta parte del c�digo corresponde espec�ficamente al ordenamiento de las partes creadas)
        for(i=0; i< e-b+1; i++){
            if(L[l] < R[r]){
                A[b+i] = L[l];
                l ++;
            }else{
                A[b+i] = R[r];
                r ++;
            }
        }
}
