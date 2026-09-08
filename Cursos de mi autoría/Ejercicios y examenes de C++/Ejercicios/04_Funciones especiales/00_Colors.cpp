#include <stdio.h>
#include <Windows.h>  // <---- API del Sistema Operativo de Windows (Permite trabajar sobre la Consola).

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
void Color(int Background, int Text);

int main(){
	for(int i=1;i<=15;i++){
		Color(BLACK, i);
		printf("%c%c",475,475);
	}
	
	/*
	char xd;
	scanf("%c",&xd);
	
	Color(BLACK, LGREEN);
	printf("Verdesito\n");
	scanf("%c",&xd);
	
	Color(BLACK, RED);
	printf("Rojito\n");
	scanf("%c",&xd);
	
	Color(BLACK, LBLUE);
	printf("Azulito\n");
	scanf("%c",&xd);
	
	Color(BLACK, YELLOW);
	printf("Amarillito\n");
	scanf("%c",&xd);
	
	Color(BLACK, MAGENTA);
	printf("Magentita\n");
	scanf("%c",&xd);
	
	Color(BLUE, WHITE);
	printf("Configuracion BIOS ENSAMBLADOR feo\n");
	scanf("%c",&xd);
	
	Color(RED, BROWN);
	printf("Configuracion Mcdonalds xd\n");
	scanf("%c",&xd);
	
	Color(WHITE, BLACK);
	printf("Es el dia opuesto xd\n");
	scanf("%c",&xd);
	
	Color(BLUE, LBLUE);
	printf("configuracion x xd\n");
	scanf("%c",&xd);
	
	Color(BROWN, GREEN);
	printf("Dios que horrible, me sangran los ojos\n� para que alguien haria una configuracion tan horrible?\ndios mio ayudame a entender xdddddd\n");
	scanf("%c",&xd);
	
	Color(GREEN, YELLOW);*/
return 0;
}



void Color(int Background, int Text){ // Funci�n para cambiar el color del fondo y/o pantalla

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

// Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
int    New_Color= Text + (Background * 16);

SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}
