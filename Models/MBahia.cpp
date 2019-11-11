//
// Created by dany on 11/10/19.
//

#include "MBahia.h"

MBahia::MBahia() {}

//Queue Methods
//Right
void MBahia::RInsertVehicle(MVehiculo mmul){
    RightQueue.Insertar(mmul);
    //mmul.SetNum(n);
}
void MBahia::RRemoveVehicle(MVehiculo &mmul){
    RightQueue.Remover(mmul);
}
bool MBahia::REmpty(){
    return RightQueue.Vacia();
}
bool MBahia::RFull(){
    return RightQueue.Llena();
}
//Left
void MBahia::LInsertVehicle(MVehiculo mmul){
    LeftQueue.Insertar(mmul);
    //mmul.SetNum(n);
}
void MBahia::LRemoveVehicle(MVehiculo &mmul){
    LeftQueue.Remover(mmul);
}
bool MBahia::LEmpty(){
    return LeftQueue.Vacia();
}
bool MBahia::LFull(){
    return LeftQueue.Llena();
}

int MBahia::GetNumeroB() const {
    return numerob;
}
void MBahia::SetNumeroB(int numerob) {
    this->numerob = numerob;
}
