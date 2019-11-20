#ifndef DATA_STRUCTURES_PROJECT_UCLA_DCYT_MVEHICULO_H
#define DATA_STRUCTURES_PROJECT_UCLA_DCYT_MVEHICULO_H

#include "../Libs/Pila/Pila.cpp"
#include <string>
#include <vector>
using namespace std;

class MVehiculo {

private:
    int tipo;
    //el vehiculo puede ser de tipo vehiculo(normal), tipo transporte o tipo carga....
    int espacio;
    //en función de ello tiene un espacio que ocupa en la bahía en la que se encuentre...
    float tanque;

    string nombre, placa;

    Pila <float> PilaHoras;


    vector <int> vec_size;
public:
    MVehiculo();
    Pila <float> GetPilaHoras() const;
    MVehiculo(int tipo);
    //~MVehiculo();
    void InsertTime(float n);
    void RemoveTime(float &n);
    bool Empty();
    bool Full();
    int GetTipo();
    int GetEspacio();
    float GetTanque();
    void SetTipo(int ti);
    void SetEspacio(int e);
    void SetTanque (float ta);
    const string &GetNombre() const;
    void SetNombre(const string &nombre);
    const string &GetPlaca() const;
    void SetPlaca(const string &placa);

    //testing this thing
    const vector<int> &getVecSize() const;
    void setVecSize(const vector<int> &vecSize);

    void Clear_Vec();
    int Cant_Vec();
    void SetVecS(int pos, int space);
    int GetVecS(int i);

};


#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_MVEHICULO_H
