//
// Created by Maximo Chattas on 31/05/2022.
//

#include "SistemaGestion.h"
#include "Administrativo.h"
#include "Profesional.h"
#include <string>
#include <iostream>

using namespace std;

SistemaGestion::SistemaGestion() = default;


void SistemaGestion::nuevaCuenta() {

    cantidadCuentas++;
    string nombre, mail;
    int dni, tipo;
    float sueldo;

    while (true) {
        do {

            cout << "Que tipo de cuenta desea crear?\n";
            cout << "1: Administrativo\n";
            cout << "2: Profesional\n";
            cin >> tipo;
        } while (tipo != 1 && tipo != 2);

        cout << "Ingrese el Nombre completo del titular de cuenta:\n";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese el numero de DNI del titular de cuenta\n";
        cin >> dni;

        cout << "Ingrese el mail del titular de cuenta\n";
        cin.ignore();
        getline(cin, mail);

        cout << "Ingrese el sueldo del titular de cuenta\n";
        cin >> sueldo;

        //Administrativo
        if (tipo == 1) {
            string puesto;

            cout << "Ingrese el puesto que ocupa el titular de cuenta\n";
            cin.ignore();
            getline(cin, puesto);

            try {
                gestionA.push_back(Administrativo(dni, nombre, mail, sueldo, cantidadCuentas, puesto));
                cout << "Su cuenta fue creada exitosamente\n";
                cout << "Numero de cuenta: " << cantidadCuentas << '\n';
                break;

            }
            catch (invalid_argument &error) {
                cout << "Error: " << error.what();
                continue;
            }

        }

            //Profesional
        else if (tipo == 2) {
            string titulo, actividad;
            int antiguedad;

            cout << "Ingrese el titulo del profesional titular de cuenta\n";
            cin.ignore();
            getline(cin, titulo);

            cout << "Ingrese la actividad que desarrolla el titular de cuenta\n";
            cin.ignore();
            getline(cin, actividad);

            cout << "Ingrese la antiguedad del titular de cuenta\n";
            cin >> antiguedad;

            try {
                gestionP.push_back(
                        Profesional(dni, nombre, mail, sueldo, cantidadCuentas, titulo, actividad, antiguedad));
                cout << "Su cuenta fue creada exitosamente\n";
                cout << "Numero de cuenta: " << cantidadCuentas << "\n\n";
                break;
            }
            catch (invalid_argument &error) {
                cout << "Error: " << error.what();
                continue;
            }
        }
    }

}

void SistemaGestion::mostrarCuenta(int indice, int tipo) {
    if (tipo == 1) {
        cout << "\n\nNombre: " << gestionA[indice].get_nombre() << '\n';
        cout << "DNI: " << gestionA[indice].get_dni() << '\n';
        cout << "Mail: " << gestionA[indice].get_mail() << '\n';
        cout << "Sueldo: $" << gestionA[indice].get_sueldo() << '\n';
        cout << "Puesto: " << gestionA[indice].get_puesto() << '\n';
        cout << "Saldo: $" << gestionA[indice].get_cuenta().get_saldo() << "\n\n";
    } else if (tipo == 2) {
        cout << "\n\nNombre: " << gestionP[indice].get_nombre() << '\n';
        cout << "DNI: " << gestionP[indice].get_dni() << '\n';
        cout << "Mail: " << gestionP[indice].get_mail() << '\n';
        cout << "Sueldo: $" << gestionP[indice].get_sueldo() << '\n';
        cout << "Titulo: " << gestionP[indice].get_titulo() << '\n';
        cout << "Actividad: " << gestionP[indice].get_actividad() << '\n';
        cout << "Antiguedad: " << gestionP[indice].get_antiguedad() << '\n';
        cout << "Saldo: $" << gestionP[indice].get_cuenta().get_saldo() << "\n\n";
        cout << "Tarjeta de Credito:\n";
        cout << "\tNumero: " << gestionP[indice].get_tarjeta().get_numero() << '\n';
        cout << "\tCategoria: " << gestionP[indice].get_tarjeta().get_categoria() << '\n';
        cout << "\tLimite: $" << gestionP[indice].get_tarjeta().get_limite() << '\n';
        cout << "\tUtilizado: $" << gestionP[indice].get_tarjeta().get_gastado() << "\n\n";
    }
}

void SistemaGestion::acceso(int nro) {
    if (nro > cantidadCuentas || nro <= 0) {
        throw out_of_range("El numero de cuenta ingresado no existe\n");
    }

    int menu;

    for (int i = 0; i < gestionA.size(); i++) {
        if (gestionA[i].get_cuenta().get_nro() == nro) {
            do {
                cout << "Cuenta Encontrada!\n";
                cout << "Que operacion desea realizar " << gestionA[i].get_nombre() << "?\n";
                cout << "1: Mostrar Datos\n";
                cout << "2: Depositar\n";
                cout << "3: Extraer\n";
                cout << "4: Baja\n";
                cin >> menu;
            } while (menu != 1 && menu != 2 && menu != 3 && menu != 4);

            if (menu == 1) {
                mostrarCuenta(i, 1);
            } else if (menu == 2) {
                while (true) {
                    float monto;
                    cout << "Ingrese el monto a depositar:\n";
                    cin >> monto;

                    try {
                        gestionA[i].get_cuenta().deposito(monto);
                        break;
                    }
                    catch (invalid_argument &Error) {
                        cout << "Error: " << Error.what();
                        continue;
                    }
                }

            } else if (menu == 3) {
                while (true) {
                    float monto;
                    cout << "Ingrese el monto a extraer:\n";
                    cin >> monto;

                    try {
                        gestionA[i].get_cuenta().extraccion(monto);
                        break;
                    }
                    catch (invalid_argument &Error) {
                        cout << "Error: " << Error.what();
                        continue;
                    }
                }
            } else if (menu == 4)
            {
                gestionA[i].baja();
            }
            break;
        }
    }
}
