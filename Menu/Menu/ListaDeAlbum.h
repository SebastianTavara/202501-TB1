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

        if (!actual) {
            cout << "No hay álbumes registrados.\n";
            return;
        }

        while (actual != nullptr) {

            actual->dato->mostrarAlbum();

            actual = actual->siguiente;
        }
    }
};
