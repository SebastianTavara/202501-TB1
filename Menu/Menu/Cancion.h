#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cancion {
private:
    string nombre;
    string autor;
    int duracion;

public:

    Cancion(string nombre, string autor, int duracion) {
        this->nombre = nombre;
        this->autor = autor;
        this->duracion = duracion;
    }

    string getNombre() {
        return nombre;
    }

    string getAutor() {
        return autor;
    }

    int getDuracion() {
    
        return duracion;
    
    }

    void mostrar() {
        cout << "\nNombre: " << nombre;
        cout << "\nAutor: " << autor;
        cout << "\nDuracion(s): " << duracion;

    }
};
