#pragma once
#include "Cancion.h"
#include "Autor.h"
#include <iostream>
using namespace std;

class Album {
private:
    string nombre;
    Lista<Cancion*>* cancionesdelAlbum;
    int cantAlbum; // numero de canciones agregadas

public:

    Album(string nombre) {
        this->nombre = nombre;
        this->cancionesdelAlbum = new Lista<Cancion*>();
        this->cantAlbum = 0;
    }

    string getNombre() {
        return nombre;
    }

    void agregarCancion(Cancion* cancion) {
        cancionesdelAlbum->agregar(cancion);
        ++cantAlbum;
    }

    void mostrarAlbum() {

        if (cantAlbum == 0) {
        
            cout << "\nNO HAY CANCIONES AGREGADAS";
            return;
        
        }

        cout << "Album: " << nombre << endl;
                
        Nodo<Cancion*>* actual = cancionesdelAlbum->getCabeza();

        while (actual != nullptr) {
            
            cout << "\nNombre: " << actual->dato->getNombre();
            cout << "\nAutor: " << actual->dato->getAutor();

            actual = actual->siguiente;
        }
    }

    void eliminarCancion();

    int getCantAlbum() {
    
        return cantAlbum;
    
    }

};
