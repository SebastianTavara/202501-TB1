#pragma once
#include "Cancion.h"
#include "Autor.h"
#include <iostream>
using namespace std;

class Album {
private:
    string nombre;
    Lista<Cancion> canciones;

public:
    Album() : nombre("SinNombre") {}  // Constructor por defecto

    Album(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() const {
        return nombre;
    }

    void agregarCancion(Cancion& cancion) {
        canciones.agregar(cancion);
    }

    void mostrarAlbum() {
        cout << "Album: " << nombre << endl;

        // Mostrar canciones agrupadas por autor
        // Suponemos que no están ordenadas, así que las agrupamos manualmente
        Lista<string> autoresProcesados;

        Nodo<Cancion>* actual = canciones.getCabeza();
        while (actual != nullptr) {
            string autor = actual->dato.getAutor();

            // Verificar si ya mostramos este autor
            Nodo<string>* nodoAutor = autoresProcesados.getCabeza();
            bool yaMostrado = false;
            while (nodoAutor != nullptr) {
                if (nodoAutor->dato == autor) {
                    yaMostrado = true;
                    break;
                }
                nodoAutor = nodoAutor->siguiente;
            }

            if (!yaMostrado) {
                cout << "Autor: " << autor << " | Canciones: ";
                Nodo<Cancion>* actualInterno = canciones.getCabeza();
                bool primero = true;
                while (actualInterno != nullptr) {
                    if (actualInterno->dato.getAutor() == autor) {
                        if (!primero) cout << " | ";
                        actualInterno->dato.mostrar();
                        primero = false;
                    }
                    actualInterno = actualInterno->siguiente;
                }
                cout << endl;
                autoresProcesados.agregar(autor);  // Marcar como mostrado
            }

            actual = actual->siguiente;
        }
    }
};


class ControladoraAlbum {
private:
    Lista<Album> listaAlbumes;
    ListaAutores* listaAutores;  // Apunta a la lista externa

public:
    ControladoraAlbum(ListaAutores* autores) {
        listaAutores = autores;
    }

    void agregarAlbum() {
        string nombreAlbum;
        cout << "Ingrese el nombre del nuevo álbum: ";
        getline(cin >> ws, nombreAlbum);

        Album nuevoAlbum(nombreAlbum);

        // Mostrar todos los autores y canciones enumeradas
        Nodo<Autor*>* nodoAutor = listaAutores->getCabeza();  // Usar getCabeza() de ListaAutores
        int index = 1;
        Lista<Cancion> opciones;
        while (nodoAutor != nullptr) {
            Nodo<Cancion>* nodoCancion = nodoAutor->dato->getCanciones().getCabeza();  // Acceder a las canciones con '->'
            while (nodoCancion != nullptr) {
                cout << index << ") " << nodoCancion->dato.getAutor()
                    << " | " << nodoCancion->dato.getNombre() << endl;
                opciones.agregar(nodoCancion->dato);
                index++;
                nodoCancion = nodoCancion->siguiente;
            }
            nodoAutor = nodoAutor->siguiente;
        }

        if (index == 1) {
            cout << "No hay canciones disponibles para agregar.\n";
            return;
        }

        int eleccion;
        cout << "Ingrese el número de la canción que desea agregar al álbum: ";
        cin >> eleccion;

        if (eleccion <= 0 || eleccion >= index) {
            cout << "Selección inválida.\n";
            return;
        }

        // Buscar la canción elegida en la lista de opciones
        Nodo<Cancion>* actual = opciones.getCabeza();
        for (int i = 1; i < eleccion && actual != nullptr; i++) {
            actual = actual->siguiente;
        }

        if (actual != nullptr) {
            nuevoAlbum.agregarCancion(actual->dato);
            listaAlbumes.agregar(nuevoAlbum);
            cout << "Canción agregada al álbum correctamente.\n";
        }
    }

    void mostrarAlbumes() {
        Nodo<Album>* actual = listaAlbumes.getCabeza();
        if (!actual) {
            cout << "No hay álbumes registrados.\n";
            return;
        }

        while (actual != nullptr) {
            actual->dato.mostrarAlbum();
            actual = actual->siguiente;
        }
    }
};
