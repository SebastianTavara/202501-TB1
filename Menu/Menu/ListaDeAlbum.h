#pragma once
#include "Album.h"

class ListadeAlbum {
private:
    Lista<Album*>* albumes;

public:
    ListadeAlbum() {

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
