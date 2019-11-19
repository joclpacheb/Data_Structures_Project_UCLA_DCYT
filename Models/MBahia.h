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
    float price;
    bool status;
public:
    MBahia();

    //Right
    void RInsertVehicle(MVehiculo mveh);
    void RRemoveVehicle(MVehiculo &mveh);
    bool REmpty();
    bool RFull();
    bool RProcessVehicles();

    //Left
    void LInsertVehicle(MVehiculo mveh);
    void LRemoveVehicle(MVehiculo &mveh);
    bool LEmpty();
    bool LFull();
    bool LProcessVehicles();

    int GetNumeroB() const;
    void SetNumeroB(int numerob);

    float GetPrice() const;
    void SetPrice(float price);

    bool GetStatus() const;
    void SetStatus(bool status);

};

#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_MBAHIA_H
