#pragma once
#include "ArrayList.h"
#include "HeapPriorityQueue.h"
#include "Ventanilla.h"
#include <string>
#include <time.h>


using std::string;
using std::runtime_error;
using std::to_string;

class Area {
private:
	string codigoArea;
	string descripcionArea;
	int cantVentanillas;
	time_t tiempoEspera;
	List<Ventanilla*>* ventanillas;
	PriorityQueue<Tiquete*>* tiquetes;

	//atributos para estadisticas
	int tiquetesDispensados = 0;
	int tiquetesAtendidos = 0;
	time_t tiempoEsperaTotal;

public:
	Area(string codigoArea, string descripcionArea, int cantVentanillas) {
		this->codigoArea = codigoArea;
		this->descripcionArea = descripcionArea;
		ventanillas = new ArrayList<Ventanilla*>(cantVentanillas);
		tiquetes = new HeapPriorityQueue<Tiquete*>();
		for (int i = 0; i < cantVentanillas; i++) {
			ventanillas->append(new Ventanilla(codigoArea + to_string(i + 1)));
		}
	}
	// evitar copias para prevenir errores de memoria
	Area(const Area& other) = delete;
	void operator=(const Area& other) = delete;

	~Area() {
		ventanillas->goToStart();
		for (int i = 0; i < ventanillas->getSize(); i++) {
			Ventanilla* v = ventanillas->getElement();
			delete v;
			ventanillas->next();
		}
		delete ventanillas;
		while (!tiquetes->isEmpty()) {
			Tiquete* t =
			tiquetes->removeMin();
			delete t;
		}
		delete tiquetes;
	}
	void agregarTiquete(Tiquete* t) {
		tiquetes->insert(t, t->getPrioridadFinal());
		tiquetesDispensados++;
	}
	void atenderTiquete(int numVentanilla) {
		if (tiquetes->isEmpty())
			throw runtime_error("No hay tiquetes por atender.");
		ventanillas->goToPos(numVentanilla);
		Ventanilla* v = ventanillas->getElement();
		if (!v->estaLibre())
			throw runtime_error("Ventanilla no disponible");
		Tiquete* t = tiquetes->removeMin();
		v->atender(t);
		tiquetesAtendidos++;
		t->setHoraAtencion(time(0));
		tiempoEsperaTotal += t->getTiempoEspera();
	}
	void setCantVentanillas(int cantidad) {
		if (cantidad < 0)
			throw runtime_error("La cantidad de ventanillas no puede ser negativa.");
		ventanillas = new ArrayList<Ventanilla*>(cantVentanillas);
	}
	long getTiempoEsperaTotal() {
		return tiempoEsperaTotal;
	}
};

