//
// Created by dany on 11/10/19.
//

#ifndef DATA_STRUCTURES_PROJECT_UCLA_DCYT_MESTACION_H
#define DATA_STRUCTURES_PROJECT_UCLA_DCYT_MESTACION_H

#include "../Libs/Lista/Lista.cpp"
#include "MBahia.h"

class MEstacion {
private:
    Lista<MBahia> ListBahia;
    nodo<MBahia> *aplist; //apuntador de MBahia
public:
    MEstacion();
    void InicializarBahia(MBahia mbah);
    MBahia GetBahia(int i);
    void SetBahia(int i,MBahia mbah);
    bool Empty();
    bool Full();
    int ContarBahia();
    bool Search(MBahia &mbah);
    bool SearchByNumber(MBahia &mbah, int n);
    void DeleteBahia(MBahia &mbah);

    };

#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_MESTACION_H
