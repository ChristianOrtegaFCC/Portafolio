#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO_TABLA 10  // Tamaño de la tabla hash

// Estructura para representar un símbolo
typedef struct Simbolo {
    char nombre[20];
    int valor;
    struct Simbolo *siguiente;  // Apuntador al siguiente símbolo (encadenamiento)
} Simbolo;

// Tabla hash (array de punteros a símbolos)
Simbolo *tabla[TAMANIO_TABLA];

// Función hash simple: Suma los valores ASCII de los caracteres del nombre y calcula el módulo
int funcion_hash(const char *nombre) {
    int suma = 0;
    for (int i = 0; nombre[i] != '\0'; i++) {
        suma += nombre[i];
    }
    return suma % TAMANIO_TABLA;
}

// Función para agregar un símbolo a la tabla hash
void agregar_simbolo(const char *nombre, int valor) {
    int indice = funcion_hash(nombre);
    Simbolo *nuevo = (Simbolo *)malloc(sizeof(Simbolo));
    strcpy(nuevo->nombre, nombre);
    nuevo->valor = valor;
    nuevo->siguiente = tabla[indice];  // Encadenar en la lista del índice
    tabla[indice] = nuevo;
    printf("Símbolo '%s' agregado con valor %d en el índice %d.\n", nombre, valor, indice);
}

// Función para buscar un símbolo por nombre en la tabla hash
int buscar_simbolo(const char *nombre) {
    int indice = funcion_hash(nombre);
    Simbolo *actual = tabla[indice];
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return actual->valor;
        }
        actual = actual->siguiente;
    }
    printf("Símbolo '%s' no encontrado.\n", nombre);
    return -1;  // Retorna -1 si no se encuentra el símbolo
}

// Función para mostrar todos los símbolos en la tabla hash
void mostrar_tabla() {
    printf("\nTabla de símbolos (Hash):\n");
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        printf("Índice %d: ", i);
        Simbolo *actual = tabla[i];
        while (actual != NULL) {
            printf("-> [Nombre: %s, Valor: %d] ", actual->nombre, actual->valor);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

int main() {
    agregar_simbolo("x", 10);
    agregar_simbolo("y", 20);
    agregar_simbolo("z", 30);
    agregar_simbolo("a", 40);
    agregar_simbolo("b", 50);

    printf("\nBuscando el símbolo 'y'...\n");
    int valor = buscar_simbolo("y");
    if (valor != -1) {
        printf("Valor encontrado: %d\n", valor);
    }

    mostrar_tabla();

    return 0;
}
