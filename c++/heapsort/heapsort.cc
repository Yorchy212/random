#include <iostream>
using namespace std;

void heapsortAux(int array[], int begin, int end) {
    int max = 0;
    for (int i = begin+1; i < end; i++) {
        if (array[i] > array[max]) {
            max = i;
        }
    }

    int aux = array[max];
    array[max] = array[end-1];
    array[end-1] = aux;

    if (end - 1 > 0) {
        heapsortAux(array, 0, end-1);
    }
}

void heapsort(int array[], int n) {
    heapsortAux(array, 0, n);
}


void imprimir(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 10;
    int array[10] = {9,3,5,4,1,7,6,2,8};
    imprimir(array, n);
    heapsort(array, n);
    imprimir(array, n);
    return 0;
}