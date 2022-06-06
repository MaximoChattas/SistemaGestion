//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_ADMINISTRATIVO_H
#define PARCIAL_2_ADMINISTRATIVO_H


#include "Empleado.h"
#include "CuentaBancaria.h"

class Administrativo: public Empleado {
public:
    Administrativo(int , string , string , float , int , string);
    string get_puesto();
    void baja() override;


private:
    string puesto;
};


#endif //PARCIAL_2_ADMINISTRATIVO_H
