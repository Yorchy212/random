#include <iostream>
using namespace std;

unsigned maximoComunDivisor(unsigned num1, unsigned num2) {
    unsigned aux;
    while ((num1 % num2) != 0) {
    aux = num2;
    num2 = num1 % num2;
    num1 = aux;
    }
    return num2;
}

int main () {
    unsigned num1, num2, aux, soporte;
    num1 = 0;
    num2 = 1;
    system("cls");
    while(num1 != 0 || num2 != 0) {
        cout << "Introduce dos numeros enteros (0 para terminar): ";
        cin >> num1;
        if (num1 == 0) {
            return 0;
        }
        cin >> num2;
        if (num2 > num1) {
            soporte = num1;
            num1 = num2;
            num2 = soporte;
        }
        if (num1 == num2) {
            cout << "El maximo comun divisor es " << num1 << endl;
        }
        if (num1 > num2) {
            cout << "El maximo comun divisor de " << num1 << " y " << num2 << " es " << maximoComunDivisor(num1, num2) << endl;
            cout << "El minimo comun multiplo de " << num1 << " y " << num2 << " es " << (num1*num2)/maximoComunDivisor(num1, num2) << endl;
        }
        num1 = 0;
        num2 = 1;
    }
    return 0;
}