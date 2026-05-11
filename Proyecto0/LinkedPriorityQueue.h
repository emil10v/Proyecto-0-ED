#pragma once
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "stdexcept"
#include <iostream>

using std::cout;
using std::runtime_error;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue<E> {
private:
	LinkedQueue<E>* queues;
	int priorities;
	int size;

public:
	LinkedPriorityQueue(int priorities) {
		if (priorities < 1)
			throw runtime_error("Cantidad de prioridades debe ser positiva.");
		this->priorities = priorities;
		queues = new LinkedQueue<E>[priorities];
		size = 0;
	}
	~LinkedPriorityQueue() {
		delete[] queues;
	}
	void insert(E element, int priority) {
		if (priority < 0 || priority > priorities)
			throw runtime_error("Prioridad invalida.");
		queues[priority].enqueue(element);
		size++;
	}
	E min() {
		if (size == 0)
			throw runtime_error("Cola de prioridad vacía.");
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty())
				return queues[i].frontValue();
		}
	}
	E removeMin() {
		if (size == 0)
			throw runtime_error("Cola de prioridad vacía.");
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				size--;
				return queues[i].dequeue();
			}
		}
	}
	void clear() {
		for (int i = 0; i < priorities; i++)
			queues[i].clear();
		size = 0;
	}
	int getSize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void print() {
		cout << "TRIAGE - Cola de espera:" << endl;
		for (int i = 0; i < priorities; i++) {
			cout << i << ": ";
			queues[i].print();
		}
	}
};


