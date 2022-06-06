//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_CUENTABANCARIA_H
#define PARCIAL_2_CUENTABANCARIA_H

#include <string>
#include <exception>
using namespace std;

class CuentaBancaria {

public:
    CuentaBancaria(int , float);
    ~CuentaBancaria();

    int get_nro();
    float get_saldo();

    void deposito(float);
    void extraccion(float);

private:
   int cuentaNro;
   float saldo;
};


#endif //PARCIAL_2_CUENTABANCARIA_H
