#include <iostream>
using namespace std ;

struct Nodo
{
    int data ;
    Nodo * Next ;
};

void InsertList(Nodo * & List)
{
    int num ;
    cout << "Ingrese un numero [0] para finalizar: ";
    cin >> num ;
    while (num != 0)
    {
        Nodo * NewList = new Nodo () ;
        NewList->data = num ;
        NewList->Next = nullptr ;
        if ( List == nullptr || num < List->data)
        {
            NewList->Next = List ;
            List = NewList ;
        }
        else
        {
            Nodo * aux = List ;
            while(aux->Next != nullptr && aux->Next->data > num)
            {
                aux = aux->Next ;
            }
            NewList->Next = aux->Next ;
            aux->Next = NewList ;
        }
        cout << "Ingrese un numero [0] para finalizar: ";
        cin >> num ;
    }
}
void ShowList(Nodo * List)
{
    Nodo * aux = List ;
    while(aux != nullptr)
    {
        cout << aux->data << "->" ;
        aux = aux->Next ; 
    }
    cout << "NULL" ;
}
int main()
{
    Nodo * List = nullptr ;
    InsertList(List) ;
    ShowList(List) ;
    return 0 ;
}