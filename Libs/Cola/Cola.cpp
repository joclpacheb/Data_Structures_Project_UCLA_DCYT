#include "Cola.h"

template <class Tipo>
Cola<Tipo>::Cola() {
     Frente=NULL;
     Final=NULL;
};

template <class Tipo>
bool Cola<Tipo>::Vacia(){
     return Frente == NULL;
};

template <class Tipo>
bool Cola<Tipo>::Llena(){
    NodoCola<Tipo> *p;
     p=new NodoCola<Tipo>;
     if (p==NULL)
        return true;
     else
    {   delete p;
        return false;
    }
};

template <class Tipo>
bool Cola<Tipo>::Insertar(Tipo Valor){
    NodoCola<Tipo> *nuevo;
     if (!Llena())
     {
        nuevo=new NodoCola<Tipo>;
        nuevo->info=Valor;
        nuevo->prox=NULL;
        if (Final==NULL) 
            Frente=nuevo;       
        else Final->prox=nuevo;
        Final=nuevo;
        return true;
      }
      else return false;
};

template <class Tipo>
bool Cola<Tipo>::Remover(Tipo &Valor){
    NodoCola<Tipo> *primero;
     if (!Vacia())
     {
        primero=Frente;
        Valor=primero->info;
        Frente=primero->prox;
        if (Frente==NULL)
            Final=NULL;
        delete primero;
        return true;
     }
     else
     return false;
};
