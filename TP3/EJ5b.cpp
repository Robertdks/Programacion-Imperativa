#include <iostream>
using namespace std ;

struct Nodo 
{
    int data ;
    Nodo * next ;
};

void InsertList(Nodo* & List )
{
    int aux ;
    cout << "Ingrese un numero [0] para finalizar: ";
    cin >> aux ;
    while(aux != 0)
    {
        Nodo * NewNodo = new Nodo ();
        NewNodo->data = aux ;
        NewNodo->next = nullptr ;
        if (List == nullptr)
        {
            List = NewNodo ;
        }
        else
        {
            Nodo * temp = List ; //usamos una var temp para evitar perdir la cabeza
            while (temp->next != nullptr)
            {
                temp = temp->next ;
            }
            temp->next = NewNodo ;
        }
        cout << "Ingrese un numero [0] para finalizar: ";
        cin >> aux ; 
    }
}
void ShowList(Nodo* List)
{
    Nodo * Aux = List ;
    while(Aux != nullptr)
    {
        cout << Aux->data << " -> " ;
        Aux = Aux->next ;
    }
    cout << "NULL" ;
}

int main ()
{
    Nodo * List = nullptr ;
    InsertList (List) ;
    ShowList (List) ;
    return 0 ;
}