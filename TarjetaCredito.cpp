//
// Created by Maximo Chattas on 30/05/2022.
//

#include "TarjetaCredito.h"
#include <stdexcept>
#include <iostream>

using namespace std;

TarjetaCredito::TarjetaCredito(int t_nro, float sueldo) : numero{t_nro} {
    if (t_nro <= 0) {
        throw invalid_argument("El numero de tarjeta debe ser positivo");
    }

    if (sueldo <= 50000) {
        limite = 20000;
        categoria = "Bronce";
    } else if (sueldo <= 100000) {
        limite = 60000;
        categoria = "Plata";
    } else {
        limite = 100000;
        categoria = "Oro";
    }
}

void TarjetaCredito::usarTarjeta(float monto) {
    if (monto <= 0) {
        throw invalid_argument("El monto gastado debe ser mayor a 0\n");
    } else if (gastado + monto > limite) {
        throw invalid_argument("Se excedió del límite\n");
    }

    gastado += monto;


}

std::ostream &operator<<(ostream &os, const TarjetaCredito &tarjeta) {
    os << "\tNumero: " << tarjeta.numero << '\n';
    os << "\tCategoria: " << tarjeta.categoria << '\n';
    os << "\tLimite: $" << tarjeta.limite << '\n';
    os << "\tUtilizado: $" << tarjeta.gastado << "\n\n";
    return os;
}

float TarjetaCredito::get_gastado() const {
    return gastado;
}

void TarjetaCredito::pagarTarjeta(float monto) {

    if (monto > gastado) {
        throw invalid_argument("El monto que desea pagar es mayor a su deuda actual\n");
    }

    if (monto < 0) {
        throw invalid_argument("Ingrese un monto positivo a pagar\n");
    }

    gastado -= monto;
}

TarjetaCredito::~TarjetaCredito() = default;
