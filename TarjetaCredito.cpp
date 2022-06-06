//
// Created by Maximo Chattas on 30/05/2022.
//

#include "TarjetaCredito.h"
#include <stdexcept>

using namespace std;

TarjetaCredito::TarjetaCredito(int t_nro , float sueldo): numero{t_nro}
{
    if (t_nro <= 0)
    {
        throw invalid_argument ("El numero de tarjeta debe ser positivo");
    }

    if (sueldo <= 50000)
    {
        limite = 20000;
        categoria = "Bronce";
    }

    else if (sueldo <= 100000)
    {
        limite = 60000;
        categoria = "Plata";
    }

    else
    {
        limite = 100000;
        categoria = "Oro";
    }
}

void TarjetaCredito::usarTarjeta(float monto) {
    if(monto <= 0)
    {
        throw invalid_argument("El monto gastado debe ser mayor a 0");
    }

    else if (gastado+monto > limite)
    {
        throw invalid_argument("Se excedió del límite");
    }

    gastado+=monto;


}

int TarjetaCredito::get_numero() {
    return numero;
}

float TarjetaCredito::get_limite() {
    return limite;
}

string TarjetaCredito::get_categoria() {
    return categoria;
}

float TarjetaCredito::get_gastado() {
    return gastado;
}

TarjetaCredito::~TarjetaCredito() = default;
