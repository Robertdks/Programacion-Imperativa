// 5b
#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int data ; 
    Nodo * next ; // Puntero al siguiente nodo
};
void InsertList(Nodo* &list, int data)
{
    cout << "Ingrese un numero [0] para finalizar: " ;
    cin >> data ;
    while(data != 0)
    {
        Nodo * NewNodo = new Nodo() ;
        NewNodo->data = data ;
        NewNodo->next = list; // Enlaza al inicio
        list = NewNodo ;    // Ahora la lista comienza en el nuevo nodo
        cout << "Ingrese un numero [0] para finalizar: " ;
        cin >> data ;
    }
}
void ShowList(Nodo* List)
{
    Nodo * Aux = List ;
    while (Aux->next != nullptr)
    {
        cout << Aux->data << " -> " ;
        Aux = Aux->next ;
    }
    cout << "NULL";
}
int main()
{
    Nodo *list = nullptr;
    int data = 0;
    InsertList(list,data);
    ShowList(list);
    return 0 ;
}
