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
        aplist = ListBahia.ObtProx(aplist);
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
        aplist = ListBahia.ObtProx(aplist);
    }
}
void MEstacion::SetBahia(int i, MBahia mbah) {
    aplist = ListBahia.ObtPrimero();
    if(aplist != nullptr) {
        while (ListBahia.ObtInfo(aplist).GetNumeroB() != i) {  //preguntas si no esta apuntando a null o sea que si hay nodos
            //aplist = aplist->ObtDer();
            aplist = ListBahia.ObtProx(aplist);
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
bool MEstacion::Search(MBahia &mbah){
//   if(ListBahia.Buscar(mbah.GetNumeroB())
    return true;
  // else return false;
}

bool MEstacion::SearchByNumber(MBahia &mbah, int n) {
    nodo<MBahia> *auxappbah = ListBahia.ObtPrimero(); // cambiando buscar por auxiliar
    while(auxappbah != nullptr) {  //preguntas si no esta apuntando a null, o sea, que si hay nodos
        //auxappbah->ObtInfo().GetNumeroB() == num
        if (ListBahia.ObtInfo(auxappbah).GetNumeroB() == n){
            //mpro = auxappbah->ObtInfo();
            ListBahia.ObtInfo(auxappbah);
            return true;
        }
        auxappbah = ListBahia.ObtProx(auxappbah);
        // auxapprod=auxapprod->ObtDer();
    }
    return false;
}

void MEstacion::DeleteBahia(MBahia &mbah) {
   if(!ListBahia.Vacia()) {
     //  if (ListBahia.Buscar(mbah.GetNumeroB())) {
           Lista<MBahia> ListaAux;
           ListaAux = ListBahia;
           nodo<MBahia> *ant, *act; // anterior y actual

           //antes de eliminar, debo conocer tanto el anterior como el actual
           ant = ListaAux.ObtPrimero(); //anterior
           act = ListaAux.ObtPrimero();//actual
           //inician siendo iguales al primero de la lista...
           while (mbah.GetNumeroB() != ListaAux.ObtInfo(act).GetNumeroB()) {
               //hasta que el numero de la bahia a eliminar coincida con act
               ListaAux.AsigProx(ant, act); //mi anterior va a ser mi actual
               ListaAux.AsigProx(act, ListBahia.ObtProx(act)); // mi actual sera el prox al antiguo actual
           }
          //ya se tiene el actual buscado y su anterior
           ListBahia.Eliminar(act, mbah, ant);
       }
   //}
   };


