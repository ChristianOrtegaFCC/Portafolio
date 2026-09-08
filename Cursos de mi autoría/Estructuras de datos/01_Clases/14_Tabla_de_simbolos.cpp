#include <stdio.h>
#include <string.h>

#define MAX_SIMBOLOS 20   // Número máximo de símbolos en la tabla

// Estructura para representar un símbolo
typedef struct {
    char nombre[20];  // Nombre del símbolo (variable)
    int valor;        // Valor asociado al símbolo
} Simbolo;

// Tabla de símbolos (array de estructuras)
Simbolo tabla[MAX_SIMBOLOS];
int cantidad_simbolos = 0;  // Contador de símbolos

// Función para agregar un símbolo a la tabla
void agregar_simbolo(const char *nombre, int valor) {
    if (cantidad_simbolos < MAX_SIMBOLOS) {
        strcpy(tabla[cantidad_simbolos].nombre, nombre);
        tabla[cantidad_simbolos].valor = valor;
        cantidad_simbolos++;
        printf("Símbolo '%s' agregado con valor %d.\n", nombre, valor);
    } else {
        printf("Error: Tabla de símbolos llena.\n");
    }
}

// Función para buscar un símbolo por nombre
int buscar_simbolo(const char *nombre) {
    for (int i = 0; i < cantidad_simbolos; i++) {
        if (strcmp(tabla[i].nombre, nombre) == 0) {
            return tabla[i].valor;
        }
    }
    printf("Símbolo '%s' no encontrado.\n", nombre);
    return -1;  // Retorna -1 si no se encuentra el símbolo
}

// Función para mostrar todos los símbolos en la tabla
void mostrar_tabla() {
    printf("\nTabla de símbolos:\n");
    for (int i = 0; i < cantidad_simbolos; i++) {
        printf("Nombre: %s, Valor: %d\n", tabla[i].nombre, tabla[i].valor);
    }
}

int main() {
    agregar_simbolo("x", 10);
    agregar_simbolo("y", 20);
    agregar_simbolo("z", 30);
    
    printf("\nBuscando el símbolo 'y'...\n");
    int valor = buscar_simbolo("y");
    if (valor != -1) {
        printf("Valor encontrado: %d\n", valor);
    }

    mostrar_tabla();
    
    return 0;
}
