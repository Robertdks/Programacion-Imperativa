#include <iostream>
using namespace std ;

struct Nodo 
{
    int dato ;
    Nodo * siguiente ;
};
 void InsertarNodo(Nodo * & cabeza, Nodo * Nuevo)
 {
    if (cabeza == nullptr || cabeza->dato <= Nuevo->dato)
    {
        Nuevo->siguiente = cabeza ;
        cabeza = Nuevo ;
    }
    else
    {
        Nodo * temp = cabeza ;
        while (temp->siguiente != nullptr && temp->siguiente->dato >= Nuevo->dato)
        {
            temp = temp->siguiente ;
        }
        Nuevo->siguiente = temp->siguiente;
        temp->siguiente = Nuevo ;
    }
 }
 void CargarLista(Nodo * & cabeza)
 {
    int numero ;
    cout << "Ingrese un numero a insertar [0] para finalizar: ";
    cin >> numero;
    while (numero != 0)
    {
        Nodo* nuevo = new Nodo();
        nuevo->dato = numero;
        nuevo->siguiente = nullptr;
        InsertarNodo(cabeza, nuevo);
        cout << "Numero insertado correctamente.\n";
        cout << "Ingrese un numero a insertar [0] para finalizar: ";
        cin >> numero;
    }
    
 }
Nodo * Verificar(Nodo * Lista, int numero)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        if (temp->dato == numero)
        {
            return temp ;
        }
        temp = temp->siguiente ;
    }
    return nullptr ;
}
 void MostrarLista(Nodo * Lista)
 {
    if (Lista != nullptr)
    {
        Nodo * temp = Lista ;
        while (temp != nullptr)
        {
            cout << temp->dato << " " ;
            temp = temp->siguiente ;
        }
        cout << endl ;
    }
    else
    {
        cout << "La Lista se encuentra vacia!!" << endl ;
    }
 }
 void EliminarMultiplos(Nodo * & cabeza , int numero )
 {
    if (Verificar(cabeza,numero) != nullptr)
    {
        Nodo * temp = cabeza ;
        Nodo * Eliminar ;
        while (temp != nullptr && temp->dato % numero == 0)
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
                if (Actual->dato %  numero == 0)
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
void Menu(Nodo * & cabeza, int numero)
{
    int opcion ;
    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar numero (orden descendente)\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Eliminar multiplos de un numero\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CargarLista(cabeza) ;
        break;

        case 2:
            MostrarLista(cabeza);
            break;

        case 3:
            if (cabeza == nullptr)
            {
                cout << "La lista esta vacia, no hay nada que eliminar.\n";
            }
            else
            {
                cout << "Ingrese el numero para eliminar sus multiplos: ";
                cin >> numero;
                EliminarMultiplos(cabeza, numero);
            }
            break;

        case 0:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != 0);
}
int main ()
{
    Nodo * Lista = nullptr ;
    int numero = 0 ;
    Menu (Lista, numero) ;
    return 0 ;
}