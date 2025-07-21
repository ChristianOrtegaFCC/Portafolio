#include <iostream>
#include <vector>
using namespace std;

void imprimirVector(const vector<int>& vec) {
    for (int i = 0; i <= vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int buscarElemento(const vector<int>& vec, int elemento) {
    for (int i = 0; i <= vec.size(); i++) { 
        if (vec[i] == elemento) {
            return i; // Se encontró el elemento
        }
    }
    return -1; // Si no se encuentra el elemento
}

int main() {
    vector<int> numeros = {10, 20, 30, 40, 50};

    cout << "Vector de números: ";
    imprimirVector(numeros);

    int elementoABuscar = 30;
    int resultado = buscarElemento(numeros, elementoABuscar);

    if (resultado != -1) {
        cout << "El elemento " << elementoABuscar << " se encuentra en el índice " << resultado << endl;
    } else {
        cout << "El elemento " << elementoABuscar << " no se encuentra en el vector" << endl;
    }

    return 0;
}
