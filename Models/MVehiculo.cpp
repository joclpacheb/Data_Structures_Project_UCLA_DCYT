#include "MVehiculo.h"

MVehiculo::MVehiculo(){
}

Pila <int> MVehiculo::GetPilaHoras() const{
return PilaHoras;
}

void MVehiculo::InsertTime(int n){
pilaHoras.Insertar(n);
}

void MVehiculo::RemoveTime(int n){
    pilaHoras.Remover(n);
}
bool MVehiculo::Empty(){
    return pilaHoras.Vacia();
}

int MVehiculo::GetTipo(){
    return tipo;
}
float MVehiculo::GetTanque(){
    return tipo;
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

int MMultiplicador::GetNum() {
        return number;
    }

void MMultiplicador::SetNum(int num) {
        number = num;
    }
void MMultiplicador::InsertNumber(int n){
        StackMult.Insertar(n);
    }
void MMultiplicador::RemoveNumber(int &n){
      StackMult.Remover(n);
    }
  bool MMultiplicador::Empty(){
        return StackMult.Vacia();