//
// Created by Joclpacheb on 14/07/2019.
//

#ifndef CLION_PROJECTS_COLA_H
#define CLION_PROJECTS_COLA_H

#include "string"

using namespace std;

template<class Tipo>
class Cola;
//
template<class Tipo>
class NodoCola {
    Tipo info;
    NodoCola *prox;
public:
    Tipo getInfoNodo(){
        return info;
    }
    friend class Cola<Tipo>;
};

template<class Tipo>
class Cola {
    NodoCola<Tipo> *Frente, *Final;

public:
    Cola();

    NodoCola<Tipo> *getFrente() const;

    NodoCola<Tipo> *getFinal() const;

    bool Vacia();

    bool Llena();

    bool Insertar(Tipo Valor);

    bool Remover(Tipo &Valor);

    int NumeroElementos(Tipo valor);
};
#include "Cola.cpp"
#endif //CLION_PROJECTS_COLA_H
