#pragma once
#include <string>
#include <iostream>
#include "Area.h"

using std::string;
using std::cout;
using std::endl;

class Servicio {
private:
    string descripcion;
    int prioridad;
    string codigoArea;
        
public:
    Servicio(string desc, int prior, string areaServ) {
        this->descripcion = desc;
        this->prioridad = prior;
		this->codigoArea = areaServ;
    }
    Servicio() {
        this->descripcion = "";
		this->prioridad = DEFAULT_MAX;
        this->codigoArea = "";
    }
    // getters
    string getDescripcion() {
        return descripcion;
    }

    int getPrioridad() {
        return prioridad;
    }
    string getCodigoArea() {
        return codigoArea;
    }

  //setters
    void setDescripcion(string desc) {
        descripcion = desc;
    }

    void setPrioridad(int prior) {
        prioridad = prior;
    }

    void setCodigoArea(string area) {
        codigoArea = area;
    }

    // Mostrar
    void mostrar() {
        cout << "Servicio: " << descripcion << " | Prioridad: " << prioridad
            << " | Área: " << codigoArea << endl;
    }
};