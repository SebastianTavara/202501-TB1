#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Controladora.h"
using namespace System;
using namespace std;


class Usuario {
public:
    string nombre;
    string contrasena;

    Usuario(string _nombre, string _contrasena) {
        nombre = _nombre;
        contrasena = _contrasena;
    }
};

class Dat {
public:
    Usuario* usuario;
    Dat* siguiente;

    Dat(Usuario* _usuario) {
        usuario = _usuario;
        siguiente = nullptr;
    }
};

class HashTable {
private:
    static const int TAM = 10;
    Dat* tabla[TAM];

    int funcionHash(string nombre) {
        int suma = 0;
        for (char c : nombre)
            suma += c;
        return suma % TAM;
    }

public:
    HashTable() {
        for (int i = 0; i < TAM; ++i)
            tabla[i] = nullptr;
    }

    void registrarUsuario(string nombre, string contrasena) {
        int indice = funcionHash(nombre);

        // Crear usuario dinámicamente
        Usuario* nuevoUsuario = new Usuario(nombre, contrasena);
        Dat* nuevoDat = new Dat(nuevoUsuario);

        // Insertar al inicio de la lista (encadenamiento)
        nuevoDat->siguiente = tabla[indice];
        tabla[indice] = nuevoDat;

        gotoxy(46, 28); cout << "Usuario " << nombre << " registrado" << ".\n";
        _getch();
    }
    /*
    void mostrarTabla() {
        cout << "\n--- Tabla Hash ---\n";
        for (int i = 0; i < TAM; ++i) {
            cout << "[" << i << "]: ";
            Dat* actual = tabla[i];
            while (actual != nullptr) {
                cout << "(" << actual->usuario->nombre << ", " << actual->usuario->contrasena << ") -> ";
                actual = actual->siguiente;
            }
            cout << "nullptr\n";
        }
    }
    */

    bool verificarAcceso(string nombre, string contrasena) {
        int indice = funcionHash(nombre);
        Dat* actual = tabla[indice];

        while (actual != nullptr) {
            if (actual->usuario->nombre == nombre) {
                if (actual->usuario->contrasena == contrasena) {
                    gotoxy(46, 28); cout << "Bienvenido " << nombre << "!\n";
                    _getch();
                    return true;
                }
                else {
                    gotoxy(46, 28); cout << "Contrasena incorrecta para '" << nombre << "'.\n";
                    _getch();
                    return false;
                }
            }
            actual = actual->siguiente;
        }

        gotoxy(46, 28); cout << "Usuario '" << nombre << "' no encontrado.\n";
        _getch();
        return false;
    }

};


int Hash() {
    Controladora sistema;
    HashTable tablaUsuarios;
    char op;
    int opcion;
    string nombre, contrasena;

    do {
        system("cls");
        gotoxy(52, 3); color(BRIGHT_CYAN); cout << "Spotify Premium";
        gotoxy(46, 17); cout << "1. Sign up" << endl;
        gotoxy(46, 18); cout << "2. Log in" << endl;
        gotoxy(46, 19); cout << "0. Salir" << endl;
        gotoxy(46, 20); opcion = _getch(); // Captura la tecla presionada

        // Convertir el carácter a entero
        if (opcion >= '0' && opcion <= '2') {
            opcion -= '0'; // Convertir el carácter a su valor numérico
        }
        else {
            opcion = -1; // Opción inválida
        }
        switch (opcion) {
        case 1:
            gotoxy(46, 22); cout << "Nombre de usuario: ";
            gotoxy(46, 23); cin >> nombre;
            gotoxy(46, 24); cout << "Contrasena: ";
            // Ocultar la entrada de la contraseña
            contrasena.clear();
            char ch;
            while ((ch = _getch()) != '\r') { // Espera hasta que se presione Enter
                if (ch == '\b') { // Maneja el retroceso
                    if (!contrasena.empty()) {
                        contrasena.pop_back(); // Elimina el último carácter
                        cout << "\b \b"; // Borra el carácter en la consola
                    }
                }
                else {
                    contrasena.push_back(ch); // Agrega el carácter a la contraseña
                    cout << '*'; // Muestra un asterisco en su lugar
                }
            }
            tablaUsuarios.registrarUsuario(nombre, contrasena);
            break;
        case 2:
            gotoxy(46, 22); cout << "Usuario: ";
            gotoxy(46, 23); cin >> nombre;
            gotoxy(46, 24); cout << "Contrasena: ";
            contrasena.clear();
            while ((ch = _getch()) != '\r') {
                if (ch == '\b') {
                    if (!contrasena.empty()) {
                        contrasena.pop_back();
                        cout << "\b \b";
                    }
                }
                else {
                    contrasena.push_back(ch);
                    cout << '*';
                }
            }
            if (tablaUsuarios.verificarAcceso(nombre, contrasena)) {
                sistema.menu();
            }
            break;
        case 0:
            gotoxy(46, 26); cout << "Saliendo del programa.\n";
            break;
        default:
            gotoxy(46, 26); cout << "Invalido.\n";
        }
    } while (opcion != 0);

    return 0;
}