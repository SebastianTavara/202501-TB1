#pragma once

#include "Nodo.h"
using namespace std;

template<class T>
class Pila {
private:
	Nodo<T>* tope;
	int numElements;
public:
	Pila() {
		tope = nullptr;
		numElements = 0;
	};
	void push(T v);
	void pop();
	void showElements();
	T top();
	bool estaVacia();
	Nodo<T>* getTope();
	void vaciar();
	int getNumElements();
};
//IMPLEKEMNTACION

template<class T>
void Pila<T>::push(T v) {
	if (estaVacia()) {
		tope = new Nodo<T>(v);
	}
	else {
		Nodo<T>* temp = new Nodo<T>(v, tope);
		tope = temp;
	}

	++numElements;

}
template<class T>
void Pila<T>::pop() {
	if (tope) {

		Nodo<T>* temp = tope;
		tope = tope->siguiente;
		delete temp;

		--numElements;

	}
	else {

		cout << "PILA VACIA\n";

	}
}

template<class T>
void Pila<T>::showElements()
{

	Nodo<T>* temp;
	temp = tope;

	while (temp != NULL) {

		cout << temp->dato << " <- ";
		temp = temp->siguiente;

	}
	cout << "nullptr";

}

template<class T>
T Pila<T>::top()
{
	if (tope) {

		return tope->dato;

	}
	else {

		cout << "PILA VACIA\n";
		return NULL;

	}
}

template<class T>
bool Pila<T>::estaVacia() {
	return (tope == nullptr);
}

template<class T>
Nodo<T>* Pila<T>::getTope()
{
	return tope;
}

template<class T>
void Pila<T>::vaciar() {
	while (tope != nullptr) {
		
		Nodo<T>* temp = tope;
		tope = tope->siguiente;
		delete temp;

	}

	numElements = 0;

}

template<class T>
int Pila<T>::getNumElements()
{

	return numElements;

}
