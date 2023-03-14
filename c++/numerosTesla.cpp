#include <iostream>
using namespace std;

bool tieneUnaCifra(unsigned n) {
    return n % 10 == n;
}

unsigned sumaCifras(unsigned n) {
    if (n < 10) {
        return n;
    }
    else {
        return n % 10 + sumaCifras(n/10);
    }
}

unsigned transformar(unsigned n) {
    while (!tieneUnaCifra(n)) {
        n = sumaCifras(n);
    }
    return n;
}

void pedirDatos(unsigned& n, unsigned& lim1, unsigned& lim2) {
    cout << "Escribe el numero y el rango a evaluar: ";
    cin >> n >> lim1 >> lim2;
    while (n <= 0 || n > 9) {
        cout << "El numero tiene que estar entre 1 y 9: ";
        cin >> n >> lim1 >> lim2;
    }
    while (lim1 >= lim2 || lim1 <= 0 || lim2 <= 0) {
        cout << "Los limites tienen que ser positivos: ";
        cin >> n >> lim1 >> lim2;
    }
    cout << endl;
}

int main () {
    system("cls");
    unsigned n, lim1, lim2;
    pedirDatos(n, lim1, lim2);
    unsigned saltoLinea = 0;
    for (unsigned i = lim1; i <= lim2; i++) {
        cout << transformar(n*i) << "   ";
        saltoLinea++;
        if (saltoLinea % 65 == 0) {
            cout << endl;
        }
    }
    return 0;
}