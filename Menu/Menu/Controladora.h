#pragma once
#include "Autor.h"
#include "Cancion.h"
#include "Album.h"
class Controladora {
private:
    ListaAutores listaAutores;
    ControladoraAlbum controlAlbum;

public:
    Controladora() : controlAlbum(&listaAutores) {}  // Pasamos la referencia de autores al controlador de álbumes

    void menu() {
        int opcion;

        do {
            cout << "\n===== MENU PRINCIPAL =====" << endl;
            cout << "1. Ingresar Datos Autor" << endl;
            cout << "2. Mostrar Datos de un Autor" << endl;
            cout << "3. Ingresar Cancion" << endl;
            cout << "4. Mostrar Todas las Canciones" << endl;
            cout << "5. Generar Album" << endl;
            cout << "6. Mostrar Canciones Favoritas (Albums)" << endl;
            cout << "7. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                ingresarDatosAutor();
                break;
            case 2:
                mostrarDatosAutor();
                break;
            case 3:
                ingresarCancion();
                break;
            case 4:
                mostrarCanciones();
                break;
            case 5:
                controlAlbum.agregarAlbum();
                break;
            case 6:
                controlAlbum.mostrarAlbumes();
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
            }

        } while (opcion != 7);
    }

private:
    void ingresarDatosAutor() {
        string nombre, nacionalidad;
        int edad;

        cout << "Ingrese nombre del autor: ";
        getline(cin >> ws, nombre);
        cout << "Ingrese edad: ";
        cin >> edad;
        cout << "Ingrese nacionalidad: ";
        getline(cin >> ws, nacionalidad);

        Autor* nuevo = new Autor(nombre, edad, nacionalidad);
        listaAutores.agregarAutor(nuevo);        // Solo se pasa como argumento

        cout << "Autor agregado con exito.\n";
    }

    void mostrarDatosAutor() {
        string nombre;
        cout << "Ingrese el nombre del autor: ";
        getline(cin >> ws, nombre);

        Autor* autor = listaAutores.buscarAutor(nombre);
        if (autor != nullptr) {
            autor->mostrarDatos();
        }
        else {
            cout << "Autor no encontrado.\n";
        }
    }

    void ingresarCancion() {
        string nombreAutor, nombreCancion;
        cout << "Ingrese el nombre del autor de la cancion: ";
        getline(cin >> ws, nombreAutor);

        Autor* autor = listaAutores.buscarAutor(nombreAutor);
        if (autor != nullptr) {
            cout << "Ingrese el nombre de la cancion: ";
            getline(cin >> ws, nombreCancion);  
            autor->agregarCancion(nombreCancion);
            cout << "Cancion agregada correctamente.\n";
        }
        else {
            cout << "Autor no encontrado.\n";
        }
    }

    void mostrarCanciones() {
        Nodo<Autor*>* actual = listaAutores.getCabeza();  // Nota: Autor* en lugar de Autor
        if (!actual) {
            cout << "No hay autores registrados.\n";
            return;
        }

        while (actual != nullptr) {
            actual->dato->mostrarCanciones();  // Usamos -> porque actual->dato es un puntero
            actual = actual->siguiente;
        }
    }
};
