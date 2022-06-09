//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_EMPLEADO_H
#define PARCIAL_2_EMPLEADO_H

#include <string>
#include "CuentaBancaria.h"

using namespace std;

class Empleado {
public:
    Empleado(int, const string &, const string &, float, int);

    string get_nombre();

    bool get_estado() const;

    CuentaBancaria &get_cuenta();

    virtual void baja() = 0;
    virtual void alta();

protected:
    int dni;
    string nombre;
    string mail;
    float sueldo;
    bool estado = true;

    CuentaBancaria cuentaSueldo;

};


#endif //PARCIAL_2_EMPLEADO_H
