#pragma once

#include "Lista.h"
#include "Cancion.h"

//lista de canciones usando lista enlazada simple
// lista general de canciones agregadas
class ListaCanciones {
private:
	Lista<Cancion*>* canciones;
public:
	ListaCanciones() {
	
		this->canciones = new Lista<Cancion*>();
	
	}

	void agregarCancion(Cancion* cancion);
	void buscarporTitulo(string titulo);
	void buscarporAutor(string autor);
	void mostrarCanciones();
	void eliminarCancion(string titulo);
	int contarCanciones();

};