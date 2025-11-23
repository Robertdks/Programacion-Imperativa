#include <iostream>
using namespace std ;

struct Nodo
{
    int dato ;
    Nodo * siguiente ;
};
void InsertarNodo(Nodo * & Lista , Nodo * Nuevo)
{
    if (Lista == nullptr || Nuevo->dato < Lista->dato)
    {
        Nuevo->siguiente = Lista ;
        Lista = Nuevo;
    }
    else
    {
        Nodo * temp = Lista ;
        while (temp != nullptr && temp->siguiente->dato < Nuevo->dato)
        {
            temp = temp->siguiente ;
        }
        Nuevo->siguiente = temp->siguiente ;
        temp->siguiente = Nuevo ;
    }
}
void InsertarOrdenado(Nodo * & Lista)
{
    int aux  ;
    cout << "Ingrese un numero [0] para finalizar: ";
    cin >> aux ;
    while (aux != 0)
    {
        Nodo * Nuevo = new Nodo () ;
        Nuevo->dato = aux ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese un numero [0] para finalizar: ";
        cin >> aux ;
    }
}
void MostrarLista(Nodo * Lista)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        cout << temp->dato ;
        temp = temp->siguiente ;
    }
}
void InsertarNodoFinal(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Lista = Nuevo ;
    }
    else
    {
        Nodo * temp  = Lista ;
        while (temp->siguiente != nullptr)
        {
            temp = temp->siguiente ;
        }
        temp->siguiente = Nuevo;
    }
}
void CargarFinal(Nodo * & Lista)
{
    int aux ;
    cout << "Ingrese un numero [0] para finalizar: " ;
    cin >> aux ;
    while (aux != 0)
    {
        Nodo * Nuevo = new Nodo () ;
        Nuevo->dato = aux ;
        Nuevo->siguiente = nullptr ;
        InsertarNodoFinal(Lista,Nuevo) ;
        cout << "Ingrese un numero [0] para finalizar: " ;
        cin >> aux ;
    }
}
void EnlaceInicio(Nodo * & Lista , Nodo * Nueva)
{
    Nueva->siguiente = Lista ;
    Lista = Nueva ;
}
void InsertarInicio(Nodo * & Lista)
{
    int aux  ;
    cout <<"Ingrese un numero [0] para finalizar: ";
    cin >> aux ;
    while (aux != 0)
    {
        Nodo * Nuevo = new Nodo() ;
        Nuevo->dato = aux ;
        Nuevo->siguiente = nullptr ;
        EnlaceInicio(Lista,Nuevo) ;
        cout <<"Ingrese un numero [0] para finalizar: ";
        cin >> aux ;
    }
}
int main ()
{
    Nodo * Lista = nullptr ;
    InsertarInicio(Lista);
    MostrarLista(Lista);
    return 0 ;
}