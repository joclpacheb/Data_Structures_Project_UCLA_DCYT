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
    MEstacion mest; //lista
    //MBahia mbah; //cola
    MVehiculo mveh; //pila

    VEstacion vest;
public:
    Controlador();
    void Menu();
    void OpcionBahia();
    void OpcionVehiculo();
    void OpcionAyuda();
    void OpcionSalir();
    void CargarBahias();
    void ConsultarBahia();
    void AddCarToQueue();
    void IncluirBahia();
    void ProcessVehicleInQueue();
};

#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
