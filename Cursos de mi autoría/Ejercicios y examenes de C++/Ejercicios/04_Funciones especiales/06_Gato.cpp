#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  // API del Sistema Operativo de Windows (Permite trabajar sobre la Consola).

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color m�s claro que su antecesor).
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};
/*				PROTOTIPOS DEL USO DE COLORES
Color(BLACK, LGREEN);
printf("Texto en color Verde Claro y fondo Negro\n");

Color(BLACK, RED);
printf("Texto en color Rojo y fondo Negro\n");

Color(WHITE, BLACK);
printf("Texto en color Negro y fondo Blanco\n");

Color(BLACK, WHITE); // Devolvemos el color original de la consola.
printf("Volvimos a la normalidad!\n");
*/
void Color(int Background, int Text); // Prototipo de funci�n          
int victoria(int gat[4][4]);

int main(){
int i,j,k=0,gat[4][4],x, turno = 1 /* 2 = O  ,  1 = X */,res,conta,used[9],detect,bandwin,rep, bandera;

printf("juguemos al gato! ^-^\nsi en la matriz hay un punto, esa casilla esta libre\n");
printf("para seleccionar las casillas, toma en cuenta la matriz siguiene:\n\n1 2 3\n4 5 6\n7 8 9\n\n\n");
do{
	// inicializa algunas variables, imprime puntos
	bandwin=0;
	conta=0;
	x=0;
	bandera = 1;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			printf("   ");
			x++;
			gat[i][j] = x;
			used[x] = x;
			printf(".     ");
		}
		printf("\n\n");
	}
	printf("\n");

	//
	do{
		conta++;// conta cuenta la cantidad de turnos jugados en total (por ambos jugadores)
		if(turno ==1){// atenci�n a la definici�n de turno:
			turno = 2;
			printf("\nturno de ");
			Color(BLACK, LBLUE); printf("'O'");
			Color(BLACK, WHITE); printf(", elige una casilla para tirar");
		}else{
			turno =1;
			printf("\nturno de ");
			Color(BLACK, LMAGENTA); printf("'X'");
			Color(BLACK, WHITE); printf(", elige una casilla para tirar");
		}
			
		do{
			detect = 0;
			printf("\nRes: ");
			if(turno == 1){
				Color(BLACK, LMAGENTA);
			}else{
				Color(BLACK, LBLUE);
			}
			scanf("%d",&res);
			Color(BLACK, WHITE);
			if(res < 1 || res > 9){
				Color(BLACK, RED);
				printf("la opcion no puede ser menor a 1 ni mayor a 9 broder, intenta de nuevo");
				Color(BLACK, WHITE);
			}
			if(used[res] == 0){
				Color(BLACK, RED);
				printf("esa posicion ya esta ocupada, intenta de nuevo...");
				Color(BLACK, WHITE);
				detect = 1;
			}else{
				used[res] = 0;
			}
			
		}while( res < 1 || res > 9 || detect == 1);
		///////		/////////	/////////
		printf("\n");
		for(i=1;i<=3;i++){
			for(j=1;j<=3;j++){
				printf("   ");
				if(gat[i][j] == res){
					if(turno == 2 /* (turno de O)*/){
						gat[i][j] = 22;	
					}else{		/*else => turno == 1 => turno de X*/
						gat[i][j] = 11;
					}
				}
				if(gat[i][j] < 10 ){
					//printf("%d     ",gat[i][j]);
					printf(".     ");
				}else{
					if(gat[i][j] == 11){
						Color(BLACK, LMAGENTA); printf("X     ");
						Color(BLACK, WHITE);
					}else{
						Color(BLACK, LBLUE); printf("O     ");
						Color(BLACK, WHITE);
					}
				}
			}
			printf("\n\n");
		}
		bandwin = victoria(gat);

	}while(conta < 9 && bandwin == 0);
	
	if(bandwin == 1){
		Color(BLACK, LMAGENTA); printf("   /// gana 'X' ///\n");
		Color(BLACK, WHITE);
	}else{
		if(bandwin == 2){
			Color(BLACK, LBLUE); printf("   /// gana 'O' ///\n");
			Color(BLACK, WHITE);
		}else{
			Color(BLACK, BROWN); printf(" ///// EMPATE ///// \n");
			Color(BLACK, WHITE);
		}
	}
	printf("quieren jugar otra vez?\n");Color(BLACK, GREEN);printf("1 = si\n");Color(BLACK, RED);printf("2 = no\n");
	Color(BLACK, WHITE);
	do{
		scanf("%d",&rep);
			if(rep < 1 || rep > 2){
				Color(BLACK, RED); printf("solo hay 2 opciones, intenta de nuevo...\n");
				Color(BLACK, WHITE);
			}
	}while(rep < 1 || rep > 2);
	printf("\n\n");
}while(rep == 1);

printf("adios\n");
return 0;
}

int victoria(int gat[4][4]){
int bandera =0;

if((gat[1][1]==11&&gat[1][2]==11&&gat[1][3]==11)||(gat[2][1]==11&&gat[2][2]==11&&gat[2][3]==11)||(gat[3][1]==11&&gat[3][2]==11&&gat[3][3]==11))
	bandera = 1;
if((gat[1][1]==11&&gat[2][1]==11&&gat[3][1]==11)||(gat[1][2]==11&&gat[2][2]==11&&gat[3][2]==11)||(gat[1][3]==11&&gat[2][3]==11&&gat[3][3]==11))
	bandera = 1;
if((gat[1][1]==11&&gat[2][2]==11&&gat[3][3]==11)||(gat[1][3]==11&&gat[2][2]==11&&gat[3][1]==11))
	bandera = 1;

if((gat[1][1]==22&&gat[1][2]==22&&gat[1][3]==22)||(gat[2][1]==22&&gat[2][2]==22&&gat[2][3]==22)||(gat[3][1]==22&&gat[3][2]==22&&gat[3][3]==22))
	bandera = 2;
if((gat[1][1]==22&&gat[2][1]==22&&gat[3][1]==22)||(gat[1][2]==22&&gat[2][2]==22&&gat[3][2]==22)||(gat[1][3]==22&&gat[2][3]==22&&gat[3][3]==22))
	bandera = 2;
if((gat[1][1]==22&&gat[2][2]==22&&gat[3][3]==22)||(gat[1][3]==22&&gat[2][2]==22&&gat[3][1]==22))
	bandera = 2;

return bandera;
}

void Color(int Background, int Text){ // Funci�n para cambiar el color del fondo y/o pantalla

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

// Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
int    New_Color= Text + (Background * 16);

SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}
