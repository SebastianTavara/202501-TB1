#pragma once

#include "Cola.h"
#include "Cancion.h"
#include "upc.h"

class ColaReproduccion {

private:
	Cola<Cancion*>* cola;
public:

	ColaReproduccion(){

		cola = new Cola<Cancion*>();

	}

	void agregar(Cancion* cancion) {
	
		cola->push(cancion);
	
	}

	void mostrar() {
	
		if (cola->esVacia()) {
		
			errorColor(); cout << "NO HAY CANCIONES AGREGADAS";

			return;
		
		}


		Nodo<Cancion*>* actual = cola->getCabeza();

		int count = 1;

		while (actual != nullptr) {
		
			cout << "\nNumero Cancion: " << count;
			actual->dato->mostrar();
			cout << "\n";

			actual = actual->siguiente;
			++count;

		}
	}

	void eliminarColaReproduccion() {
	
		cola->vaciar();
	
	}

};