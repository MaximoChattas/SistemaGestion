//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Administrativo.h"
#include <iostream>

Administrativo::Administrativo(int t_dni , string t_nombre , string t_mail , float t_sueldo, int t_nro , string t_puesto):
Empleado(t_dni , t_nombre , t_mail , t_sueldo , t_nro),
puesto{t_puesto}
{
    if (t_puesto.empty())
    {
        throw invalid_argument ("Debe especificar el puesto de trabajo\n");
    }

}

string Administrativo::get_puesto() {
    return puesto;
}

void Administrativo::baja() {
    cuentaSueldo.~CuentaBancaria();

}

std::ostream &operator<<(ostream &os, const Administrativo &administrativo) {

    cout << "\n\nNombre: " << administrativo.nombre << '\n';
    cout << "DNI: " << administrativo.dni << '\n';
    cout << "Mail: " << administrativo.mail << '\n';
    cout << "Sueldo: $" << administrativo.sueldo << '\n';
    cout << "Puesto: " << administrativo.puesto << '\n';
    cout << administrativo.cuentaSueldo;
    return os;
}
