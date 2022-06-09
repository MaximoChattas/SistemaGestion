//
// Created by Maximo Chattas on 31/05/2022.
//

#ifndef PARCIAL_2_SISTEMAGESTION_H
#define PARCIAL_2_SISTEMAGESTION_H

#include <vector>
#include "Empleado.h"
#include "Profesional.h"
#include "Administrativo.h"

using namespace std;

class SistemaGestion {

public:
    SistemaGestion();

    void nuevaCuenta();

    void acceso(int);

    void mostrarCuenta(int, int);

    void mostrarTodo();

    int get_cantidad() const;


private:
    int cantidadCuentas = 0;
    vector<Profesional> gestionP;
    vector<Administrativo> gestionA;
};


#endif //PARCIAL_2_SISTEMAGESTION_H
