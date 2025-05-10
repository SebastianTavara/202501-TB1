#pragma once
#include "Nodo.h"

// Lista genérica
template <typename T>
class Lista {
protected:
    Nodo<T>* cabeza;

public:
    Lista() {
        cabeza = nullptr;
    }

    void agregar(T dato) {

        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (!cabeza) {
            cabeza = nuevo;
        }

        else {

            Nodo<T>* temp = cabeza;

            while (temp->siguiente) {

                temp = temp->siguiente;

            }

            temp->siguiente = nuevo;
        
        }
    }

    Nodo<T>* getCabeza() {
        return cabeza;
    }
};
