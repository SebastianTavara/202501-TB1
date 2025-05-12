#pragma once
#include "NodoDoble.h"

template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;
    int numElementos;

public:
    ListaDoble() {
        cabeza = nullptr;
        cola = nullptr;
        numElementos = 0;
    }

    void agregarAlFinal(T dato) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(dato);

        if (!cabeza) {
            cabeza = cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }

        numElementos++;
    }

    void mostrarAdelante() {
        NodoDoble<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    void mostrarAtras() {
        NodoDoble<T>* actual = cola;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->anterior;
        }
        std::cout << std::endl;
    }

    int getNumElementos() {
        return numElementos;
    }

    void agregar(T dato) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
        if (!cabeza) {
            cabeza = cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
        ++numElementos;
    }


    NodoDoble<T>* getCabeza() {
        return cabeza;
    }

    NodoDoble<T>* getCola() {
        return cola;
    }


};
