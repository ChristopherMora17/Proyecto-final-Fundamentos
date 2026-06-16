//Parte de christopher

#pragma once
#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;


void borrar() {
	std::cout << "\033[2J\033[1;1H";
}
void limpiarbuffer() {
	std::cin.clear();
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pausa() {
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	std::cin.get();
}

struct clientes {

private:
	string nombre;
	string apellido1;
	string apellido2;
	int edad;
	int cedula;
	int Ncliente = 0;

public:
	clientes(string _nombre, string _apellido1, string _apellido2, int _edad, int _cedula, int _Ncliente) {
		nombre = _nombre;
		apellido1 = _apellido1;
		apellido2 = _apellido2;
		edad = _edad;
		cedula = _cedula;
		Ncliente = _Ncliente;
	}

	bool informacion() {
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido 1: " << apellido1 << endl;
		cout << "Apellido 2: " << apellido2 << endl;
		cout << "Edad: " << edad << endl;
		cout << "Cedúla: " << cedula << endl;
		cout << "Número de cliente: " << Ncliente << endl;

		return true;

	}

	void setnom(string _nombre) {
		nombre = _nombre;
	}

	void setape1(string _apellido1) {
		apellido1 = _apellido1;
	}
	void setape2(string _apellido2) {
		apellido2 = _apellido2;
	}
	void seted(int _edad) {
		edad = _edad;
	}

	void setced(int _cedula) {
		cedula = _cedula;
	}

	int getncliente() {
		return Ncliente;
	}

	string getnom() { return nombre; }
	int getced() { return cedula; }
};

class sistemac {

private:
	vector<clientes> listaclientes;
	bool corriendo = true;

	void casierror() {
		borrar();
		cout << "\nNada que ver (Toca enter para continuar)" << endl;
		pausa();
		while (true) {
			std::this_thread::sleep_for(chrono::milliseconds(1));
		}
		borrar();
	}

	void registrar() {
		borrar();
		string nom, ape1, ape2;
		int ed, ced;

		cout << "================================" << endl;
		cout << "registro de clientes" << endl;
		cout << "================================" << endl;

		cout << "Ingrese el nombre del cliente: ";
		cin >> nom;
		while (any_of(nom.begin(), nom.end(), [](unsigned char c) {return isdigit(c);})) {
			borrar();
			cout << "Error el nombre no puede contener números, intente de nuevo:" << endl;
			cin >> nom;
		}

		cout << "Ingrese el primer apellido del cliente: ";
		cin >> ape1;
		while (any_of(ape1.begin(), ape1.end(), [](unsigned char c) {return isdigit(c);})) {
			borrar();
			cout << "Error el primer apellido no puede contener números, intente de nuevo:" << endl;
			cin >> ape1;
		}

		cout << "Ingrese el segundo apellido del cliente: ";
		cin >> ape2;
		while (any_of(ape2.begin(), ape2.end(), [](unsigned char c) {return isdigit(c);})) {
			borrar();
			cout << "Error el segundo apellido no puede contener números, intente de nuevo:" << endl;
			cin >> ape2;
		}

		cout << "Ingrese la edad del cliente: ";
		while (!(cin >> ed) || ed < 18 || ed > 120) {
			borrar();
			cout << "Error. La edad ddebe ser un número entero entre 18 y 120." << endl;
			limpiarbuffer();
			cout << "Ingrese la edad del cliente: ";
		}

		cout << "Ingrese la cedula del cliente: ";
		while (!(cin >> ced)) {
			borrar();
			cout << "Error. La cédula debe ser un número entero. Intente de nuevo." << endl;
			limpiarbuffer();
			cout << "Ingrese la cedula del cliente: ";
		}

		int Nuliente = listaclientes.size() + 1;

		listaclientes.push_back(clientes(nom, ape1, ape2, ed, ced, Nuliente));

		cout << "\nCliente agregado con exito (Toca enter para continuar)" << endl;
		cout << "El numero de cliente es: " << Nuliente << endl;
		pausa();
		borrar();
	}

	void mostrar() {
		borrar();
		cout << "================================" << endl;
		cout << "Información de clientes ya existentes" << endl;
		cout << "================================" << endl;
		if (listaclientes.empty()) {
			cout << "No hay clientes registrados para mostrar" << endl;
		}
		else {
			for (clientes c : listaclientes) {
				c.informacion();
				cout << "-----------------------------" << endl;
			}
		}
		pausa();
		borrar();
	}

	void editar() {
		borrar();
		cout << "================================" << endl;
		cout << "Editar información de un cliente" << endl;
		cout << "================================" << endl;
		if (listaclientes.empty()) {
			cout << "No hay clientes registrados para editar" << endl;
		}
		else {
			int buscarnum;
			cout << "Ingrese el número de cliente que desea editar: ";
			cin >> buscarnum;

			bool encontrado = false;

			for (clientes& c : listaclientes) {
				if (c.getncliente() == buscarnum) {
					encontrado = true;
					borrar();
					cout << "--- Editando cliente número " << buscarnum << "---\n";

					limpiarbuffer();

					string nuevonom, nuevoape1, nuevoape2;

					cout << "Ingrese el nuevo nombre (o presione enter para mantener el actual): ";
					getline(cin, nuevonom);

					if (!nuevonom.empty()) {
						while (any_of(nuevonom.begin(), nuevonom.end(), [](unsigned char c) { return isdigit(c); })) {
							borrar();
							cout << "Error: El nombre no puede contener números. Intente de nuevo: ";
							getline(cin, nuevonom);
						}
						c.setnom(nuevonom);
						cout << "Nombre actualizado.\n";
					}
					else {
						cout << "Se mantiene el nombre actual.\n";
					}

					cout << "\nIngrese el nuevo primer apellido (o presione enter para mantener el actual): ";
					getline(cin, nuevoape1);

					if (!nuevoape1.empty()) {
						while (any_of(nuevoape1.begin(), nuevoape1.end(), [](unsigned char c) { return isdigit(c); })) {
							borrar();
							cout << "Error: El apellido no puede contener números. Intente de nuevo: ";
							getline(cin, nuevoape1);
						}
						c.setape1(nuevoape1);
						cout << "Primer apellido actualizado.\n";
					}
					else {
						cout << "Se mantiene el primer apellido actual.\n";
					}

					cout << "\nIngrese el nuevo segundo apellido (o presione enter para mantener el actual): ";
					getline(cin, nuevoape2);

					if (!nuevoape2.empty()) {
						while (any_of(nuevoape2.begin(), nuevoape2.end(), [](unsigned char c) { return isdigit(c); })) {
							borrar();
							cout << "Error: El apellido no puede contener números. Intente de nuevo: ";
							getline(cin, nuevoape2);
						}
						c.setape2(nuevoape2);
						cout << "Segundo apellido acctualizado.\n";
					}
					else {
						cout << "Se mantiene el segundo apellido actual.\n";
					}

					cout << "\nCliente editado con éxito (Toca enter para continuar)" << endl;
					break;
				}
			}
			if (!encontrado) {
				cout << "No se encontró ningun cliente con el número " << buscarnum << endl;
			}
		}
		std::cin.get();
		borrar();
	}

	void eliminar() {
		borrar();
		cout << "================================" << endl;
		cout << "Eliminar un cliente" << endl;
		cout << "================================" << endl;

		if (listaclientes.empty()) {
			cout << "No hay clientes registrados aun.\n";
			cin.get();
			return;
		}
		int buscarnum;
		cout << "Ingrese el número de cliente que desea eliminar: ";
		cin >> buscarnum;

		bool encontrado = false;

		for (auto it = listaclientes.begin(); it != listaclientes.end(); ++it) {
			if (it->getncliente() == buscarnum) {
				encontrado = true;

				borrar();
				cout << "--- Cliente encontrado ---\n";
				it->informacion();

				char confirmar;
				cout << "\n¿Estas seguro de eliminar al cliente numero " << buscarnum << "? (s/n): ";
				cin >> confirmar;

				if (confirmar == 's' || confirmar == 'S') {
					listaclientes.erase(it);
					cout << "\nCliente eliminnado con exito.\n";
				}
				else {
					cout << "\nOperación cancelada, no se borro nada.\n";
				}
				break;
			}
		}

		if (!encontrado) {
			cout << "No se encontró ningun cliente con el número " << buscarnum << endl;
			cin.get();
		}
		else {
			pausa();
		}
		borrar();
	}

	void menu() {
		cout << "================================" << endl;
		cout << "Bienvenido a sistema de gestion de clientes" << endl;
		cout << "¿Qué desea hacer?" << endl;
		cout << "1. Agregar un cliente" << endl;
		cout << "2. Mostrar información de clientes ya existentes" << endl;
		cout << "3. Editar información de un cliente" << endl;
		cout << "4. Eliminar un cliente" << endl;
		cout << "5. Salir" << endl;
		cout << "================================" << endl;
	}

public:

	sistemac() {
		listaclientes.push_back(clientes{ "Christopher", "Mora", "Madriz", 18, 209000762, 1 });
		listaclientes.push_back(clientes{ "Jouse", "Jimenez", "Seas", 18, 504760177, 2 });
		listaclientes.push_back(clientes{ "Hector", "Molina", "Chaverri", 18, 208970277 , 3 });
		listaclientes.push_back(clientes{ "Mauro", "Carrillo", "Blanco", 18, 504790479, 4 });
	}

	void ejecutar() {

		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);

		string salida;

		while (corriendo) {
			menu();
			cin >> salida;

			if (salida == "1") registrar();
			else if (salida == "2") mostrar();
			else if (salida == "3") editar();
			else if (salida == "4") eliminar();
			else if (salida == "5") corriendo = false;
			else if (salida == "0" || salida == "67") casierror();
			else {
				borrar();
				cout << "Opcion no valida. Intente otra vez (1-5).\n" << endl;
			}
		}
		borrar(),
			cout << "================================" << endl;
		cout << "Gracias por usar el sistema." << endl;
		cout << "================================" << endl;
	}
	vector<clientes>& getListaClientes() { return listaclientes; }
};