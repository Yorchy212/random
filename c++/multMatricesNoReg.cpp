#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;
const int MAX_NUM = 5;

void leerMatriz(int mat[][MAX], int& nf, int& nc) {
    cout << "Escribe la dimensión de tu matriz: ";
    cin >> nf >> nc;
    for (int i = 0; i < nf; i++) {
        cout << "Fila " << i << ", mete " << nc << " números: ";
        for (int j = 0; j < nc; j++) {
            cin >> mat[i][j];
        }
    }
}

void escribirMatriz(int mat[][MAX], const int nf, const int nc) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            cout << setw(4) << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void crearVectorFila(int v[], const int mat[][MAX], const int numFila, const int nc) {
    for (int i = 0; i < nc; i++) {
        v[i] = mat[numFila][i];
    }
}

void crearVectorColumna(int v[], const int mat[][MAX], const int numColumna, const int nf) {
    for (int i = 0; i < nf; i++) {
        v[i] = mat[i][numColumna];
    }
}

int producto(const int v[], const int w[], const int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += (v[i] * w[i]);
    }
    return suma;
}

void multMatrices(const int matA[][MAX], const int matB[][MAX], int matC[][MAX], const int nfA, const int ncA,
                  const int nfB, const int ncB) {
    int fila[ncA];
    int columna[nfB];
    for (int i = 0; i < nfA; i++) {
        crearVectorFila(fila, matA, i, ncA);
        for (int j = 0; j < ncB; j++) {
            crearVectorColumna(columna, matB, j, nfB);
            matC[i][j] = producto(fila, columna, ncA);
        }
    }
}

void generarMatriz(int mat[][MAX], const int nf, const int nc) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            mat[i][j] = rand() % (MAX_NUM+1) - rand() % (MAX_NUM+1);
        }
    }
}

int main() {
    int matA[MAX][MAX];
    int matB[MAX][MAX];
    int matC[MAX][MAX];

    int nfA, ncA, nfB, ncB;
    nfA = 2;
    ncA = 2;
    nfB = 2;
    ncB = 3;
    // generarMatriz(matA, nfA, ncA);
    // generarMatriz(matB, nfB, ncB);
    cout << "Escribe los datos de la matriz A \n";
    leerMatriz(matA, nfA, ncA);
    cout << endl;
    cout << "Escribe los datos de la matriz B \n";
    leerMatriz(matB, nfB, ncB);
    escribirMatriz(matA, nfA, ncA);
    cout << endl;
    escribirMatriz(matB, nfB, ncB);
    cout << endl;
    multMatrices(matA, matB, matC, nfA, ncA, nfB, ncB);
    escribirMatriz(matC, nfA, ncB);

    return 0;
}
