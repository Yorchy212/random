#include <iostream>
#include <memory>

using namespace std;

class Error {};

int sumarPares(int a, int b) {
    try {
        if (a % 2 != 0 || b % 2 != 0) {
            throw Error();
        }
        return a+b;
    }
    catch(Error e) {
        cout << "Los números tienen que ser pares\n";
    }
}

int main() {
    auto x = sumarPares(3,6);

    return 0;
}