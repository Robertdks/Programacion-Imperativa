#include <iostream>
using namespace std ;

struct Nodo
{
    int dato ;
    Nodo * siguiente ;
};

void InsertarFinal(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
    }
    else 
    {
       Nuevo->siguiente = Lista->siguiente ;
       Lista->siguiente = Nuevo ;
    }
    Lista = Nuevo ;
}
void InsertarPrincipio(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
        Lista = Nuevo ;
    }
    else
    {
        Nuevo->siguiente = Lista->siguiente ;
        Lista->siguiente = Nuevo ;
    }
}
void CargarLista(Nodo * & Lista)
{
    int num ;
    cout <<"Ingrese un numero [0] para finalizar: " ;
    cin >> num ;
    while (num != 0)
    {
        Nodo * Nuevo = new Nodo();
        Nuevo->dato = num;
        InsertarPrincipio(Lista,Nuevo) ;
        cout <<"Ingrese un numero [0] para finalizar: " ;
        cin >> num ;
    }
}
void MostrarLista(Nodo * Lista)
{
    Nodo * temp = Lista->siguiente ;
    do
    {
        cout << temp->dato <<" ";
        temp = temp->siguiente ;
    } while (temp != Lista->siguiente);
} 

int main()
{
    Nodo * Lista = nullptr ;
    CargarLista(Lista) ;
    MostrarLista (Lista);
    return 0 ;
}