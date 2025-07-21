#include <stdio.h>
#define mx 20

int funcion(int n,int p);

int main(){
	int a,b;
	
	// como siempre, opté por el llenado automático de datos, pero si
	// es preciso, lo puedo modificar a una configuración manual :)
	
	printf("(versi%cn din%cmica modificada)...\n",418,416);
	printf("Con (A=0,B=1):");a=0;b=1;
	if (funcion(a,b) < funcion(b,a)){ // adaptación para interpretar sólo 1's o 0's en en el resultado.
		printf(" %d",1);			  // realmente, la función funcion(n,p) puede retornar muchos más
	}else{							  // valores de tipo int que solo 1's y 0's.
		printf(" %d",0);	
	}
	return 0;
}

// algoritmo dinámico presentado en el libro.
int funcion(int n, int p){
	int datos[mx][mx];
	int q,s,k;
	q=1-p;
	for(s=1;s<=n;s++){
		datos[0][s] = 1;
		datos[s][0] = 0;
		for(k=1;k <= s-1;k++){
			datos[k][s-k] = datos[k-1][s-k] + datos[k][s-k-1];
		}
	}
	
	for(s=1;s<=n;s++){
		for(k=0;k<=n-s;k++){
			datos[s+k][n-k] = datos[s+k-1][n-k] + datos[s+k][n-k-1] ;
		}
	}
	return datos[n][n];
}
