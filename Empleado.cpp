//
// Created by Maximo Chattas on 30/05/2022.
//

#include "Empleado.h"
#include <stdexcept>

using namespace std;

Empleado::Empleado(int t_dni, const string &t_nombre, const string &t_mail, float t_sueldo, int t_nro) :
        dni{t_dni},
        nombre{t_nombre},
        mail{t_mail},
        sueldo{t_sueldo},
        cuentaSueldo(t_nro, sueldo) {
    if (t_sueldo <= 0) {
        throw invalid_argument("El sueldo debe ser mayor a 0\n");
    }

    if (t_dni <= 0) {
        throw invalid_argument("El numero de DNI debe ser mayor o igual a 0\n");
    }

    if (t_nombre.empty()) {
        throw invalid_argument("El nombre no puede estar vacio\n");
    }

    if (t_mail.empty()) {
        throw invalid_argument("El mail no puede estar vacio\n");
    }
}

string Empleado::get_nombre() {
    return nombre;
}

CuentaBancaria & Empleado::get_cuenta() {
    return cuentaSueldo;
}

bool Empleado::get_estado() const {
    return estado;
}

void Empleado::alta() {
    estado = true;
}
