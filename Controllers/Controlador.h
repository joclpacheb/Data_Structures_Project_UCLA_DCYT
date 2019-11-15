//
// Created by dany on 11/10/19.
//

#ifndef DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
#define DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H

#include "../Models/MEstacion.h"
#include "../Views/VEstacion.h"
#include "../Views/VBahia.h"
#include "../Views/VVehiculo.h"

class Controlador {
private:
    MBahia mbah;
    MEstacion mest;
    MVehiculo mveh;

    VEstacion vest;
public:
    Controlador();
    void Menu();
    void OpcionBahia();
    void OpcionVehiculo();
    void OpcionAyuda();
    void OpcionSalir();
    void IncluirBahia();
    void CargarBahias();
    void ConsultarBahia();
    void AddCarToQueue();
};

#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
