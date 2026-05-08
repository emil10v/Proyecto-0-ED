#include <iostream>
#include "Usuario.h"
#include "Servicio.h"

using namespace std;

int main() {
 
  
    Usuario adulto = Usuario::adultoMayor();
    Usuario regular = Usuario::regular();

    adulto.mostrar();
    regular.mostrar();

 
    
    Servicio compra = Servicio::compra();
    Servicio info = Servicio::informacion();

    compra.mostrar();
    info.mostrar();

    return 0;
}