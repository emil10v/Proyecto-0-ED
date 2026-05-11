#pragma once
#include <string>
#include "ArrayList.h"
#include "Tiquete.h"

using std::string;

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

    // Setters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    // Atender un tiquete
    void atender(Tiquete* t) {
        this->atendido = t;
        this->cantAtendidos++;
    }
    // Mostrar
    void mostrar() {
        cout << "Ventanilla: " << nombre;
        if (atendido != nullptr) {
            cout << " | Atendiendo: " << atendido->getCodigo();
        }
        else {
            cout << " | Libre";
        }
        cout << " | Total atendidos: " << cantAtendidos << endl;
    }
};