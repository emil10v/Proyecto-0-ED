#pragma once
#include <string>
#include <iostream>
using namespace std;

class Servicio {
private:
    string descripcion;
    int prioridad;       // PS en la fórmula PT = PU * 10 + PS
    string codigoArea;   // Área donde se atiende (ej: "C", "S", "E")

public:
    // Constructor por defecto
    Servicio() : descripcion(""), prioridad(0), codigoArea("") {}

    // Constructor con parámetros
    Servicio(const string& desc, int prior, const string& area)
        : descripcion(desc), prioridad(prior), codigoArea(area) {


