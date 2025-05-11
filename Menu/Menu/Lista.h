#pragma once
#include "Nodo.h"

// Lista genérica
template <typename T>
class Lista {
protected:
    Nodo<T>* cabeza;
    int numElements;

public:
    Lista() {
        cabeza = nullptr;
        this->numElements = 0;
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

        ++numElements;
    }

    void eliminar(int index) {
    

        // si la lista esta vacia o index fuera de rango
        if (cabeza == nullptr || index < 1 || index>numElements) {
        
            return;
        
        }

        //eliminar cabeza
        if (index == 1) {
        
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            --numElements;
            return;
        
        }

        Nodo<T>* actual = cabeza;
        
        for (int i = 1; i < index - 1; ++i) {
        
            actual = actual->siguiente;
        }

        Nodo<T>* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
        --numElements;

    
    }

    Nodo<T>* getCabeza() {
        return cabeza;
    }

    int getNumElements() {
    
        return numElements;
    
    }

};
