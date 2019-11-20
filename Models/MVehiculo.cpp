#include "MVehiculo.h"

MVehiculo::MVehiculo(){
    vec_size.push_back(0);
}

Pila <float> MVehiculo::GetPilaHoras() const{
return PilaHoras;
}

void MVehiculo::InsertTime(float n){
    PilaHoras.Insertar(n);
}

void MVehiculo::RemoveTime(float &n){
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

const string &MVehiculo::GetNombre() const {
    return nombre;
}

void MVehiculo::SetNombre(const string &nombre) {
    MVehiculo::nombre = nombre;
}

const string &MVehiculo::GetPlaca() const {
    return placa;
}

void MVehiculo::SetPlaca(const string &placa) {
    MVehiculo::placa = placa;
}

const vector<int> &MVehiculo::getVecSize() const {
    return vec_size;
}
void MVehiculo::setVecSize(const vector<int> &vecSize) {
    vec_size = vecSize;
}
void MVehiculo:: Clear_Vec() {
    vec_size.clear();
}
int MVehiculo:: Cant_Vec() {
    return vec_size.size();
}
void MVehiculo::SetVecS(int pos, int space) {
    vec_size[pos] = space;
}
int MVehiculo::GetVecS(int i) {
    return vec_size[i];
}
