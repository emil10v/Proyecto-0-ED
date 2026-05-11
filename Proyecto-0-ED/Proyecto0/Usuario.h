// Archivo: Usuario.h
// Autor: Isaac
//
// Descripción:
// Clase que representa a un usuario del sistema.
// Cada usuario posee una descripción, prioridad y cantidad
// de tiquetes emitidos.
//
// Funcionalidades principales:
// - Almacenar información del usuario.
// - Manejar prioridad de atención.
// - Llevar conteo de tiquetes emitidos.
// - Mostrar información del usuario.
//
// Los usuarios son necesarios para la generación de tiquetes.

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
