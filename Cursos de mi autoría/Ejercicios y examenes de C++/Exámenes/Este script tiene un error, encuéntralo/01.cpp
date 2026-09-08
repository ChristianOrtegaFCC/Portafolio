#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Ingresa el primer número: ";
    cin >> num1;
    cout << "Ingresa el segundo número: ";
    cin >> num2;

    if (num1 > num2) {
        cout << "El primer número es mayor." << endl;
    } else if (num1 < num2) {
        cout << "El segundo número es mayor." << endl;
    } else {
        cout << "Los números son iguales." << endl;
    }

    int resultado = num1 + num2;
    cout << "La suma de los números es: " << resultado << endl;

    if (num1 % 2 == 0) 
        cout << "El primer número es par" << endl;
    else
        cout << "El primer número es impar" << endl;

    if (num2 % 2 = 0)
        cout << "El segundo número es par" << endl;
    else
        cout << "El segundo número es impar" << endl;
    
    return 0;
}
