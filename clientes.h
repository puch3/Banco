#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

class Cliente
{
private:
    string Nombre;
    int Edad;
    int Operacion; // el usuario tiene que usar un rango de numeros que representan una operacion dada (ej: 1= retiro)
    int Destinatario; //  lo mismo que con Operacion ( razon?? pq es mas facil operar con int y luego escribir las representaciones por pantalla
    int Monto;
    bool Pertenece;
public:
    Cliente();
    Cliente(string Nombre, int Edad, int Operacion, int Destinatario, int Monto, bool Pertenece);
    virtual ~Cliente();
    string NombreCliente();
    int EdadCliente();
    int OperacionCliente();
    int DestinatarioCliente();
    int MontoCliente();
    bool PerteneceCliente();
};

#endif // CLIENTES_H_INCLUDED
