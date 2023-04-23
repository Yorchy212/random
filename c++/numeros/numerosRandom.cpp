#include <iostream>
#include <time.h>
using namespace std;

void pedirDatos(int& min, int& max, int& num) {
    cout << "Numero de valores aleatorios: ";
    cin >> num;
    cout << "Rango de tus numeros aleatorios: ";
    cin >> min >> max;
}

bool esta(const int v[], const int n, const int num) {
    for (int i = 0; i < n; i++) {
        if (v[i] == num) {
            return true;
        }
    }
    return false;
}

int main () {
    system("cls");
    time_t seed1 = time(nullptr);
    int min;
    time_t seed2 = time(nullptr);
    int max;
    time_t seed3 = time(nullptr);
    int num;
    time_t seed4 = time(nullptr);
    pedirDatos(min, max, num);
    time_t seed5 = time(nullptr);
    int i = 0;
    time_t seed6 = time(nullptr);
    int v[num];
    time_t seed7 = time(nullptr);
    srand(seed1 + seed2 + seed3 + seed4 + seed5 + seed6 + seed7);
    while (i < num) {
        int numero = min + rand() % (max - min + 1);
        if (!esta(v, num, numero)) {
            v[i] = numero;
            i++;
        }
    }

    for (int j = 0; j < num; j++) {
        cout << v[j] << " ";
    }
    return 0;
}