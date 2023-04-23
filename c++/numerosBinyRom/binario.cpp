#include <iostream>
#include <cmath>
using namespace std;

int pedirDatos(int numeroD) {
    cout << "Escribe un número entero positivo en base 10: ";
    cin >> numeroD;
    while(numeroD < 0) {
        cout << "El número tiene que ser un entero positivo: ";
        cin >> numeroD;
    }
    return numeroD;
}

string binario(int numeroD) {
    int pot = 0;
    while (pow(2,pot) <= numeroD) {
        pot++;
    }

    int pesos[pot];
    char bin[pot];
    int aux = pot - 1;

    for (int i = 0; i < pot; i++) {
        pesos[i] = pow(2, aux);
        aux--;
    }

    for (int j = 0; j < pot; j++) {
        if (numeroD >= pesos[j]) {
            bin[j] = '1';
            numeroD -= pesos[j];
        }
        else {
            bin[j] = '0';
        }
    }

    string numeroB = "";

    for (int k = 0; k < pot; k++) {
        numeroB += bin[k];
    }

    if (numeroB == "") {
        numeroB = "0";
    }

    return numeroB;
}

int main() {
    int numeroD;
    numeroD = pedirDatos(numeroD);
    cout << "El número " << numeroD << " es " << binario(numeroD) << " en binario \n";
    return 0;
}
