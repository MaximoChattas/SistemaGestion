//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_TARJETACREDITO_H
#define PARCIAL_2_TARJETACREDITO_H

#include <string>

using namespace std;

class TarjetaCredito {
public:
    TarjetaCredito(int, float);

    ~TarjetaCredito();

    float get_gastado() const;

    void usarTarjeta(float);

    void pagarTarjeta(float);

    friend std::ostream &operator<<(std::ostream &os, const TarjetaCredito &tarjeta);


private:
    int numero;
    float limite;
    string categoria;
    float gastado = 0;

};


#endif //PARCIAL_2_TARJETACREDITO_H
