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
        cout << gestionA[indice];
    } else if (tipo == 2) {
        cout << gestionP[indice];
    }
}

void SistemaGestion::acceso(int nro) {
    if (nro > cantidadCuentas || nro <= 0) {
        throw out_of_range("El numero de cuenta ingresado no existe\n");
    }

    int menu;

    //Cuentas Administrativas
    for (int i = 0; i < gestionA.size(); i++) {
        if (gestionA[i].get_cuenta().get_nro() == nro) {

            if (gestionA[i].get_estado()) {
                do {
                    cout << "Cuenta Encontrada!\n";
                    cout << "Que operacion desea realizar " << gestionA[i].get_nombre() << "?\n";
                    cout << "1: Mostrar Datos\n";
                    cout << "2: Depositar\n";
                    cout << "3: Extraer\n";
                    cout << "4: Baja\n";
                    cout << "5: Alta\n"; //Falta Implementar!!
                    cin >> menu;
                } while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5);
            } else {
                cout << gestionA[i];
                do {
                    cout << "Desea dar de Alta su cuenta nuevamente?\n";
                    cout << "5: SI\n";
                    cout << "0: NO\n";
                    cin >> menu;
                } while (menu != 0 && menu != 5);
            }

            if (menu == 1) {
                mostrarCuenta(i, 1);
            } else if (menu == 2) {

                while (true) {
                    float monto;
                    cout << "Ingrese el monto a depositar:\n";
                    cin >> monto;

                    try {
                        gestionA[i].get_cuenta().deposito(monto);
                        cout << "Se ha depositado correctamente $" << monto << '\n';
                        cout << gestionA[i].get_cuenta();
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
                        cout << "Se ha extraido correctamente $" << monto << '\n';
                        cout << gestionA[i].get_cuenta();
                        break;
                    }
                    catch (invalid_argument &Error) {
                        cout << "Error: " << Error.what();
                        continue;
                    }
                }
            } else if (menu == 4) {

                gestionA[i].baja();
                cout << "Su cuenta fue dada de baja exitosamente\n";
            } else if (menu == 5) {

                if (gestionA[i].get_estado()) {
                    cout << "Su cuenta ya está de Alta\n";
                } else {
                    gestionA[i].alta();
                    cout << "Su cuenta fue dada de Alta exitosamente\n";
                }
            }
            break;
        }
    }

    //Cuentas Profesionales
    for (int i = 0; i < gestionP.size(); i++) {
        if (gestionP[i].get_cuenta().get_nro() == nro) {

            if (gestionP[i].get_estado()) {
                do {
                    cout << "Cuenta Encontrada!\n";
                    cout << "Que operacion desea realizar " << gestionP[i].get_nombre() << "?\n";
                    cout << "1: Mostrar Datos\n";
                    cout << "2: Depositar\n";
                    cout << "3: Extraer\n";
                    cout << "4: Baja\n";
                    cout << "5: Alta\n"; //Falta Implementar!!
                    cout << "6: Usar Tarjeta de Credito\n";
                    cout << "7: Pagar Resumen\n";
                    cin >> menu;
                } while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 6 && menu != 7);
            } else {
                cout << gestionP[i];
                do {
                    cout << "Desea dar de Alta su cuenta nuevamente?\n";
                    cout << "5: SI\n";
                    cout << "0: NO\n";
                    cin >> menu;
                } while (menu != 0 && menu != 5);
            }

            if (menu == 1) {
                mostrarCuenta(i, 2);
            } else if (menu == 2) {
                while (true) {

                    float monto;
                    cout << "Ingrese el monto a depositar:\n";
                    cin >> monto;

                    try {
                        gestionP[i].get_cuenta().deposito(monto);
                        cout << "Se ha depositado correctamente $" << monto << '\n';
                        cout << gestionP[i].get_cuenta();
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
                        gestionP[i].get_cuenta().extraccion(monto);
                        cout << "Se ha extraido correctamente $" << monto << '\n';
                        cout << gestionP[i].get_cuenta();
                        break;
                    }
                    catch (invalid_argument &Error) {
                        cout << "Error: " << Error.what();
                        continue;
                    }
                }
            } else if (menu == 4) {

                gestionP[i].baja();
                cout << "Su cuenta fue dada de baja exitosamente\n";
            } else if (menu == 5) {

                if (gestionP[i].get_estado()) {
                    cout << "Su cuenta ya está de Alta\n";
                } else {
                    gestionP[i].alta();
                    cout << "Su cuenta fue dada de Alta exitosamente\n";
                }
            } else if (menu == 6) {

                while (true) {
                    float monto;
                    cout << "Ingrese el monto a pagar con tarjeta:\n";
                    cin >> monto;

                    try {
                        gestionP[i].get_tarjeta().usarTarjeta(monto);
                        cout << "Pago con tarjeta por $" << monto << " registrado" << '\n';
                        break;
                    }
                    catch (invalid_argument &Error) {
                        cout << "Error: " << Error.what();
                        continue;
                    }
                }
            } else if (menu == 7) {

                gestionP[i].pagarResumen();
                cout << "Su saldo actual es: " << gestionP[i].get_cuenta().get_saldo() << '\n';
                cout << "Su deuda de tarjeta es: " << gestionP[i].get_tarjeta().get_gastado() << '\n';
            }
            break;
        }
    }
}

int SistemaGestion::get_cantidad() const {
    return cantidadCuentas;
}

void SistemaGestion::mostrarTodo() {

    cout << "Cuentas Administrativas:\n";

    for (auto &i: gestionA) {
        cout << i;
        cout << "\n\n";
    }

    cout << "\n\n\nCuentas Profesionales:\n";
    for (auto &i: gestionP) {
        cout << i;
        cout << "\n\n";
    }
}


