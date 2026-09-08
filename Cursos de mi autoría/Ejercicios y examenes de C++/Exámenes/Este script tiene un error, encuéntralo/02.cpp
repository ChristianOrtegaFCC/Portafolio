#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 5;

    cout << "La suma de " << a << " y " << b << " es: " << a + b << endl;
    cout << "La resta de " << a << " y " << b << " es: " << a - b << endl;
    cout << "La multiplicación de " << a << " y " << b << " es: " << a * b << endl;

    if (b != 0)
        cout << "La división de " << a << " y " << b << " es: " << a / b << endl;
    else
        cout << "No se puede dividir entre cero" << endl;

    double result = 0.0;
    result = a / b;
    cout << "El resultado de la división es: " << result << endl;

    int arreglo[5] = {1, 2, 3, 4, 5};
    cout << "El valor del tercer elemento del arreglo es: " << arreglo[2] << endl;

    return 0;
}
