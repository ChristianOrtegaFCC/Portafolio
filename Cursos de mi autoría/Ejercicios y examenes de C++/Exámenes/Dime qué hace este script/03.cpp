#include <iostream>
using namespace std;

int fibonacciSum(int n) {
    if (n <= 1) return n;
    return fibonacciSum(n - 1) + fibonacciSum(n - 2);  // !!!! Dime qué hace esto
}

void scaleValues(int arr[], int size, int factor) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * factor;  // !!!! Dime qué hace esto
    }
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];  // !!!! Dime qué hace esto
        }
    }
    return maxVal;
}

int main() {
    int n;
    cout << "Ingresa un número: ";
    cin >> n;
    cout << "Suma de Fibonacci hasta " << n << ": " << fibonacciSum(n) << endl;

    int numbers[] = {5, 8, 2, 10, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    scaleValues(numbers, size, 3);

    cout << "Valores escalados: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";  // !!!! Dime qué hace esto
    }
    cout << endl;

    cout << "El valor máximo es: " << findMax(numbers, size) << endl;

    return 0;
}
