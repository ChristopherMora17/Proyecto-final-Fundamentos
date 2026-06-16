//parte de hector

#pragma once
#include <iostream>

using namespace std;

class Servicios {
private:

    int opcion;
    char continuar;
    int total = 0;

public:

    void ejecutarMenu() {
        cout << "=====================================\n";
        cout << "     TALLER MECANICO MOTOR PLUS\n";
        cout << "=====================================\n";

        do {

            cout << "\nSERVICIOS DISPONIBLES\n";
            cout << "1. Cambio de aceite - 25000\n";
            cout << "2. Revision de frenos - 18000\n";
            cout << "3. Alineado y balanceo - 22000\n";
            cout << "4. Cambio de bateria - 45000\n";
            cout << "5. Diagnostico computarizado - 30000\n";
            cout << "6. Reparacion de motor - 180000\n";
            cout << "7. Cambio de llantas - 70000\n";

            cout << "\nSeleccione un servicio: ";
            cin >> opcion;

            switch (opcion) {

            case 1:
                cout << "Cambio de aceite agregado.\n";
                total += 25000;
                break;

            case 2:
                cout << "Revision de frenos agregada.\n";
                total += 18000;
                break;

            case 3:
                cout << "Alineado y balanceo agregado.\n";
                total += 22000;
                break;

            case 4:
                cout << "Cambio de bateria agregado.\n";
                total += 45000;
                break;

            case 5:
                cout << "Diagnostico computarizado agregado.\n";
                total += 30000;
                break;

            case 6:
                cout << "Reparacion de motor agregada.\n";
                total += 180000;
                break;

            case 7:
                cout << "Cambio de llantas agregado.\n";
                total += 70000;
                break;

            default:
                cout << "Opcion invalida.\n";
                break;
            }

            cout << "Desea agregar otro servicio? (s/n): ";
            cin >> continuar;

        } while (continuar == 's' || continuar == 'S');

        cout << "\nTotal a pagar: " << total << "\n";
        cout << "Gracias por su preferencia.\n";
    }
};
