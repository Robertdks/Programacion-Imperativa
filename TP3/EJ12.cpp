#include <iostream>
#include <string>
using namespace std ;

struct Pruducto 
{
    int codigo ;
    string descripcion ;
    float precio ;
    int stock ;
} ;
struct Nodo
{
    Pruducto dato ;
    Nodo * siguiente ;
};

void InsertarNodo (Nodo * & Lista, Nodo * Nuevo)
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
void AgregarProducto (Nodo * & Lista )
{
    int codigo ;
    cout <<"Ingrese el codigo del producto [-1] para finalizar: ";
    cin >> codigo ;
    while (codigo != -1)
    {
        Nodo * Nuevo = new Nodo();
        Nuevo->dato.codigo = codigo ;
        Nuevo->siguiente = nullptr ;
        cout <<"Ingrese la descripcion del producto: " ;
        getline(cin>>ws,Nuevo->dato.descripcion) ;
        cout <<"Ingrese el precio del producto: " ;
        cin >>Nuevo->dato.precio ;
        cout <<"Ingrese la cantidad del producto: ";
        cin >> Nuevo->dato.stock ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese el codigo del producto [-1] para finalizar: ";
        cin >> codigo;
    }
}
Nodo * Verificar(Nodo * Lista, int codigo)
{
    while (Lista != nullptr)
    {
        if (Lista->dato.codigo == codigo)
        {
            return Lista ;
        }
        Lista = Lista->siguiente ;
    }
    return nullptr ;
}
void IncrementarPrecio(Nodo * & Lista, int porcentaje)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        temp->dato.precio += temp->dato.precio * (porcentaje/100) ;
        temp = temp->siguiente ;
    }
    cout <<"Precios Incrementados con exito!!" << endl ;
}
void IncrementarStock(Nodo * & Lista, int codigo, int stock)
{
    Nodo * temp = Verificar(Lista,codigo) ;
    if (temp != nullptr)
    {
        temp->dato.stock += stock ;
        cout <<"Stock actualizado!!" << endl ;
    }
    else
    {
        cout << "El producto no se encuentra en la lista!" << endl ;
    }
}
void ActualizarLista(Nodo * & Lista)
{
   Nodo * Eliminar ;
   while (Lista != nullptr && Lista->dato.stock == 0)
   {
    Eliminar = Lista ;
    Lista = Lista->siguiente ;
    delete Eliminar ;
   }
   if (Lista == nullptr)
   {
    return ;
   }
   Nodo * temp = Lista ;
   while (temp->siguiente != nullptr)
   {
        if (temp->siguiente->dato.stock == 0)
        {
            Eliminar = temp->siguiente ;
            temp->siguiente = temp->siguiente->siguiente ;
            delete Eliminar ;
        }
        else
        {
            temp = temp->siguiente ;
        }
   }
}
void MostrarLista(Nodo * Lista)
{
    if (Lista != nullptr)
    {
        Nodo * temp = Lista ;
        while (temp != nullptr)
        {
            cout << "==============================================" << endl ;
            cout <<"Numero de Codigo = "<< temp->dato.codigo << endl ;
            cout <<"Descripcion de Producto = " << temp->dato.descripcion << endl ;
            cout <<"Precio del producto = $" << temp->dato.precio << endl ;
            cout <<"Cantidad de Stock = " << temp->dato.stock << endl ;
            temp = temp->siguiente ;
        }
    }
    else
    {
        cout << "La lista se encuentra vacia!! "<< endl ;
    }
}
void Menu(Nodo*& Lista)
{
    int opcion;

    do
    {
        cout << "\n====== MENU PRINCIPAL ======" << endl;
        cout << "1. Agregar productos" << endl;
        cout << "2. Incrementar precio a todos" << endl;
        cout << "3. Incrementar stock de un producto" << endl;
        cout << "4. Eliminar productos con stock = 0" << endl;
        cout << "5. Buscar producto por codigo" << endl;
        cout << "6. Mostrar lista completa" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                AgregarProducto(Lista);
                break;

            case 2:
            {
                int porcentaje;
                cout << "Ingrese el porcentaje a incrementar: ";
                cin >> porcentaje;
                IncrementarPrecio(Lista, porcentaje);
                break;
            }

            case 3:
            {
                int codigo, stock;
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese la cantidad a incrementar: ";
                cin >> stock;
                IncrementarStock(Lista, codigo, stock);
                break;
            }

            case 4:
                ActualizarLista(Lista);
                cout << "Productos con stock 0 eliminados." << endl;
                break;

            case 5:
            {
                int codigo;
                cout << "Ingrese el codigo a buscar: ";
                cin >> codigo;
                Nodo* encontrado = Verificar(Lista, codigo);
                if (encontrado != nullptr)
                {
                    cout << "Producto encontrado!" << endl;
                    cout << "Descripcion: " << encontrado->dato.descripcion << endl;
                    cout << "Precio: " << encontrado->dato.precio << endl;
                    cout << "Stock: " << encontrado->dato.stock << endl;
                }
                else
                {
                    cout << "No existe un producto con ese codigo." << endl;
                }
                break;
            }

            case 6:
                MostrarLista(Lista);
                break;

            case 7:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
        }

    } while (opcion != 7);
}
int main ()
{
    Nodo * Lista  = nullptr ;
    Menu(Lista) ;
    return 0 ;
}