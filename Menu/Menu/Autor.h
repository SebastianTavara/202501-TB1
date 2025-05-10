#pragma once
#include <iostream>
#include <string>
#include "Cancion.h"
#include "Lista.h"

using namespace std;

class Autor {
private:
    string nombre;
    int edad;
    string nacionalidad;
    int numAlbumes;
    Lista<Cancion*>* cancionesdelAutor; 

public:

    Autor(string nombre, int edad, string nacionalidad, int numAlbumes){

        this->nombre = nombre;
        this->edad = edad;
        this->nacionalidad = nacionalidad;
        this->numAlbumes = numAlbumes;
        cancionesdelAutor = new Lista<Cancion*>();

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
        // numero de canciones
        int numCanciones = 0;
        Nodo<Cancion*>* actual = cancionesdelAutor->getCabeza();
        while (actual != nullptr) {
            numCanciones++;
            actual = actual->siguiente;
        }

        cout << "Nombre: " << nombre << " | Edad: " << edad << " | Nacionalidad: " << nacionalidad
            << " | #Albumes: " << numAlbumes << " | #Canciones: " << numCanciones << endl;
    }

    Lista<Cancion*>* getCanciones() {
        return cancionesdelAutor;
    }

};

