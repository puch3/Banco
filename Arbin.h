#ifndef ARBIN_H_INCLUDED
#define ARBIN_H_INCLUDED
#include <stdlib.h>
#include "ListaSimple.h"
#include "Arbin.h"

class Arbin
{
private:
    struct NodoArbin{
        Cliente dato;
        NodoArbin * izq, * der;
    };
    NodoArbin * Raiz;
    void AgregarArbinP(NodoArbin *& Arbol,Cliente & dato);
    void recorrerP(ListaSimple & listamonto,int MMin,int MMax,NodoArbin * Arbol) const;
public:
    Arbin(); // esta clase es de un arbol in-order
    void AgregarArbin(Cliente & dato);
    bool VacioArbin() const;
    void recorrer (ListaSimple & listamonto,int MMin,int MMax) const;
};
#endif // ARBIN_H_INCLUDED
