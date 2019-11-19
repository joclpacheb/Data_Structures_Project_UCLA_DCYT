//
// Created by dany on 11/10/19.
//

#ifndef DATA_STRUCTURES_PROJECT_UCLA_DCYT_VBAHIA_H
#define DATA_STRUCTURES_PROJECT_UCLA_DCYT_VBAHIA_H

#include "../Libs/Genericas/VGeneral.h"
class VBahia: public VGeneral {
public:
    VBahia();

    void ImprimirBahia(string vehiculo, string placa, int cantlitro, float bs, float time);
};


#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_VBAHIA_H
