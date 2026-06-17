//parte de josue

#pragma once
#include "Header.h" 
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class ModuloJosue {
private:
    string clienteCedula;
    string clienteNombre;
    double clienteDescuento;

    string servicioNombre;
    double servicioPrecio;
    double servicioManoDeObra;

    double totalPagar;
    int repetir = 1;

    void calcularTotal() {
       totalPagar = ((servicioPrecio + servicioManoDeObra ) * (1 - clienteDescuento / 100.0));
    }

    void mostrarFactura() {
        cout << "\033[33m" << endl;
        cout << "==================================" << endl;
        cout << "              FACTURA             " << endl;
        cout << "==================================" << endl;
        cout << "Cedula  : " << clienteCedula << endl;
        cout << "Nombre  : " << clienteNombre << endl;
        cout << "==================================" << endl;
        cout << "Servicio: " << servicioNombre << endl;
        cout << "Precio  : $" << servicioPrecio << endl;
        cout << "Descuento: " << clienteDescuento << "%" << endl;
        cout << "Mano de obra: $" << servicioManoDeObra << endl;
        cout << "==================================" << endl;
        cout << "Total a pagar: $" << totalPagar << endl;
        cout << "==================================" << endl;
        cout << "Gracias por confiar en nuestros servicios!" << endl;
        cout << "\033[0m";
    }

public:
  
    void seleccionarServicio() {
        int opcion = 0;
        bool opcionValida = false;

        while (!opcionValida) {
            cout << "        SERVICIOS Y PRECIOS      " << endl;
            cout << "==================================" << endl;
            cout << "1.  Cambio de aceite y filtro   $30\n2.  Afinacion de motor          $60\n3.  Cambio de frenos (del.)    $120\n";
            cout << "4.  Cambio de frenos (tras.)   $100\n5.  Alineacion y balanceo       $40\n6.  Revision general            $25\n";
            cout << "7.  Cambio de bateria           $90\n8.  Diagnostico electronico     $50\n9.  Reparacion de suspension   $150\n10. Limpieza de inyectores      $70\n" << endl;

            cout << "Ingrese el numero del servicio: ";
            cin >> opcion;

            opcionValida = true;

            if (opcion == 1) { servicioNombre = "Cambio de aceite y filtro";   servicioPrecio = 30;  servicioManoDeObra = 10; }
            else if (opcion == 2) { servicioNombre = "Afinacion de motor";           servicioPrecio = 60;  servicioManoDeObra = 20; }
            else if (opcion == 3) { servicioNombre = "Cambio de frenos (delanteros)"; servicioPrecio = 120; servicioManoDeObra = 30; }
            else if (opcion == 4) { servicioNombre = "Cambio de frenos (traseros)";  servicioPrecio = 100; servicioManoDeObra = 25; }
            else if (opcion == 5) { servicioNombre = "Alineacion y balanceo";        servicioPrecio = 40;  servicioManoDeObra = 15; }
            else if (opcion == 6) { servicioNombre = "Revision general";             servicioPrecio = 25;  servicioManoDeObra = 10; }
            else if (opcion == 7) { servicioNombre = "Cambio de bateria";            servicioPrecio = 90;  servicioManoDeObra = 20; }
            else if (opcion == 8) { servicioNombre = "Diagnostico electronico";      servicioPrecio = 50;  servicioManoDeObra = 15; }
            else if (opcion == 9) { servicioNombre = "Reparacion de suspension";     servicioPrecio = 150; servicioManoDeObra = 40; }
            else if (opcion == 10) { servicioNombre = "Limpieza de inyectores";       servicioPrecio = 70;  servicioManoDeObra = 20; }
            else {
                cout << "\nError: Opcion invalida. Por favor, intente de nuevo.\n\n";
                opcionValida = false;
            }
        }
    }


    void facturarModuloJosue(vector<clientes>& listaclientes) {
        borrar();
        cout << "====================================\n";
        cout << "   FACTURAR CLIENTE EXISTENTE (JOSUE) \n";
        cout << "====================================\n";

        if (listaclientes.empty()) {
            cout << "No hay clientes registrados en el sistema principal todavía.\n";
            pausa();
            return;
        }

        int buscarnum;
        cout << "Ingrese el número de cliente que va a realizar la factura: ";
        cin >> buscarnum;

        bool encontrado = false;
        for (clientes& c : listaclientes) {
            if (c.getncliente() == buscarnum) {
                encontrado = true;

               
                this->arrancarModulo(c.getnom(), c.getced());
                break;
            }
        }

        if (!encontrado) {
            cout << "Error: No se encontró ningún cliente con el número " << buscarnum << endl;
            pausa();
        }
        borrar();
    }

    void arrancarModulo(string nombreSistema, int cedulaSistema) {
        clienteNombre = nombreSistema;
        clienteCedula = to_string(cedulaSistema);

        repetir = 1;
        while (repetir == 1) {
            cout << "   TALLER MECANICO Factura   \n" << endl;
            cout << "\033[96m";
            cout << "--- Cliente Cargado: " << clienteNombre << " (Ced: " << clienteCedula << ") ---\n";
            cout << "Ingrese el descuento para esta factura (%): ";
            cin >> clienteDescuento;
            cout << "\033[0m\n";

            seleccionarServicio();

            calcularTotal();
            cout << endl;
            mostrarFactura();

            cout << "\nDesea ingresar otra factura para este mismo cliente?\n1. Si\n2. No\nOpcion: ";
            cin >> repetir;

            if (repetir != 1 && repetir != 2) {
                cout << "Opcion invalida. Saliendo..." << endl;
                break;
            }
            cout << endl;
        }
        cout << "Saliendo del modulo de facturacion..." << endl;
    }
};
