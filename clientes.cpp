#include "clientes.h"

using namespace std;

Cliente::Cliente()
{
    //ctor
}
Cliente::Cliente(string Nombre, int Edad, int Operacion, int Destinatario, int Monto, bool Pertenece)
{
    this->Nombre = Nombre;
    this->Edad = Edad;
    this->Operacion = Operacion;
    this->Destinatario = Destinatario;
    this->Monto = Monto;
    this->Pertenece = Pertenece;


}


Cliente::~Cliente()
{
    //dtor
}

string Cliente::NombreCliente()
{
    return Nombre;
}

int Cliente::EdadCliente()
{
    return Edad;
}

int Cliente::OperacionCliente()
{
    return Operacion;
}

int Cliente::DestinatarioCliente()
{
    return Destinatario;
}

int Cliente::MontoCliente()
{
    return Monto;
}

bool Cliente::PerteneceCliente()
{
    return Pertenece;
}

