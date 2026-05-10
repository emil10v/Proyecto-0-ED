#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Servicio {
private:
    string descripcion;
    int prioridad;
    string codigoArea;

public:
    Servicio(string desc, int prior, string area) {
        this->descripcion = desc;
        this->prioridad = prior;
        this->codigoArea = area;
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