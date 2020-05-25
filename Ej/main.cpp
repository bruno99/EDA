#include <iostream>
#include <string>
#include <vector>
#include <listadoble.h>

using namespace std;

int main()
{
    cout << "Empezamos..." << endl;
    ListaDoble MiLista;

    nodo N0={"Nodo 0",0, nullptr, nullptr};
    nodo N1={"Primer Nodo",1, nullptr, nullptr};
    nodo N2={"Segundo Nodo",2, nullptr, nullptr};
    nodo N3={"Tercer Nodo",3, nullptr, nullptr};
    nodo N4={"Cuarto Nodo",4, nullptr, nullptr};
    nodo N5={"Quinto Nodo",5, nullptr, nullptr};
    nodo N6={"Sexto Nodo",6, nullptr, nullptr};

    nodo n77={"Nodo 77",7, nullptr, nullptr};
    nodo n88={"Nodo 88",8, nullptr, nullptr};
    nodo n99={"Nodo 99",9, nullptr, nullptr};

    nodo n100={"Nodo100",10, nullptr, nullptr};


    cout << "Montamos lista" << endl;
    MiLista.InsertarNodoEnListaVacia(&N1);
    MiLista.InsertarNodoFinLista(&N2);
    MiLista.InsertarNodoFinLista(&N3);
    MiLista.InsertarNodoFinLista(&N4);
    MiLista.InsertarNodoFinLista(&N5);
    MiLista.InsertarNodoFinLista(&N6);
    MiLista.InsertarNodoFinLista(&n77);
    MiLista.InsertarNodoFinLista(&n88);
    MiLista.InsertarNodoFinLista(&n99);
    MiLista.InsertarNodoFinLista(&n100);
    MiLista.InsertarNodoInicioLista(&N0);

    MiLista.ImprimirLista(1);

    std::cout<<"POsicion de nodo 0: "<<MiLista.Buscar(0)<<std::endl;

   //obtenemos el puntero del inicio de la lista
    nodo* ptr=MiLista.getNodoInicio();

    std::cout<<"Buscamos el nodo con valor 6 de manera recursiva. Su direccion es: ";
    std::cout<<MiLista.BusquedaRecursiva(6,ptr)<<std::endl;

    std::cout<<"Lista recorrida de manera recursiva: ";
    MiLista.RecorrerRecursivo(1,ptr);

    std::cout<<"La suma de los valores contenidos en la lista es de: ";
    std::cout<<MiLista.SumaListaRecursiva(ptr)<<std::endl;

    std::cout<<"Eliminamos por valor el nodo con valor 78. Resultado?: "<< MiLista.SuprimirNodo(8)<<std::endl;
    std::cout<<"Eliminamos por valor el nodo con valor 78. Resultado?: "<< MiLista.SuprimirNodo(8)<<std::endl;
    std::cout<<"Eliminamos de manera recursiva el nodo con valor 7. Resultado?: "<<MiLista.EliminaRecursivo(7,ptr)<<std::endl;
    std::cout<<"Eliminamos de manera recursiva el nodo con valor 7. Resultado?: "<<MiLista.EliminaRecursivo(7,ptr)<<std::endl;


    MiLista.ImprimirLista(1);
    MiLista.RecorrerRecursivo(1,ptr);

    std::cout<<"Destruimos la lista entera...";
    MiLista.DestruirRecursivo(ptr);

    cout << "Hemos terminado..." << endl;
    return 0;
}
