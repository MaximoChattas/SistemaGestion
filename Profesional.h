//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_PROFESIONAL_H
#define PARCIAL_2_PROFESIONAL_H

#include "Empleado.h"
#include "TarjetaCredito.h"


class Profesional : public Empleado {
public:
    Profesional(int, const string&, const string&, float, int, const string&, const string&, int);

    void baja() override;

    TarjetaCredito get_tarjeta();

    void pagarResumen();

    friend std::ostream &operator<<(std::ostream &os, const Profesional &profesional);

private:
    string titulo;
    string actividad;
    int antiguedad;
    TarjetaCredito tarjeta;

};


#endif //PARCIAL_2_PROFESIONAL_H
