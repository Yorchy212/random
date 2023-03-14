#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 15;
const int MAX_NUM = 5;

void crearVectorFila(int v[], const int mat[][MAX], const int numFila) {
    for (int i = 0; i < MAX; i++) {
        v[i] = mat[numFila][i];
    }
}

void crearVectorColumna(int v[], const int mat[][MAX], const int numColumna) {
    for (int i = 0; i < MAX; i++) {
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

void multMatrices(const int matA[][MAX], const int matB[][MAX], int matC[][MAX]) {
    int fila[MAX];
    int columna[MAX];
    for (int i = 0; i < MAX; i++) {
        crearVectorFila(fila, matA, i);
        for (int j = 0; j < MAX; j++) {
            crearVectorColumna(columna, matB, j);
            matC[i][j] = producto(fila, columna, MAX);
        }
    }
}

void generarMatriz(int mat[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat[i][j] = rand() % (MAX_NUM+1) - rand() % (MAX_NUM+1);
        }
    }
}

void escribirMatriz(int mat[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << setw(4) << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    srand(7);
    int matA[MAX][MAX];
    int matB[MAX][MAX];
    int matC[MAX][MAX];

    generarMatriz(matA);
    generarMatriz(matB);

    escribirMatriz(matA);
    cout << "\n";
    escribirMatriz(matB);
    cout << "\n";
    multMatrices(matA, matB, matC);
    escribirMatriz(matC);

    return 0;
}