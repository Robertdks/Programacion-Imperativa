#include <iostream>
#include <string>
using namespace std;

struct Dato
{
    string palabra ;
    int posición = 0 ;
};

struct Nodo 
{
    Dato dato ;
    Nodo * Siguiente ;
} ;
string Mayuscula(string n)
{
    int l = n.length();
    for(int i = 0; i < l; i++)
    {
        n[i] = toupper(n[i]) ;
    }
    return n ;
}
void InsertarNodo(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Nuevo->Siguiente = Nuevo ;
    }
    else
    {
        Nuevo->Siguiente = Lista->Siguiente ;
        Lista->Siguiente = Nuevo ;
    }
    Lista = Nuevo ;
}
void CargarLista(Nodo *& Lista)
{
    string aux ;
    int pos = 1 ;
    cout <<"Ingrese un nombre [FIN] para finalizar: " ;
    cin >> aux ;
    while (Mayuscula(aux) != "FIN")
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato.palabra = aux ;
        Nuevo->dato.posición = pos ;
        pos ++ ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese un nombre [FIN] para finalizar: " ;
        cin >> aux ;
    }
}
Nodo * BuscarPosicion (Nodo * & Lista, int poscion )
{
    Nodo * temp = Lista->Siguiente ;
    do
    {
        if (temp->dato.posición == poscion)
        {
            return temp ;
        }
        temp = temp->Siguiente ;
    } while (temp != Lista->Siguiente);
    return nullptr ;
}
void InsertarDespues(Nodo * & Lista)
{
    string texto ;
    cout << "Ingrese la palabra a Insertar: ";
    getline(cin>>ws,texto) ;
    Nodo * Nuevo = new Nodo () ;
    Nuevo->dato.palabra = texto ;
    InsertarNodo (Lista,Nuevo) ;
    cout <<"Palabra agregada con exito!!" << endl;
}
void MostrarLista(Nodo * Lista)
{
    if(Lista != nullptr)
    {
        Nodo * temp = Lista->Siguiente ;
        do
        {
            cout << temp->dato.palabra  <<" "  ;
            temp = temp->Siguiente ;
        } while (temp != Lista->Siguiente);
    }
    else
    {
        cout <<"La lista se encuentra vacia !!" << endl ;
    }
}
void Menu(Nodo * & Lista)
{
       int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Cargar lista\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Buscar por posicion\n";
        cout << "4. Insertar palabra al final\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            CargarLista(Lista);
            break;

        case 2:
            MostrarLista(Lista);
            break;

        case 3: {
            int pos;
            cout << "Ingrese la posicion a buscar: ";
            cin >> pos;

            Nodo* encontrado = BuscarPosicion(Lista, pos);
            if (encontrado != nullptr)
                cout << "Encontrado: " << encontrado->dato.palabra << endl;
            else
                cout << "No existe esa posicion." << endl;
            break;
        }

        case 4:
            InsertarDespues(Lista);
            break;

        case 0:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida!" << endl;
        }

    } while (opcion != 0);
}
int main()
{
    Nodo * Lista = nullptr ;

    Menu(Lista) ;

    return 0 ;

}