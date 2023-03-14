#include <iostream>
#include <iomanip>
using namespace std;

const unsigned DIM = 10;

void leerMatriz(int mat[][DIM], unsigned& nf, unsigned& nc) {
    cout << "Introduzca el numero de filas y columnas (>0): ";
    cin >> nf >> nc;

    unsigned i = 1;
    unsigned j = 0;
    unsigned k = 0;

    while (i <= nf) {
        cout << "Fila " << i << ": " << "Introduzca " << nc << " enteros: ";
        while (k <= (nc - 1)) {
            cin >> mat[j][k];
            k++;
        }
        i++;
        j++;
        k = 0;
    }
}

void escribirMatriz(int mat[][DIM], unsigned nf, unsigned nc) {
    unsigned i = 0;
    unsigned j = 0;
    while (i <= (nf - 1)) {
        cout << setw(4) << mat[i][j];
        j++;
        if (j == nc) {
            cout << endl;
            i++;
            j = 0;
        }
    }
}

void escribirTraspuesta(int mat[][DIM], unsigned nf, unsigned nc) {
    unsigned i = 0;
    unsigned j = 0;

    while (i <= (nc - 1)) {
        cout << setw(4) << mat[j][i];
        j++;
        if (j == nf) {
            cout << endl;
            i++;
            j = 0;
        }
    }
}

bool esSimetrica(int mat[][DIM], unsigned nf, unsigned nc) {
    bool deMomentoIgual = true;
    if (nf != nc) {
        deMomentoIgual = false;
    }
    else {
        unsigned i = 0;
        unsigned j = 1;
        while (deMomentoIgual && i < nc) {
            while (i < nc) {
                if (mat[i][j] != mat[j][i]) {
                    deMomentoIgual = false;
                }
                j++;
                if (j == nc) {
                    i++;
                    j = 0;
                }
            }
        }
    }
    return deMomentoIgual;
}

int main () {
    unsigned nfa, nca, nfb, ncb;
    int mat[DIM][DIM];
    int matb[DIM][DIM];
    int matc[DIM}[DIM];
    bool deMomentoIgual;

    leerMatriz(mat, nfa, nca);
    cout << endl;
    escribirMatriz(mat, nfa, nca);
    cout << endl;
    escribirTraspuesta(mat, nfa, nca);
    cout << endl;
    cout << esSimetrica(mat, nfa, nca);
    cout << endl;
    leerMatriz(matb, nfb, ncb);
    cout << endl;
    escribirMatriz(matb, nfb, ncb);
    return 0;
}
