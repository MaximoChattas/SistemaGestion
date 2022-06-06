#include <iostream>
#include "CuentaBancaria.h"
#include "SistemaGestion.h"

using namespace std;

void menu(SistemaGestion);

int main() {

    SistemaGestion s1;

    menu(s1);

    return 0;
}

void menu(SistemaGestion s1)
{
    int mainMenu;
    do {
        cout << "Bienvenido\nQué operación desea realizar?\n";
        cout << "1: Registrar nueva cuenta\n";
        cout << "2: Acceder a una cuenta registrada\n";
        cout << "0: Salir\n";
        do {
            cin >> mainMenu;
        } while (mainMenu != 1 && mainMenu!=2 && mainMenu!=0);

        if (mainMenu == 1)
        {
            s1.nuevaCuenta();
        }

        if (mainMenu == 2)
        {
            while (true)
            {
                int nro;
                cout << "Ingrese el Numero de Cuenta al que desea acceder\n";
                cin >> nro;

                try {
                    s1.acceso(nro);
                    break;
                }

                catch (out_of_range &Error)
                {
                    cout << "Error: " << Error.what();
                }

            }
        }

    }while(mainMenu !=0);
}
