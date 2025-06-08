#pragma once

#include "Lista.h"
#include "Cancion.h"

//lista de canciones usando lista enlazada simple
// lista general de canciones agregadas
class ListaCanciones {
private:
	Lista<Cancion*>* canciones;
	int numCanciones;
public:
	ListaCanciones() {
	
		this->canciones = new Lista<Cancion*>();
		this->numCanciones = 0;
	}

	void agregarCancion(string titulo, string autor, int duracion) {
	
		Cancion* temp = new Cancion(titulo, autor, duracion);

		canciones->agregar(temp);
		++numCanciones;
	}

	void eliminarCancionXIndex(int index) {
	
		if (index > numCanciones || index < 1) {
		
			errorColor(); cout << "\nIndice incorrecto";
			clearColor();

			return;
		
		}

		canciones->eliminar(index);

		errorColor(); cout << "\nEliminado Correctamente";
	
	}

	void mostrarCanciones() {
	
		int count = 1;

		if (canciones->getCabeza() == nullptr) {
		
			errorColor(); cout << "\nNO SE A AGREGADO CANCIONES";
			return;
		}

		Nodo<Cancion*>* actual = canciones->getCabeza();

		while (actual != nullptr) {
		
			color(BRIGHT_CYAN); cout << "\nCancion num " << count;
			clearColor();
			cout<<"\nNombre: " << actual->dato->getNombre();
			cout << "\nAutor: " << actual->dato->getAutor();
			cout << "\nDuracion(s): " << actual->dato->getDuracion();
			cout << "\n";
			actual = actual->siguiente;
			++count;
		}
	
	}
	void buscarporTitulo(string titulo) {
	
		Nodo<Cancion*>*	temporal = canciones->getCabeza();

		while (temporal != nullptr)
		{
			if (temporal->dato->getNombre() == titulo)
			{
				cout << "RESULTADO: " << endl;
				cout << " AUTOR: " << temporal->dato->getAutor() << endl;
				cout << " CANCION: " << temporal->dato->getNombre() << endl << endl;

				return;
			}
			
			temporal = temporal->siguiente;


		}
		
		cout << "\nCancion no encontrada";

	}
	
	void borrarCancionesxAutor(string autor) {
	
		Nodo<Cancion*>* temp = canciones->getCabeza();

		int count = 1;

		while (temp != nullptr) {
		
			if (temp->dato->getAutor() == autor) {
			
				canciones->eliminar(count);
			
			}

			++count;
			temp = temp->siguiente;
		
		}

	}

	string getAutorXIndex(int index) {
	
		if (index > numCanciones || index < 1) {

			errorColor(); cout << "\nIndice incorrecto";
			clearColor();

			return 0;

		}

		Nodo<Cancion*>* actual = canciones->getCabeza();

		int count = 1;

		while (count <= index) {
		
			if (count == index) {
			
				return actual->dato->getAutor();
			
			}
		
			actual = actual->siguiente;

			++count;

		}
	
	}

	// Devuleve un string
	string getCancionXIndex(int index) {
	
		if (index > numCanciones || index < 1) {

			errorColor(); cout << "\nIndice incorrecto";
			clearColor();

			return 0;

		}

		Nodo<Cancion*>* actual = canciones->getCabeza();

		int count = 1;

		while (count <= index) {

			if (count == index) {

				return actual->dato->getNombre();

			}

			actual = actual->siguiente;

			++count;

		}
	
	}

	// devuelve un objeto Cancion
	Cancion* getCancionPorIndex(int index) {
		if (index < 0 || index >= numCanciones) {
			errorColor(); cout << "\nÍndice incorrecto\n"; clearColor();
			return nullptr;
		}

		Nodo<Cancion*>* actual = canciones->getCabeza();
		int count = 0;

		while (actual != nullptr) {
			if (count == index) {
				return actual->dato;
			}
			actual = actual->siguiente;
			++count;
		}

		return nullptr; // Por si acaso no se encuentra (aunque no debería pasar)
	}

};