#pragma once

#include "Cola.h"
#include "Cancion.h"

class Historial {

private:
	Cola<Cancion*>* historial;
	int numHistorial;
public:
	Historial() {
	
		this->historial = new Cola<Cancion*>();
	
	}

	void agregar(Cancion* cancion) {
	
		historial->push(cancion);
		++numHistorial;

	}

	void mostrar() {
	
		if (historial->esVacia()) {
		
			cout << "\nAUN NO SE HA ESCUCHADO NADA";
			return;
		
		}

		historial->showElements();
	
	}

	void borrarHistorial() {
	

	
	}


};