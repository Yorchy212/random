#include <iostream>
using namespace std;

string romano(int numero) {
    struct par {
        string s;
        int i;
    };

    par nums[13];
    string str[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int ints[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int j = 0; j < 13; j++) {
        nums[j].s = str[j];
        nums[j].i = ints[j];
    }
    
    string resul = "";
    int cociente;
    for (int j = 0; j < 13 && numero > 0; j++) {
        if (numero >= nums[j].i) {
            cociente = numero / nums[j].i;
            numero = numero % nums[j].i;
            for (int k = 0; k < cociente; k++) {
                resul += nums[j].s;
            }
        }
    }

    return resul;
}

int main(int argc, char* argv[]) {
    int numero = atoi(argv[1]);
    cout << "El número " << numero << " en romano es " << romano(numero) << endl;
}