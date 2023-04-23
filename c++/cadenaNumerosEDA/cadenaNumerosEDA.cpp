#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1000;

struct Numero {
    int num = -1;
    int frec = 0;
};

void annadir(Numero v[MAX], int a, int& ult) {
    v[ult+1].num = a;
    v[ult+1].frec++;
    ult++;
}

bool esta(Numero v[MAX], int c) {
    for (int i = 0; i < MAX; i++) {
        if (v[i].num == c) {
            return true;
        }
    }
    return false;
}

void sumarF(Numero v[MAX], int b) {
    bool encontrado = false;
    for (int i = 0; i < MAX && !encontrado; i++) {
        if (v[i].num == b) {
            v[i].frec++;
            encontrado = true;
        }
    }
}

int main() {
    Numero tabla[MAX];
    int ult = -1;
    system("cls");
    ifstream f("C:/Users/espia/OneDrive - Nanoengeineer/Jorge/Code/C++/datos.txt");
    if (f.is_open()) {
        int num;
        while (!f.eof()) {
            f >> num;
            f.ignore();
            if (esta(tabla,num)) {
                sumarF(tabla,num);
            }
            else {
                annadir(tabla,num,ult);
            }
        }
        for (int i = 0; i <= ult; i++) {
            cout << tabla[i].num << ", " << tabla[i].frec << endl;
        }
    }
    else {
        cout << "cagaste";
    }

    return 0;
}