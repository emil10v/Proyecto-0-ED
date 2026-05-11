// Archivo: Queue.h
// Autor: Hecho en clase
//
// Descripción:
// Interfaz abstracta para una cola genérica.
// Define las operaciones fundamentales de una estructura FIFO
// (First In, First Out).
//
// Funcionalidades principales:
// - Encolar y desencolar elementos.
// - Consultar el frente de la cola.
// - Limpiar y consultar estado.
//
// Sirve como base para futuras implementaciones de colas

#pragma once

template <typename E>
class Queue {
public:
	Queue() {}
	Queue(const Queue<E>&) = delete;
	void operator=(const Queue<E>&) = delete;
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual E frontValue() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
};