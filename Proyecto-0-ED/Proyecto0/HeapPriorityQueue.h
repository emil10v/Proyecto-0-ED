// Archivo: HeapPriorityQueue.h
// Autor: Hecho en clase
//
// Descripción:
// Implementación de una cola de prioridad utilizando un MinHeap.
// Esta clase almacena elementos junto con una prioridad mediante
// objetos Pair, permitiendo acceder rápidamente al elemento con
// mayor prioridad (menor valor numérico).
//
// Funcionalidades principales:
// - Insertar elementos con prioridad.
// - Obtener el elemento de mayor prioridad.
// - Eliminar el elemento prioritario.
// - Consultar tamaño y estado de la cola.
// - Mostrar elementos almacenados.
//
// Esta estructura es utilizada en el sistema para administrar
// los tiquetes pendientes de atención.

#pragma once

#include<stdexcept>
#include <iostream>
#include "PriorityQueue.h"
#include "Pair.h"
#include "MinHeap.h"

using std::runtime_error;
using std::cout;
using std::endl;

template<typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
	MinHeap<Pair<int, E>>* pairs;

public:
	HeapPriorityQueue(int max = DEFAULT_MAX) {
		pairs = new MinHeap<Pair<int, E>>(max);
	}
	~HeapPriorityQueue() {
		delete pairs;
	}
	void insert(E element, int priority) {
		Pair<int, E> p(priority, element);
		pairs->insert(p);
	}
	E min() {
		Pair<int, E> p = pairs->first();
		return p.value;
	}
	E removeMin() {
		Pair<int, E> p = pairs->removeFirst();
		return p.value;
	}
	virtual void clear() {
		pairs->clear();
	}
	int getSize() {
		return pairs->getSize();
	}
	bool isEmpty() {
		return pairs->isEmpty();
	}
	virtual void print() {
		pairs->print();
	}

};