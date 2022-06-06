//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Administrativo.h"

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
