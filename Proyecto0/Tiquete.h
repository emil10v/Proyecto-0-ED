#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "Usuario.h"
#include "Servicio.h"
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;

class Tiquete {
private:
    string codigo;
    time_t horaSolicitud;
    time_t horaAtencion;
    int prioridadFinal;
    Usuario usuario;
    Servicio servicio;

    // Función manual para convertir string a int
    int stringToInt(string str) {
        if (str == "0") return 0;
        if (str == "1") return 1;
        if (str == "2") return 2;
        if (str == "3") return 3;
        if (str == "4") return 4;
        return 0;  // Por defecto
    }

public:
    // Constructor con parámetros
    Tiquete(string codigo, Usuario user, Servicio serv) {
        this->codigo = codigo;
        this->usuario = user;
        this->servicio = serv;
        this->horaSolicitud = time(0);
        this->horaAtencion = 0;

        // Calcular prioridad usando stringToInt manual
        int pu = stringToInt(user.getPrioridad());
        int ps = stringToInt(serv.getPrioridad());
        this->prioridadFinal = (pu * 10) + ps;
    }

    // Constructor por defecto
    Tiquete() {
        this->codigo = "";
        this->horaSolicitud = time(0);
        this->horaAtencion = 0;
        this->prioridadFinal = 999;
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

    Usuario getUsuario() {
        return usuario;
    }

    Servicio getServicio() {
        return servicio;
    }

    double getTiempoEspera() {
        if (horaAtencion == 0) {
            throw std::runtime_error("Error: El tiquete no ha sido atendido todavia");
        }
        return difftime(horaAtencion, horaSolicitud);
    }
    // Mostrar tiquete
    void mostrar() {
        cout << "Tiquete: " << codigo;
        cout << " | Prioridad: " << prioridadFinal;
        cout << " | Usuario: " << usuario.getDescripcion();
        cout << " | Servicio: " << servicio.getDescripcion();
        cout << " | Atendido: " << (horaAtencion != 0 ? "Si" : "No") << endl;
    }
};