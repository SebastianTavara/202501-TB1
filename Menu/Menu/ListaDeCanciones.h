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

	void mostrarCanciones() {
	
		if (canciones->getCabeza() == nullptr) {
		
			cout << "\nNO SE A AGREGADO CANCIONES";
			return;
		}

		Nodo<Cancion*>* actual = canciones->getCabeza();

		while (actual != nullptr) {
		
			cout<<"\nNombre: " << actual->dato->getNombre();
			cout << "\nAutor: " << actual->dato->getAutor();
			actual = actual->siguiente;
		}
	
	}
	//void agregarCancion(Cancion* cancion);
	void buscarporTitulo(string titulo) {}
	//void buscarporAutor(string autor);
	//void eliminarCancion(string titulo);
	//int contarCanciones();

};