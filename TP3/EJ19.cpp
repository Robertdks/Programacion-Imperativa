#include <iostream>
using namespace std ;

struct Nodo 
{
    string dato  ;
    Nodo * siguiente ;
};

void InsertarNodo(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
        Lista = Nuevo ;
    }
    else
    {
        Nuevo->siguiente = Lista->siguiente ;
        Lista->siguiente = Nuevo ;
    }
}
string Mayuscula(string texto)
{
    int longitud = texto.length() ;
    for(int i = 0; i < longitud ; i++)
    {
        texto[i] = toupper(texto[i]);
    }
    return texto ;
}
void VerificarCuit(string & cuit)
{
    int longitud = cuit.length() ;
    while (longitud != 11)
    {
        cout << "Error, Intente Nuevamente!!"<< endl ;
        cout <<"Ingrese el CUIT: " ;
        cin >> cuit ;
        longitud = cuit.length() ;
    }
    cout <<"CUIT agregado con exito!!"<< endl ;
}
void CargarLista(Nodo * & Lista)
{
    string cuit ;
    cout <<"Ingrese el CUIT [FIN] para finalizar: " ;
    cin >> cuit ;
    while (Mayuscula(cuit) != "FIN")
    {
        Nodo * Nuevo = new Nodo () ;
        VerificarCuit(cuit) ;
        Nuevo->dato = cuit ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese el CUIT [FIN] para finalizar: " ;
        cin >> cuit ;
    }
}
Nodo * BuscarCuit(Nodo * Lista, string cuit)
{
    Nodo * temp = Lista->siguiente ;
    do
    {
        if (cuit == temp->dato)
        {
            return temp ;
        }
        temp = temp->siguiente ;
    } while (temp != Lista->siguiente);
    return nullptr ;
}
void EliminarNodo(Nodo * & Lista , string cuit )
{
    Nodo* temp = Lista->siguiente; // primer nodo
    Nodo* anterior = Lista;

    // Caso: un solo nodo
    if (Lista == Lista->siguiente && Lista->dato == cuit)
    {
        delete Lista;
        Lista = nullptr;
        return;
    }

    // Caso: el primer nodo es el que hay que eliminar
    if (temp->dato == cuit)
    {
        anterior->siguiente = temp->siguiente;  // último apunta al 2°
        delete temp;
        return;
    }

    // Buscar el nodo a eliminar
    do
    {
        anterior = temp;
        temp = temp->siguiente;

    } while (temp != Lista->siguiente && temp->dato != cuit);

    // Si no se encontró
    if (temp->dato != cuit) return;

    // Eliminar nodo intermedio o final
    anterior->siguiente = temp->siguiente;

    // Si se elimina el último nodo, actualizo Lista
    if (temp == Lista)
        Lista = anterior;

    delete temp;
}

void EliminarCuit(Nodo * & Lista)
{
    string cuit ;
    cout <<"Ingrese el CUIT a eliminar: ";
    cin >> cuit ;
    if (BuscarCuit(Lista,cuit) != nullptr)
    {
        EliminarNodo(Lista,cuit);
        cout <<"CUIT eliminado con exito!!"<< endl ;
    }
    else
    {
        cout <<"El CUIT ingresado no se encuentra en la lista!!" << endl ;
    }
}
void MostrarLista(Nodo * Lista)
{
    int longitud = 0;
    int n  = 1;
    if(Lista != nullptr)
    {
        Nodo * temp = Lista->siguiente ;
        do
        {
            longitud = temp->dato.length();
            cout << "\nCUIT "<< n << ": "  ;
            for(int i = 0 ; i < longitud; i++)
            {
                cout << temp->dato[i] ;
                if (i == 1)
                {
                    cout << "-" ;
                }
                if (i == 9)
                {
                    cout <<"-";
                }
            }
            n++ ;
            temp = temp->siguiente ;
        } while (temp != Lista->siguiente);
    }
    else
    {
        cout <<"La lista se encuentra vacia!"<< endl ;
    }
}
void Menu(Nodo *& Lista)
{
    int opcion;

    do
    {
        cout << "\n========= MENU CUIT =========\n";
        cout << "1. Cargar lista de CUIT\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Buscar CUIT\n";
        cout << "4. Eliminar CUIT\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CargarLista(Lista);
            break;

        case 2:
            MostrarLista(Lista);
            break;

        case 3:
        {
            string cuit;
            cout << "Ingrese el CUIT a buscar: ";
            cin >> cuit;

            if (BuscarCuit(Lista, cuit) != nullptr)
                cout << "El CUIT se encuentra en la lista.\n";
            else
                cout << "El CUIT NO se encuentra en la lista.\n";

            break;
        }

        case 4:
            if (Lista == nullptr)
                cout << "No hay CUIT cargados.\n";
            else
                EliminarCuit(Lista);
            break;

        case 0:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida, intente nuevamente.\n";
        }

    } while (opcion != 0);
}
int main()
{
    Nodo * Lista = nullptr ;
    Menu(Lista) ;

    return 0 ;
}