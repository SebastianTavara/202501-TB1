#pragma once
#include <iostream>
#include <string>
#include "Cancion.h"
#include "Lista.h"

using namespace std;

class Autor {
private:
    string nombre;
    Lista<Cancion*>* cancionesdelAutor; 
    int numCanciones;

public:

    Autor(string nombre){

        this->nombre = nombre;
        cancionesdelAutor = new Lista<Cancion*>();
        this->numCanciones = 0;

    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    void agregarCancion(string nombreCancion, int duracion) {
        Cancion* nueva = new Cancion(nombreCancion, nombre, duracion);  // Usa el nombre del autor
        cancionesdelAutor->agregar(nueva);

        ++numCanciones;

    }

    void mostrarCancionesdeAutor() {
        cout << "Autor: " << nombre << " | Canciones: ";
        Nodo<Cancion*>* actual = cancionesdelAutor->getCabeza();
        while (actual != nullptr) {
            actual->dato->mostrar();
            if (actual->siguiente != nullptr) cout << " | ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void mostrarDatos() {
        
        cout << "Nombre del Autor: " << nombre << " | #Canciones: " << numCanciones << endl;
    }

    int getNumCanciones() {
    
        return numCanciones;
    
    }

    Lista<Cancion*>* getCanciones() {
        return cancionesdelAutor;
    }

    void borrarXNombreCancion(string nombreCancion) {
    
        Nodo<Cancion*>* temp = cancionesdelAutor->getCabeza();
        
        int count = 1;

        while (temp != nullptr) {
        
            if (temp->dato->getNombre() == nombreCancion) {
            
                cancionesdelAutor->eliminar(count);
                
                --numCanciones;

                return;
            }
            ++count;
            temp = temp->siguiente;
        
        }
    
    }

};

