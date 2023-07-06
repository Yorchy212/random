#include <iostream>
#include "list.hpp"

using namespace std;

int main() {
    List <int> lista;
    /*
    lista.append(2);
    lista.append(5);
    lista.append(1);
    lista.append(-4);
    lista.append(-1);
    int a;
    lista.min(a);
    cout << a << endl;
    lista.max(a);
    cout << a << endl;
    */
   cout << lista.count(4) << endl;
    return 0;
}
