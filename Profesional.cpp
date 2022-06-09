//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Profesional.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Profesional::Profesional(int t_dni, const string &t_nombre, const string &t_mail, float t_sueldo, int t_nro,
                         const string &t_titulo, const string &t_actividad, int t_antiguedad) :
        Empleado(t_dni, t_nombre, t_mail, t_sueldo, t_nro),
        titulo{t_titulo},
        actividad{t_actividad},
        antiguedad{t_antiguedad},
        tarjeta(t_nro, t_sueldo) {
    if (t_titulo.empty()) {
        throw invalid_argument("Debe especificar el titulo del profesional\n");
    }

    if (t_actividad.empty()) {
        throw invalid_argument("Debe especificar la actividad que desarrolla el profesional\n");
    }

    if (t_antiguedad < 0) {
        throw invalid_argument("La antiguedad del profesional debe ser mayor o igual a 0 años\n");
    }

    if (t_sueldo < 20000) {
        throw invalid_argument("El sueldo minimo de un profesional es $20.000\n");
    }

}

TarjetaCredito & Profesional::get_tarjeta() {
    return tarjeta;
}

void Profesional::baja() {
    estado = false;
    cuentaSueldo.~CuentaBancaria();
    tarjeta.~TarjetaCredito();

}

void Profesional::pagarResumen() {

    if (cuentaSueldo.get_saldo() >= tarjeta.get_gastado()) {
        tarjeta.pagarTarjeta(tarjeta.get_gastado());
        cuentaSueldo.extraccion(tarjeta.get_gastado());
    } else {
        tarjeta.pagarTarjeta(cuentaSueldo.get_saldo());
        cuentaSueldo.extraccion(cuentaSueldo.get_saldo());
    }

}

std::ostream &operator<<(ostream &os, const Profesional &profesional) {

    os << "\n\nNombre: " << profesional.nombre << '\n';
    os << "DNI: " << profesional.dni << '\n';
    os << "Mail: " << profesional.mail << '\n';
    os << "Sueldo: $" << profesional.sueldo << '\n';
    os << "Titulo: " << profesional.titulo << '\n';
    os << "Actividad: " << profesional.actividad << '\n';
    os << "Antiguedad: " << profesional.antiguedad << " anios\n";
    if (profesional.estado) {
        os << profesional.cuentaSueldo;
        os << "Tarjeta de Credito:\n";
        os << profesional.tarjeta;
    } else {
        os << "Estado: BAJA\n";
    }
    return os;
}
