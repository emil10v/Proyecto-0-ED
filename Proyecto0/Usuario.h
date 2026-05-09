#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Usuario {
private:
    string descripcion;
    string prioridad;

public:
    // Constructor con parámetros (único constructor)
    Usuario(string desc, string prior) {
        this->descripcion = desc;
        this->prioridad = prior;
    }

    // Getters
    string getDescripcion() {
        return descripcion;
    }

    string getPrioridad() {
        return prioridad;
    }

    // Setters
    void setDescripcion(string desc) {
        descripcion = desc;
    }

    void setPrioridad(string prior) {
        prioridad = prior;
    }

    // Mostrar
    void mostrar() {
        cout << "Usuario: " << descripcion << " | Prioridad: " << prioridad << endl;
    }
};