#include <iostream>
#include <cmath>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;  // !!!! Dime qué hace esto
    }
    return a;
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }  // !!!! Dime qué hace esto
    }
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

double calculateStandardDeviation(int arr[], int size) {
    double sum = 0, mean, sd = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    mean = sum / size;  // !!!! Dime qué hace esto
    for (int i = 0; i < size; i++) {
        sd += pow(arr[i] - mean, 2);
    }
    return sqrt(sd / size);
}

int main() {
    int arr1[] = {2, 5, 9};
    int arr2[] = {1, 3, 7, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, merged);

    cout << "Arreglo fusionado: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    int nums[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "Desviación estándar: " << calculateStandardDeviation(nums, size) << endl;

    cout << "MCD de 56 y 98: " << findGCD(56, 98) << endl;

    return 0;
}
