#include <iostream>
#include <string>
#include <limits>
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
void Continuar()
{
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");
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
void SepararLista(Nodo *  Lista, Nodo * & Repetidos)
{
 Nodo* i = Lista;

    while (i != nullptr)
    {
        Nodo* j = i->siguiente;
        bool repetido = false;

        // Verificamos si el valor de i->data aparece más adelante
        while (j != nullptr)
        {
            if (i->data == j->data)
            {
                repetido = true;
                break;
            }
            j = j->siguiente;
        }

        // Si encontramos repetido, verificamos que no esté ya en la lista Repetidos
        if (repetido)
        {
            bool ya_agregado = false;
            Nodo* k = Repetidos;
            while (k != nullptr)
            {
                if (k->data == i->data)
                {
                    ya_agregado = true;
                    break;
                }
                k = k->siguiente;
            }

            // Si no está, lo agregamos
            if (!ya_agregado)
            {
                Nodo* nuevo = new Nodo();
                nuevo->data = i->data;
                nuevo->siguiente = Repetidos;
                Repetidos = nuevo;
            }
        }

        i = i->siguiente;
    }
}
void MostrarLista(Nodo * Lista)
{
    if (Lista == nullptr)
    {
        cout <<"[Lista vacias]" << endl ;
        return ;
    }
    Nodo * aux = Lista ;
    while(aux != nullptr)
    {
        cout << aux->data << " -> " ; 
        aux = aux->siguiente ;
    }
    cout << "Null." << endl ;
}
void Menu()
{
    Nodo* Lista = nullptr;
    Nodo* Repetidos = nullptr;
    char opcion;

    do
    {
        cout << "\n=====================================\n";
        cout << "                 MENU                 \n";
        cout << "=====================================\n";
        cout << "[A] Cargar palabras en la lista\n";
        cout << "[B] Mostrar lista principal\n";
        cout << "[C] Verificar si hay repetidos\n";
        cout << "[D] Separar los repetidos en nueva lista\n";
        cout << "[E] Mostrar lista de repetidos\n";
        cout << "[F] Salir\n";
        cout << "-------------------------------------\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        opcion = toupper(opcion);
        system("clear"); // Limpia la terminal (en Windows usar "cls")

        switch (opcion)
        {
        case 'A':
            CargarLista(Lista);
            break;

        case 'B':
            cout << "Lista principal:\n";
            MostrarLista(Lista);
            break;

        case 'C':
            if (VerificarLista(Lista))
                cout << "Hay palabras repetidas en la lista.\n";
            else
                cout << "No hay palabras repetidas.\n";
            break;

        case 'D':
            if (VerificarLista(Lista))
            {
                SepararLista(Lista, Repetidos);
                cout << "Se han separado las palabras repetidas.\n";
            }
            else
            {
                cout << "No hay palabras repetidas que separar.\n";
            }
            break;

        case 'E':
            cout << "Lista de palabras repetidas:\n";
            MostrarLista(Repetidos);
            break;

        case 'F':
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }

        if (opcion != 'F')
        {
            Continuar();
        }

    } while (opcion != 'F');
}
int main()
{
    Menu();
}