//Archivo: Area.h
// Autores: Emilio
// Descripción:
// Esta clase representa un área de atención dentro del sistema de colas.
// Cada área administra sus propias ventanillas y una cola de tiquetes
// priorizada mediante un heap de prioridad. Además, se encarga de llevar
// estadísticas relacionadas con la atención de clientes, como cantidad de
// tiquetes dispensados, atendidos y tiempo promedio de espera.
//
// Funcionalidades principales:
// - Agregar tiquetes a la cola del área.
// - Atender tiquetes desde una ventanilla específica.
// - Liberar ventanillas luego de finalizar una atención.
// - Administrar dinámicamente la cantidad de ventanillas.
// - Mostrar el estado de las ventanillas y la cola de tiquetes.
// - Calcular estadísticas del área.
//
// También incluye manejo manual de memoria dinámica para evitar fugas
// de memoria al destruir ventanillas y tiquetes almacenados.
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
	double tiempoEsperaTotal = 0;

public:
	Area(string codigoArea, string descripcionArea, int cantVentanillas) {
		this->codigoArea = codigoArea;
		this->descripcionArea = descripcionArea;
		this->cantVentanillas = cantVentanillas;
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
		clearTiquetes();
		delete tiquetes;
	}
	void clearTiquetes() {
		while (!tiquetes->isEmpty()) {
			Tiquete* t = tiquetes->removeMin();
			delete t;
		}
		tiquetesDispensados = 0;
		tiquetesAtendidos = 0;
		tiempoEsperaTotal = 0;
	}
	void agregarTiquete(Tiquete* t) {
		tiquetes->insert(t, t->getPrioridadFinal());
		tiquetesDispensados++;
	}
	void atenderTiquete(int numVentanilla) {
		if (tiquetes->isEmpty())
			throw runtime_error("No hay tiquetes por atender.");
		if (numVentanilla < 0 || numVentanilla >= cantVentanillas)
			throw runtime_error("Numero de ventanilla invalido");
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
		ventanillas->goToStart();
		for (int i = 0; i < ventanillas->getSize(); ++i) {
			Ventanilla* v = ventanillas->getElement();
			delete v;
			ventanillas->next();
		}
		delete ventanillas;
		cantVentanillas = cantidad;
		ventanillas = new ArrayList<Ventanilla*>(cantVentanillas);
		for (int i = 0; i < cantVentanillas; ++i) {
			ventanillas->append(new Ventanilla(codigoArea + to_string(i + 1)));
		}
	}
	List<Ventanilla*>* getVentanillas() {
		return ventanillas;
	}
	string getCodigoArea() {
		return codigoArea;
	}
	int getCantVentanillas() {
		return cantVentanillas;
	}
	double getPromedioEspera() {
		if (tiquetesAtendidos == 0)
			return 0;
		return (double)tiempoEsperaTotal / tiquetesAtendidos;
	}
	int getTiquetesDispensados() {
		return tiquetesDispensados;
	}
	int getTiquetesAtendidos() {
		return tiquetesAtendidos;
	}
	void liberarVentanilla(int numVenanilla) {
		if (numVenanilla < 0 || numVenanilla >= cantVentanillas)
			throw runtime_error("Numero de ventanilla invalido");
		ventanillas->goToPos(numVenanilla);
		Ventanilla* v = ventanillas->getElement();
		if (v->estaLibre())
			throw runtime_error("Ventanilla ya esta libre");
		delete v->getAtendido();
		v->liberar();
	}
	string getColaTiquetes() {
		if (tiquetes->isEmpty()) return "[]";
		string res = "[";
		int sizeTiquetes = tiquetes->getSize();
		Tiquete** temp = new Tiquete* [sizeTiquetes];
		for (int i = 0; i < sizeTiquetes; i++) {
			temp[i] = tiquetes->removeMin();
			res += temp[i]->getCodigo();
			if (i < sizeTiquetes - 1) res += ", ";
		}
		for (int i = 0; i < sizeTiquetes; i++) {
			tiquetes->insert(temp[i], temp[i]->getPrioridadFinal());
		}
		delete[] temp;
		return res + "]";
	}
	string mostrarVentanillas() {
		string res = "";
		ventanillas->goToStart();
		for (int i = 0; i < ventanillas->getSize(); i++) {
			Ventanilla* v = ventanillas->getElement();
			res += v->mostrar() + "\n";
			ventanillas->next();
		}
		return res;
	}
};

