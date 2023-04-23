#include <iostream>
using namespace std;

unsigned fibonacci(const unsigned n) {
    if (n < 2) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    system("cls");
    unsigned n = 100;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}
