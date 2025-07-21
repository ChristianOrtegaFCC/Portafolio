#include <iostream>
#include <vector>
using namespace std;

void agregarElementos(std::vector<int>& vec) {
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
}

int main() {
    std::vector<int> numeros;
    agregarElementos(numeros);

    // Se intenta acceder al último elemento fuera del vector
    cout << "El último número agregado es: " << numeros.at(10) << endl;

    return 0;
}
