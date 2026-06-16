#include "Header.h"
#include "Servicios_Precios.h"
#include "Facturas.h"
#include "seguimiento.h"

using namespace std;

int main() {
    int opcion;
    sistemac sistemaCH;  
    Servicios preciosHEC;    
    ModuloJosue facturJOS;  
    SeguimientoVehicular seguimientoMAU;

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    do {
        borrar();
        cout << "================================" << endl;
        cout << "Sistema de Mecanica facíl" << endl;
        cout << "================================" << endl;
        cout << "1. Registro de cliente (Christopher)" << endl;
        cout << "2. Seguiminento vehíular (Mauro)" << endl;
        cout << "3. Ordenes de trabajo (hector)" << endl;
        cout << "4. Facturas (Josue)" << endl;
        cout << "5. Salír" << endl;
        cout << "Elija que quiere hacer en el sistema. (1-5)" << endl;


        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            std::cout << "Opcion no valida (1-5): ";
            limpiarbuffer();
        }

        switch (opcion) {

        case 1: borrar(); {
            sistemaCH.ejecutar();
            break;
        }
        case 2: borrar(); {
            seguimientoMAU.ejecutarSeguimiento();
            break;
        }
              case 3: borrar(); {
                  preciosHEC.ejecutarMenu();
                  break;
              }
              case 4: borrar(); {
                  facturJOS.facturarModuloJosue(sistemaCH.getListaClientes());
                  break;
              }
        }
    } while (opcion != 5);
    
    borrar();
    cout << "saliendo del programa..." << endl;
    return 0;
}