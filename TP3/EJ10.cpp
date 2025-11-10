#include <iostream>
#include <string>
using namespace std ;

struct Nodo
{
    string data ;
    Nodo * siguiente ;
};
string Minuscula(string texto)
{
    int longitud = texto.length();
    for (int i = 0;  i < longitud ; i++)
    {
        texto[i] = tolower (texto[i]) ;
    }
    return texto ;
}
void InsertarNodo(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Lista = Nuevo ;
    }
    else
    {
        Nodo * temp = Lista ;
        while(temp->siguiente != nullptr)
        {
            temp = temp->siguiente ;
        }
        temp->siguiente = Nuevo ;
    }
}
void CargarLista(Nodo * & Lista)
{
    string aux  ;
    cout <<"Ingrese una palabra [FIN] para finalizar: " ;
    getline(cin>>ws,aux) ;
    while (Minuscula(aux) != "fin")
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->data = aux ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese una palabra [FIN] para finalizar: ";
        getline(cin>>ws,aux);
    }
}
bool VerificarLista(Nodo * Lista)
{
    for (Nodo * i = Lista ; i != nullptr ; i = i->siguiente)
    {
        for(Nodo * j = i->siguiente ; j != nullptr ; j = j->siguiente)
        {
            if (i->data == j->data)
            {
                return true ;
            }
        }
    }
    return false ;
}
void SepararLista(Nodo * & Lista)
{
    //Primero verificamos si hay alguna palabra de la lista repetida
    if (VerificarLista(Lista))
    {
        
    }
}
int main()
{
    Nodo * Lista = nullptr ;
}