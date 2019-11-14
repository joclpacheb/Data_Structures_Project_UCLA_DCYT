//
// Created by dany on 11/10/19.
//
#include "Controlador.h"

Controlador::Controlador() {}

//============================================================
//                  GAS PUMPS METHODS                       ||
//============================================================
void Controlador::CargarBahias() {
    vest.Limpiar();
    if (mest.Empty()){
        for (int i = 1; i <= 2; ++i) { //porque son 2 bahías
            mbah.SetNumeroB(i);
            mest.InicializarBahia(mbah);
        }
        vest.ImprimirMensaje("\n ¡BAHIAS CARGADAS EXITOSAMENTE! \n");
    }else{
        vest.ImprimirMensaje("\n ¡LAS BAHIAS YA FUERON CARGADAS!\n");
    }
}

//============================================================
//                  MENU METHODS                            ||
//============================================================

void Controlador::Menu(){
    int opc;
    VGeneral  vg;
    //vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      Proyecto Programación No Numérica 1\n","      =======  ===============");
        vg.ImprimirEncabezado("\n      Estación de Servicios 'La Sin Colas'  \n","      =======  ===============");
        vg.ImprimirEncabezado("\n      M E N U  O P C I O N E S\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Bahía\n");
        vg.ImprimirMensaje("   2. Vehículo\n");
        vg.ImprimirMensaje("   3. Reportes\n");
        vg.ImprimirMensaje("   4. Ayuda\n");
        vg.ImprimirMensaje("   5. Salir\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ",1,5);
        switch (opc)
        {
            case 1: OpcionBahia();
                break;
            case 2: OpcionVehiculo();
                break;
            case 3: //OpcionReportes();
                break;
            case 4: OpcionAyuda();
                break;
            case 5: OpcionSalir();
        }
    }
    while(opc != 5);
}
void Controlador::OpcionBahia(){
    int opc;
    VGeneral  vg;
   //vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  B A H I A\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Cargar Bahías\n"); //this shit is here for the moment, I'll delete it later.
        //vg.ImprimirMensaje("   . Incluir Bahía \n");
        vg.ImprimirMensaje("   2. Modificar Bahía\n");
        vg.ImprimirMensaje("   3. Consultar Bahía\n");
        vg.ImprimirMensaje("   4. Eliminar Bahía\n");
        vg.ImprimirMensaje("   5. Volver al menú anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ",1,3);
        switch (opc)
        {
            case 1: CargarBahias();
                break;
            case 2: //ModificarBahia();
                break;
            case 3: //ConsultarBahia();
                break;
            case 4: //EliminarBahia();
                break;
        }
    }
    while(opc != 5);
}
void Controlador::OpcionVehiculo(){
    int opc;
    VGeneral  vg;
    vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  V E H I C U L O\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Incluir Vehículo\n");
        vg.ImprimirMensaje("   2. Consultar Vehículo\n");
        vg.ImprimirMensaje("   3. Eliminar Vehículo\n");
        vg.ImprimirMensaje("   4. Volver al menú anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-4): ",1,3);
        switch (opc)
        {
            case 1: //IncluirVehiculo();
                break;
            case 2: //ConsultarVehiculo();
                break;
            case 3: //EliminarVehiculo();
                break;
        }
    }
    while(opc != 4);
}
void Controlador::OpcionAyuda(){
    vest.ImprimirMensaje("  La opción 1 cargará (de manera predeterminada carga dos bahías), incluirá, consultará, modificará, y eliminará las bahías en la estación.\n");
    vest.ImprimirMensaje("  La opción 2 incluirá, consultará, y eliminará los vehículos en cola.\n");
    vest.ImprimirMensaje("  La opción 3 imprimirá un reporte indicando el tipo de vehículo, placa,"
                         "cantidad de combustible en litros y Bs. y el tiempo en cola.\n");
    vest.ImprimirMensaje("  Program created by: José Luis Pacheco & Dany Karam.\n");
}
void Controlador::OpcionSalir(){
    int opc = vest.LeerValidarNro("   ¿Está seguro que desea salir? 1.Si 2.No ",1,2);
    if(opc == 1)
        vest.Pausa();
    else
        Menu();
}