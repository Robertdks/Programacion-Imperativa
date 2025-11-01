#include <iostream>
#include <string>
using namespace std ;

struct Nodo 
{
    string dato ;
    Nodo * siguiente ;
};
string Mayuscula (string tex)
{
    int aux = tex.length () ;
    for(int i = 0;  i < aux ; i++)
    {
        tex[i] = toupper (tex[i]) ;
    }
    return tex ;
}
void InsertarLista (Nodo * & Lista)
{
    string aux ;
    cout << "Ingrese un nombre [x] para finalizar: ";
    getline(cin>>ws,aux);
    while(Mayuscula(aux) != "X")
    {
        Nodo * Nuevo = new Nodo() ;
        Nuevo->dato = aux ;
        Nuevo->siguiente = nullptr ;
        if (Lista == nullptr)
        {
            Lista = Nuevo ;
        }
        else
        {
            Nodo * temp = Lista ;
            while (temp->siguiente != nullptr)
            {
                temp = temp->siguiente ;
            }
            temp->siguiente = Nuevo ;
        }
        cout << "Ingrese un nombre [x] para finalizar: ";
        getline(cin>>ws,aux);

    }
}
void ImprimirLista(Nodo * Lista)
{
    Nodo * aux = Lista ;
    while(aux != nullptr)
    {
        cout << aux->dato << "->" ;
        aux = aux->siguiente ;
    }
    cout << "NUll" ;
}
bool BuscarNombre(Nodo * Lista, string dato)
{
    Nodo * aux = Lista ;
    while(aux != nullptr)
    {
        if (dato == aux->dato)
        {
            return true ;
        }
        aux = aux->siguiente ;
    }
    return false ;
}
bool EliminarNombre(Nodo * & Lista, string nombre)
{

}
string IngresarNombre(string nombre)
{
    cout <<"Ingrese el nombre para realizar el trabajo:  ";
    getline(cin>>ws,nombre) ;
    return nombre ;
}
void menu (Nodo *& Lista, string nombre)
{
    char opcion ;
    do
    { 
    cout << "================================"<< endl ;
    cout << "           BIENVENIDO           " << endl ;
    cout << "================================"<< endl ;
    cout <<"[A] - Ingresar Nombres a la Lista." << endl ;
    cout <<"[B] - Verificar si el nombre se encuentra en la Lista." << endl ;
    cout <<"[C] - Eliminar Nombre de la Lista." << endl ;
    cout <<"[D] - Imprimir Lista." << endl ;
    cout <<"[E] - Salir" << endl ;
    cout <<"Ingrese una opcion: " ;
    cin >> opcion ;
    system("clear");
    switch (toupper(opcion))
    {
    case    'A':
        InsertarLista(Lista) ;
        break;
    case    'B':
        if (BuscarNombre(Lista,IngresarNombre(nombre)))
        {
            cout << "El nombre ingresado si se encontro en la lista."<< endl;
        }
        else 
        {
            cout << "El nombre  ingresado no se encontro en la lista."<< endl ;
        }
        break;
    case    'C':
        EliminarNombre(Lista,IngresarNombre(nombre)) ;
        break;
    case    'D':
        ImprimirLista(Lista) ;
        break;
    case    'E':
        cout << "Gracias por el uso del programa."<< endl ;
        break;
    default:
        cout << "Error! Ingrese una opcion valida." << endl ;
        break;
    }
    }
    while(opcion != 'E');
     
}
int main ()
{
    Nodo * Lista = nullptr ;
    string nombre ;
    menu(Lista,nombre);
    return 0 ;
}