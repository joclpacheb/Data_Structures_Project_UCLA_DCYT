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
    MBahia mbah; //cola
    MVehiculo mveh; //pila

    VEstacion vest;
    bool check;
    int j,w;
public:
    Controlador();

    //Menu Methods
    void Menu();
    void OpcionBahia();
    void OpcionVehiculo();
    void OpcionAyuda();
    void OpcionSalir();

    //Bahia Methods
    void CargarDosBahias();
    void CargarBahias();
    void IncluirBahia();
    void ConsultarBahia();
    void ModificarBahia();
    void EliminarBahia();

    //Vehicle Methods
    void AddCarToQueue();
    void ConsultarVehiculo();
    void ProcessVehicleInQueue();
    void EliminarVehiculo();
};

#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
