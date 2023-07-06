#include <iostream>
#include <ostream>
using namespace std;

class Error {};

template <typename T>
class Node {
    private:
    T elem;
    Node<T>* sigE;
    
    public:
    T e() {
        return elem;
    }

    Node <T>* sig() {
        return sigE;
    }

    void modE(const T& a) {
        elem = a;
    }

    void modS(Node<T>* s) {
        sigE = s;
    }
};


template <typename T>
class List {
    private:
    int longi;
    Node<T>* pri;
    Node<T>* ult;

    public:
    List() {
        longi = 0;
        pri = nullptr;
        ult = nullptr;
    }

    Node<T>* primero() {
        return pri;
    }

    int size() { // OKAY
        return longi;
    }

    void append(const T& a) { // OKAY
        if (longi == 0) {
            pri = new Node<T>;
            pri->modE(a);
            pri->modS(nullptr);
            ult = pri;
        }
        else {
            Node<T>* temp = ult;
            ult = new Node<T>;
            temp->modS(ult);
            ult->modE(a);
            ult->modS(nullptr);
        }
        longi++;
    }

    int count(const T& a) { // OKAY
        int cont = 0;
        Node<T>* aux = pri;
        for (int i = 0; i < longi - 1; i++) {
            if (aux->e() == a) {
                cont++;
            }
            aux = aux->sig();
        }
        if (longi > 0 && aux->e() == a) {
            cont++;
        }
        return cont;
    }

    bool min(T& a) { // OKAY
        bool resul;
        if (longi > 0) {
            a = pri->e();
            T temp;
            Node<T>* aux = pri->sig();
            for (int i = 0; i < longi - 1; i++) {
                temp = aux->e();
                if (temp < a) {
                    a = temp;
                }
                aux = aux->sig();
            }
            resul = true;
        }
        else {
            cout << "La lista está vacía\n";
            resul = false;
        }
        return resul;
    }

    bool max(T& a) { // OKAY
        bool resul;
        if (longi > 0) {
            a = pri->e();
            T temp;
            Node<T>* aux = pri->sig();
            for (int i = 0; i < longi - 1; i++) {
                temp = aux->e();
                if (temp > a) {
                    a = temp;
                }
                aux = aux->sig();
            }
            resul = true;
        }
        else {
            cout << "La lista está vacía\n";
            resul = false;
        }
        return resul;
    }

    bool insert(const T& a, const int& n) {
        bool resul;
        if (n >= 0 && n <= longi) {
            resul = true;
            if (n == longi || longi == 0) {
                this->append(a);
            }
            else {
                Node<T>* aux = pri;
                if (n == 0) {
                    pri = new Node<T>;
                    pri->modE(a);
                    pri->modS(aux);
                }
                else {
                    for (int i = 0; i < n - 1; i++) {
                        aux = aux->sig();
                    }
                    Node<T>* aux2 = aux->sig();
                    Node<T>* aux3 = new Node<T>;
                    aux3->modE(a);
                    aux3->modS(aux2);
                    aux->modS(aux3);
                }
                longi++;
            }
        }
        else {
            resul = false;
        }
        return resul;
    }
/*
    bool pop(const int& index, T& a) {
    }

    bool pop(T& a) {
    }
*/
};

template <typename T>
ostream& operator<<(ostream& os, List<T>& list) {
    Node<T>* aux = list.primero();
    os << "[";
    for (int i = 0; i < list.size(); i++) {
        if (i == list.size() - 1) {
            os << aux->e();
        }
        else {
            os << aux->e() << ", ";
        }
        aux = aux->sig();
    }
    os << "]\n";
    return os;
}
