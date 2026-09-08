#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {  // !!!! Dime qué hace esto
        if (n % i == 0) return false;
    }
    return true;
}

void rotateArrayRight(int arr[], int size) {
    int last = arr[size - 1];
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];  // !!!! Dime qué hace esto
    }
    arr[0] = last;
}

int countPrimes(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) count++;  // !!!! Dime qué hace esto
    }
    return count;
}

int main() {
    int numbers[] = {11, 8, 5, 13, 20, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    rotateArrayRight(numbers, size);

    cout << "Arreglo rotado a la derecha: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Número de primos en el arreglo: " << countPrimes(numbers, size) << endl;

    return 0;
}
