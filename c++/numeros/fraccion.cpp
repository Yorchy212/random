#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int mcd(int num1, int num2) {
    unsigned aux1;
    while ((num1 % num2) != 0) {
        aux1 = num2;
        num2 = num1 % num2;
        num1 = aux1;
    }
    return num2;
}

bool entero(double num1) {
    if (num1 - int(num1) == 0) {
        return true;
    }
    else {
        return false;
    }
}

void escribirFraccion(double num1, double num2) {
    int aux2 = 0;
    double num3 = num1;
    if (entero(num1)) {
        cout << "El numero " << num1 << " equivale a la fraccion " << num1 << endl;
    }
    else {
        while (!entero(num1)) {
            num1 = num1 * 10;
            aux2++;
            num2 = pow(10, aux2);
        }

        cout << "El numero " << num3 << " equivale a " << fixed << setprecision(0) <<
        num1 / mcd(num1, num2) << " / " << num2 / mcd(num1, num2) << endl;

    }
}

int main () {
    double num1, num2, i = 1;
    system("cls");
    while (i != 0) {
        cout << "Escribe un numero decimal no irracional (max 4 decimales) (0 para terminar): ";
        cin >> num1;
        if (num1 == 0) {
            return 0;
        }
        escribirFraccion(num1, num2);
    }

    return 0;
}