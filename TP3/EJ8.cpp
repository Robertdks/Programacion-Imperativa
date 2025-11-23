#include <iostream>
using namespace std ;

struct Nodo 
{
    int dato ;
    Nodo * siguiente ;
};
void InsertarNodo (Nodo * & cabeza , Nodo * Nuevo)
{
    if (cabeza == nullptr)
    {
        cabeza = Nuevo ;
    }
    else
    {
        Nodo * temp = cabeza ;
        while (temp->siguiente != nullptr)
        {
            temp = temp->siguiente ;
        }
        temp->siguiente = Nuevo ;
    }
}
void CargarLista(Nodo * & cabeza)
{
    int num ;
    cout <<"Ingrese un numero [0] para finalizar: " ;
    cin >> num ;
    while (num != 0)
    {
        Nodo * Nuevo = new Nodo();
        Nuevo->dato = num ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(cabeza,Nuevo) ;
        cout <<"Ingrese un numero [0] para finalizar: " ;
        cin >> num ;
    }
}
void MostrarLista(Nodo * Lista)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        cout << temp->dato << " " ;
        temp = temp->siguiente ;
    }
    cout << endl ;
}
Nodo * Verificar(Nodo * Lista, int num)
{
    Nodo * aux = Lista ;
    while (aux != nullptr)
    {
        if (aux->dato == num)
        {
            return  aux ;
        }
        aux = aux->siguiente ;
    }
    return nullptr ;
    
}
void ElimarOcurrencia(Nodo * & cabeza, int numero)
{
    if (Verificar(cabeza,numero) != nullptr)
    {
        Nodo * temp = cabeza ;
        Nodo * Eliminar ;
        while (temp != nullptr && temp->dato == numero)
        {
            Eliminar = temp ;
            temp = temp->siguiente;
            delete Eliminar ;
        }
        cabeza = temp ;
        if (cabeza == nullptr)
        {
            return ;
        }
        else
        {
            Nodo * Actual = cabeza->siguiente ;
            Nodo * Anterior = cabeza ;
            while (Actual != nullptr)
            {
                if (Actual->dato == numero)
                {
                    Anterior->siguiente = Actual->siguiente ;
                    delete Actual ;
                    Actual = Anterior->siguiente ;
                }
                else
                {
                    Anterior = Actual ;
                    Actual = Actual->siguiente ;
                }
            }
        }

    }
    else 
    {
        cout << "El numero " << numero << " no se encuentra en la lista. "<< endl ;
    }
        
}
void Menu (Nodo * & cabeza, int numero)
{

    int opcion ;
    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Cargar lista\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Eliminar ocurrencias de un numero\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CargarLista(cabeza);
            break;

        case 2:
            if (cabeza == nullptr)
                cout << "La lista está vacía.\n";
            else
                MostrarLista(cabeza);
            break;

        case 3:
            if (cabeza == nullptr)
            {
                cout << "La lista está vacía, no hay nada que eliminar.\n";
            }
            else
            {
                cout << "Ingrese el numero a eliminar: ";
                cin >> numero;
                ElimarOcurrencia(cabeza, numero);
            }
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
    Nodo * Lista =  nullptr ;
    int numero  = 0;
    Menu(Lista,numero) ;
    return 0 ;
}