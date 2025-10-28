#include <iostream>
using namespace std ;

struct Nodo
{
    int data ;
    Nodo * Next ;
};

void InsertList(Nodo * & List)
{
    int aux ;
    Nodo * NewNodo =  new Nodo() ;
    cout << "Ingrese un numero [0] para finalizar: " ;
    cin >> aux ;
    while(aux != 0)
    {
        
    }
}
void ShowList(Nodo * List)
{

}
int main()
{
    Nodo * List = nullptr ;
    InsertList(List) ;
    ShowList(List) ;
    return 0 ;
}