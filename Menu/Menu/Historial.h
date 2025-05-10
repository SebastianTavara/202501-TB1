#pragma once

#include "Pila.h"
#include "Cancion.h"

// historial usando pila
class Historial {

private:
	Pila<Cancion*>* historial;
	int numHistorial;
public:
	Historial() {
	
		this->historial = new Pila<Cancion*>();
	
	}

	void agregar(Cancion* cancion) {
	
		historial->push(cancion);
		++numHistorial;

	}

	void mostrar() {
	
		if (historial->estaVacia()) {
		
			cout << "\nAUN NO SE HA ESCUCHADO NADA";
			return;
		
		}

		historial->showElements();
	
	}

	void borrarHistorial() {
	

	
	}


};