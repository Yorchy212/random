#include <iostream>
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

    bool min(T& a) {
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

    void max(T& a) {
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

    void pop(const int& index, T& a) {
    }

    void pop(T& a) {
    }

};
