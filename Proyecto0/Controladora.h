#pragma once

#include "LinkedList.h"
#include "Area.h"
#include "Servicio.h"
#include "Usuario.h"
#include "Tiquete.h"


using std::runtime_error;
using std::to_string;

class Controladora {
private:
    List<Usuario*>* usuarios;
    List<Area*>* areas;
    List<Servicio*>* servicios;

public:
    Controladora() {
        areas = new LinkedList<Area*>();
        servicios = new LinkedList<Servicio*>();
        usuarios = new LinkedList<Usuario*>();
    }
    ~Controladora() {
        areas->goToStart();
        for (int i = 0; i < areas->getSize(); i++) {
            delete areas->getElement();
            areas->next();
        }
        servicios->goToStart();
        for (int i = 0; i < servicios->getSize(); i++) {
            delete servicios->getElement();
            servicios->next();
        }
		usuarios->goToStart();
        for (int i = 0; i < usuarios->getSize(); i++) {
            delete usuarios->getElement();
            usuarios->next();
		}
        delete areas;
        delete servicios;
        delete usuarios;
    }
    // subrutinas
    Usuario* getUsuario(string descUsuario) {
        usuarios->goToStart();
        for (int i = 0; i < usuarios->getSize(); i++) {
            Usuario* u = usuarios->getElement();
            if (u->getDescripcion() == descUsuario) {
                return u;
            }
            usuarios->next();
        }
		throw runtime_error("Usuario no encontrado.");
    }

    Area* getArea(string codArea) {
        areas->goToStart();
        for (int i = 0; i < areas->getSize(); i++) {
            Area* a = areas->getElement();
            if (a->getCodigoArea() == codArea) {
                return a;
            }
            areas->next();
        }
        throw runtime_error("Área no encontrada.");
    }
    Servicio* getServicio(string descServicio) {
        servicios->goToStart();
        for (int i = 0; i < servicios->getSize(); i++) {
            Servicio* s = servicios->getElement();
            if (s->getDescripcion() == descServicio) {
                return s;
            }
            servicios->next();
        }
        throw runtime_error("Servicio no encontrado.");
    }
    void clearColasTiquetes() {
        areas->goToStart();
        for (int i = 0; i < areas->getSize(); i++) {
            Area* a = areas->getElement();
            a->clearTiquetes();
            areas->next();
		}
    }

    // 1. estado de las colas
    string estadoColas() {
        string res = "Estado de las colas:\n";
        areas->goToStart();
        for (int i = 0; i < areas->getSize(); i++) {
            Area* a = areas->getElement();
            res += "Área: " + a->getCodigoArea() + "\n";
            res += "Cola de tiquetes: ";
            res += a->getColaTiquetes() + "\n";
            res += "Ventanillas del área: ";
            res += a->mostrarVentanillas() + "\n";
            areas->next();
        }
        return res;
    }
    // 2. crear tiquete
    void crearTiquete(string usuario, string servicio) {
        Usuario* u = getUsuario(usuario);
        Servicio* s = getServicio(servicio);
        Tiquete* t = new Tiquete(u, s);
        Area* area = getArea(s->getCodigoArea());
		area->agregarTiquete(t);
    }
    // 3. atender
    void atenderTiquete(string codArea, int numVentanilla) {
        Area* a = getArea(codArea);
        a->atenderTiquete(numVentanilla);
    }

    // 4. administracion

    void agregarUsuario(string nombre, int prioridad) {
		Usuario* nuevo = new Usuario(nombre, prioridad);
        usuarios->append(nuevo);
    }
    void agregarArea(string codigo, string descripcion,int cantVentanillas) {
        Area* nueva = new Area(codigo, descripcion, cantVentanillas);
        areas->append(nueva);
    }
    void agregarServicio(string descripcion, int prioridad, string codArea) {
        Area* areaServ = getArea(codArea);
        Servicio* nuevo = new Servicio(descripcion, prioridad, areaServ);
		servicios->append(nuevo);
    }
    void eliminarUsuario(string usuario) {
        Usuario* u = getUsuario(usuario);
        usuarios->remove();
        clearColasTiquetes();
    }
    List<Servicio*>* getServiciosAsociados(Area* area) {
        areas->remove();
        servicios->goToStart();
        List<Servicio*>* serviciosAsociados = new LinkedList<Servicio*>();
        for (int i = 0; i < servicios->getSize(); i++) {
            Servicio* s = servicios->getElement();
            if (s->getCodigoArea() == area->getCodigoArea()) {
                serviciosAsociados->append(s);
            }
            servicios->next();
        }
    }
    void eliminarArea(List<Servicio*>*) {

    }
    void setVentanillas(string codArea, int cantidad) {
        Area* area = getArea(codArea);
		area->setCantVentanillas(cantidad);
    }
    void eliminarArea(string codArea) {
        Area* a = getArea(codArea);
		areas->goToStart();
		for (int i = 0; i < areas->getSize(); i++) {
			if (areas->getElement() == a) {
				areas->remove();
				delete a;
                return;
            }
            areas->next();
        }
    }
    
};