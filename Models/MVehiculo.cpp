#include "MVehiculo.h"

MVehiculo::MVehiculo(){}

Pila <int> MVehiculo::GetPilaHoras() const{
return PilaHoras;
}

void MVehiculo::InsertTime(int n){
    PilaHoras.Insertar(n);
}

void MVehiculo::RemoveTime(int &n){
    PilaHoras.Remover(n);
}
bool MVehiculo::Empty(){
    return PilaHoras.Vacia();
}
bool MVehiculo::Full(){
    return PilaHoras.Llena();
}
int MVehiculo::GetTipo(){
    return tipo;
}
float MVehiculo::GetTanque(){
    return tanque;
}
int MVehiculo::GetEspacio(){
    return espacio;
}
void  MVehiculo::SetTipo(int ti){
    tipo=ti;
}

void MVehiculo::SetEspacio(int e){
    espacio=e;
}
void MVehiculo::SetTanque (float ta){
    tanque=ta;
}