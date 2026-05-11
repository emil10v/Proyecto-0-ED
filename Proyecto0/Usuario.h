#pragma once
#include <string>
#include <iostream>
#include "Util.h"

using std::string;
using std::cout;
using std::endl;

class Usuario {
private:
    string descripcion;
    int prioridad;
    int tiquetesEmitidos;

public:
    Usuario(string desc, int prior) {
        this->descripcion = desc;
        this->prioridad = prior;
        this->tiquetesEmitidos = 0;
    }
    Usuario() {
        this->descripcion = "";
        this->prioridad = DEFAULT_MAX;
    }

    // Getters
    string getDescripcion() {
        return descripcion;
    }

    int getPrioridad() {
        return prioridad;
    }

    // Setters
    void setDescripcion(string desc) {
        descripcion = desc;
    }

    void setPrioridad(int prior) {
        prioridad = prior;
    }

    // Mostrar
    void mostrar() {
        cout << "Usuario: " << descripcion << endl;
    }

    void aumentarTiquetes() {
        tiquetesEmitidos++;
    }
    int getTiquetesEmitidos() {
        return tiquetesEmitidos;
    }
};
