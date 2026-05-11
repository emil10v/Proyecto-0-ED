// Archivo: Servicio.h
// Autores: Isaac y María Celeste
//
// Descripción:
// Clase que representa un servicio ofrecido dentro del sistema.
// Cada servicio pertenece a un área específica y posee un nivel
// de prioridad.
//
// Funcionalidades principales:
// - Almacenar información del servicio.
// - Llevar conteo de tiquetes solicitados.
// - Obtener y modificar atributos.
// - Mostrar información del servicio.
//
// Los servicios son utilizados al generar tiquetes.

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
    int tiquetesSolicitados;
        
public:
    Servicio(string desc, int prior, string areaServ) {
        this->descripcion = desc;
        this->prioridad = prior;
		this->codigoArea = areaServ;
        this->tiquetesSolicitados = 0;
    }
    Servicio() {
        this->descripcion = "";
		this->prioridad = DEFAULT_MAX;
        this->codigoArea = "";
    }
    void aumentarSolicitados() {
        tiquetesSolicitados++;
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

    int getTiquetesSolicitados() {
        return tiquetesSolicitados;
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