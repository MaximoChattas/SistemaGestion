//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Administrativo.h"
#include <iostream>

Administrativo::Administrativo(int t_dni , const string& t_nombre , const string& t_mail , float t_sueldo, int t_nro , const string& t_puesto):
Empleado(t_dni , t_nombre , t_mail , t_sueldo , t_nro),
puesto{t_puesto}
{
    if (t_puesto.empty())
    {
        throw invalid_argument ("Debe especificar el puesto de trabajo\n");
    }

}

std::ostream &operator<<(ostream &os, const Administrativo &administrativo) {

    os << "\n\nNombre: " << administrativo.nombre << '\n';
    os << "DNI: " << administrativo.dni << '\n';
    os << "Mail: " << administrativo.mail << '\n';
    os << "Sueldo: $" << administrativo.sueldo << '\n';
    os << "Puesto: " << administrativo.puesto << '\n';
    if (administrativo.estado)
    {
        os << "Estado: ALTA\n";
        os << administrativo.cuentaSueldo;
    } else
    {
        os << "Estado: BAJA\n";
    }
    return os;
}

void Administrativo::baja() {
    estado = false;
}
