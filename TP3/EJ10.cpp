#include <iostream>
#include <string>
using namespace std ;

struct Nodo 
{
    string dato ;
    Nodo * siguiente ;
};

string Minusculas (string texto)
{
    int longitud = texto.length();
    for (int i = 0 ; i < longitud ; i++)
    {
        texto[i] = tolower(texto[i]) ;
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
        while (temp->siguiente != nullptr)
        {
            temp = temp->siguiente ;
        }
        temp->siguiente = Nuevo ;
    }
}
void CargarLista(Nodo * & Lista)
{
    string aux ;
    cout <<"Ingrese un nombre [FIN] para finalizar: ";
    getline(cin>>ws,aux) ;
    aux = Minusculas (aux) ;
    while (aux != "fin")
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato = aux ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo (Lista,Nuevo) ;
        cout <<"Ingrese un nombre [FIN] para finalizar: ";
        getline(cin>>ws,aux) ;
        aux = Minusculas (aux) ;
    }
    cout << "Nombres ingresados con exito!!"<< endl ;
}
void MostrarLista(Nodo * Lista)
{
    if(Lista != nullptr)
    {
        Nodo * temp = Lista ;
        while (temp != nullptr)
        {
            cout << temp->dato << endl;
            temp = temp->siguiente ;
        }
    }
    else 
    {
        cout <<"La lista se encuentra vacia!"<< endl ;
    }
}
Nodo * Verificar(Nodo * Lista, string texto)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        if(temp->dato == Minusculas(texto))
        {
            return temp ;
        }
        temp = temp->siguiente;
    }
    return nullptr ;
}
void SepararRepetidos(Nodo * Lista , Nodo * & Repetidos)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        Nodo * aux  = temp->siguiente ;
        while (aux != nullptr)
        {
            if (temp->dato == aux->dato)
            {
                if (Verificar(Repetidos,temp->dato) == nullptr)
                {
                    Nodo * Nuevo = new Nodo ();
                    Nuevo->dato = temp->dato ;
                    Nuevo->siguiente = nullptr ;
                    InsertarNodo(Repetidos,Nuevo) ;
                }
                break ;
            }
            aux = aux->siguiente ;
            
        }
        temp = temp->siguiente ;
    }
}
void LlenarLista(Nodo * & Lista)
{
    string Nombres [6] = {"Juan","Jose","Robert","Santi","Robert","Juan"} ;

    for (int i = 0 ; i < 6 ; i++)
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato = Nombres[i];
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
    }
    cout << "Lista generada con exito!!" << endl ;
}
void Menu (Nodo * & Lista, Nodo * & Repetidos)
{
    int opcion;
    string nombre;

    do
    {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Cargar lista de nombres\n";
        cout << "2. Mostrar lista completa\n";
        cout << "3. Verificar si un nombre existe\n";
        cout << "4. Separar nombres repetidos en otra lista\n";
        cout << "5. Mostrar lista de repetidos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        cin.ignore(); // limpia buffer

        switch(opcion)
        {
            case 1:
                LlenarLista(Lista) ;
                break;

            case 2:
                cout << "\n--- Lista de nombres ---\n";
                MostrarLista(Lista);
                break;

            case 3:
                cout << "Ingrese un nombre a buscar: ";
                getline(cin, nombre);

                if(Verificar(Lista, nombre) != nullptr)
                    cout << "El nombre SI existe en la lista.\n";
                else
                    cout << "El nombre NO se encuentra.\n";
                break;

            case 4:
                SepararRepetidos(Lista, Repetidos);
                cout << "Repetidos separados correctamente.\n";
                break;

            case 5:
                cout << "\n--- Lista de repetidos ---\n";
                MostrarLista(Repetidos);
                break;

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } 
    while(opcion != 0);
}
int main ()
{
    Nodo * Lista = nullptr ;
    Nodo * Repetidos = nullptr ;
    Menu(Lista,Repetidos) ;
    return 0 ;
}