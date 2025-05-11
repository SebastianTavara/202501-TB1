#pragma once

#include <conio.h>
#include "upc.h"
#include "Autor.h"
#include "Cancion.h"
#include "Album.h"
#include "ListaDeCanciones.h"
#include "ListaDeAutores.h"
#include "ListaDeAlbum.h"

// aun en modificacion

class Controladora {
private:
    ListaCanciones canciones;
    ListaAutores autores;
    ListaAlbum albumes;

public:
    Controladora() {
    
    
    }

    // Solo la parte grafica sin texto
    void interfaz() {
    
        for (int k = 0; k < 2; ++k) {

            for (int i = 0; i < 70; ++i) {

                gotoxy(25 + i, 6 + k * 18); color(DARK_GREEN); cout << "-";
            }

            gotoxy(25, 6 + k * 18); cout << "+";
            gotoxy(60, 6 + k * 18); cout << "+";
            gotoxy(94, 6 + k * 18); cout << "+";
        }
        clearColor();

    }

    void interfazTextoMain() {

        // titulo
        gotoxy(52, 3); color(BRIGHT_CYAN); cout << "Spotify Premium";

        clearColor();
        //opciones

        // 1ra Columna

        gotoxy(26, 9);  cout << "1. Mostrar todas las canciones";
        gotoxy(26, 11); cout << "2. Agregar cancion a cola";
        gotoxy(26, 12); cout << "   reproduccion";
        gotoxy(26, 14); cout << "3. Reproducir cola";
        gotoxy(26, 16); cout << "4. Ver historial";
        gotoxy(26, 18); cout << "5. Crear Album/Playlist";

        //2da columna

        gotoxy(61, 9); cout << "6. Reproducir Playlist";
        gotoxy(61, 11); cout << "7. Mostrar opciones para canciones";
        gotoxy(61, 13); cout << "8. Mostrar opciones para autores";
        gotoxy(61, 15); cout << "9. Motrar opciones para albumes";
        gotoxy(61, 17); cout << "ESC. Salir";

    }

    void interfazTextoCanciones() {
    
        // title
        gotoxy(52, 3); color(BRIGHT_CYAN); cout << "Spotify Premium";
        gotoxy(48, 4); color(BRIGHT_CYAN); cout << "Opciones para canciones";

        clearColor();

        //Unica Columna
        // el eje x de gotoxy es la mitad del ancho
        // de pantalla menos la mitad del size de string
        gotoxy(45, 9); cout << "1. Mostrar todas las canciones";
        gotoxy(44, 11); cout << "2. Buscar por nombre de cancion";
        gotoxy(50, 13); cout << "3. Eliminar cancion";
        gotoxy(51, 15); cout << "4. Agregar cancion";
        gotoxy(50, 17); cout << "5. Reproducir cancion";
        gotoxy(55, 19); cout << "ESC. Salir";
    
    }

    void interfazTextoAutores() {
    
        // title
        gotoxy(52, 3); color(BRIGHT_CYAN); cout << "Spotify Premium";
        gotoxy(49, 4); color(BRIGHT_CYAN); cout << "Opciones para autores";

        clearColor();

        //Unica Columna
        // el eje x de gotoxy es la mitad del ancho
        // de pantalla menos la mitad del size de string
        gotoxy(46, 9); cout << "1. Mostrar todos los autores";
        gotoxy(45, 11); cout << "2. Buscar por nombre del autor";
        gotoxy(31, 13); cout << "3. Eliminar autor (elimina todas las canciones asociadas)";
        gotoxy(52, 15); cout << "4. Agregar autor";
        gotoxy(47, 17); cout << "5. Agregar Cancion a autor";
        gotoxy(55, 19); cout << "ESC. Salir";

    
    }

    void opcionesCanciones() {
    

        bool salir = false;

        while (!salir) {
            
            clear();

            interfaz();

            interfazTextoCanciones();

            int tecla = _getch();

            clear();

            switch (tecla)
            {
            case '1':

                canciones.mostrarCanciones();
                system("pause>0");

                break;

            case '2': {

                setCursorVisible(true);

                string titulo = " ";

                cout << "Ingrese titulo de la cancion: ";
                cin >> titulo;

                canciones.buscarporTitulo(titulo);

                setCursorVisible(false);

                system("pause>0");

                break;
            }
            case '3': {
                
                setCursorVisible(true);

                canciones.mostrarCanciones();

                int index = 0;

                cout << "\n\nIngrese index a eliminar: ";
                cin >> index;

                // nombre de autor a eliminar cancion
                string nombreAutor = canciones.getAutorXIndex(index);
                // nombre de la cancion eliminada
                string nombreCancion = canciones.getCancionXIndex(index);
                
                autores.borrarCancionXAutorXCancion(nombreAutor, nombreCancion);

                canciones.eliminarCancionXIndex(index);

                
                setCursorVisible(false);

                system("pause>0");

                break;
            }
            case '4': {

                setCursorVisible(true);

                string titulo = " ";
                string autor = " ";
                int duracion = 0;

                cout << "\nIngrese el nombre de la cancion (sin espacios): ";
                cin >> titulo;

                cout << "\nIngrese el autor de la cancion (sin espacios): ";
                cin >> autor;

                cout << "\nIngrese la duracion de la cancion en segundos: ";
                cin >> duracion;

                canciones.agregarCancion(titulo, autor, duracion);

                autores.agregarAutor(autor);

                autores.agregarCancion(autor, titulo, duracion);

                cout << "\nCancion agregada correctamente";

                setCursorVisible(false);

                system("pause>0");

                break;
            }

            case '5':

                canciones.mostrarCanciones();

                // reproduce cancion;

                break;

            case 27:

                salir = true;
                break;

            default:
                break;
            }
        }

    }

    void opcionesAutores() {
    
        bool salir = false;

        while (!salir) {

            clear();

            interfaz();

            interfazTextoAutores();

            int tecla = _getch();

            clear();

            switch (tecla)
            {
            case '1':

                autores.mostrarAutores();
                system("pause>0");

                break;

            case '2': {

                setCursorVisible(true);

                string nombre = " ";

                cout << "Ingrese nombre del autor: ";
                cin >> nombre;

                autores.BuscarAutor(nombre);

                setCursorVisible(false);

                system("pause>0");

                break;
            }
            case '3': {

                setCursorVisible(true);

                autores.mostrarAutores();

                int index = 0;
                
                cout << "\n\nSe eliminara todos las canciones referenciadas al autor";
                cout << "\nIngrese index a eliminar: ";
                
                cin >> index;

                
                string nombre = " ";

                autores.borrarAutorXIndex(index, nombre);

                canciones.borrarCancionesxAutor(nombre);

                setCursorVisible(false);

                system("pause>0");

                break;
            }
            case '4': {

                setCursorVisible(true);

                string nombreAutor = " ";
                
                cout << "\nIngrese el nombre del autor (sin espacios): ";
                cin >> nombreAutor;

                autores.agregarAutor(nombreAutor);

                cout << "\nAutor agregado correctamente";

                setCursorVisible(false);

                system("pause>0");

                break;
            }

            case '5': { // agregar cancion a autor

                // primero muestra todos los autores
                autores.mostrarAutores();

                string nombreAutor = " ";
                string nombreCancion = " ";
                int duracion = 0;


                cout << "\nIngrese el nombre de la cancion (sin espacios): ";
                cin >> nombreCancion;

                cout << "\nIngrese el autor de la cancion (sin espacios): ";
                cin >> nombreAutor;

                cout << "\nIngrese la duracion de la cancion en segundos: ";
                cin >> duracion;

                // agrega a la lista de autores
                autores.agregarCancion(nombreAutor, nombreCancion, duracion);
                
                // agrega a la lista de canciones
                canciones.agregarCancion(nombreCancion, nombreAutor, duracion);

                system("pause>0");

                break;
            }
            case 27:

                salir = true;
                break;

            default:
                break;
            }
        }
    
    }

    void menu() {

        bool salir = false;

        while (!salir) {

            clear();
            interfaz();
            interfazTextoMain();

            int tecla = _getch();
            clear();
            switch (tecla)
            {
            case '1': //Mostrar todas las canciones

                canciones.mostrarCanciones();
                system("pause>0");
                break;

            case '2'://Agregar cancion a cola de reproduccion

                break;

            case '3': //Reproducir cola


                break;

            case '4': //Ver historial



                break;

            case '5':

                //Ver historial

                break;

            case '6': {//Crear Album/Playlist
                string nombreAlbum = " ";
                cout << "\nIngrese nombre del album (obvie espacios): ";
                cin >> nombreAlbum;

                albumes.agregarAlbum(nombreAlbum);

                cout << "\nAlbum agregado correctamente";

                break;
            }
            case '7':

                //mostrar opciones para canciones

                opcionesCanciones();

                break;

            case '8':

                //Mostrar opciones para autores

                opcionesAutores();

                break;

            case '9': // mostrar opciones para albumes

                break;

            case 27: // salir con escape
                clear();
                gotoxy(45, 14); color(BRIGHT_BLUE); cout << "Gracias por usar nuestra app!";
                clearColor();
                //gotoxy(0, 29);
                salir = true;

                break;
            default:
                break;
            }

        }

    }


    //void ingresarDatosAutor() {
    //    string nombre, nacionalidad;
    //    int edad;
    //
    //    cout << "Ingrese nombre del autor: ";
    //    getline(cin >> ws, nombre);
    //    cout << "Ingrese edad: ";
    //    cin >> edad;
    //    cout << "Ingrese nacionalidad: ";
    //    getline(cin >> ws, nacionalidad);
    //
    //    Autor* nuevo = new Autor(nombre, edad, nacionalidad);
    //    //listaAutores.agregarAutor(nuevo);        // Solo se pasa como argumento
    //
    //    cout << "Autor agregado con exito.\n";
    //}

    //void mostrarDatosAutor() {
    //    string nombre;
    //    cout << "Ingrese el nombre del autor: ";
    //    getline(cin >> ws, nombre);
    //
    //    //Autor* autor = listaAutores.buscarAutor(nombre);
    //    if (autor != nullptr) {
    //        autor->mostrarDatos();
    //    }
    //    else {
    //        cout << "Autor no encontrado.\n";
    //    }
    //}
    //
    //void ingresarCancion() {
    //    string nombreAutor, nombreCancion;
    //    cout << "Ingrese el nombre del autor de la cancion: ";
    //    getline(cin >> ws, nombreAutor);
    //
    //    //Autor* autor = listaAutores.buscarAutor(nombreAutor);
    //    if (autor != nullptr) {
    //        cout << "Ingrese el nombre de la cancion: ";
    //        getline(cin >> ws, nombreCancion);  
    //        autor->agregarCancion(nombreCancion);
    //        cout << "Cancion agregada correctamente.\n";
    //    }
    //    else {
    //        cout << "Autor no encontrado.\n";
    //    }
    //}
    //
    //void mostrarCanciones() {
    //    Nodo<Autor*>* actual = listaAutores.getCabeza();  // Nota: Autor* en lugar de Autor
    //    if (!actual) {
    //        cout << "No hay autores registrados.\n";
    //        return;
    //    }
    //
    //    while (actual != nullptr) {
    //        actual->dato->mostrarCanciones();  // Usamos -> porque actual->dato es un puntero
    //        actual = actual->siguiente;
    //    }
    //}
};
