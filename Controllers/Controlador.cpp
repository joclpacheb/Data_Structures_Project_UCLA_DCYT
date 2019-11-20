//
// Created by dany on 11/10/19.
//
#include "Controlador.h"

Controlador::Controlador() {
    this->check = true;
    this->w = 1; //posición del vector
    this->j = 0; //espacio que abarcará el vehículo
}

//============================================================
//                  GAS PUMPS METHODS                       ||
//============================================================

//This method works only to pre-load two gas pumps for default. It can be used only once.
void Controlador::CargarDosBahias() {
    vest.Limpiar();
    if (mest.Empty()) {
        for (int i = 1; i <= 2; ++i) { //porque son 2 bahías
            mbah.SetNumeroB(i);
            mest.InicializarBahia(mbah);
        }
        vest.ImprimirMensaje("\n ¡Bahías cargadas exitosamente! \n");
        vest.ImprimirNro("\n N# de bahías cargadas: ", mest.ContarBahia());
    } else {
        vest.ImprimirMensaje("\n ¡Las bahías ya fueron cargadas!\n");
    }
    vest.Pausa();
}

//This methods loads only 2 gas pumps. It can be used more than once.
void Controlador::CargarBahias() {
    vest.Limpiar();
    if (mest.Empty() || !this->check) {
        for (int i = 1; i <= 2; ++i) { //porque son 2 bahías
            //mbah.SetNumeroB(i);
            mest.InicializarBahia(mbah);
        }
        //float p =vest.LeerNroDecimal("\n Introduzca precio nuevo: ");
        //mbah.SetPrice(p);
        this->check = true;
        vest.ImprimirMensaje("\n ¡Bahías cargadas exitosamente! \n");
        vest.ImprimirNro("\n N# de bahías cargadas: ", mest.ContarBahia());
    }
    vest.Pausa();
}

//This method asks whether you want to include two gas pumps by default or choose the quantity you want.
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
    }
    if (a == 2 || b == 1) {
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

//This method shows the gas pumps available.
void Controlador::ConsultarBahia() {
    vest.Limpiar();
    if (mest.Empty()) {
        vest.ImprimirMensaje("\n ¡Advertencia! No hay bahías disponibles.\n");
        vest.Pausa();
    }
    vest.ImprimirMensaje("\n LISTA DE BAHIAS DISPONIBLES: \n");
    //This is one way to do it. If there's still time I'll do a fancier version.
    for (int j = 1; j <= mest.ContarBahia(); j++) {
        mbah.SetNumeroB(j);
        vest.ImprimirMensaje("\n BAHIA ");
        vest.ImprimirMensaje(to_string(mbah.GetNumeroB()));
        vest.ImprimirMensaje(". \n");
    }
    vest.ImprimirNro("\n Número total de bahías: \n ", mest.ContarBahia());
}

//This method will (probably) modify number, status and price of gas pumps.
void Controlador::ModificarBahia() {
    vest.ImprimirMensaje("¿Qué desea modificar? \n");
    int a = vest.LeerValidarNro("\n1.Precio de la gasolina. \n"
                                "2.Status de la bahía. \n", 1, 2);
    if (a == 1) {
        vest.ImprimirNroDecimal("\n Precio actual de la gasolina: ", mbah.GetPrice());
        float p = vest.LeerNroDecimal("\n Introduzca precio nuevo: ");
        mbah.SetPrice(p);
        vest.Pausa();
        vest.ImprimirMensaje("¡Precio actualizado satisfactoriamente! \n");
        vest.ImprimirNroDecimal("\n El precio nuevo ahora es: ", mbah.GetPrice());
    }
    if (a == 2) {
        ConsultarBahia();
        int i = vest.LeerNro("\n Introduzca el número de la bahía que desea modificar el status: ");
        //Search doesn't work yet.
        if (mest.SearchByNumber(mbah, i)) {
            int b = vest.LeerValidarNro("\n ¿Está seguro que quiere cambiar el status? 1.Si 2.No ", 1, 2);
            if (b == 1) {
                mbah.SetStatus(false);
            }
            vest.ImprimirMensaje("El status de la bahía fue cambiada satisfactoriamente \n");
        }
    }

}

//This method will delete gas pumps. It needs to validate if there are queues of vehicles before deleting.
void Controlador::EliminarBahia() {
    if (mest.Empty()){
        vest.ImprimirMensaje("Actualmente no hay bahias disponibles.");
    }else{
        ConsultarBahia();
        int b = vest.LeerNro("\n Ingrese el numero de la bahia a eliminar: ");
        mbah= mest.GetBahia(b);
        if (mest.Search(mbah)) {
            int a = vest.LeerValidarNro("\n ¿Está seguro que quiere eliminar la? 1.Si 2.No ", 1, 2);
            if (a == 1) {
                mest.DeleteBahia(mbah);
                vest.ImprimirMensaje("La bahia fue eliminada satisfactoriamente \n");

            }
        }


    }

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
            string v = vest.LeerString("\n  Nombre de vehículo : ");
            mveh.SetNombre(v);
            string p = vest.LeerString("\n  Placa : ");
            mveh.SetPlaca(p);
            vest.ImprimirMensaje(" ==== Tipo ===.\n");
            vest.ImprimirMensaje("   1. Vehículo.\n");
            vest.ImprimirMensaje("   2. Transporte.\n");
            vest.ImprimirMensaje("   3. Carga.\n");
            int opc = vest.LeerValidarNro("   Seleccione su opción (1-3): ", 1, 3);
            switch (opc) {
                case 1:
                    if (j <= 2) {
                        j++;
                        //vector<int> auxvecs;
                        mveh.SetVecS(w, j);
                        //mveh.setVecSize(auxvecs);
                        mveh.SetTipo(opc);
                        // vector <int> auxvec;
                        // auxvec.push_back(mveh.GetVecS(w));
                    } else {
                        w++;
                        j = 1;
                        mveh.SetVecS(w, j);
                        mveh.SetTipo(opc);
                        j = 0;
                    }
                    break;
                case 2:
                    w++;
                    j = 2;
                    mveh.SetVecS(w, j);
                    mveh.SetTipo(opc);
                    j = 0;
                    break;
                case 3:
                    w++;
                    j = 2;
                    mveh.SetVecS(w, j);
                    mveh.SetTipo(opc);
                    j = 0;
                    break;
            }
            int l = vest.LeerNro("\n  Capacidad máxima en litros del tanque : ");
            mveh.SetTanque(l);
            vest.Pausa();
            ConsultarBahia();
            //numbahia = vest.LeerValidarNro("\n  ¿A cuál bahía quieres pasar? (1-2) : ", 1, 2);
            vest.Pausa();
            numbahia = vest.LeerValidarNro("\n  ¿A cuál bahía quieres pasar? : ", 1, 2);
            mbahaux = mest.GetBahia(numbahia);
            //I want to validate whether the gas pumps are available or not. If I have time I'll do it.
            numcola = vest.LeerValidarNro("\n  ¿Cola 1.Derecha o 2.Izquierda? (1-2) : ", 1, 2);
            //hora = vest.LeerNroDecimal("\n Hora de llegada: si es 4:30pm ingrese 16.5 formato militar ");
            //la hora se podria ingresar en otro formato? lo deje decimal..
            if (numcola == 1) {

                vest.ImprimirMensaje("\n Test2 \n");
                if(mbah.REmpty()) {
                    //mveh.InsertTime(hora);
                    //mbahaux.RInsertVehicle(mveh);
                    //mest.SetBahia(numcola, mbahaux);
                    vest.ImprimirMensaje("\n Test \n");
                }
            } else {
                if (mbah.LEmpty()) {
                    // mveh.InsertTime(hora);
                    mbahaux.LInsertVehicle(mveh);
                    mest.SetBahia(numcola, mbahaux);
                    vest.ImprimirMensaje("\n Test3 \n");
                }
                vest.ImprimirMensaje("\n Test4 \n");
            }
        }
        vest.ImprimirMensaje("\n ¡Vehículo(s) añadido(s) en cola exitosamente! \n");
        test = vest.LeerValidarNro("\n ¿Deseas añadir más vehículos? 1.Si 2.No \n", 1, 2);
        if (test == 1) {
            AddCarToQueue();
        }
    } else {
        vest.ImprimirMensaje("\n ¡Error! Bahías fuera de servicio. \n");
    }
}

//Still in progress.
void Controlador::ProcessVehicleInQueue() { //procesar vehículo en cola.
    if (!mest.Empty()) {
        MBahia mbahaux;
        long numbah, numcola;
        float hora;
        ConsultarBahia();
        vest.Pausa();
        numbah = vest.LeerValidarNro("\n  ¿Cuál bahía quieres procesar? : ", 1, mest.ContarBahia());
        //I need to validate whether the gas pump is available or not.
        //numbah = vest.LeerValidarNro("\n  ¿Cuál bahía quieres procesar? (1-2) : ", 1, 2);
        numcola = vest.LeerValidarNro("\n  ¿Cola 1.Derecha o 2.Izquierda? (1-2) : ", 1, 2);
        //Also, I want to show how many vehicles are in queue if I have the time. And validate if there are vehicles at all.
        if (numcola == 1) {
            int ve = vest.LeerValidarNro("\n  ¿Cuántos vehículos quieres procesar? (1-2) : ",1,2);
            //Validate the number of vehicle cause if there's only one in queue you can't process 2.
            //Validate the type of vehicles, it can't enter two with different types.
            /*  for (int k = 0; k < ve; ++k) {
                  if (mveh.GetTipo() == 1) {

                  } else {
                      if (mveh.GetTipo() == 2 or mveh.GetTipo() == 3) {

                      }
                  }
              }*/

            do{
                int a = vest.LeerNro("\n  Introduzca cantidad de litros actual en su tanque : ");
                int li = vest.LeerValidarNro("\n1.Llenar full el tanque. \n"
                                             "2.Llenar cantidad deseada. \n", 1, 2);
                if(li == 1){
                    int c = mveh.GetTanque()-a;
                    //  mveh.SetTanqueFull(c);
                }if (li == 2){
                    int x = vest.LeerNroDecimal("\n  Cuanto desea echar?: ");
                    //mveh.SetTanqueFull(x);
                }
                hora = vest.LeerNroDecimal("\n  Hora de salida: ");
                //Cola por la derecha
                mbahaux = mest.GetBahia(numbah);
                if (mbahaux.RProcessVehicles()) { // I need to implement that method in Mbahia
                    mest.SetBahia(numbah, mbahaux);
                    mbahaux.RRemoveVehicle(mveh);
                    mveh.InsertTime(hora);
                    vest.ImprimirMensaje("\n Vehículo(s) procesado(s) con exito! \n");
                } else {
                    vest.ImprimirMensaje("\n No hay más vehículos que procesar! \n");
                }
                numbah = vest.LeerValidarNro("\n  Qué bahía quieres procesar? (1,2) 3 para salir : ", 1, 2);
            } while(numbah);
        } else {
            //cola por la izquierda
            do {
                mbahaux = mest.GetBahia(numbah);
                if (mbahaux.LProcessVehicles()) { // I need to implement that method in Mbahia
                    mest.SetBahia(numbah, mbahaux);
                    mbahaux.LRemoveVehicle(mveh);
                    vest.ImprimirMensaje("\n Vehículo(s) procesado(s) con exito! \n");
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

//This method shows how many vehicles are in each queue depending on selected gas pump.
void Controlador::ConsultarVehiculo() {

}

//This method will delete vehicles that got tired of waiting a lot in the queue (?).
void Controlador::EliminarVehiculo() {

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
        vg.ImprimirMensaje("   1. Bahía.\n");
        vg.ImprimirMensaje("   2. Vehículo.\n");
        vg.ImprimirMensaje("   3. Reportes.\n");
        vg.ImprimirMensaje("   4. Ayuda.\n");
        vg.ImprimirMensaje("   5. Salir.\n");
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
        vg.ImprimirMensaje(
                "   1. Cargar Bahías. (Esta opción carga solo dos bahías).\n"); //carga dos bahias, para el inicio
        vg.ImprimirMensaje("   2. Incluir Bahía.\n"); //para incluir una bahia a la vez
        vg.ImprimirMensaje("   3. Consultar Bahía.\n");
        vg.ImprimirMensaje("   4. Modificar Bahía.\n");
        vg.ImprimirMensaje("   5. Eliminar Bahía.\n");
        vg.ImprimirMensaje("   6. Volver al menú anterior.\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-6): ", 1, 6);
        switch (opc) {
            case 1:
                CargarBahias();
                break;
            case 2:
                IncluirBahia();
                break;
            case 3:
                ConsultarBahia();
                break;
            case 4:
                ModificarBahia();
                break;
            case 5:
                EliminarBahia();
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
        vg.ImprimirMensaje("   1. Incluir Vehículo.\n");
        vg.ImprimirMensaje("   2. Consultar Vehículo.\n");
        vg.ImprimirMensaje("   3. Procesar Vehículo.\n");
        vg.ImprimirMensaje("   4. Eliminar Vehículo.\n");
        vg.ImprimirMensaje("   5. Volver al menú anterior.\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
        switch (opc) {
            case 1:
                AddCarToQueue();
                break;
            case 2:
                ConsultarVehiculo();
                break;
            case 3:
                ProcessVehicleInQueue();
                break;
            case 4:
                EliminarVehiculo();
                break;
            case 5:
                Menu();
                break;
        }
    } while (opc != 5);
}

void Controlador::OpcionAyuda() {
    vest.ImprimirMensaje(
            "  La opción 1 cargará, incluirá, consultará, modificará, y eliminará las bahías en la estación.\n");
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