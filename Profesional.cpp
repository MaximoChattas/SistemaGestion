//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Profesional.h"
#include <stdexcept>

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
        throw invalid_argument ("Debe especificar el titulo del profesional");
    }

    if (t_actividad.empty())
    {
        throw invalid_argument ("Debe especificar la actividad que desarrolla el profesional");
    }

    if (t_antiguedad < 0)
    {
        throw invalid_argument ("La antiguedad del profesional debe ser mayor o igual a 0 años");
    }

    if (t_sueldo < 20000)
    {
        throw invalid_argument("El sueldo minimo de un profesional es $20.000");
    }

}

void Profesional::baja() {
    cuentaSueldo.~CuentaBancaria();
    tarjeta.~TarjetaCredito();

}

string Profesional::get_titulo() {
    return titulo;
}

string Profesional::get_actividad() {
    return actividad;
}

int Profesional::get_antiguedad() {
    return antiguedad;
}

TarjetaCredito Profesional::get_tarjeta() {
    return tarjeta;
}
