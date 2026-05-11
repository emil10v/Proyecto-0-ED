// Archivo: main.cpp
// Autores: Emilio, Isaac y María Celeste
//
// Descripción:
// Archivo principal del sistema de control de colas prioritarias.
// Contiene la interfaz de consola y la interacción directa con el usuario.
//
// Funcionalidades principales:
// - Mostrar menús del sistema.
// - Procesar opciones del usuario.
// - Crear, atender y liberar tiquetes.
// - Administrar usuarios, áreas y servicios.
// - Mostrar estadísticas del sistema.
// - Manejar errores mediante excepciones.
//
// Además, inicializa la clase Controladora, la cual administra
// toda la lógica interna del sistema.

#include <iostream>
#include <string>
#include <stdexcept>
#include "Controladora.h"
int Tiquete::consecutivo = 100;

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::runtime_error;
using std::string;

void menuPrincipal() {
    cout << "\n----- SISTEMA DE TIQUETES ----" << endl;
    cout << "1. Estado de colas" << endl;
    cout << "2. Crear tiquete" << endl;
    cout << "3. Atender tiquete" << endl;
    cout << "4. Liberar ventanilla" << endl;
    cout << "5. Administracion" << endl;
    cout << "6. Estadisticas" << endl;
    cout << "7. Salir" << endl;
    cout << "Opcion > ";
}
void menuAdmin() {
    cout << "\n------ ADMINISTRACION ------" << endl;
    cout << "1. Agregar usuario" << endl;
    cout << "2. Agregar area" << endl;
    cout << "3. Agregar servicio" << endl;
    cout << "4. Eliminar Usuario" << endl;
    cout << "5. Eliminar area" << endl;
    cout << "6. Eliminar Servicio" << endl;
    cout << "7. Cambiar cantidad ventanillas" << endl;
    cout << "8. Mostrar usuarios" << endl;
    cout << "9. Mostrar areas" << endl;
    cout << "10. Mostrar servicios" << endl;
    cout << "0. Volver" << endl;
    cout << "Opcion > ";
}
int main() {
    Controladora sistema;
    string op = "";
    while (op != "7") {
        try {
            menuPrincipal();
            getline(cin, op);
            if (op == "1") {
                cout << sistema.estadoColas() << endl;
            }
            else if (op == "2") {
                string usuario;
                string servicio;
                cout << "\nUSUARIOS DISPONIBLES\n";
                cout << sistema.mostrarUsuarios() << endl;
                cout << "Usuario > ";
                getline(cin, usuario);
                cout << "\nSERVICIOS DISPONIBLES\n";
                cout << sistema.mostrarServicios() << endl;
                cout << "Servicio > ";
                getline(cin, servicio);
                sistema.crearTiquete(usuario, servicio);
                cout << "Tiquete creado correctamente." << endl;
            }
            else if (op == "3") {
                string codArea;
                string temp;
                int ventanilla;
                cout << sistema.mostrarAreas() << endl;
                cout << "Codigo area > ";
                getline(cin, codArea);
                cout << sistema.mostrarVentanillas(codArea);
                cout << "numero de ventanilla (sin letras) > ";
                getline(cin, temp);
                if (temp.empty())
                    throw runtime_error("Debe ingresar un numero.");
                ventanilla = stoi(temp);
                sistema.atenderTiquete(codArea, ventanilla);
                cout << "Tiquete atendido." << endl;
            }
            else if (op == "4") {
                string codArea;
                string temp;
                int ventanilla;
                cout << sistema.mostrarAreas() << endl;
                cout << "Codigo area > ";
                getline(cin, codArea);
                cout << "Numero ventanilla > ";
                getline(cin, temp);
                if (temp.empty())
                    throw runtime_error("Debe ingresar un numero.");
                ventanilla = stoi(temp);
                sistema.liberarVentanilla(codArea, ventanilla);
                cout << "Ventanilla liberada." << endl;
            }
            else if (op == "5") {
                string opAdmin = "";
                while (opAdmin != "0") {
                    try {
                        menuAdmin();
                        getline(cin, opAdmin);
                        if (opAdmin == "1") {
                            string nombre;
                            string temp;
                            int prioridad;
                            cout << "Nombre usuario > ";
                            getline(cin, nombre);
                            cout << "Prioridad > ";
                            getline(cin, temp);
                            if (temp.empty())
                                throw runtime_error("Debe ingresar un numero.");
                            prioridad = stoi(temp);
                            sistema.agregarUsuario(nombre, prioridad);
                            cout << "Usuario agregado." << endl;
                        }
                        else if (opAdmin == "2") {
                            string codigo;
                            string descripcion;
                            string temp;
                            int cant;
                            cout << "Codigo area > ";
                            getline(cin, codigo);
                            cout << "Descripcion > ";
                            getline(cin, descripcion);
                            cout << "Cantidad ventanillas > ";
                            getline(cin, temp);
                            if (temp.empty())
                                throw runtime_error("Debe ingresar un numero.");
                            cant = stoi(temp);
                            sistema.agregarArea(codigo, descripcion, cant);
                            cout << "Area agregada." << endl;
                        }
                        else if (opAdmin == "3") {
                            string descripcion;
                            string codArea;
                            string temp;
                            int prioridad;
                            cout << "Areas Disponibles: \n";
                            cout << sistema.mostrarAreas() << endl;
                            cout << "Descripcion servicio > ";
                            getline(cin, descripcion);
                            cout << "Prioridad > ";
                            getline(cin, temp);
                            if (temp.empty())
                                throw runtime_error("Debe ingresar un numero.");
                            prioridad = stoi(temp);
                            cout << "Codigo area > ";
                            getline(cin, codArea);
                            sistema.agregarServicio(descripcion, prioridad, codArea);
                            cout << "Servicio agregado." << endl;
                        }
                        else if (opAdmin == "4") {
                            string usuario;
                            cout << "\nUSUARIOS DISPONIBLES\n";
                            cout << sistema.mostrarUsuarios() << endl;
                            cout << "Usuario a eliminar > ";
                            getline(cin, usuario);
                            sistema.eliminarUsuario(usuario);
                            cout << "Usuario eliminado correctamente." << endl;
                        }
                        else if (opAdmin == "5") {
                            string codArea;
                            cout << sistema.mostrarAreas() << endl;
                            cout << "Codigo area eliminar > ";
                            getline(cin, codArea);
                            // mostrar servicios asociados
                            Area* a = sistema.getArea(codArea);
                            List<Servicio*>* lista = sistema.getServiciosAsociados(a);
                            cout << "\nADVERTENCIA\n";
                            cout << "Se eliminaran los siguientes servicios:\n";
                            lista->goToStart();
                            for (int i = 0; i < lista->getSize(); i++) {
                                Servicio* s = lista->getElement();
                                cout << "- " << s->getDescripcion() << endl;
                                lista->next();
                            }
                            string confirmar;
                            cout << "\nDesea continuar? (s/n) > ";
                            getline(cin, confirmar);
                            if (confirmar == "s" || confirmar == "S") {
                                sistema.eliminarArea(codArea);
                                cout << "Area eliminada correctamente.\n";
                            }
                            else {
                                cout << "Operacion cancelada.\n";
                            }
                            delete lista;
                        }
                        else if (opAdmin == "6") {
                            string servicio;
                            cout << "----SERVICIOS DISPONIBLES----" << endl;
                            cout << sistema.mostrarServicios() << endl;
                            cout << "Servicio a eliminar > ";
                            getline(cin, servicio);
                            sistema.eliminarServicio(servicio);
                            cout << "Servicio eliminado correctamente." << endl;
                        }
                        else if (opAdmin == "7") {
                            string codArea;
                            string temp;
                            int cant;
                            cout << sistema.mostrarAreas() << endl;
                            cout << "Codigo area > ";
                            getline(cin, codArea);
                            cout << "---- VENTANILLAS ACTUALES ----";
                            cout << sistema.mostrarVentanillas(codArea);
                            cout << "Nueva cantidad > ";
                            getline(cin, temp);
                            if (temp.empty())
                                throw runtime_error("Debe ingresar un numero.");
                            cant = stoi(temp);
                            sistema.setVentanillas(codArea, cant);
                            cout << "Cantidad actualizada." << endl;
                        }
                        else if (opAdmin == "8") {
                            cout << sistema.mostrarUsuarios() << endl;
                        }
                        else if (opAdmin == "9") {
                            cout << sistema.mostrarAreas() << endl;
                        }
                        else if (opAdmin == "10") {
                            cout << "---- SERVICIOS DISPONIBLES ----" << endl;
                            cout << sistema.mostrarServicios() << endl;
                        }
                        else if (opAdmin != "0")
                            throw runtime_error("Opcion invalida.");
                    }
                    catch (const runtime_error& e) {
                        cout << "ERROR: " << e.what() << endl;
                    }
                }
            }
            else if (op == "6") {
                cout << sistema.estadisticasSistema() << endl;
            }
            else if (op != "7") {
                throw runtime_error("Opcion invalida.");
            }
        }
        catch (const runtime_error& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }
    cout << "\nGracias por usar el sistema :)" << endl;
    return 0;
};