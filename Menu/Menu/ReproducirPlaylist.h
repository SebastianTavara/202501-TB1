#pragma once
#include <conio.h>      
#include <thread>       
#include <chrono>       
#include "Historial.h"
#include "ListaDoble.h"
#include "ListaDeAlbum.h"
#include "utilidadesLogos.h"
class ReproducirPlaylist {
private:
    ListaDoble<Cancion*>* listaReproduccion;
    ListaAlbum* listaAlbumes;
    Introduccion intro;
public:
    ReproducirPlaylist(ListaAlbum* listaAlbumes) {
        this->listaAlbumes = listaAlbumes;
        listaReproduccion = new ListaDoble<Cancion*>();
    }

    void seleccionarAlbumYReproducir(Historial*& historial) {
        Nodo<Album*>* actual = listaAlbumes->getAlbumes()->getCabeza();

        if (!actual) {
            gotoxy(44, 11); cout << "No hay albumes disponibles.\n";
            return;
        }

        // Mostrar álbumes con índice
        int index = 1;
        gotoxy(1, 1); cout << "\n== Lista de Albumes ==\n";
        while (actual != nullptr) {
            cout << index << ".- " << actual->dato->getNombre() << " (" << actual->dato->getCantAlbum() << " canciones)\n";
            actual = actual->siguiente;
            ++index;
        }

        // Selección
        int eleccion;
        gotoxy(25, 1); cout << "\nIngrese el numero del album que desea reproducir: ";
        cin >> eleccion;

        actual = listaAlbumes->getAlbumes()->getCabeza();
        int contador = 1;
        while (actual && contador < eleccion) {
            actual = actual->siguiente;
            contador++;
        }

        if (!actual) {
        cout << "Seleccion invalida.\n";
            return;
        }

        Album* albumSeleccionado = actual->dato;

        // Limpiar listaReproduccion previa
        delete listaReproduccion;
        listaReproduccion = new ListaDoble<Cancion*>();

        // Copiar canciones del álbum seleccionado
        Nodo<Cancion*>* temp = albumSeleccionado->getCanciones()->getCabeza();
        while (temp != nullptr) {
            listaReproduccion->agregar(temp->dato);
            temp = temp->siguiente;
        }

        if (listaReproduccion->getCabeza() == nullptr) {
            gotoxy(45, 12); cout << "\nEste album no tiene canciones.";
            return;
        }

        // Reproducción
        NodoDoble<Cancion*>* cancionActual = listaReproduccion->getCabeza();
        char tecla;

        historial->agregar(cancionActual->dato);

        cout << "\nReproduciendo (←: anterior | →: siguiente | ESC: salir)\n";

        do {
            system("cls"); // Limpia pantalla
            intro.computadora();
            gotoxy(46, 17); cout << "|| Reproduciendo || "<< endl;
            _sleep(300);
            gotoxy(46, 19); cout << "Album: " << albumSeleccionado->getNombre() << endl;
            _sleep(100);
            gotoxy(46, 20); cout << "Autor: " << cancionActual->dato->getAutor() << endl;
            _sleep(100);
            gotoxy(46, 21); cout << "Canción: " << cancionActual->dato->getNombre() << endl;
            _sleep(100);
            gotoxy(46, 22); cout << "Duración: " << cancionActual->dato->getDuracion() << "s\n";
            _sleep(100);
            gotoxy(46, 25); cout << "<==     ||     ==> ";
            _sleep(100);
            gotoxy(46, 35); cout << "Esc = salir";

            // Espera teclax
            tecla = _getch();

            if (tecla == -32) { // Flecha especial
                tecla = _getch();
                if (tecla == 75 && cancionActual->anterior != nullptr) { // ←
                    
                    cancionActual = cancionActual->anterior;
                    // agregar al historial
                    historial->agregar(cancionActual->dato);
                }
                else if (tecla == 77 && cancionActual->siguiente != nullptr) { // →
                    
                    cancionActual = cancionActual->siguiente;
                    // agregar al historial                    
                    historial->agregar(cancionActual->dato);
                }
            }

        } while (tecla != 27); // ESC

        gotoxy(45, 28); cout << "\nSaliendo de la reproduccion...\n";
    }
};
