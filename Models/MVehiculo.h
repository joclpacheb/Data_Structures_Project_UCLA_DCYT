#ifndef DATA_STRUCTURES_PROJECT_UCLA_DCYT_MVEHICULO_H
#define DATA_STRUCTURES_PROJECT_UCLA_DCYT_MVEHICULO_H

#include "../Libs/Pila/Pila.cpp"

class MVehiculo {

private:
    int tipo;
    //el vehiculo puede ser de tipo vehiculo(normal), tipo transporte o tipo carga....
    int espacio;
    //en función de ello tiene un espacio que ocupa en la bahía en la que se encuentre...
    float tanque;

    Pila <int> PilaHoras;

public:
    MVehiculo();
    Pila <int> GetPilaHoras() const;
    MVehiculo(int tipo);
    //~MVehiculo();
    void InsertTime(int n);
    void RemoveTime(int &n);
    bool Empty();
    bool Full();
    int GetTipo();
    int GetEspacio();
    float GetTanque();
    void SetTipo(int ti);
    void SetEspacio(int e);
    void SetTanque (float ta);

};


#endif //DATA_STRUCTURES_PROJECT_UCLA_DCYT_MVEHICULO_H
