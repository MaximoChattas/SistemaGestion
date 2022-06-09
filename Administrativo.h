//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_ADMINISTRATIVO_H
#define PARCIAL_2_ADMINISTRATIVO_H


#include "Empleado.h"
#include "CuentaBancaria.h"

class Administrativo: public Empleado {
public:
    Administrativo(int , const string& , const string& , float , int , const string&);

    friend std::ostream &operator<<(std::ostream &os, const Administrativo &administrativo);

    void baja() override;


private:
    string puesto;
};


#endif //PARCIAL_2_ADMINISTRATIVO_H
