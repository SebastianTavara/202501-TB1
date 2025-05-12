#pragma once

#include "Pila.h"
#include "Cancion.h"

// historial usando pila
class Historial {

private:
	Pila<Cancion*>* historial;
public:
	Historial() {
	
		this->historial = new Pila<Cancion*>();

	}

	void agregar(Cancion* cancion) {
	
		historial->push(cancion);

	}

	void mostrar() {
	
		if (historial->estaVacia()) {
		
			errorColor(); cout << "\nAUN NO SE HA ESCUCHADO NADA";
			return;
		
		}

		cout << "Numero de canciones vistas: " << historial->getNumElements();

		Nodo<Cancion*>* actual = historial->getTope();

		int count = 1;

		while (actual != nullptr) {
		
			cout << "\n\nNumero. " << count;
			cout << "\nCancion: " << actual->dato->getNombre();
			cout << "\nAutor: " << actual->dato->getAutor();
			cout<<"\nDuracion: " << actual->dato->getDuracion();
			cout << "\n";
			
			actual = actual->siguiente;
			++count;

		}

		cout << "\nDEBUG: tope actual = " << historial->top()->getNombre();
	
	}

	void borrarHistorial() {

		historial->vaciar();
	
	}

	Pila<Cancion*>* getPila() {
	
		return historial;
	
	}

};