#include <iostream>
using namespace std;

int mcd(int num1, int num2, int aux) {
    while ( (num1 % num2) != 0 ) {
        aux = num2;
        num2 = num1 % num2;
        num1 = aux;
    }
    return num2;
}

int main() {

    cout << "Escriba dos numeros enteros: ";

    int num1, num2, soporte, aux;
    cin >> num1 >> num2;
    
    if (num1 == 0 || num2 == 0) {
        cout << "Uno de los numeros no puede ser 0." << endl;
    }
    if (num2 > num1) {
        soporte = num1;
        num1 = num2;
        num2 = soporte;
    }
    if (num1 == num2) {
        cout << "El maximo comun divisor es " << num1 << endl;
    }
    if (num1 > num2) {
        cout << "El maximo comun divisor de " << num1 << " y " << num2 << " es " << mcd(num1, num2, aux) << endl;
    }

    return 0;
}