#include <iostream>
#include <iomanip>
using namespace std;

unsigned long long aplicarCollatz(unsigned long long n) {
    if (n % 2 == 0) {
        n = n/2;
    }
    else {
        n = n*3+1;
    }
    return n;
}

void pedirDatos(int long long& n) {
    cout << "Escribe tu numero: ";
    cin >> n;
    while (n <= 0) {
        cout << "El numero tiene que ser mayor que 0: ";
        cin >> n;
    }
}

int main () {
    system("cls");
    int long long num;
    pedirDatos(num);
    unsigned long long saltoLinea = 0;
    cout << endl;
    unsigned separacion = 25;
    while (num >= 1) {
        cout << setw(separacion) << num;
        num = aplicarCollatz(num);
        saltoLinea++;
        if (saltoLinea % 8 == 0) {
            cout << endl << endl;
        }
        if (num == 1) {
            cout << setw(separacion) << "1";
            num = 0;
        }
    }
    return 0;
}