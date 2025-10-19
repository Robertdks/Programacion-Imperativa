#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int data ; 
    Nodo * head ;
};
void InsertList(Nodo* &list, int data)
{
    Nodo * NewList = new Nodo ;
    list->data = data;
    NewList->head = list ;
    list = NewList;
    cout <<"Ingrese un numero: ";
    cin >> list->data ;
}
int main()
{
    Nodo *list = nullptr;
    list->data = 5;
    int data = 0;
    InsertList(list,data);
    return 0 ;
}