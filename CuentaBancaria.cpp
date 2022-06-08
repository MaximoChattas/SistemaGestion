//
// Created by Maximo Chattas on 30/05/2022.
//

#include "CuentaBancaria.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CuentaBancaria::CuentaBancaria(int t_nroCuenta, float t_saldo): cuentaNro{t_nroCuenta} , saldo{t_saldo}
{
    if (t_nroCuenta <= 0)
    {
        throw invalid_argument ("El numero de cuenta debe ser mayor a 0");
    }

    if (t_saldo <= 0)
    {
        throw invalid_argument ("El saldo debe ser mayor o igual a 0");
    }

}

int CuentaBancaria::get_nro() {
    return cuentaNro;
}

float CuentaBancaria::get_saldo() {
    return saldo;
}

void CuentaBancaria::deposito(float monto) {

    if (monto < 0)
    {
        throw invalid_argument ("Ingrese un monto positivo para depositar\n");
    }

    saldo += monto;
}

void CuentaBancaria::extraccion(float monto) {

    if (monto < 0)
    {
        throw invalid_argument ("Ingrese un monto positivo para depositar\n");
    }

    if (saldo - monto < 0)
    {
        throw invalid_argument ("Su saldo no es suficiente\n");
    }

    saldo -= monto;
}

std::ostream &operator<<(ostream &os, const CuentaBancaria &cuenta) {
    cout << "Saldo: $" << cuenta.saldo << '\n';
    return os;
}

CuentaBancaria::~CuentaBancaria() = default;
