// Archivo: PriorityQueue.h
// Autor: Hecho en clase
//
// Descripción:
// Interfaz abstracta para una cola de prioridad genérica.
// Define las operaciones básicas que debe implementar cualquier
// estructura de cola priorizada.
//
// Funcionalidades principales:
// - Insertar elementos con prioridad.
// - Obtener y eliminar el elemento de mayor prioridad.
// - Consultar tamaño y estado.
// - Limpiar y mostrar elementos.
//
// Esta interfaz es implementada por estructuras específicas como
// HeapPriorityQueue en nuestro caso.

#pragma once
template <typename E>
class PriorityQueue {
public:
	PriorityQueue() {}
	PriorityQueue(const PriorityQueue<E>&) = delete;
	void operator=(const PriorityQueue<E>&) = delete;
	virtual ~PriorityQueue() {}
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};