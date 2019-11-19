//
// Created by dany on 11/10/19.
//

#include "VBahia.h"

VBahia::VBahia() {}

void VBahia::ImprimirBahia(string vehiculo, string placa, int cantlitro, float bs, float time) {
    Limpiar();
    ImprimirEncabezado("  INFORMACION DE BAHIAS",
                       "  ======================");
    ImprimirString("\n\n  Vehículo ", vehiculo);
    ImprimirString("\n\n  Placa: ", placa);
    ImprimirNro("\n\n  Cantidad de combustible en litros: ", cantlitro);
    ImprimirNroDecimal("\n\n  Bs. : ", bs);
    ImprimirNroDecimal("\n\n  Tiempo en cola: ", time);
    ImprimirLineasBlanco(2);
    //Pausa();//

}