#include <iostream>
using namespace std;

void imprimirCaracteres(char* texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        cout << texto[i];
    }
    cout << endl;
}

int main() {
    const char* mensaje = "Hola, mundo!";
    imprimirCaracteres(mensaje);

    return 0;
}
