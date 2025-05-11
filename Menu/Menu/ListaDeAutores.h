#pragma once
#include "Autor.h"

class ListaAutores{
private:
    Lista<Autor*>* autores;
    int numAutores;

public:

    ListaAutores() {
    
        this->autores = new Lista<Autor*>();
        this->numAutores = 0;
    }

    void mostrarAutores() {
    
        int count = 1;

        Nodo<Autor*>* actual = autores->getCabeza();

        while (actual != nullptr) {
        
            cout << "\nAutor Num " << count;
            cout << "\nNombre de autor: " << actual->dato->getNombre();
            cout << "\nNumero de canciones hechas: " << actual->dato->getNumCanciones();
            cout << "\n";

            actual = actual->siguiente;
            ++count;
        }
    
    }

    void borrarCancionXAutorXCancion(string nombreAutor, string nombreCancion) {
    
        Nodo<Autor*>* temp = autores->getCabeza();

        while (temp != nullptr) {
        
            if (nombreAutor == temp->dato->getNombre()) {

                temp->dato->borrarXNombreCancion(nombreCancion);
                
                return;

            }

            temp = temp->siguiente;
        
        }

        errorColor(); cout << "\nNombre de cancion o nombre de autor incorectos";
        clearColor();
    
    }

    void agregarAutor(string nombre) {

        // verifica si no se ha creado uno de igual nombre
        Nodo<Autor*>* temp = autores->getCabeza();

        // verifica si es que autores esta vacia
        if (!(autores->getCabeza() == nullptr)) {

            while (temp != nullptr) {

                if (temp->dato->getNombre() == nombre) {


                    // retorna si encuentra otro con el mimso nombre
                    return;

                }


                temp = temp->siguiente;

            }
        }

        Autor* nuevo = new Autor(nombre);

        autores->agregar(nuevo);

        ++numAutores;
    }

    void BuscarAutor(string nombreBuscado) {
        
        Nodo<Autor*>* actual = autores->getCabeza();
        bool encontrado = false;

        while (actual != nullptr) {
            
            if (actual->dato->getNombre() == nombreBuscado) { 
                
                actual->dato->mostrarDatos();  // Muestra los datos del autor
                
                return;
            
            }
            actual = actual->siguiente;
        }

        errorColor(); cout << "\nAutor no encontrado";
        clearColor;
    }


    void agregarCancion(string nombreAutor, string nombreCancion, int duracion) {
        
        Nodo<Autor*>* actual = autores->getCabeza();  // Nodo con punteros
       
        while (actual != nullptr) {

            if (actual->dato->getNombre() == nombreAutor) { 

                actual->dato->agregarCancion(nombreCancion, duracion);  
                cout << "Canción agregada correctamente.\n";
                return;
            }

            actual = actual->siguiente;

        }

        errorColor(); cout << "Autor no encontrado.\n";
        clearColor();
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

        
        errorColor(); cout << "Autor no encontrado.\n";
        clearColor();
    }

    // se borrara el autor con sus canciones
    void borrarAutorXIndex(int index, string& nombreAutor) {

        if (index > numAutores || index < 1) {

            errorColor(); cout << "\nIndice incorrecto";
            clearColor();

            return;

        }

        int count = 1;

        Nodo<Autor*>* temp = autores->getCabeza();

        autores->eliminar(index);
        errorColor(); cout << "\nEliminado Correctamente";
    
    }

    Nodo<Autor*>* getAutorxIndice(int index) {
    

        if (index > numAutores || index < 1) {

            return false;

        }

        int count = 1;

        Nodo<Autor*>* temp = autores->getCabeza();
        

        while (count <= numAutores) {
        
            if (index == count) {
            
                break;
            
            }

            temp = temp->siguiente;
        
        }
    
        return temp;

    }

    Nodo<Autor*>* getCabeza() {
        return autores->getCabeza();
    }
};
