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
