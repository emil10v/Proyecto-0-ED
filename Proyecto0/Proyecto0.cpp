
#include <iostream>
#include "Tiquete.h"
#include "Servicio.h"
#include "Area.h"
#include "LinkedList.h"
#include "Usuario.h"

using std::runtime_error;
using std::to_string;
using std::cin;
using std::getline;
using std::cout;

using std::cout;
int Tiquete::consecutivo = 100;



int main() {
	List<Area*>* areas = new LinkedList<Area*>();
	List<Servicio*>* servicios = new LinkedList<Servicio*>();

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






    // liberar memoria
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
    delete areas;
    delete servicios;
    return 0
}
