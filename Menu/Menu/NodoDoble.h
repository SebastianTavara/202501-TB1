#pragma once

template <typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble<T>* siguiente;
    NodoDoble<T>* anterior;

    NodoDoble(T dato) {
        this->dato = dato;
        this->siguiente = nullptr;
        this->anterior = nullptr;
    }
};
