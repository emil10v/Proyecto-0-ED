#pragma once
#include <string>
#include <iostream>
using namespace std;

class Usuario {
private:
    string descripcion;
    int prioridad;

public:
    Usuario() : descripcion(""), prioridad(999) {}//constructor
    Usuario(const string& desc, int prior) : descripcion(desc), prioridad(prior) {}
    ~Usuario() {}//destructor

    //setters
    void setDescripcion(const string& desc) { descripcion = desc; }
    void setPrioridad(int prior) { prioridad = prior; }
    //getters
    string getDescripcion() const { return descripcion; }
    int getPrioridad() const { return prioridad; }
    void mostrar() const {
        cout << "Usuario: " << descripcion << " | Prioridad: " << prioridad << endl;
    }

    //Métodos para asignar la prioridad automaticamente 
    static Usuario adultoMayor() { return Usuario("Adulto Mayor", 0); }
    static Usuario necesidadesEspeciales() { return Usuario("Persona con Necesidades Especiales", 0); }
    static Usuario representanteOrganizacional() { return Usuario("Representante Organizacional", 1); }
    static Usuario regular() { return Usuario("Usuario Regular", 2); }
};