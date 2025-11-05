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
string IngresarNombre(string nombre)
{
    cout <<"Ingrese el nombre para realizar el trabajo:  ";
    getline(cin>>ws,nombre) ;
    return nombre ;
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
    cout << "NUll" << endl;
}
void EliminarNodo(Nodo * & Lista,string nombre)
{
    Nodo * aux = Lista ;
    if (aux->dato == nombre)
    {
        Lista = Lista->siguiente ;
    }
    else
    {
        while(aux->siguiente != nullptr && aux->siguiente->dato != nombre)
        {
            aux = aux->siguiente ;
        }
        Nodo * temp = aux->siguiente ;
        aux->siguiente = aux->siguiente->siguiente ;
        delete temp ;
    }
}
Nodo * BuscarNombre(Nodo * Lista, string dato)
{
    Nodo * aux = Lista ;
    while(aux != nullptr && Mayuscula(aux->dato) != Mayuscula(dato))
    {
        aux = aux->siguiente ; 
    }
    return aux ;
}
void EliminarNombre(Nodo * & Lista)
{
    string nombre ;
    nombre = IngresarNombre (nombre) ;
    //Primero verifiquemos si el nombre se encuentra en la lista
    Nodo * temp = BuscarNombre(Lista,nombre) ;
    if(temp != nullptr) 
    {
        EliminarNodo(Lista,nombre);
        cout << "Nombre elimiando con exito!." << endl;
    }
    else
    {
        cout << "El nombre ingresado no se encuentra en la Lista." << endl;
    }

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
        nombre = IngresarNombre(nombre);
        if(BuscarNombre(Lista,nombre) != nullptr)
        {
            cout << "El nombre si se encuentra en la lista." << endl ;
        }
        else
        {
            cout << "El nombre no se encuentra en la lista." << endl ;
        }
        break;
    case    'C':
        EliminarNombre(Lista) ;
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
    while(toupper(opcion) != 'E');
     
}
int main ()
{
    Nodo * Lista = nullptr ;
    string nombre ;
    menu(Lista,nombre);
    return 0 ;
}