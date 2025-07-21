#include <iostream>
using namespace std;

void llenarArreglo(int* arr, int tamano) {
    for (int i = 0; i <= tamano; i++) { // !!! Error aquí
        arr[i] = i * 2;
    }
}

int main() {
    int* numeros = new int[5]; // Arreglo de tamaño 5
    llenarArreglo(numeros, 5);

    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    delete[] numeros; // Liberar memoria
    return 0;
}
