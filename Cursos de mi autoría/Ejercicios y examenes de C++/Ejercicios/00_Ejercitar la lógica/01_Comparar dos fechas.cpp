#include <stdio.h>
#include <iostream>
#include <cstdlib>
//#include <cmath>
int main(){
	int A[3];
	int B[3];
	int C[3];
	int i;int o; o=0;
while(o==0){

printf("Este programa pide dos fechas en el formato (dd/mm/aaaa), \n y da el orden de estas.\n");
printf("Dame la fecha A\n Dia: ");
scanf("%d", &A[0]);
printf("\n Mes:");
scanf("%d", &A[1]);
printf("\n Año:");
scanf("%d", &A[2]);
printf("Dame la fecha B\n Dia: ");
scanf("%d", &B[0]);
printf("\n Mes:");
scanf("%d", &B[1]);
printf("\n Año:");
scanf("%d", &B[2]);

for(i=0;i<3; i++){
	if(A[i]-B[i]==0){C[i]=0;
	}
	else{
		C[i]=(A[i]-B[i])/(abs(A[i]-B[i]));}
}
switch(C[2]){
	case 0:
		switch(C[1]){
			case 0:
				switch(C[0]){
					case 0:
						/* en este caso las fechas coinciden*/
						printf("Las fechas A y B son el mismo dia\n");
						break;
					case -1:
						/* en este caso A pasa antes que B*/
						printf("La fecha A pasa antes que la fecha B\n");
						break;
					case 1:
						/* en este caso B pasa antes que A*/ 
						printf("La fecha A pasa después de la fecha B\n");
				}
				break;
			case -1:
				/*en este caso A pasa antes que B*/
				printf("La fecha A pasa antes que la fecha B\n");
				break;
			case 1:
				/* en este caso B pasa antes que A*/
				printf("La fecha A pasa después de la fecha B\n");
		}
		break;
	case -1:
		/* en este caso las fecha A es antes de la B*/
		printf("La fecha A pasa antes que la fecha B\n");
		break;
	case 1:
		/* en este caso la fecha A es después de B*/
		printf("La fecha A pasa después de la fecha B\n");
		break;
}
printf("Si quieres volver a consultar escribe 0; si quieres salir escribe cualquier cosa.\n");
scanf("%d", &o);
}

return 0;}
