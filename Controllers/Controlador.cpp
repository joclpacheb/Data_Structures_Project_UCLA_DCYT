//
// Created by dany on 11/10/19.
//
#include "Controlador.h"

Controlador::Controlador() {
    this->check = true;
}

//============================================================
//                  GAS PUMPS METHODS                       ||
//============================================================

//This method works only to pre-load two gas pumps for default.
void Controlador::CargarDosBahias() {
    vest.Limpiar();
    if (mest.Empty()) {
            for (int i = 1; i <= 2; ++i) { //porque son 2 bahías
                //mbah.SetNumeroB(i);
                mest.InicializarBahia(mbah);
            }
        vest.ImprimirMensaje("\n ¡Bahías cargadas exitosamente! \n");
        vest.ImprimirNro("\n N# de bahías cargadas: ", mest.ContarBahia());
    } else {
        vest.ImprimirMensaje("\n ¡Las bahías ya fueron cargadas!\n");
    }
    vest.Pausa();
}

void Controlador::CargarBahias() {
    vest.Limpiar();
    if (mest.Empty() || !this->check) {
        for (int i = 1; i <= 2; ++i) { //porque son 2 bahías
            //mbah.SetNumeroB(i);
            mest.InicializarBahia(mbah);
        }
        this->check = true;
        vest.ImprimirMensaje("\n ¡Bahías cargadas exitosamente! \n");
        vest.ImprimirNro("\n N# de bahías cargadas: ", mest.ContarBahia());
    }
    vest.Pausa();
}
void Controlador::IncluirBahia() {
    vest.Limpiar();
    if (mest.Empty()) {
        vest.ImprimirMensaje("\n ¡Advertencia! No hay bahías precargadas.\n");
        vest.Pausa();
    }
        vest.ImprimirMensaje("\n Usted puede cargar dos bahías de manera predeterminada \n"
                             " o cargar la cantidad deseada.\n");
        vest.Pausa();
        int a = vest.LeerValidarNro("\n1.Cargar dos bahías. \n"
                                    "2.Cargar cantidad deseada. \n", 1, 2);
        int b = 0;
        if (a == 1) {
            this->check = false;
            CargarBahias();
            b = vest.LeerValidarNro("\n ¿Agregar más bahías? 1.Si 2.No \n", 1, 2);
        }  if (a == 2 || b == 1){
            if (!mest.Full()) {
                int numbah = vest.LeerNro("\n  ¿Cuántas bahías desea incluir? : ");
                for (int i = 1; i <= numbah; ++i) {
                    // int i = mbah.GetNumeroB();
                    //i++;
                    // mbah.SetNumeroB(i);
                    mest.InicializarBahia(mbah);
                    // vest.ImprimirMensaje("\n ¡BAHIA N°"+ i +"CARGADA EXITOSAMENTE! \n");
                }
                vest.ImprimirNro("\n Bahía N°\n", mest.ContarBahia());
                vest.ImprimirMensaje("\n ¡Bahía(s) cargada(s) exitosamente! \n");
                //vest.ImprimirNro("\n N# de Bahías \n", mbah.GetNumeroB());
            }
        }
    }

void Controlador::ConsultarBahia() {
    vest.Limpiar();
    if (mest.Empty()) {
        vest.ImprimirMensaje("\n ¡Advertencia! No hay bahías disponibles.\n");
        vest.Pausa();
    }
    vest.ImprimirMensaje("\n LISTA DE BAHIAS: \n");
    //This is one way to do it. If there's still time I'll do a fancier version.
    for (int j = 1; j <= mest.ContarBahia(); j++) {
        mbah.SetNumeroB(j);
        vest.ImprimirMensaje("\n BAHIA ");
        vest.ImprimirMensaje(to_string(mbah.GetNumeroB()));
        vest.ImprimirMensaje(". \n");
    }
    vest.ImprimirNro("\n Número total de bahías: \n ", mest.ContarBahia());

}

//============================================================
//                  VEHICLE METHODS                         ||
//============================================================

//In Progress.
void Controlador::AddCarToQueue() { //añadir vehículo a cola
    if (!mest.Empty()) {
        MBahia mbahaux;
        int numbahia, numcola, numveh, test;
        float hora; //la hora estara en formato militar
        //preguntar hora de entrada y settear

        numveh = vest.LeerNro("\n  ¿Cuántos vehículos entrarán en la cola? : ");
        for (int i = 1; i <= numveh; ++i) {
            vest.ImprimirNro("\n  Vehículo N# : ", i);
            numbahia = vest.LeerValidarNro("\n  ¿A cuál bahía quieres pasar? (1-2) : ", 1, 2);
            mbahaux = mest.GetBahia(numbahia);
            numcola = vest.LeerValidarNro("\n  ¿Cola 1.Derecha o 2.Izquierda? (1-2) : ", 1, 2);
            hora = vest.LeerValidarNroDecimal("\n Hora de llegada: si es 4:30pm ingrese 16.5 formato militar ", 1, 2);
//la hora se podria ingresar en otro formato? lo deje decimal..
            if (numcola == 1) {
                mveh.InsertTime(hora);
                mbahaux.RInsertVehicle(mveh);
                mest.SetBahia(numcola, mbahaux);
            } else {
                mveh.InsertTime(hora);
                mbahaux.LInsertVehicle(mveh);
                mest.SetBahia(numcola, mbahaux);
            }
        }
        vest.ImprimirMensaje("\n ¡Vehículo(s) añadido(s) en cola exitosamente! \n");
        test = vest.LeerValidarNro("\n ¿Deseas añadir más vehículos a la cola? 1.Si 2.No \n", 1, 2);
        if (test == 1) {
            AddCarToQueue();
        }
    } else {
        vest.ImprimirMensaje("\n ¡Error! Bahías fuera de servicio. \n");
    }
}

//Still in progress.
void Controlador::ProcessVehicleInQueue() { //procesar vehiculo en cola.
    if (!mest.Empty()) {
        MBahia mbahaux;
        long numbah, numcola;
        numbah = vest.LeerValidarNro("\n  ¿Cuál bahía quieres procesar? (1-2) : ", 1, 2);
        numcola = vest.LeerValidarNro("\n  ¿Cola 1.Derecha o 2.Izquierda? (1-2) : ", 1, 2);
        if (numcola == 1) {
            do {
                //Cola por la derecha
                mbahaux = mest.GetBahia(numbah);
                if (mbahaux.RProcessVehicles()) { // I need to implement that method in Mbahia
                    mest.SetBahia(numbah, mbahaux);
                    mbahaux.RRemoveVehicle(mveh);
                    vest.ImprimirMensaje("\n Vehículos procesados con exito! \n");
                } else {
                    vest.ImprimirMensaje("\n No hay más vehículos que procesar! \n");
                }
                numbah = vest.LeerValidarNro("\n  Qué bahía quieres procesar? (1,2) 3 para salir : ", 1, 2);
            } while (numbah != 3);
        } else {
            //cola por la izquierda
            do {
                mbahaux = mest.GetBahia(numbah);
                if (mbahaux.LProcessVehicles()) { // I need to implement that method in Mbahia
                    mest.SetBahia(numbah, mbahaux);
                    mbahaux.LRemoveVehicle(mveh);
                    vest.ImprimirMensaje("\n Vehículos procesados con exito! \n");
                } else {
                    vest.ImprimirMensaje("\n No hay más vehículos que procesar! \n");
                }
                numbah = vest.LeerValidarNro("\n  Qué bahía quieres procesar? (1,2) 3 para salir : ", 1, 2);
            } while (numbah != 3);
        }
    } else {
        vest.ImprimirMensaje("\n ¡Error! Bahías fuera de servicio. \n");
    }
}
//============================================================
//                  MENU METHODS                            ||
//============================================================

void Controlador::Menu() {
    int opc;
    VGeneral vg;
    //vg.Pausa();
    do {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      Proyecto Programación No Numérica 1\n", "      =======  ===============");
        vg.ImprimirEncabezado("\n      Estación de Servicios 'La Sin Colas'  \n", "      =======  ===============");
        vg.ImprimirEncabezado("\n      M E N U  O P C I O N E S\n", "      =======  ===============");
        vg.ImprimirMensaje("   1. Bahía\n");
        vg.ImprimirMensaje("   2. Vehículo\n");
        vg.ImprimirMensaje("   3. Reportes\n");
        vg.ImprimirMensaje("   4. Ayuda\n");
        vg.ImprimirMensaje("   5. Salir\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
        switch (opc) {
            case 1:
                OpcionBahia();
                break;
            case 2:
                OpcionVehiculo();
                break;
            case 3: //OpcionReportes();
                break;
            case 4:
                OpcionAyuda();
                break;
            case 5:
                OpcionSalir();
        }
    } while (opc != 5);
}

void Controlador::OpcionBahia() {
    int opc;
    VGeneral vg;
    //vg.Pausa();
    do {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  B A H I A\n", "      =======  ===============");
        vg.ImprimirMensaje("   1. Cargar Bahías. (Esta opción carga solo dos bahías de manera predeterminada).\n"); //carga dos bahias, para el inicio
        vg.ImprimirMensaje("   2. Incluir Bahía\n"); //para incluir una bahia a la vez
        vg.ImprimirMensaje("   3. Modificar Bahía\n");
        vg.ImprimirMensaje("   4. Consultar Bahía\n");
        vg.ImprimirMensaje("   5. Eliminar Bahía\n");
        vg.ImprimirMensaje("   6. Volver al menú anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-6): ", 1, 6);
        switch (opc) {
            case 1:
                CargarBahias();
                break;
            case 2:
                IncluirBahia();
                break;
            case 3: //ModificarBahia();
                break;
            case 4:
                ConsultarBahia();
                break;
            case 5: //EliminarBahia();
                break;
            case 6:
                Menu();
                break;
        }
    } while (opc != 6);
}

void Controlador::OpcionVehiculo() {
    int opc;
    VGeneral vg;
    vg.Pausa();
    do {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  V E H I C U L O\n", "      =======  ===============");
        vg.ImprimirMensaje("   1. Incluir Vehículo\n");
        vg.ImprimirMensaje("   2. Consultar Vehículo\n");
        vg.ImprimirMensaje("   3. Eliminar Vehículo\n");
        vg.ImprimirMensaje("   4. Procesar Vehículo\n");
        vg.ImprimirMensaje("   5. Volver al menú anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
        switch (opc) {
            case 1:
                AddCarToQueue(); //IncluirVehiculo();
                break;
            case 2: //ConsultarVehiculo();
                break;
            case 3: //EliminarVehiculo();
                break;
            case 4: //ProcessVehicleInQueue();
                break;
            case 5:
                Menu();
                break;
        }
    } while (opc != 5);
}

void Controlador::OpcionAyuda() {
    vest.ImprimirMensaje(
            "  La opción 1 cargará (de manera predeterminada carga dos bahías), incluirá, consultará, modificará, y eliminará las bahías en la estación.\n");
    vest.ImprimirMensaje("  La opción 2 incluirá, consultará, y eliminará los vehículos en cola.\n");
    vest.ImprimirMensaje("  La opción 3 imprimirá un reporte indicando el tipo de vehículo, placa,"
                         "cantidad de combustible en litros y Bs. y el tiempo en cola.\n");
    vest.ImprimirMensaje("  Program created by: José Luis Pacheco & Dany Karam.\n");
}

void Controlador::OpcionSalir() {
    int opc = vest.LeerValidarNro("   ¿Está seguro que desea salir? 1.Si 2.No ", 1, 2);
    if (opc == 1)
        vest.Pausa();
    else
        Menu();
}