#ifndef LISTADOBLE_H
#define LISTADOBLE_H
​
#include <iostream>
#include <vector>
#include <string>
​
​
struct nodo{
    std::string nombre;
    int valor;
    nodo *SiguienteElemento;
    nodo *AnteriorElemento;
};
​
struct IdentificadorLista
{
    nodo *Primero;
    nodo *Ultimo;
    int tamano;
};
​
class ListaDoble{
private:
    IdentificadorLista *MiLista=new IdentificadorLista; //Reservamos dinámicamente un puntero a IdentificadorLista
public:
    ListaDoble();
    bool InsertarNodoEnListaVacia(nodo*);
    bool InsertarNodoInicioLista(nodo*);
    bool InsertarNodoFinLista(nodo*);
    bool SuprimirInicioLista(void);
    bool SuprimirNodoPosicion(int);
    bool ImprimirLista(bool sentido);
​
    //*******************
    nodo* getNodoInicio();
    nodo* getNodoFin();
​
    nodo* BusquedaRecursiva(int v, nodo* inicio);
    void RecorrerRecursivo(bool sentido, nodo* inicio);
    int SumaListaRecursiva(nodo* inicio);
​
    int Buscar(int valor); //devuelve posición
    bool SuprimirNodo(int);
    bool EliminaRecursivo(int v, nodo* inicio);
    void DestruirRecursivo(nodo* inicio);
​
    void InsertaConOrdenRecursivo(int v);
};
​
#endif // LISTADOBLE_H
Contraer



17:24
ListaDoble.cpp
Parte practica 
#include "listadoble.h"
​
ListaDoble::ListaDoble()
{
    MiLista->Primero=nullptr;
    MiLista->Ultimo=nullptr;
    MiLista->tamano=0;
}
​
bool ListaDoble::InsertarNodoEnListaVacia(nodo* n)
{
    if(MiLista->Primero==nullptr)
    {//Si está vacía lo creamos
        //Reserva en memoria dinámica para un nuevo nodo
        nodo *NodoNuevo=new nodo;;
        //Información que tiene el nuevo nodo en la lista
        //NodoNuevo=n; OJO esto iguala direcciones!!! al hacer delete error porque no lo habremos creado con new
        *NodoNuevo=*n; //Esto iguala contenidos, lo que queremos hacer :)
        
        //Actualizamos punteros del nuevo nodo, al ser el primero apuntán a null los 2
        NodoNuevo->SiguienteElemento=nullptr;
        NodoNuevo->AnteriorElemento=nullptr;
        //Actualizamos nuestro identificador de lista
        MiLista->Primero=NodoNuevo;
        MiLista->Ultimo=NodoNuevo;
​
        MiLista->tamano++;
​
        return true; //Nodo insertado
    }
    else {
        return false; //Nodo no insertado
    }
}
​
bool ListaDoble::InsertarNodoInicioLista(nodo* n)
{
​
    if(MiLista->Primero!=nullptr)
    {//Si la lista no está vacía insertamos nodo
        nodo *NodoNuevo=new nodo;
​
        //NodoNuevo=n; OJO esto iguala direcciones!!! al hacer delete error porque no lo habremos creado con new
        *NodoNuevo=*n; //Esto iguala contenidos, lo que queremos hacer :)
​
        NodoNuevo->SiguienteElemento=MiLista->Primero;
        NodoNuevo->AnteriorElemento=nullptr; //Al ser el primer nodo no apuntara a un nodo anterior
​
        MiLista->Primero->AnteriorElemento=NodoNuevo;
​
        //Actualizamos el identificador de lista
        MiLista->Primero=NodoNuevo;
        MiLista->tamano++;
​
        return true;
    }
    else {
        //Lista vacía, deberemos usar InsertarNodoEnListaVacia
        return false;
    }
​
}
​
bool ListaDoble::InsertarNodoFinLista(nodo* n)
{
​
    if(MiLista->Primero!=nullptr)
    {//Si la lista no está vacía insertamos el nodo
        nodo *NodoNuevo=new nodo;
​
        //NodoNuevo=n; OJO esto iguala direcciones!!! al hacer delete error porque no lo habremos creado con new
        *NodoNuevo=*n; //Esto iguala contenidos, lo que queremos hacer :)
​
        NodoNuevo->SiguienteElemento=nullptr;
        NodoNuevo->AnteriorElemento=MiLista->Ultimo;
​
        MiLista->Ultimo->SiguienteElemento=NodoNuevo; //Antes era null, ahora es el penultimo
        //Actualizamos identificador de lista
        MiLista->Ultimo=NodoNuevo;
​
        MiLista->tamano++;
​
        return true;
    }
    else {
        //Lista vacía, deberemos usar InsertarNodoEnListaVacia
        return false;
    }
}
​
bool ListaDoble::SuprimirInicioLista()
{
    if(MiLista->tamano==0)
    {//Lista vacia, no podemos suprimir
        return 0;
    }
​
    nodo *ASuprimir;
​
    ASuprimir=MiLista->Primero;
​
    //Actualizamos identificador de lista.
    MiLista->Primero=ASuprimir->SiguienteElemento;
    if(MiLista->tamano==1)
    {//Si sólo hay un nodo, al eliminarle nos quedamos sin nodos->no hay último ni primero
        MiLista->Ultimo=nullptr;
        MiLista->Primero=nullptr;
    }
    else
    {
        MiLista->Primero->AnteriorElemento=nullptr;
    }
    //Borramos el nodo
    delete ASuprimir; //Liberamos memoria
​
    MiLista->tamano--;
​
    return 1;
}
​
bool ListaDoble::SuprimirNodoPosicion(int posicion)
{
    //if(MiLista->tamano<=1 || posicion < 1 || posicion>MiLista->tamano)
    if(MiLista->tamano<=0 || posicion < 0 || posicion>MiLista->tamano)
    {//Error: lista vacia, posición negativa, posición fuera del rango tamaño de la lista
        return 0;
    }
​
    if(MiLista->tamano==posicion)
    {//Queremos borrar el ultimo elemento
        nodo *ASuprimir;
        ASuprimir=MiLista->Ultimo;
​
        MiLista->Ultimo->AnteriorElemento->SiguienteElemento=nullptr;
        MiLista->Ultimo=MiLista->Ultimo->AnteriorElemento;
        delete ASuprimir;
        MiLista->tamano--;
​
        return 1;
    }
    /*else if (posicion==0)
    {//Queremos borrar el primer nodo
        if(SuprimirInicioLista())
        {//Devuelve true si ejecuta el borrado del inicio
            return 1;
        }
        return 0;
    }*/
    else
    {//Queremos borrar uno intermedio
        nodo *ASuprimir, *temporal;
​
        temporal=MiLista->Primero;
        for(int i=0;i<posicion;i++)
        {//Recorremos Lista hasta encontrar Nodo de la posición indicada
            temporal=temporal->SiguienteElemento;
        }
​
​
        ASuprimir=temporal;
        temporal->SiguienteElemento->AnteriorElemento=ASuprimir->AnteriorElemento;
        temporal->AnteriorElemento->SiguienteElemento=ASuprimir->SiguienteElemento;
​
        delete ASuprimir;
        MiLista->tamano--;
​
        return 1;
    }
}
​
bool ListaDoble::ImprimirLista(bool sentido)
{
    if(MiLista->Primero!=nullptr)
    {//Lista no está vacía
        nodo *temporal;
​
        if(sentido)
        {//Recorremos de inicio a fin
            temporal=MiLista->Primero;
            std::cout<<"--Inicio de la lista--"<<std::endl;
            while(temporal!=nullptr)
            {
                std::cout<<"Dir nodo: "<< temporal <<"|| Anterior nodo: "<<temporal->AnteriorElemento <<"\t"<< "|| Siguiente nodo: "<< temporal->SiguienteElemento <<"\t"<< "|| Nombre nodo: "<<temporal->nombre<<std::endl;
                temporal=temporal->SiguienteElemento;
            }
            std::cout<<"--Fin de la lista--"<<std::endl;
        }
        else
        {//Recorremos de fin a inicio
            temporal=MiLista->Ultimo;
            std::cout<<"--Fin de la lista--"<<std::endl;
            while(temporal!=nullptr)
            {
                std::cout<<"Dir nodo: "<< temporal << "|| Siguiente nodo: "<< temporal->SiguienteElemento <<"\t"<<" || Anterior nodo: "<<temporal->AnteriorElemento<<"\t"<<" || Nombre nodo: "<<temporal->nombre<<std::endl;
                temporal=temporal->AnteriorElemento;
            }
            std::cout<<"--Inicio de la lista--"<<std::endl;
        }
        return true;
    }
    else {
        std::cout<<"La lista esta vacia."<<std::endl;
        return false;
    }
​
}
​
nodo *ListaDoble::getNodoInicio()
{
    return MiLista->Primero;
}
​
nodo *ListaDoble::getNodoFin()
{
    return MiLista->Ultimo;
}
​
nodo *ListaDoble::BusquedaRecursiva(int v, nodo* inicio)
{
    if(inicio->SiguienteElemento!=nullptr)
    {
        if(inicio->valor==v)
        {
            return inicio;
        }
        else {
            BusquedaRecursiva(v, inicio->SiguienteElemento);
        }
    }
    else
    {
        return nullptr;
    }
}
​
void ListaDoble::RecorrerRecursivo(bool sentido, nodo* inicio)
{
    if(sentido==true)
    {
        if(inicio->SiguienteElemento!=nullptr)
        {
            std::cout<<inicio->valor<<" ";
            RecorrerRecursivo(sentido, inicio->SiguienteElemento);
        }
        else {
            std::cout<<inicio->valor<<std::endl;
        }
    }
    else {
        if(inicio->AnteriorElemento!=nullptr)
        {
            std::cout<<inicio->valor<<" ";
            RecorrerRecursivo(sentido, inicio->AnteriorElemento);
        }
        else {
            std::cout<<inicio->valor<<std::endl;
        }
    }
}
​
int ListaDoble::SumaListaRecursiva(nodo *inicio)
{
    int resultado=0;
​
    if(inicio->SiguienteElemento!=nullptr)
    {
        resultado=inicio->valor+SumaListaRecursiva(inicio->SiguienteElemento);
        return resultado;
    }
    else {
        return resultado+inicio->valor;
    }
}
​
int ListaDoble::Buscar(int valor)
{
    nodo* aux=MiLista->Primero;
    int pos=0;
​
    while(aux!=nullptr)
    {
        if(aux->valor==valor)
        {
            return pos; //devolvemos la posición en la lista
        }
        else {
            aux=aux->SiguienteElemento;
            pos++; //Incrementamos la posición
        }
    }
    return -1; //No lo hemos encontrado
}
​
bool ListaDoble::SuprimirNodo(int v)
{
   int pos=Buscar(v);
​
   if(pos!=-1)
   {
        if(pos==0)
        {
            return SuprimirInicioLista();
        }
        else
        {
            return SuprimirNodoPosicion(pos);
        }
​
   }
   else {
       std::cout<<"Nodo no encontrado"<<std::endl;
       return 0;
   }
}
​
bool ListaDoble::EliminaRecursivo(int v, nodo* inicio)
{
    if(inicio->SiguienteElemento!=nullptr)
    {
        if(inicio->valor==v)
        {
            return SuprimirNodo(inicio->valor);
        }
        EliminaRecursivo(v, inicio->SiguienteElemento);
    }
    else {
        //Hemos llegado al final y no está
        return 0;
    }
}
​
void ListaDoble::DestruirRecursivo(nodo* inicio)
{
    if(inicio->SiguienteElemento!=nullptr)
    {
        SuprimirInicioLista();
        DestruirRecursivo(inicio->SiguienteElemento);
    }
    else {
        SuprimirInicioLista();
    }
}
