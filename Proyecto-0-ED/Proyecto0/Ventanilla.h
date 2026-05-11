#pragma once
#include <string>
#include "ArrayList.h"
#include "Tiquete.h"

using std::to_string;

class Ventanilla {
private:
    string nombre;
    Tiquete* atendido;
    int cantAtendidos;

public:
    // Constructor con parámetros
    Ventanilla(string nombre) {
        this->nombre = nombre;
        this->atendido = nullptr;
        this->cantAtendidos = 0;
    }
// constructo sin parameros ventanilla
    Ventanilla() {
        this->nombre = "";
        this->atendido = nullptr;
        this->cantAtendidos = 0;
    }
    ~Ventanilla() {
        delete atendido;
    }
    // Getters
    Tiquete* getAtendido() {
        return atendido;
    }
    int getCantAtendidos() {
        return cantAtendidos;
    }
    string getNombre() {
        return nombre;
    }
    bool estaLibre() {
        return atendido == nullptr;
    }

    // Setters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    // Atender un tiquete
    void atender(Tiquete* atendido) {
        this->atendido = atendido;
		cantAtendidos++;
    }
    void liberar() {
        atendido = nullptr;
    }
    // Mostrar
    string mostrar() {
        string res = "Ventanilla: " + nombre;
        if (!estaLibre()) {
            res += " | Atendiendo: " + atendido->getCodigo();
        }
        else {
            res += " | Libre";
        }
        return res;
    }
};