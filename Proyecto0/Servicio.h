#pragma once
#include <string>
#include <iostream>
using namespace std;

class Servicio {
private:
    string descripcion;
    int prioridad;      // PS en la fórmula PT = PU * 10 + PS
    string codigoArea;  // Área donde se atiende (ej: "C", "S", "E")

public:
    // Constructor 
    Servicio() : descripcion(""), prioridad(0), codigoArea("") {} 
    Servicio(const string& desc, int prior, const string& area)
        : descripcion(desc), prioridad(prior), codigoArea(area) {
    }

    // Destructor
    ~Servicio() {}
    // Setters
    void setDescripcion(const string& desc) {
        descripcion = desc;
    }
    void setPrioridad(int prior) {
        prioridad = prior;
    }
    void setCodigoArea(const string& area) {
        codigoArea = area;
    }
    // Getters
    string getDescripcion() const {
        return descripcion;
    }
    int getPrioridad() const {
        return prioridad;
    }
    string getCodigoArea() const {
        return codigoArea;
    }
    // Mostrar información
    void mostrar() const {
        cout << "Servicio: " << descripcion << " | Prioridad: " << prioridad
            << " | Área: " << codigoArea << endl;
    }

    // Métodos estáticos para crear servicios con prioridad automática
    static Servicio compra() {
        return Servicio("Comprar boleto", 2, "C");
    }
    static Servicio cambio() {
        return Servicio("Cambiar boleto", 3, "C");
    }
    static Servicio informacion() {
        return Servicio("Solicitar información", 1, "S");
    }
    static Servicio reclamo() {
        return Servicio("Realizar reclamo", 4, "E");
    }
};