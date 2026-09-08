#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);  // !!!! Dime qué hace esto
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;  // !!!! Dime qué hace esto
    }
}

int sumOddIndices(int arr[], int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += arr[i];  // !!!! Dime qué hace esto
    }
    return sum;
}

int main() {
    int num;
    cout << "Ingresa un número: ";
    cin >> num;
    cout << "Factorial de " << num << ": " << factorial(num) << endl;

    int myArray[] = {7, 3, 9, 2, 6};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    reverseArray(myArray, size);

    cout << "Arreglo invertido: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    cout << "Suma de elementos en índices impares: " << sumOddIndices(myArray, size) << endl;

    return 0;
}
