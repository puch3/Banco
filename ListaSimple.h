#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "clientes.h"
class ListaSimple
{
private:
     struct NodoLista{
        Cliente dato;
        NodoLista * sig;
    };
    NodoLista *Primero;
public:
    ListaSimple();
    void BorrarLista(Cliente elemento);
    bool VaciaLista() const;
    void InsertarFLista(Cliente NuevoDato);
    void InsertarPLista(Cliente NuevoDato); // funciones agregar en distintas posiciones (se podria usar solo Arbitrario)
    void AvanzarLista(); // herramientas para iterar por fuera
    void InicioLista(); // ATENCION: InicioLista debe ser usado siempre al comienzo de iterar
    int promedio() const;
    NodoLista *CursorPublico;
};
#endif // LISTASIMPLE_H
