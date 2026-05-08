#pragma once
#include <string>
#include <iostream>
using namespace std;

class Usuario {
private:
    string descripcion;
    int prioridad;

public:
   
    Usuario() : descripcion(""), prioridad(999) {} // Constructor default
    Usuario(const string& desc, int prior) : descripcion(desc), prioridad(prior) {}  // Constructor con parámetros 
   
    ~Usuario() {}// Destructor
    // Getters
    string getDescripcion() const { return descripcion; }
    int getPrioridad() const { return prioridad; 
    // Setters
    void setDescripcion(const string& desc) { descripcion = desc; }
    void setPrioridad(int prior) { prioridad = prior; }
    }
};

