//
// Created by dany on 11/10/19.
//

#ifndef DATA_STRUCTURES_PROJECT_UCLA_DCYT_MBAHIA_H
#define DATA_STRUCTURES_PROJECT_UCLA_DCYT_MBAHIA_H

#include "../Libs/Cola/Cola.cpp"
#include "MVehiculo.h"

class MBahia {
private:
    Cola<MVehiculo> RightQueue;
    Cola<MVehiculo> LeftQueue;
    int numerob; // numero de la bahia
public:
    MBahia();
    //Right
    void RInsertVehicle(MVehiculo mmul);
    void RRemoveVehicle(MVehiculo &mmul);
    bool REmpty();
    bool RFull();

    //Left
    void LInsertVehicle(MVehiculo mmul);
    void LRemoveVehicle(MVehiculo &mmul);
    bool LEmpty();
    bool LFull();

    int GetNumeroB() const;
    void SetNumeroB(int numerob);
};

#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_MBAHIA_H
