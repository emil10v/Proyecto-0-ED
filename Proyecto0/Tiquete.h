#pragma once

#include <string>
#include <time.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Tiquete {
private:
    string codigo;
    int prioridad;       // PT = PU * 10 + PS
    string codigoArea;
    time_t horaSolicitud;
    time_t horaAtencion;
    time_t tiempoEspera;

public:
    Tiquete(string codigo, string codigoArea, int prioridad) {
        this->codigo = codigo;
        this->codigoArea = codigoArea;
        this->prioridad = prioridad;
        horaSolicitud = time(0);
        horaAtencion = 0;
        tiempoEspera = 0;
    }

    Tiquete() {
        prioridad = 0;
        horaSolicitud = 0;
        horaAtencion = 0;
        tiempoEspera = 0;
    }

    void atender() {
        horaAtencion = time(0);
        tiempoEspera = horaAtencion - horaSolicitud;
    }

    //getters
    string getCodigo() const
    {
        return codigo;
    }
    string getCodigoArea() const
    {
        return codigoArea;
    }
    int getPrioridad() const
    {
        return prioridad;
    }
    time_t getTiempoEspera() const
    {
        return tiempoEspera;
    }


    void print() const {
        cout << "Codigo:    " << codigo << endl;
        cout << "Area:      " << codigoArea << endl;
        cout << "Prioridad: " << prioridad << endl;

        struct tm info;
        localtime_s(&horaSolicitud, &info); 
        cout << "Solicitud: "
        cout << (info.tm_year + 1900) << "-"
        cout << (info.tm_mon + 1) << "-"
        cout << info.tm_mday << " "
        cout << info.tm_hour << ":"
        cout << info.tm_min << ":"
        cout << info.tm_sec << endl;

        if (horaAtencion != 0) {
            struct tm info2;
            localtime_s(&horaAtencion, &info2);
            cout << "Atendido:  "
            cout << (info2.tm_year + 1900) << "-"
            cout << (info2.tm_mon + 1) << "-"
            cout << info2.tm_mday << " "78
            cout << info2.tm_hour << ":"
            cout << info2.tm_min << ":"
            cout << info2.tm_sec << endl;
            cout << "Espera:    " << tiempoEspera << " s" << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Tiquete& t) {
        os << "(Codigo: " << t.codigo << ", Prioridad: " << t.prioridad << ")";
        return os;
    }
};