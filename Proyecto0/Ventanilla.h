#pragma once
#include <string>
#include "Tiquete.h"

using std::string;

class Ventanilla {
private:
	string nombre;
	Tiquete* atendido;
	int cantAtendidos;

public:
	Ventanilla(string nombre) {
		this->nombre = nombre;
		this->atendido = nullptr;
		cantAtendidos = 0;
	}
	Ventanilla() {
		atendido = nullptr;
		cantAtendidos = 0;
	}
	void atender(Tiquete* t) {
		atendido = t;
		cantAtendidos++;
	}
	Tiquete* getAtendido() {
		return atendido
	}
	int getCantAtendidos() {
		return cantAtendidos;
	}
	string getNombre() {
		return nombre;
	}

};

