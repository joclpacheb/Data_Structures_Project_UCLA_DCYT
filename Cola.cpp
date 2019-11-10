#include "Cola.h"

template <class Tipo>
Cola<Tipo>::Cola() {
    Frente=NULL;
    Final=NULL;
};

template <class Tipo>
bool Cola<Tipo>::Vacia(){
    return Frente == NULL;
}

template<class Tipo>
NodoCola<Tipo> *Cola<Tipo>::getFrente() const {
    return Frente;
}

template<class Tipo>
NodoCola<Tipo> *Cola<Tipo>::getFinal() const {
    return Final;
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
// Solo sirve con numeros
template <class Tipo>
int Cola<Tipo>::NumeroElementos(Tipo valor){
    Tipo v2;
    int cont=0;
    if(Vacia())
        return 0;
    else{
        Remover(v2);
        Insertar(valor);
        cont++;
        if(valor == Frente->info){
            Remover(v2);
            return 1;
        }
        else{
            do{
                Remover(v2);
                Insertar(v2);
                cont++;
            }while(valor != Frente->info);
            Remover(v2);
            return cont;
        }

    }
}

