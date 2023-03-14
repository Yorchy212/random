#include <iostream>
#include <cctype>
using namespace std;
const unsigned NUM_MAX = 10000;

void permutar(double& a, double& b) {
    double aux = a;
    a = b;
    b = aux;
}

bool estaOrdenado(const double v[], const unsigned n) {
    bool ordenado = true;
    for (unsigned i = 1; i < n && ordenado; i++) {
        if (v[i] < v[i-1]) {
            ordenado = false;
        }
    }
    return ordenado;
}

void ordenar(double v[], const unsigned n) {
    while (!estaOrdenado(v, n)) {
        for (unsigned i = 1; i < n; i++) {
            if (v[i] < v[i-1]) {
                permutar(v[i], v[i-1]);
            }
        }
    }
}

double mediana(const double v[], const unsigned n) {
    if (n % 2 == 1) {
        return v[n/2];
    }
    else {
        unsigned medio = n / 2;
        return (v[medio] + v[medio-1]) / 2;
    }
}

unsigned contarVeces(const double v[], const unsigned n, const double a) {
    unsigned cuenta = 0;
    for (unsigned i = 0; i < n; i++) {
        if (v[i] == a) {
            cuenta++;
        }
    }
    return cuenta;
}

double media(const double v[], const unsigned n) {
    double suma = 0;
    for (unsigned i = 0; i < n; i++) {
        suma += v[i];
    }
    return suma / n;
}

bool esta(const double v[], const unsigned n, const double a) {
    for (unsigned i = 0; i < n; i++) {
        if (v[i] == a) {
            return true;
        }
    }
    return false;
}

unsigned numElementos(const double v[], const unsigned n) {
}

void moda(const double v[], const unsigned n, double u[]) {
}

int main () {
    system("cls");
    cout << "Escriba los numeros de su distribucion con una 'x' al final: ";
    string cadenas[NUM_MAX];
    bool acabado = false;
    unsigned numCifras = 0;
    for (unsigned i = 0; !acabado; i++) {
        cin >> cadenas[i];
        if (cadenas[i] == "x") {
            acabado = true;
        }
        else {
            numCifras++;
        }
    }
    double cifras[numCifras];
    for (unsigned j = 0; j < numCifras; j++) {
        cifras[j] = stod(cadenas[j]);
    }
    cout << endl << "1) Media" << endl << "2) Mediana" << endl << "3) Moda" << endl << "Elija lo que quiere calcular (0 = No, 1 = Si): ";
    unsigned XMedia, XMediana, XModa;
    cin >> XMedia >> XMediana;
    cout << endl;
    if (XMedia == 1) {
        cout << "La media de su distribucion de numeros es: " << media(cifras, numCifras) << endl;
    }
    if (XMediana == 1) {
        ordenar(cifras, numCifras);
        cout << "La mediana de su distribucion es: " << mediana(cifras, numCifras) << endl;
    }

    return 0;
}