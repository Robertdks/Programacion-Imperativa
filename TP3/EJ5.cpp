#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato ;
    Nodo *siguiente ;
};

void InsertarLista (Nodo *&lista)
{   
    Nodo *nuevo ;
    Nodo *ultimo  = nullptr;
    int num ;
    cout <<"Ingrese un numero [0] para finalizar: " ;
    cin >> num;
    while(num != 0)
    {   
        nuevo = new Nodo() ;
        nuevo->dato = num ;
        nuevo->siguiente = nullptr ;
        if (lista == nullptr)
        {
            lista = nuevo ; // Primer nodo
        }
        else
        {
            ultimo->siguiente = nuevo ; // Se enlaza al último
        }
        ultimo = nuevo ;
        cout << "Ingrese un numero: " ;
        cin >>num;
    }
}
void MostrarLista(Nodo* Lista)
{
    Nodo* actual = Lista ;
    cout << "\nLista enlazada: " ;
    while(actual != nullptr)
    {
        cout << actual->dato <<" -> ";
        actual=actual->siguiente ;
    }
    cout << "NULL\n"  ;
}
int main()
{

    Nodo * Lista = NULL;
    InsertarLista(Lista);
    MostrarLista(Lista);
    return 0 ;
}