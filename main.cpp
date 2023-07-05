#include <iostream>
#include <fstream>
#include <clocale>
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include "listasimple.h"
#include "arbin.h"
#include "clientes.h"

using namespace std;

//opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1opcion1op
void AgregarClienteFila(Cliente NuevoCliente, ListaSimple & Principal,ListaSimple & Aux1,ListaSimple & Aux2,int puertas[]){
    if ((puertas[0]==0) && (puertas[1]==0))
        Principal.InsertarFLista(NuevoCliente);
    else if ((puertas[0]==NuevoCliente.OperacionCliente()) && (NuevoCliente.PerteneceCliente()))
        Aux1.InsertarFLista(NuevoCliente);
    else if ((puertas[1]==NuevoCliente.OperacionCliente()) && (NuevoCliente.PerteneceCliente()))
        Aux2.InsertarFLista(NuevoCliente);

}

void AgregarCliente(ListaSimple & Principal,ListaSimple & Aux1,ListaSimple & Aux2, int puertas[]){
    string nombre;
    cout << "Ingrese nombre del cliente (sin espacios): ";
    cin >> nombre;
    int edad;
    cout << endl << "Ingrese edad: ";
    cin >> edad;
    int operacion;
    cout << endl << "Ingrese operacion(1.Retiro, 2.Deposito, 3.Transferencia o 4.Pago): ";
    cin >> operacion;
    int destinatario;
    cout << endl << "Ingrese destinatario(1.persona, 2.banco, 3.impuesto): ";
    cin >> destinatario;
    int monto;
    cout << endl << "Ingrese monto:";
    cin >> monto;
    char son;
    cout << endl << "Ingrese si el cliente pertenece o no al banco (s=si, n=no): ";
    cin >> son;
    bool pertenece;
    if (son=='s')
        pertenece = true;
    else if (son=='n')
        pertenece = false;
    Cliente NuevoCliente(nombre, edad, operacion, destinatario, monto, pertenece);
    AgregarClienteFila(NuevoCliente, Principal, Aux1, Aux2, puertas);
}

//opcion2opcion2opcion2opcion2opcion2opcion2opcion2opcion2opcion2opcion2opcio
void ChequeoPrincipal(ListaSimple & Principal,ListaSimple & Aux, int puerta){
    cout << "-CHECKING PRINCIPAL-" << endl;
    Cliente ClienteAux;
    Principal.InicioLista();
    while (Principal.CursorPublico!= nullptr){
        ClienteAux = Principal.CursorPublico->dato;
        if ((ClienteAux.OperacionCliente()==puerta) && (ClienteAux.PerteneceCliente())){
            Principal.BorrarLista(ClienteAux);
            Aux.InsertarFLista(ClienteAux);
        }
        Principal.AvanzarLista();
    }
}

void AgregarFilaAux(ListaSimple & Principal,ListaSimple & Aux1,ListaSimple & Aux2,int puertas[]){
    cout << "inserte operacion excluyente para su nueva fila auxiliar (1.Retiro, 2.Deposito, 3.Transferencia o 4.Pago): ";
    int operacion;
    cin >> operacion;
    cout << endl;
    if (puertas[0]==0){
        puertas[0]= operacion;
        ChequeoPrincipal(Principal, Aux1, puertas[0]);
        cout << "-AUX1 CHARGED-" << endl;
    }
    else if ((puertas[0]!=0)&&(puertas[1]==0)){
        puertas[1]= operacion;
        ChequeoPrincipal(Principal, Aux2, puertas[1]);
        cout << "-AUX2 CHARGED-" << endl;
    }
    else if ((puertas[0]!=0)&&(puertas[1]!=0))
        cout << "todas las filas auxiliares estan ocupadas!" << endl;
}

//opcion3opcion3opcion3opcion3opcio
void MostrarCliente(Cliente aux1,int i){
    cout<<"Cliente: "<<i<<endl;
    cout<<"nombre: "<<aux1.NombreCliente()<<endl;
    cout<<"Edad: "<<aux1.EdadCliente()<<endl;
    cout<<"Operacion a realizar: ";
    if (aux1.OperacionCliente()==1)
        cout<<"Retiro"<<endl;
    if (aux1.OperacionCliente()==2)
        cout<<"Deposito"<<endl;
    if (aux1.OperacionCliente()==3)
        cout<<"Transferencia"<<endl;
    if (aux1.OperacionCliente()==4)
        cout<<"Pago"<<endl;
    cout<<"Destinatario: ";
    if (aux1.DestinatarioCliente()==1)
        cout<<"persona"<<endl;
    if (aux1.DestinatarioCliente()==2)
        cout<<"Banco"<<endl;
    if (aux1.DestinatarioCliente()==3)
        cout<<"Impuesto"<<endl;
    cout<<"Monto de la Transaccion: "<<aux1.MontoCliente()<<endl;
    if (aux1.PerteneceCliente())
        cout<<"El cliente pertenece al banco";
    else
        cout<<"El cliente no pertenece al banco"<<endl;
    cout<<endl;
}

void MostrarFila(ListaSimple fila){
    fila.InicioLista();
    Cliente aux1;
    int i = 1;
    while ((fila.CursorPublico) !=nullptr){
        aux1=fila.CursorPublico->dato;
        MostrarCliente(aux1,i);
        fila.AvanzarLista();
        i++;
    }
    fila.InicioLista();
}

void MostrarFilas (ListaSimple Principal,ListaSimple Aux1,ListaSimple Aux2, int puertas[]){
    cout << "-------------------------------------------------------------------------" << endl;
    cout <<
    "FILA PRINCIPAL" << endl;
    if (Principal.VaciaLista()==true)
        cout << "La fila esta vacia o cerrada"<<endl;
    else{
        MostrarFila(Principal);
        cout << endl;
    }
    cout << endl << "FILA AUX1" << endl;
    if (Aux1.VaciaLista()==true)
        cout << "La fila esta vacia o cerrada"<<endl;
    else
        MostrarFila(Aux1);
    cout << endl << "FILA AUX2" << endl;
    if (Aux2.VaciaLista()==true)
        cout << "La fila esta vacia o cerrada"<<endl;
    else
        MostrarFila(Aux2);
    cout << "-------------------------------------------------------------------------" << endl;
}

//opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion4opcion
void AtenderFila(ListaSimple & Lista, Arbin & Atendidos){
    int i=1;
    Lista.InicioLista();
    MostrarCliente(Lista.CursorPublico->dato,i);
    cout << endl;
    Atendidos.AgregarArbin(Lista.CursorPublico->dato);
    Lista.BorrarLista(Lista.CursorPublico->dato);
}

void AtenderCliente(ListaSimple & Principal,ListaSimple & Aux1,ListaSimple & Aux2,int puertas[],Arbin & Atendidos){
    int fila = 1;
    if ((puertas[0] != 0) && (puertas[1] != 0)){
        cout << "Seleccione la fila que desea atender (1.Principal, 2.Aux1, 3.Aux2): " << endl;
        cin >> fila;
    }
    if ((fila == 1)&&(!Principal.VaciaLista()))
        AtenderFila(Principal, Atendidos);
    else if((fila == 2)&&(!Aux1.VaciaLista()))
        AtenderFila(Aux1, Atendidos);
    else if((fila == 3)&&(!Aux2.VaciaLista()))
        AtenderFila(Aux2, Atendidos);
    else{
        cout << "fila vacia o inexistente" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
    }
}

//opcion5opcion5opcion5opcion5opcion5opcion5opcion5opcion5opcion5opcion5opcion5opcion5opcio
void CerrarColaAux(ListaSimple Principal,ListaSimple Aux1,ListaSimple Aux2, int puertas[]){
    int fila;
    cout << "elija cual fila desea cerrar (Aux1=1 y Aux2=2): ";
    cin >> fila;
    if (fila==1 && Aux1.VaciaLista()){
        puertas[0]=0;
        cout << "COLA " << fila << " CERRADA" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
    }
    else if (fila==2 && Aux2.VaciaLista()){
        puertas[0]=0;
        cout << "COLA " << fila << " CERRADA" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
    }
    else{
        cout << "la lista q desea cerrar no esta vacia!" << endl;
    }
}

//opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6opcion6
void ListarOppMonto (Arbin Atendidos){
    if (!Atendidos.VacioArbin()){
        int MMax,MMin;
        ListaSimple listamonto;
        cout<<"Ingrese el monto minimo: ";
        cin>>MMin;
        cout<<endl;
        cout<<"Ingrese el monto maximo: ";
        cin>>MMax;
        cout<<endl;
        Atendidos.recorrer(listamonto,MMin,MMax);
        MostrarFila(listamonto);
        cout<<"Promedio de Edad de clientes atendidos dentro del rango de monto: "<<listamonto.promedio()<<endl;
    }
}

//menumenumenumenumenu
void LimpiarPantalla()
{
    char x;
    scanf("%c",&x);
    system("cls");
}

void Menu(ListaSimple Principal,ListaSimple Aux1,ListaSimple Aux2,Arbin Atendidos, int puertas[]) // central de funciones
{
    // puertas es para ver si aux o aux2 estan abiertas, su valor sera la operacion"
    int opcion; // la opcion que elije el usuario
    cout <<"BANCO PA" << endl << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "elija que accion desea resolver: " << endl;
    cout << "1. Agregar cliente a la cola" << endl;
    cout << "2. Agregar fila auxiliar" << endl;
    cout << "3. Mostrar filas" << endl;
    cout << "4. Atender cliente" << endl;
    cout << "5. Cerrar cola auxiliar" << endl;
    cout << "6. Listar operaciones atendidas segun rango de monto" << endl << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "opcion:";
    cin >> opcion;
    while ((opcion<1) || (opcion>6)){
        cout << "escoja un valor dentro de los especificados!" << endl;
        cin >> opcion;
    }
    if (opcion == 1)
        AgregarCliente(Principal, Aux1, Aux2, puertas);
    else if (opcion == 2)
        AgregarFilaAux(Principal, Aux1, Aux2, puertas);
    else if (opcion == 3)
        MostrarFilas(Principal, Aux1, Aux2, puertas);
    else if (opcion == 4)
        AtenderCliente(Principal, Aux1, Aux2, puertas, Atendidos);
    else if (opcion == 5)
        CerrarColaAux(Principal, Aux1, Aux2, puertas);
    else if (opcion == 6)
        ListarOppMonto(Atendidos);
    cout << "desea realizar otra accion? (s o n) " << endl;
    char siono;
    cin >> siono;
    if (siono=='s'){
        LimpiarPantalla();
        Menu(Principal, Aux1, Aux2, Atendidos, puertas);
    }
    else
        cout << "hasta luego!";
}

int main()
{
    int puertas[1];
    puertas[0]=0;
    puertas[1]=0;
    Arbin Atendidos;
    ListaSimple Principal;
    ListaSimple Aux1;
    ListaSimple Aux2;
    Menu(Principal, Aux1, Aux2, Atendidos, puertas);
    return 0;
}
