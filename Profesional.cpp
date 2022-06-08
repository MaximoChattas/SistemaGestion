//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Profesional.h"
#include <stdexcept>
#include <iostream>

using namespace std;
Profesional::Profesional(int t_dni , string t_nombre , string t_mail , float t_sueldo, int t_nro , string t_titulo , string t_actividad, int t_antiguedad):
        Empleado(t_dni , t_nombre , t_mail , t_sueldo , t_nro),
        titulo{t_titulo},
        actividad{t_actividad},
        antiguedad{t_antiguedad},
        tarjeta(t_nro , t_sueldo)
{
    if (t_titulo.empty())
    {
        throw invalid_argument ("Debe especificar el titulo del profesional\n");
    }

    if (t_actividad.empty())
    {
        throw invalid_argument ("Debe especificar la actividad que desarrolla el profesional\n");
    }

    if (t_antiguedad < 0)
    {
        throw invalid_argument ("La antiguedad del profesional debe ser mayor o igual a 0 años\n");
    }

    if (t_sueldo < 20000)
    {
        throw invalid_argument("El sueldo minimo de un profesional es $20.000\n");
    }

}

void Profesional::baja() {
    estado = false;
    cuentaSueldo.~CuentaBancaria();
    tarjeta.~TarjetaCredito();

}

std::ostream &operator<<(ostream &os, const Profesional &profesional) {

    cout << "\n\nNombre: " << profesional.nombre << '\n';
    cout << "DNI: " << profesional.dni << '\n';
    cout << "Mail: " << profesional.mail << '\n';
    cout << "Sueldo: $" << profesional.sueldo << '\n';
    cout << "Titulo: " << profesional.titulo << '\n';
    cout << "Actividad: " << profesional.actividad << '\n';
    cout << "Antiguedad: " << profesional.antiguedad << " anios\n";
    if (profesional.estado)
    {
        cout << profesional.cuentaSueldo;
        cout << "Tarjeta de Credito:\n";
        cout << profesional.tarjeta;
    } else
    {
        cout << "Estado: BAJA\n";
    }
    return os;
}
