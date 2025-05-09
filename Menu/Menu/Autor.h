#pragma once
#include <iostream>
#include <string>
#include "Cancion.h"
#include "Lista.h"

using namespace std;

// Autor actualizado para usar una lista de Cancion
class Autor {
private:
    string nombre;
    int edad;
    string nacionalidad;
    int numAlbumes;
    Lista<Cancion> canciones;  // Ahora es lista de objetos Cancion

public:
    Autor() : nombre(""), edad(0), nacionalidad(""), numAlbumes(0) {}

    Autor(string nombre, int edad, string nacionalidad, int numAlbumes = 0)
        : nombre(nombre), edad(edad), nacionalidad(nacionalidad), numAlbumes(numAlbumes) {
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    void agregarCancion(const string& nombreCancion) {
        Cancion nueva(nombreCancion, nombre);  // Usa el nombre del autor
        canciones.agregar(nueva);
    }

    void mostrarCanciones() {
        cout << "Autor: " << nombre << " | Canciones: ";
        Nodo<Cancion>* actual = canciones.getCabeza();
        while (actual != nullptr) {
            actual->dato.mostrar();
            if (actual->siguiente != nullptr) cout << " | ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void mostrarDatos() {
        // Contamos cuántas canciones tiene
        int numCanciones = 0;
        Nodo<Cancion>* actual = canciones.getCabeza();
        while (actual != nullptr) {
            numCanciones++;
            actual = actual->siguiente;
        }

        cout << "Nombre: " << nombre << " | Edad: " << edad << " | Nacionalidad: " << nacionalidad
            << " | #Albumes: " << numAlbumes << " | #Canciones: " << numCanciones << endl;
    }

    Lista<Cancion>& getCanciones() {
        return canciones;
    }

};

class ListaAutores : public Lista<Autor> {
private:
    Lista<Autor*> autores;
public:
    void agregarAutor(Autor* autor) {
        autores.agregar(autor);  // Esto debería funcionar
    }

    void mostrarAutor() {
        string nombreBuscado;
        cout << "Ingrese el nombre del autor que desea buscar: ";
        getline(cin >> ws, nombreBuscado);

        Nodo<Autor*>* actual = autores.getCabeza();  // Nodo con punteros
        bool encontrado = false;

        while (actual != nullptr) {
            if (actual->dato->getNombre() == nombreBuscado) {  // Usamos -> porque 'dato' es un puntero
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


    void agregarCancion() {
        string nombreAutor, nombreCancion;
        cout << "Ingrese el nombre del autor: ";
        getline(cin >> ws, nombreAutor);

        Nodo<Autor*>* actual = autores.getCabeza();  // Nodo con punteros
        while (actual != nullptr) {
            if (actual->dato->getNombre() == nombreAutor) {  // Usamos -> porque 'dato' es un puntero
                cout << "Ingrese el nombre de la canción: ";
                getline(cin >> ws, nombreCancion);
                actual->dato->agregarCancion(nombreCancion);  // Agregar la canción al autor
                cout << "Canción agregada correctamente.\n";
                return;
            }
            actual = actual->siguiente;
        }

        cout << "Autor no encontrado.\n";
    }

    void mostrarCancionesPorAutor() {
        string nombreAutor;
        cout << "Ingrese el nombre del autor: ";
        getline(cin >> ws, nombreAutor);

        Nodo<Autor*>* actual = autores.getCabeza();  // Nodo con punteros
        while (actual != nullptr) {
            if (actual->dato->getNombre() == nombreAutor) {  // Usamos -> porque 'dato' es un puntero
                actual->dato->mostrarCanciones();  // Mostrar canciones del autor
                return;
            }
            actual = actual->siguiente;
        }

        cout << "Autor no encontrado.\n";
    }

    Autor* buscarAutor(const string& nombre) {
        Nodo<Autor*>* actual = autores.getCabeza();  // Nodo con punteros
        while (actual != nullptr) {
            if (actual->dato->getNombre() == nombre) {
                return actual->dato;  // Devolvemos el puntero al autor encontrado
            }
            actual = actual->siguiente;
        }
        return nullptr;  // Si no se encuentra el autor, retornamos nullptr
    }

    // Obtener la cabeza de la lista (de punteros a Autor)
    Nodo<Autor*>* getCabeza() {
        return autores.getCabeza();  // Usamos la cabeza de la lista de punteros
    }
};

