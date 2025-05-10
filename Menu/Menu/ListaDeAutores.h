#pragma once
#include "Autor.h"

class ListaAutores{
private:
    Lista<Autor*>* autores;
public:

    ListaAutores() {
    
        this->autores = new Lista<Autor*>();

    }

    void agregarAutor(Autor* autor) {



        autores->agregar(autor);
    }

    void BuscarAutor(string nombreBuscado) {
        
        Nodo<Autor*>* actual = autores->getCabeza();
        bool encontrado = false;

        while (actual != nullptr) {
            if (actual->dato->getNombre() == nombreBuscado) { 
                actual->dato->mostrarDatos();  // Muestra los datos del autor
                encontrado = true;
                break;
            }
            actual = actual->siguiente;
        }

        if (!encontrado) {
            cout << "Autor no encontrado.\n";
        }
    }


    void agregarCancion(string nombreAutor, string nombreCancion, int duracion) {
        
        Nodo<Autor*>* actual = autores->getCabeza();  // Nodo con punteros
       
        while (actual != nullptr) {

            if (actual->dato->getNombre() == nombreAutor) {  // Usamos -> porque 'dato' es un puntero
                
                actual->dato->agregarCancion(nombreCancion, duracion);  // Agregar la canción al autor
                cout << "Canción agregada correctamente.\n";
                return;
            }

            actual = actual->siguiente;

        }

        cout << "Autor no encontrado.\n";
    }

    void mostrarCancionesPorAutor(string nombreAutor) {
        
        Nodo<Autor*>* actual = autores->getCabeza();
       
        while (actual != nullptr) {

            if (actual->dato->getNombre() == nombreAutor) { 
                actual->dato->mostrarCancionesdeAutor(); 
                return;
            }
            actual = actual->siguiente;
        }

        cout << "Autor no encontrado.\n";
    }

    Nodo<Autor*>* getCabeza() {
        return autores->getCabeza();
    }
};
