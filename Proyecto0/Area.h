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
	PriorityQueue<Tiquete>* tiquetes;

	//atributos para estadisticas
	int tiquetesDispensados = 0;
	int tiquetesAtendidos = 0;
	time_t tiempoEsperaTotal;

public:
	Area(string codigoArea, string descripcionArea, int cantVentanillas) {
		this->codigoArea = codigoArea;
		this->descripcionArea = descripcionArea;
		ventanillas = new ArrayList<Ventanilla*>(cantVentanillas);
		tiquetes = new HeapPriorityQueue<Tiquete>();
		for (int i = 0; i < cantVentanillas; i++) {
			ventanillas->append(new Ventanilla(codigoArea + to_string(i + 1)));
		}
	}
	// evitar copias para prevenir errores de memoria
	Area(const Area& other) = delete;
	void operator=(const Area& other) = delete;

	~Area() {
		for (int i = 0; i < cantVentanillas; i++) {
			delete ventanillas->getElement();
			ventanillas->next();
		}
		delete ventanillas;
		delete tiquetes;
	}
	void agregarTiquete(Tiquete t) {
		tiquetes->insert(t, t.prioridadFinal);

	}
	void atenderTiquete(int numVentanilla) {
		if (tiquetes->isEmpty())
			throw runtime_error("No hay tiquetes por atender.");
		Tiquete* t = tiquetes->removeMin();
		ventanillas->goToPos(numVentanilla);
		Ventanilla v = ventanillas->getElement();
		v.atender(t);
		
		tiquetesAtendidos++;
	}
	void setCantVentanillas(int cantidad) {
		if (cantidad < 0)
			throw runtime_error("La cantidad de ventanillas no puede ser negativa.");
		ventanillas = new ArrayList<Ventanilla>(cantVentanillas);
	}
	long getTiempoEsperaTotal() {
		return tiempoEsperaTotal;
	}
};

