#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cancion {
private:
    string nombre;
    string autor;

public:
    Cancion(){
        this->nombre = " ";
        this->autor = " ";
    }

    Cancion(string nombre, string autor) {
        this->nombre = nombre;
        this->autor = autor;
    }

    string getNombre() {
        return nombre;
    }

    string getAutor() {
        return autor;
    }

    void mostrar() {
        cout << nombre;
    }
};
