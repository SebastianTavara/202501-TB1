#pragma once

#include "Nodo.h"
using namespace std;

template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = nullptr; };
	void push(T v);
	void pop();
	void showElements();
	T top();
	bool estaVacia();
};
//IMPLEKEMNTACION

template<class T>
void Pila<T>::push(T v) {
	if (estaVacia()) {
		tope = new Nodo<T>(v);
	}
	else {
		tope = new Nodo<T>(v, tope);
	}
}
template<class T>
void Pila<T>::pop() {
	if (tope) {

		Nodo<T>* temp = tope;
		tope = tope->siguiente;
		delete temp;

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

	while (!temp == NULL) {

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
