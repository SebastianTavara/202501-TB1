#pragma once
#include "Album.h"

class ListaAlbum {
private:
    Lista<Album*>* albumes;

public:
    ListaAlbum() {
        albumes = new Lista<Album*>();
    }

    void agregarAlbum(string nombreAlbum) {
        Album* nuevoAlbum = new Album(nombreAlbum);
        albumes->agregar(nuevoAlbum);
    }

    void mostrarAlbumes() {
        Nodo<Album*>* actual = albumes->getCabeza();
        int index = 1;

        if (!actual) {
            cout << "No hay albumes registrados.\n";
            return;
        }

        while (actual != nullptr) {
            cout << index << ". ";
            actual->dato->mostrarAlbum();  // Muestra solo el nombre del álbum
            cout << endl;
            actual = actual->siguiente;
            index++;
        }
    }

    Album* obtenerUltimoAlbum() {
        Nodo<Album*>* actual = albumes->getCabeza();
        if (!actual) return nullptr;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        return actual->dato;
    }

    Lista<Album*>* getAlbumes() {
        return albumes;
    }


    void modificarAlbumPorIndice(int indice, const string& nuevoNombre) {
        Nodo<Album*>* actual = albumes->getCabeza();
        int contador = 1;

        while (actual != nullptr && contador < indice) {
            actual = actual->siguiente;
            contador++;
        }

        if (actual != nullptr && contador == indice) {
            actual->dato->setNombre(nuevoNombre);  // Cambiar solo el nombre del álbum
            cout << "Nombre del álbum modificado correctamente.\n";
        }
        else {
            cout << "Índice inválido.\n";
        }
    }

    void eliminarAlbumPorIndice(int indice) {
        if (indice <= 0) {
            cout << "Indice invalido.\n";
            return;
        }

        Nodo<Album*>* actual = albumes->getCabeza();
        Nodo<Album*>* anterior = nullptr;
        int contador = 1;

        while (actual != nullptr && contador < indice) {
            anterior = actual;
            actual = actual->siguiente;
            contador++;
        }

        if (actual == nullptr) {
            cout << "Indice fuera de rango.\n";
            return;
        }

        if (anterior == nullptr) {
            // Eliminar el primer nodo (cabeza)
            albumes->setCabeza(actual->siguiente);
        }
        else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual->dato;  // Liberar la memoria del Album
        delete actual;        // Liberar el nodo
        cout << "Album eliminado correctamente.\n";
    }

    bool esVacia() {
    
        return (albumes->getCabeza() == nullptr);
    
    }

};
