//
// Created by dany on 11/10/19.
//

#include "MEstacion.h"

MEstacion::MEstacion() {}

void MEstacion::InicializarBahia(MBahia mbah) {
    if (ListBahia.Vacia()) {
        ListBahia.InsComienzo(mbah);
       //aplist = ListaCaja.ObtPrimero();
        aplist = ListBahia.ObtPrimero();
    } else {
        ListBahia.InsDespues(aplist, mbah);
        //aplist = aplist->ObtDer();
        ListBahia.ObtProx(aplist);
    }
}

int MEstacion::ContarBahia(){

    return ListBahia.Contar();
}


MBahia MEstacion::GetBahia(int i) {
    aplist = ListBahia.ObtPrimero();
    while(aplist != nullptr) {  //preguntas si no esta apuntando a null o sea que si hay nodos
        // aplist->ObtInfo().getNumeroB() == i
        if (ListBahia.ObtInfo(aplist).GetNumeroB() == i){
            // return aplist->ObtInfo();
            return ListBahia.ObtInfo(aplist);
        }
        // aplist=aplist->ObtDer();
        ListBahia.ObtProx(aplist);
    }
}
void MEstacion::SetBahia(int i, MBahia mbah) {
    aplist = ListBahia.ObtPrimero();
    if(aplist != nullptr) {
        while (ListBahia.ObtInfo(aplist).GetNumeroB() != i) {  //preguntas si no esta apuntando a null o sea que si hay nodos
            //aplist = aplist->ObtDer();
            ListBahia.ObtProx(aplist);
        }
    }
   // aplist->AsigInfo(mbah);
   ListBahia.AsigInfo(aplist, mbah);
}
bool MEstacion::Empty(){
    return ListBahia.Vacia();
}
bool MEstacion::Full(){
    return ListBahia.Llena();
}