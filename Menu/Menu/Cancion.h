#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cancion {
private:
    string nombre;
    string autor;

public:
    Cancion() : nombre(""), autor("") {}

    Cancion(string nombre, string autor) {
        this->nombre = nombre;
        this->autor = autor;
    }

    string getNombre() const {
        return nombre;
    }

    string getAutor() const {
        return autor;
    }

    void mostrar() const {
        cout << nombre;
    }
};
