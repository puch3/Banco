#include "Arbin.h"
#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

Arbin::Arbin()
{
    this->Raiz = nullptr;
}

void Arbin::AgregarArbinP(NodoArbin *& Arbol,Cliente & dato)
{
    if (Arbol == nullptr){
        NodoArbin * Nodo = new NodoArbin();
        Nodo->dato = dato;
        Nodo->izq = nullptr;
        Nodo->der = nullptr;
        Arbol = Nodo;
    }
    else{
        if (Arbol->dato.MontoCliente() < dato.MontoCliente())
            AgregarArbinP(Arbol->der, dato);
        else
            AgregarArbinP(Arbol->izq, dato);
    }
}

void Arbin::AgregarArbin(Cliente & dato)
{
    if (Raiz == nullptr){
        NodoArbin * Nodo = new NodoArbin();
        Nodo->dato = dato;
        Nodo->izq = nullptr;
        Nodo->der = nullptr;
        Raiz = Nodo;
    }
    else
        AgregarArbinP(Raiz, dato);
}

void Arbin::recorrerP(ListaSimple & listamonto,int MMin,int MMax,NodoArbin * Arbol) const{
    if (Arbol !=nullptr){
        if (Arbol->dato.MontoCliente()<MMin)
            recorrerP(listamonto,MMin,MMax,Arbol->der);
        if ((Arbol->dato.MontoCliente()>=MMin) && ((Arbol->dato.MontoCliente()<=MMax))){
            recorrerP(listamonto,MMin,MMax,Arbol->izq);
            listamonto.InsertarPLista(Arbol->dato);
            recorrerP(listamonto,MMin,MMax,Arbol->der);
        }
        if (Arbol->dato.MontoCliente()>MMax)
            recorrerP(listamonto,MMin,MMax,Arbol->izq);
    }
}

void Arbin::recorrer(ListaSimple & listamonto,int MMin,int MMax) const
{
    if (Raiz == nullptr)
        cout << "No hay clientes atendidos!" << endl;
    else
        recorrerP(listamonto,MMin,MMax,Raiz);

}

bool Arbin::VacioArbin() const
{
    if (Raiz == nullptr)
        return true;
    else
        return false;
}
