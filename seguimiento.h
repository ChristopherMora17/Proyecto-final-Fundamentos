//parte de mauro

#pragma once
#include <iostream>
#include <limits> 

using namespace std;

class SeguimientoVehicular {
private:
    int opcion;
    int estado;
    int informacionCorrecta;
    int mantenimientoRealizado;
    int datosActualizados;

  
    int leerEntero(string mensaje) {
        int valor;
        while (true) {
            cout << mensaje;
            if (cin >> valor) {
                return valor;
            }
            else {
                cout << "Error: Entrada no valida. Por favor ingrese unicamente el numero.\n";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
    }

public:
    void ejecutarSeguimiento() {
        cout << "========================================" << endl;
        cout << "=== SISTEMA DE SEGUIMIENTO VEHICULAR ===" << endl;
        cout << "========================================" << endl;

       
        do {
            cout << "\n[ Registro del vehiculo ]" << endl;
            informacionCorrecta = leerEntero("La informacion es correcta? (1=Si, 0=No): ");

            if (informacionCorrecta == 0) {
                cout << "=> Error: Por favor, vuelva a verificar e ingresar la informacion." << endl;
            }
        } while (informacionCorrecta == 0);

        cout << "=> Informacion guardada correctamente." << endl;

        
        cout << "\n[ Seleccione el tipo de mantenimiento ]" << endl;
        cout << "1. Cambio de aceite\n2. Revision\n3. Reparacion\n4. Frenos\n5. Balanceo" << endl;
        opcion = leerEntero("Opcion: ");

        mantenimientoRealizado = leerEntero("Se realizo el mantenimiento? (1=Si, 0=No): ");

        if (mantenimientoRealizado == 1) {
            cout << "=> Mantenimiento registrado y guardado en historial." << endl;
        }
        else {
            cout << "=> Mantenimiento pendiente." << endl;
        }

      
        cout << "\n[ Estado del vehiculo ]" << endl;
        cout << "1. Disponible\n2. En taller\n3. En circulacion\n4. Fuera de servicio" << endl;
        estado = leerEntero("Opcion: ");

        cout << "=> Estado actualizado correctamente." << endl;

        
        cout << "\nActualizando datos..." << endl;
        datosActualizados = leerEntero("Los datos estan actualizados? (1=Si, 0=No): ");

        if (datosActualizados == 1) {
            cout << "\nMostrando informacion en tiempo real:" << endl;
            cout << "  - Ubicacion actual" << endl;
            cout << "  - Kilometraje" << endl;
            cout << "  - Velocidad" << endl;
            cout << "  - Ruta recorrida" << endl;
            cout << "  - Alertas" << endl;
        }
        else {
            cout << "=> Error al actualizar los datos." << endl;
        }

        cout << "\nGenerando reportes y estadisticas..." << endl;
        cout << "========================================" << endl;
        cout << "Fin del modulo de seguimiento. Preparando siguiente modulo..." << endl;
        cout << "========================================" << endl;

        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nPresione Enter para continuar al modulo de Servicios y Precios...";
        cin.get();
    }
};