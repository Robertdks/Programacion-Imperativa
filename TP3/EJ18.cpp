#include <iostream>
#include <string>
using namespace std ;

struct Nodo 
{
    string dato ;
    Nodo * siguiente   ;
};
void InsertarNodo(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
    }
    else
    {
        Nuevo->siguiente = Lista->siguiente ;
        Lista->siguiente  = Nuevo ;
    }
    Lista = Nuevo ;
}
string ConvertirTexto(string t)
{
    int l = t.length();
    t[0] = toupper(t[0]) ;
    for (int n = 1; n < l ;n++)
    {
        t[n] = tolower(t[n]);
    }
    return t ;
}
void CargarLista(Nodo * & Lista)
{
    string titulo ;
    cout <<"Ingrese el Titulo [FIN] para finalizar: ";
    getline(cin>>ws,titulo) ;
    while (ConvertirTexto(titulo) != "Fin")
    {
        Nodo * Nuevo = new Nodo();
        Nuevo->dato = ConvertirTexto(titulo) ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese el Titulo [FIN] para finalizar: ";
        getline(cin>>ws,titulo) ;
    }
}
void MostraLista(Nodo * Lista)
{
    Nodo * temp = Lista->siguiente;
    do
    {
        cout << "Titulo: "<<temp->dato << endl ;
        temp = temp->siguiente ;
    } while (temp != Lista->siguiente);
    
}
Nodo * Verificar (Nodo * Lista, string titulo)
{
    Nodo * temp = Lista->siguiente ;
    do
    {
        if (temp->dato == ConvertirTexto(titulo))
        {
            return temp ;
        }
    } while (temp != Lista->siguiente );
    return nullptr ;
}
void BuscarLista(Nodo * Lista)
{
    string titulo ;
    cout << "Ingrese el titulo que desee buscar: " ;
    getline(cin>>ws,titulo) ;
    if(Verificar(Lista,titulo) != nullptr)
    {
        cout <<"El titulo se encuentra en la lista. "<< endl ;
    }
    else
    {
        cout <<"El titulo no se encuentra en la lista." << endl ;
    }
}
void Menu(Nodo *& Lista)
{
    int opcion;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Cargar lista\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Buscar titulo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CargarLista(Lista);
            break;

        case 2:
            if (Lista == nullptr)
                cout << "La lista esta vacia.\n";
            else
                MostraLista(Lista);
            break;

        case 3:
            if (Lista == nullptr)
                cout << "La lista esta vacia.\n";
            else
                BuscarLista(Lista);
            break;

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);
}
int main ()
{
    Nodo * Lista = nullptr ;
    Menu(Lista) ;
    return 0 ;
}