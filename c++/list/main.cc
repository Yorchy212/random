#include <iostream>
#include "list.hpp"

using namespace std;

int main() {
    List <int> lista;
    lista.append(2); // 0
    lista.append(5); // 1
    lista.append(1); // 2
    lista.append(-4); // 3
    lista.append(-1); // 4
    cout << lista;
    List <int> lista2;
    lista2.insert(777, 0);
    lista2.insert(888, 0);
    cout << lista2;
    return 0;
}

