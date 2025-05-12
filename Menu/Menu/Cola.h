#pragma once

#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* frente;
	Nodo<T>* final;
public:
	Cola() {
		this->frente = NULL;
		this->final = NULL;
	}
	void push(T v);
	void pop();
	T front();
	bool esVacia();
	void showElements();
	T getDato();
	Nodo<T>* getCabeza();
	void Cola<T>::vaciar();

};

template<class T>
bool Cola<T>::esVacia() {
	return (frente == NULL);
}

template<class T>
void Cola<T>::showElements()
{
	Nodo<T>* temp;
	temp = frente;

	while (!temp == NULL) {

		cout << temp->dato << " <- ";
		temp = temp->siguiente;

	}
	cout << "nullptr";

}

template<class T>
void Cola<T>::vaciar() {
	while (frente != nullptr) {
		Nodo<T>* temp = frente;
		frente = frente->siguiente;
		delete temp;
	}
	final = nullptr;
}

template<class T>
T Cola<T>::getDato()
{
	return T();
}

template<class T>
Nodo<T>* Cola<T>::getCabeza()
{
	return frente;
}

template<class T>
T Cola<T>::front()
{
	T dato = frente->dato;
	if (frente)
		return dato;
	else {
		cout << "Cola vacía\n";
		return dato;
	}
}



template<class T>
void Cola<T>::push(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia()) {
		frente = nodo;
		final = frente;
	}
	else {

		final->siguiente = nodo;
		final = nodo;
	}
	nodo = NULL;
}

template<class T>
void Cola<T>::pop()
{

	if (frente) {
		Nodo<T>* temp = frente;
		frente = frente->siguiente;
		delete temp;
		if (!frente)
			final = nullptr;

	}
	else {

		cout << "COLA VACIA\n";

	}

}

