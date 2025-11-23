#include <iostream>
#include <string>
using namespace std ;
struct Venta
{
    int codigo ;
    int cantidad ;
};
struct Nodo
{
    Venta dato ;
    Nodo * siguiente ;
};
void InsertarNodo(Nodo * & Lista , Nodo * Nuevo)
{
    if (Lista == nullptr || Lista->dato.codigo > Nuevo->dato.codigo)
    {
        Nuevo->siguiente = Lista ;
        Lista = Nuevo ;
        return ;
    }
    Nodo * temp = Lista ;
    while (temp->siguiente != nullptr && temp->siguiente->dato.codigo < Nuevo->dato.codigo)
    {
        temp = temp->siguiente ;
    }
    Nuevo->siguiente = temp->siguiente ;
    temp->siguiente = Nuevo ;
}
void RegistrarVenta(Nodo * & Lista)
{
    int num ;
    cout <<"Ingrese el codigo del producto [0] para finalizar: " ;
    cin >> num ;
    while (num != 0)
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato.codigo = num ;
        cout << "Ingrese la cantidad del producto: "  ;
        cin >> Nuevo->dato.cantidad ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese el codigo del producto [0] para finalizar: " ;
        cin >> num ;
    }
    cout << "Ventas Realizadas con Exito!!" << endl ;
}
void UnificarLista(Nodo * & Lista, Nodo * & Sucursal1, Nodo * & Sucursal2 )
{
    Nodo * Eliminar  ;   
    while (Sucursal1 != nullptr && Sucursal2 != nullptr)
    {
        if (Sucursal1->dato.codigo >= Sucursal2->dato.codigo)
        {
            Nodo * Nuevo = new Nodo ();
            Nuevo->dato = Sucursal2->dato ;
            Nuevo->siguiente = nullptr ;
            InsertarNodo(Lista,Nuevo) ;
            Eliminar = Sucursal2 ;
            Sucursal2 = Sucursal2->siguiente ;
            delete Eliminar ;
        }
        else
        {
            Nodo * Nuevo1 = new Nodo ();
            Nuevo1->dato = Sucursal1->dato ;
            Nuevo1->siguiente = nullptr ;
            InsertarNodo(Lista,Nuevo1) ;
            Eliminar = Sucursal1 ;
            Sucursal1 = Sucursal1->siguiente ;
            delete Eliminar ;
        }
    }
    // agregamos los restos de la lista sobrante, en caso de que queden restos que tenga algun valor sobrante

    while (Sucursal1 != nullptr)
    {
        Nodo * Nuevo = new  Nodo ;
        Nuevo->dato = Sucursal1->dato ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        Eliminar = Sucursal1 ;
        Sucursal1 = Sucursal1->siguiente ;
        delete Eliminar ;
    }
    // Verificamos la siguiente lista, por si quedo con algun valor 
    while (Sucursal2 != nullptr)
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato = Sucursal2->dato ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        Eliminar = Sucursal2 ;
        Sucursal2 = Sucursal2->siguiente ;
    }
}
void MostrarLista(Nodo * Lista)
{
    if (Lista != nullptr)
    {
        Nodo * temp = Lista ;
        while ( temp != nullptr)
        {
            cout << "Codigo de producto: " << temp->dato.codigo << endl ;
            cout << "Cantidad de ventas: "<< temp->dato.cantidad << endl ;
            cout << "------------------------------" << endl ;
            temp = temp->siguiente ;    
        }
    }
    else
    {
        cout <<"La lista se encuentra vacia!!" << endl ;
    }
}
void Menu(Nodo *&Sucursal1, Nodo *&Sucursal2, Nodo *&ListaFinal)
{
    int opcion;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1) Registrar ventas Sucursal 1\n";
        cout << "2) Registrar ventas Sucursal 2\n";
        cout << "3) Unificar listas\n";
        cout << "4) Mostrar lista final unificada\n";
        cout << "5) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                cout << "\n--- REGISTRAR SUCURSAL 1 ---\n";
                RegistrarVenta(Sucursal1);
                break;

            case 2:
                cout << "\n--- REGISTRAR SUCURSAL 2 ---\n";
                RegistrarVenta(Sucursal2);
                break;

            case 3:
                cout << "\n--- UNIFICANDO LISTAS ---\n";
                UnificarLista(ListaFinal, Sucursal1, Sucursal2);
                cout << "Listas unificadas con exito!\n";
                break;

            case 4:
                cout << "\n--- LISTA FINAL ---\n";
                MostrarLista(ListaFinal);
                break;

            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 5);
}
int main()
{
    Nodo *Sucursal1 = nullptr;
    Nodo *Sucursal2 = nullptr;
    Nodo *ListaFinal = nullptr;

    Menu(Sucursal1, Sucursal2, ListaFinal);

    return 0;
}
