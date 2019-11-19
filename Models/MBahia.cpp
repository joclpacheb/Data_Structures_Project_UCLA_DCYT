//
// Created by dany on 11/10/19.
//

#include "MBahia.h"

MBahia::MBahia() {}

//Queue Methods
//Right
void MBahia::RInsertVehicle(MVehiculo mveh){
    RightQueue.Insertar(mveh);
}
void MBahia::RRemoveVehicle(MVehiculo &mveh){
    RightQueue.Remover(mveh);
}
bool MBahia::REmpty(){
    return RightQueue.Vacia();
}
bool MBahia::RFull(){
    return RightQueue.Llena();
}
//Left
void MBahia::LInsertVehicle(MVehiculo mveh){
    LeftQueue.Insertar(mveh);
}
void MBahia::LRemoveVehicle(MVehiculo &mveh){
    LeftQueue.Remover(mveh);
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

float MBahia::GetPrice() const {
    return price;
}
void MBahia::SetPrice(float price) {
    this->price = price;
}

bool MBahia::GetStatus() const {
    return status;
}
void MBahia::SetStatus(bool status) {
    this->status = status;
}

bool MBahia::RProcessVehicles() {
    MVehiculo aux;
    if(!RightQueue.Vacia()){
        RightQueue.Remover(aux);
        return true;
    }else
        return false;
}
bool MBahia::LProcessVehicles() {
    MVehiculo aux;
    if(!LeftQueue.Vacia()){
        LeftQueue.Remover(aux);
        return true;
    }else
        return false;
}

