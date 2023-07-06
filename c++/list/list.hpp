#include <iostream>
using namespace std;

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

    void modS(const Node<T> *s) {
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

    void append(const T& a) {
        if (longi == 0) {
            pri = new Node<T>;
            pri->modE(a);
            pri->modS(nullptr);
            ult = pri;
        }
        else {
            Node<T> temp = ult;
            ult = new Node<T>;
            temp->modS(ult);
            ult->modE(a);
            ult->modS(nullptr);
        }
        longi++;
    }

    T pop(const int& index) {
        Node<T>* aux;
        if (index == 0) {
            aux = pri->sig();
            delete pri;
            pri = aux;
            longi--;
        }
        else {
            aux = pri;
            for (int i = 0; i < index; i++) {
                aux = aux->sig();
            }
        }
    }

    T pop() {

    }

};
