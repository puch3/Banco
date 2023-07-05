#include "ListaSimple.h"
#include <iostream>
#include <cassert>
#include "clientes.h"

using namespace std;

void ListaSimple::AvanzarLista()
{
    this->CursorPublico = this->CursorPublico->sig;
}

void ListaSimple::InicioLista()
{
    this->CursorPublico = this->Primero;
}

ListaSimple::ListaSimple() {
    this->Primero = nullptr;
    this->CursorPublico = nullptr;
}


bool ListaSimple::VaciaLista() const
{
    if (this->Primero==nullptr)
        return true;
    else
        return false;
}

void ListaSimple::BorrarLista(Cliente dato)
{
    NodoLista * Aux = this->Primero;
    NodoLista * Borrar;
    if ((Primero->dato.NombreCliente()) == (dato.NombreCliente())){
        Aux = Primero;
        Primero = Primero->sig;
        delete Aux;
    }
    else{
        while(Borrar->dato.NombreCliente() != dato.NombreCliente()){
            Aux = Borrar;
            Borrar = Borrar->sig;
        }
        Aux->sig = Aux->sig->sig;
        delete Borrar;
    }
}

void ListaSimple::InsertarFLista(Cliente NuevoDato)
{
    NodoLista* Aux = this->Primero;
    NodoLista* Nuevo = new NodoLista;

    Nuevo->dato = NuevoDato;
    Nuevo->sig = nullptr;

    if (Aux == nullptr)
       this->Primero = Nuevo;
    else{
        while (Aux->sig != nullptr)
            Aux= Aux->sig;
        Aux->sig = Nuevo;
    }
}

void ListaSimple::InsertarPLista(Cliente NuevoDato)
{
    NodoLista* Nuevo = new NodoLista;
    Nuevo->dato = NuevoDato;
    Nuevo->sig = nullptr;

    Nuevo->sig = Primero;
    Primero = Nuevo;

}
int ListaSimple::promedio() const
{
    int b=0;
    int a=0;
    NodoLista* Cursor = this->Primero;
    while (Cursor!= nullptr){
        a+=Cursor->dato.EdadCliente();
        b++;
        Cursor=Cursor->sig;
    }
    return (a/b);
}
