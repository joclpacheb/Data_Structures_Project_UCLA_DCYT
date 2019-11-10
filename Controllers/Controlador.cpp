//
// Created by dany on 11/10/19.
//

#include "Controlador.h"

Controlador::Controlador() {
    this->check = false;
}

void Controlador::CargarLista() {
    vg.Limpiar();
    if (Lista1.Vacia()){
        // Lista<int> Lista1;
        nodo<int> *ap;
        int valor;
        for(int i=0; i<10;i++) {
            valor = vg.LeerNro("\nIntroduzca un numero: ");
            // cout << "Introduzca un numero: " << endl;
            // cin >> valor;
            if (Lista1.Vacia()) {
                Lista1.InsComienzo(valor);
                ap=Lista1.ObtPrimero();
            }
            else {
                Lista1.InsDespues(ap,valor);
                //ap=ap->ObtProx();
                ap = Lista1.ObtProx(ap);
            }
        }
    }else{
        vg.ImprimirMensaje("\n LA LISTA YA FUE CARGADA \n");
    }
}
void Controlador::ImprimirLista() {
    vg.Limpiar();
    if(!Lista1.Vacia()) {
        nodo<int> *ap;
        int valor;
        ap=Lista1.ObtPrimero();
        while(ap!=NULL) {
            // valor=ap->ObtInfo(ap);
            valor = Lista1.ObtInfo(ap);
            cout << valor <<  " -> ";
            // ap=ap->ObtDer();
            ap = Lista1.ObtProx(ap);
        }
    }else{
        vg.ImprimirMensaje("\n LA LISTA ESTA VACIA \n");
    }
}
void Controlador::CargarPila(){
    if(PilaA.Vacia()) {
        int i,valor;
        for(i=0;i<10;i++){
            //cout << "Ingresar 10 numeros: ";
            //cin >> valor;
            valor = vg.LeerNro("\nIntroduzca un numero: ");
            PilaA.Insertar(valor);
        }
    }else {
        vg.ImprimirMensaje("\n LA PILA YA FUE CARGADA \n");
    }
}
void Controlador::ImprimirPila(){
    if(!PilaA.Vacia()) {
        int valor;
        Pila<int> PilaAux;
        do {
            PilaA.Remover(valor);
            //  cout << valor << endl;
            PilaAux.Insertar(valor);
        } while (!PilaA.Vacia());
        do {
            PilaAux.Remover(valor);
            cout << valor << endl;
            PilaA.Insertar(valor);
        } while (!PilaAux.Vacia());
    }else{
        vg.ImprimirMensaje("\n LA PILA ESTA VACIA \n");
    }
}
void Controlador::CargarCola(){
    if(Cola1.Vacia()) {
        int i, valor;
        for(i=1;i<10;i++){
            valor = vg.LeerNro("\nIntroduzca un numero: ");
            Cola1.Insertar(valor);
        }
    }else{
        vg.ImprimirMensaje("\n LA COLA YA FUE CARGADA \n");
    }
}
void Controlador::ImprimirCola(){
    if(!Cola1.Vacia()) {
        int marca,valor;
        bool encontro;
        marca=-1;
        Cola1.Insertar(marca);
        encontro=false;
        do {
            Cola1.Remover(valor);
            if (valor==marca)
                encontro=true;
            else{
                cout << valor <<  " <- ";
                Cola1.Insertar(valor);
            }
        } while (!encontro);
    }else{
        vg.ImprimirMensaje("\n LA COLA ESTA VACIA \n");
    }
}
void Controlador::CargarTabla(){
    if(mtab.Empty()) {
        mtab.AgregarMultiplicando();
        vg.ImprimirMensaje("\n TABLA CARGADA EXITOSAMENTE! \n");
    }else{
        vg.ImprimirMensaje("\n LA TABLA YA FUE CARGADA \n");
    }
}

void Controlador::ImprimirTabla() {
    if (!mtab.Empty()) {
        MMultiplicador aux;
        // Numeros n;
        //Pila<int> aux;
        int m;
        int p;
        mmul.SetNum(-1);
        // mtab.InsertStack(mmul);
        //mtab.RemoveStack(mmul);
        //cout << "¿Qué tabla desea que se muestre del 1 al 10?" << endl;
        // cin >> p;
        p = vg.LeerValidarNro("   Seleccione la tabla que desea imprimir (1-10): ", 1, 10);
        if (!mtab.SearchTable(p)) {
            vg.ImprimirMensaje("\n LA TABLA FUE BORRADA \n");
        } else {
            mtab.InsertStack(mmul);
            mtab.RemoveStack(mmul);
            while (mmul.GetNum() != -1) {
                if (mmul.GetNum() == p) {
                    do {
                        mmul.RemoveNumber(m);
                        aux.InsertNumber(m);
                    } while (!mmul.Empty());
                    cout << "TABLA DE MULTIPLICAR DEL: " << mmul.GetNum() <<endl;
                    while (!aux.Empty()) {
                        aux.RemoveNumber(m);
                        cout << mmul.GetNum();
                        cout << "x";
                        cout << m;
                        cout << "=";
                        cout << mmul.GetNum() * m << endl;
                        mmul.InsertNumber(m);
                    }
                    vg.ImprimirMensaje("\n .\n");
                }
                mtab.InsertStack(mmul);
                mtab.RemoveStack(mmul);
            }
        }
    } else {
        vg.ImprimirMensaje("\n LA TABLA ESTA VACIA \n");
    }
}
/*int Controlador::Busqueda(int n) {
    for(int i=0;i<vecnro.size();i++)
        if(vecnro[i] == n)
            return i;
    return -1;
}*/
void Controlador::BorrarTabla(){
    if (!mtab.Empty()) {
        int e;
        // Numeros nro;
        mmul.SetNum(-1);
        e = vg.LeerValidarNro("   Seleccione la tabla que desea eliminar (1-10): ", 1, 10);
        //this->vecnro.push_back(e);
        //SearchTable(e);
        if(mtab.SearchTable(e)){
            mtab.InsertStack(mmul);
            mtab.RemoveStack(mmul);
            while(mmul.GetNum()!=-1){
                if(mmul.GetNum()==e) {
                    mtab.RemoveStack(mmul);
                }else if(mmul.GetNum()!=-1){
                    mtab.InsertStack(mmul);
                    mtab.RemoveStack(mmul);
                }
            }
            vg.ImprimirMensaje("\n TABLA ELIMINADA EXITOSAMENTE \n");
        }else{
            cout<<"LA TABLA NO EXISTE\n\n"<<endl;
        }

    } else {
        vg.ImprimirMensaje("\n LA TABLA ESTA VACIA \n");
    }
}
void Controlador::OpcionLista(){
    int opc;
    VGeneral  vg;
    Controlador c;
    vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  L I S T A\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Cargar Lista\n");
        vg.ImprimirMensaje("   2. Imprimir Lista\n");
        vg.ImprimirMensaje("   3. Volver al menu anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-3): ",1,3);
        switch (opc)
        {
            case 1: CargarLista();
                break;
            case 2:  ImprimirLista();
                break;
        }
    }
    while(opc != 3);
}
void Controlador::OpcionPila(){
    int opc;
    VGeneral  vg;
    Controlador c;
    vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  P I L A\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Cargar Pila\n");
        vg.ImprimirMensaje("   2. Imprimir Pila\n");
        vg.ImprimirMensaje("   3. Volver al menu anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-3): ",1,3);
        switch (opc)
        {
            case 1: CargarPila();
                break;
            case 2:  ImprimirPila();
                break;
        }
    }
    while(opc != 3);
}
void Controlador::OpcionCola(){
    int opc;
    VGeneral  vg;
    Controlador c;
    vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  C O L A\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Cargar Cola\n");
        vg.ImprimirMensaje("   2. Imprimir Cola\n");
        vg.ImprimirMensaje("   3. Volver al menu anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-3): ",1,3);
        switch (opc)
        {
            case 1: CargarCola();
                break;
            case 2:  ImprimirCola();
                break;
        }
    }
    while(opc != 3);
}
void Controlador::OpcionTabla(){
    int opc;
    VGeneral  vg;
    Controlador c;
    //  vg.Pausa();
    do
    {
        vg.Limpiar();
        vg.ImprimirLineasBlanco(2);
        vg.Limpiar();
        vg.ImprimirEncabezado("\n      M E N U  T A B L A\n","      =======  ===============");
        vg.ImprimirMensaje("   1. Cargar una tabla\n");
        vg.ImprimirMensaje("   2. Imprimir una tabla\n");
        vg.ImprimirMensaje("   3. Borrar una tabla\n");
        vg.ImprimirMensaje("   4. Volver al menu anterior\n");
        opc = vg.LeerValidarNro("   Seleccione su opción (1-4): ",1,4);
        switch (opc)
        {
            case 1: CargarTabla();
                break;
            case 2: ImprimirTabla();
                break;
            case 3:  BorrarTabla();
                break;
        }
    }
    while(opc != 4);
}
void Controlador::OpcionAyuda(){
    vg.ImprimirMensaje("  Las opciones 1,2 y 3 cargarán e imprimirán 10 números en su "
                       "respectiva Estructura de Dato.\n");
    vg.ImprimirMensaje("  La opción 4 imprimirá y borrará la tabla de multiplicar deseada.\n");
}
void Controlador::OpcionSalir(){
    int opc = vg.LeerValidarNro("   ¿Está seguro que desea salir? 1.Si 2.No ",1,2);
    if(opc == 1)
        vg.Pausa();
    else
        Menu();
}
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
        vg.ImprimirMensaje("   1. Lista\n");
        vg.ImprimirMensaje("   2. Pila\n");
        vg.ImprimirMensaje("   3. Cola\n");
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
