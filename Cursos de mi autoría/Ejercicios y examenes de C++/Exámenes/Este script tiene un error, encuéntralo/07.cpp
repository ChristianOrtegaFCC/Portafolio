#include <iostream>
using namespace std;

void calcularSuma(int& a, int& b) {
    cout << "Suma: " << a + b << endl;
}

int main() {
    int x;
    int y = 10;
    calcularSuma(x, y);  // !!! Error aquí

    return 0;
}
