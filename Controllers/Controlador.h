#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../Libs/Genericas/VGeneral.h"
#include "../Libs/Lista/Lista.cpp"
//#include "../Librerias/Pila/Pila.cpp"
//#include "../Librerias/Cola/Cola.cpp"
//#include "../Libs/MTablaMultiplicar.h"
#include <vector>

class Controlador {
private:
    VGeneral  vg;
    Lista<int> Lista1;
    Pila<int> PilaA;
    Cola<int> Cola1;

   // Pila<int> PilaB;
   // Cola<Pila<int>> Cola2;
    MMultiplicador mmul; //pila
    MTablaMultiplicar mtab; //cola

  bool check;
  // int nro;
   vector<int> vecnro;
public:
    Controlador();
    void CargarLista();
    void ImprimirLista();
    void CargarPila();
    void ImprimirPila();
    void CargarCola();
    void ImprimirCola();
    void CargarTabla();
    void ImprimirTabla();
    void BorrarTabla();
    void OpcionLista();
    void OpcionPila();
    void OpcionCola();
    void OpcionTabla();
    void OpcionAyuda();
    void OpcionSalir();
    void Menu();
   //bool SearchTable(int q);
  // int Busqueda(int n);
};

#endif
