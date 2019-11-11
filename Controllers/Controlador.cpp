//
// Created by dany on 11/10/19.
//
#include "Controlador.h"

Controlador::Controlador() {}

void Controlador::Menu(){
    int opc;
    VGeneral  vg;
    Controlador c;
    //vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  O P C I O N E S\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Bahía\n");
        vg.ImprimirMensaje("   2. Vehículo\n");
        vg.ImprimirMensaje("   3. Reportes\n");
        vg.ImprimirMensaje("   4. Tabla de Multiplicar\n");
        vg.ImprimirMensaje("   5. Ayuda\n");
        vg.ImprimirMensaje("   6. Salir\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-6): ",1,6);
        switch (opc)
        {
            case 1: OpcionLista();
                break;
            case 2:  OpcionPila();
                break;
            case 3:  OpcionCola();
                break;
            case 4:  OpcionTabla();
                break;
            case 5: OpcionAyuda();
                break;
            case 6: OpcionSalir();
        }
    }
    while(opc != 6);
}