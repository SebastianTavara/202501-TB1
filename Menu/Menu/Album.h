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
    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
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

    void eliminarCancion() {
        if (cantAlbum == 0) {
            cout << "\nEl �lbum no tiene canciones.\n";
            return;
        }

        cout << "\nCanciones en el �lbum \"" << nombre << "\":\n";
        Nodo<Cancion*>* actual = cancionesdelAlbum->getCabeza();
        int index = 1;

        while (actual != nullptr) {
            cout << index << ". " << actual->dato->getNombre() << " - " << actual->dato->getAutor() << endl;
            actual = actual->siguiente;
            index++;
        }

        int opcion;
        cout << "\nIngrese el n�mero de la canci�n que desea quitar del �lbum: ";
        cin >> opcion;

        if (opcion < 1 || opcion > cantAlbum) {
            cout << "�ndice inv�lido.\n";
            return;
        }

        cancionesdelAlbum->eliminar(opcion - 1);   
        cantAlbum--;

        cout << "Canci�n removida del �lbum correctamente.\n";
    }

    int getCantAlbum() {
    
        return cantAlbum;
    
    }

    Lista<Cancion*>* getCanciones() {
        return cancionesdelAlbum;
    }


};
