#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "Usuario.h"
#include "Servicio.h"
#include "Util.h"
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;
using std::to_string;
using std::runtime_error;

class Tiquete {
private:
    int static consecutivo;
    string codigo;
    time_t horaSolicitud;
    time_t horaAtencion;
    int prioridadFinal;
    Usuario* usuario;
    Servicio* servicio;

public:
    // Constructor con parámetros
    Tiquete(Usuario* user, Servicio* serv) {
        this->codigo = serv->getCodigoArea() + to_string(consecutivo);
        consecutivo++;  
        this->usuario = user;
        this->servicio = serv;
        this->horaSolicitud = time(0);
        this->horaAtencion = 0;
        // Calcular prioridadFinal 
        int pu = user->getPrioridad();
        int ps = serv->getPrioridad();
        this->prioridadFinal = (pu * 10) + ps;
    }

    // Constructor por defecto
    Tiquete() {
        this->codigo = "";
        this->horaSolicitud = time(0);
        this->horaAtencion = 0;
        this->prioridadFinal = DEFAULT_MAX;
    }


    // Setters
    void setHoraAtencion(time_t hora) {
        this->horaAtencion = hora;
    }

    void setCodigo(string codigo) {
        this->codigo = codigo;
    }
    // Getters
    string getCodigo() {
        return codigo;
    }

    time_t getHoraSolicitud() {
        return horaSolicitud;
    }

    time_t getHoraAtencion() {
        return horaAtencion;
    }

    int getPrioridadFinal() {
        return prioridadFinal;
    }

    Usuario* getUsuario() {
        return usuario;
    }

    Servicio* getServicio() {
        return servicio;
    }

    double getTiempoEspera() {
        if (horaAtencion == 0) {
            throw runtime_error("El tiquete no ha sido atendido todavia");
        }
        return difftime(horaAtencion, horaSolicitud);
    }
    // Mostrar tiquete
    void mostrar() {
        cout << "Tiquete: " << codigo;
        cout << " | Prioridad: " << prioridadFinal;
        cout << " | Usuario: " << usuario->getDescripcion();
        cout << " | Servicio: " << servicio->getDescripcion();
        cout << " | Atendido: " << (horaAtencion != 0 ? "Si" : "No") << endl;
    }
};