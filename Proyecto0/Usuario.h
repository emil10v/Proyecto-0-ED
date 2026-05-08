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
   
    // Destructor
    ~Usuario() {}

