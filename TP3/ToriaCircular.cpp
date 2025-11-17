/*La definición para las listas enlazadas circulaler es la misma, a continuacion se muestra*/

#include <iostream>
#include <string>
#include <limits>

using namespace std ;

struct Nodo 
{
    int dato ;
    Nodo * siguiente ;
} ;
void InsertarPrincipio (Nodo * &  Fin, Nodo * Nuevo) // Función que inserta al principio
{
    if (Fin == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
        Fin = Nuevo ;
    }
    else
    {
        Nuevo->siguiente = Fin->siguiente ;
        Fin->siguiente = Nuevo ;
    }
}
void InsertarFinal(Nodo * & Fin, Nodo * Nuevo) // Función que inserta al final
{
    if (Fin == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
    }
    else
    {
        Nuevo->siguiente = Fin->siguiente ;
        Fin->siguiente = Nuevo ;
    }
    Fin = Nuevo ; // Es lo unico que cambia entre insertar al final y al principio..
}
void MostrarLista(Nodo * Fin) // Recorrer la lista y mostrarlo
{
    if (Fin != nullptr)
    {
        Nodo * aux = Fin->siguiente ;
        do
        {
            cout << aux->dato << " " ;
            aux = aux->siguiente ;
        }
        while (aux != Fin->siguiente) ;
    }
    else
    {
        cout << "La lista se encuentra vacia !" << endl ;
    }
}
void CargarLista(Nodo * Fin)
{

}
int main ()
{
    Nodo * Fin = nullptr ; // declaración de la lista;
    //Insertar al principio.

}
