//
// Created by Maximo Chattas on 30/05/2022.
//

#ifndef PARCIAL_2_TARJETACREDITO_H
#define PARCIAL_2_TARJETACREDITO_H

#include <string>
using namespace std;

class TarjetaCredito {
public:
    TarjetaCredito(int , float);
    ~TarjetaCredito();
    void usarTarjeta(float);

    int get_numero();
    float get_limite();
    string get_categoria();
    float get_gastado();

    friend std::ostream &operator<<(std::ostream &os, const TarjetaCredito &tarjeta);


private:
    int numero;
    float limite;
    string categoria;
    float gastado = 0;

};


#endif //PARCIAL_2_TARJETACREDITO_H
