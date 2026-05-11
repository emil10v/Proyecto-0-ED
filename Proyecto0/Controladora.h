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
        throw runtime_error("Area no encontrada.");
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
    List<Servicio*>* getServiciosAsociados(Area* area) {
        servicios->goToStart();
        List<Servicio*>* serviciosAsociados = new LinkedList<Servicio*>();
        for (int i = 0; i < servicios->getSize(); i++) {
            Servicio* s = servicios->getElement();
            if (s->getCodigoArea() == area->getCodigoArea()) {
                serviciosAsociados->append(s);
            }
            servicios->next();
        }
        return serviciosAsociados;
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
            res += "Area: " + a->getCodigoArea() + "\n";
            res += "Cola de tiquetes: ";
            res += a->getColaTiquetes() + "\n";
            res += "Ventanillas del area: ";
            res += a->mostrarVentanillas() + "\n";
            areas->next();
        }
        return res;
    }
    // 2. crear tiquete
    void crearTiquete(string usuario, string servicio) {
        Usuario* u = getUsuario(usuario);
        u->aumentarTiquetes();
        Servicio* s = getServicio(servicio);
        s->aumentarSolicitados();
        Tiquete* t = new Tiquete(u, s);
        Area* area = getArea(s->getCodigoArea());
		area->agregarTiquete(t);
    }
    // 3. atender
    void atenderTiquete(string codArea, int numVentanilla) {
        Area* a = getArea(codArea);
        cout << a->mostrarVentanillas() << "\n";
        a->atenderTiquete(numVentanilla);
    }
    //4. liberar ventanilla
    void liberarVentanilla(string codArea, int numVentanilla) {
        Area* a = getArea(codArea);
		a->liberarVentanilla(numVentanilla);
    }
    // 5. administracion
    void agregarUsuario(string nombre, int prioridad) {
		Usuario* nuevo = new Usuario(nombre, prioridad);
        usuarios->append(nuevo);
    }
    void agregarArea(string codigo, string descripcion,int cantVentanillas) {
        Area* nueva = new Area(codigo, descripcion, cantVentanillas);
        areas->append(nueva);
    }
    void agregarServicio(string descripcion, int prioridad, string codArea) {
        Area* a = getArea(codArea); //revisar si esta el codigoArea
        Servicio* nuevo = new Servicio(descripcion, prioridad, codArea);
		servicios->append(nuevo);
    }
    void eliminarUsuario(string usuario) {
        usuarios->goToStart();
        for (int i = 0; i < usuarios->getSize(); i++) {
            Usuario* u = usuarios->getElement();
            if (u->getDescripcion() == usuario) {
                usuarios->remove();
                delete u;
                clearColasTiquetes();
                return;
            }
            usuarios->next();
        }
        throw runtime_error("Usuario no encontrado.");
    }
    void eliminarArea(string codArea) {
        Area* a = getArea(codArea);
        // eliminar servicios asociados
        servicios->goToStart();
        int size = servicios->getSize();
        for (int i = 0; i < size; )  {
            Servicio* s = servicios->getElement();
            if (s->getCodigoArea() == codArea) {
                servicios->remove();
                delete s;
                size--;
            }
            else {
                servicios->next();
                i++;
            }
        }
        // eliminar area
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
    void setVentanillas(string codArea, int cantidad) {
        Area* area = getArea(codArea);
		area->setCantVentanillas(cantidad);
    }
    string mostrarUsuarios() {
        string res = "";
        usuarios->goToStart();
        for (int i = 0; i < usuarios->getSize(); i++) {
            Usuario* u = usuarios->getElement();
            res += u->getDescripcion() + "\n";
            usuarios->next();
        }
        return res;
    }
    // mostrar
    string mostrarAreas() {
        string res = "";
        areas->goToStart();
        for (int i = 0; i < areas->getSize(); i++) {
            Area* a = areas->getElement();
            res += a->getCodigoArea() + "\n";
            areas->next();
        }
        return res;
    }
    string mostrarVentanillas(string codArea) {
        Area* a = getArea(codArea);
		return a->mostrarVentanillas();
    }
    string mostrarServicios() {
        string res = "";
        servicios->goToStart();
        for (int i = 0; i < servicios->getSize(); i++) {
            Servicio* s = servicios->getElement();
             res += s->getDescripcion() + "\n";
            servicios->next();
        }
        return res;
    }
    string estadisticasSistema() {
        string res = "\n---- ESTADISTICAS DEL SISTEMA ----\n";
        areas->goToStart();
        int totalDispensados = 0;
        int totalAtendidos = 0;
        for (int i = 0; i < areas->getSize(); i++) {
            Area* a = areas->getElement();
            res += "\nAREA: " + a->getCodigoArea() + "\n";
            res += "Tiquetes dispensados: " + to_string(a->getTiquetesDispensados()) + "\n";
            res += "Tiquetes atendidos: " + to_string(a->getTiquetesAtendidos()) + "\n";
            res += "Promedio espera (segundos): "+ to_string(a->getPromedioEspera()) + "\n";
            res += "Cantidad ventanillas: " + to_string(a->getCantVentanillas()) + "\n";
            res += "\n--- VENTANILLAS ---\n";
            List<Ventanilla*>* ventanillas = a->getVentanillas();
            ventanillas->goToStart();
            for (int j = 0; j < ventanillas->getSize(); j++) {
                Ventanilla* v = ventanillas->getElement();
                res += v->getNombre() + " -> " + to_string(v->getCantAtendidos()) + " atendidos\n";
                ventanillas->next();
            }
            totalDispensados += a->getTiquetesDispensados();
            totalAtendidos += a->getTiquetesAtendidos();
            areas->next();
        }
        res += "\n---- TOTALES ----\n";
        res += "Total dispensados: " + to_string(totalDispensados) + "\n";
        res += "Total atendidos: " + to_string(totalAtendidos) + "\n";
        res += "\n--- SERVICIOS ---\n";
        servicios->goToStart();
        for (int i = 0; i < servicios->getSize(); i++) {
            Servicio* s = servicios->getElement();
            res += s->getDescripcion() + " -> " + to_string(s->getTiquetesSolicitados()) + " tiquetes\n";
            servicios->next();
        }
        res += "\n--- USUARIOS ---\n";
        usuarios->goToStart();
        for (int i = 0; i < usuarios->getSize(); i++) {
            Usuario* u = usuarios->getElement();
            res += u->getDescripcion() + " -> " + to_string(u->getTiquetesEmitidos()) + " tiquetes\n";
            usuarios->next();
        }
        return res;
    }

};