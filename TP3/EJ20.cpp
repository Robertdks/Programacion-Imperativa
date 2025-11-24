#include <iostream>
#include <string>

using namespace std ;

struct Proceso
{
    int pid ;
    string usuario ;
    int fecha [3] ;
};
struct Nodo
{
    Proceso dato ;
    Nodo * siguiente ;
};
string Mayuscula(string texto)
{
    int longtitud = texto.length ();
    for (int i = 0; i < longtitud ; i++)
    {
        texto[i] = toupper(texto[i]);
    }
    return texto ;
}
void InsertarPrincipio(Nodo * & Lista, Nodo * Nuevo)
{
    if(Lista == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
        Lista = Nuevo;
    }
    else
    {
        Nuevo->siguiente = Lista->siguiente ;
        Lista->siguiente = Nuevo;
    }
}
void   CargaFecha(int a [])
{
    cout <<"Ingrese la fecha [DD/MM/AA] " << endl ;
    string fecha [3] = {"Dia","Mes","Año"} ;
    for (int i = 0; i <3 ; i++)
    {
        cout << fecha[i] << ": " ;
        cin >>  a[i] ;
    }
}
Nodo * CargaDatos(int pid)
{
    Nodo * Nuevo = new Nodo ();
    Nuevo->dato.pid = pid;
    CargaFecha(Nuevo->dato.fecha)  ;
    cout << "Ingrese el Nombre de usuario: " ;
    getline(cin>>ws,Nuevo->dato.usuario) ;
    return Nuevo ;
}
void CargarLista(Nodo * & Lista)
{
    int num ;
    cout <<"Ingrese el numero de proceso ";
    cin >> num ;
    while(num != 0)
    {
        InsertarPrincipio(Lista,CargaDatos(num)) ;
        cout <<"Ingrese el numero de proceso ";
        cin >> num ;
    }
}
Nodo * VerificarPid(Nodo * Lista, int pid)
{
    Nodo * temp = Lista->siguiente ;
    do
    {
        if(temp->dato.pid == pid)
        {
            return temp ;
        }
        temp = temp->siguiente ;
    } while (temp != Lista->siguiente);
    return nullptr ;
}
void BuscarProceso(Nodo * Lista)
{
    int num ;
    cout <<"Ingrese el  numero de proceso: " ;
    cin >> num ;
    if(VerificarPid(Lista,num) != nullptr)
    {
        cout <<"El proceso se encuentra en la lista!! "<<endl ;
    }
    else
    {
        cout <<"El proceso no se encontro en la lista!! "<<endl;
    }
}
void EliminarNodo(Nodo * & Lista, Nodo * Anterior)
{
    Nodo* Eliminar = Anterior->siguiente;

    // Caso: único nodo
    if (Eliminar == Lista && Eliminar->siguiente == Lista)
    {
        delete Eliminar;
        Lista = nullptr;
        return;
    }

    // Caso: eliminar primer nodo
    if (Eliminar == Lista->siguiente)
    {
        Lista->siguiente = Eliminar->siguiente;
    }

    // Caso: eliminar último nodo
    if (Eliminar == Lista)
    {
        Lista = Anterior;
    }

    // Caso general
    Anterior->siguiente = Eliminar->siguiente;

    delete Eliminar;
}

void FinalizarProceso(Nodo * & Lista)
{
    int num;
    cout << "Ingrese el numero de proceso que desea Finalizar: ";
    cin >> num;

    // Para eliminar necesito encontrar el nodo anterior
    Nodo * anterior = Lista;

    if (Lista == nullptr)
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Nodo * temp = Lista->siguiente;

    do
    {
        if (temp->dato.pid == num)
        {
            EliminarNodo(Lista, anterior);
            cout << "Proceso eliminado con exito!!" << endl;
            return;
        }

        anterior = temp;
        temp = temp->siguiente;

    } while (temp != Lista->siguiente);

    cout << "El proceso no se encontro en la lista!" << endl;
}
void ImprimirFecha(int a[])
{
    for (int i = 0; i < 3 ; i ++)
    {
        cout << a[i] ;
        if(i < 2)
        {
            cout <<"/" ;
        }
    }
}
void MostrarLista(Nodo * Lista)
{
    if (Lista == nullptr)
    {
        cout <<"La Lista se encuentra vacia! "<< endl ;
        return ;
    }
    
    Nodo * temp = Lista->siguiente ;
    do
    {
        cout <<"Proceso numero : " << temp->dato.pid << endl ;
        cout <<"Fecha de Inicio: " ;
        ImprimirFecha(Lista->dato.fecha) ;
        cout <<"\nUsuario: "<< temp->dato.usuario << endl ;
        cout <<"--------------------------------------------------"<< endl ;
        temp = temp->siguiente ;
    } while (temp != Lista->siguiente);
    
}
void Menu(Nodo * & Lista)
{
    int opcion;

    do
    {
        cout << "\n=========== MENU DE PROCESOS ===========\n";
        cout << "1. Cargar lista de procesos\n";
        cout << "2. Buscar proceso por PID\n";
        cout << "3. Finalizar proceso (Eliminar)\n";
        cout << "4. Mostrar lista de procesos\n";
        cout << "5. Salir\n";
        cout << "========================================\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                CargarLista(Lista);
                break;

            case 2:
                BuscarProceso(Lista);
                break;

            case 3:
                FinalizarProceso(Lista);
                break;

            case 4:
                if (Lista == nullptr)
                    cout << "La lista esta vacia.\n";
                else
                    MostrarLista(Lista);
                break;

            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida, intente nuevamente.\n";
        }
    }while(opcion != 5);
}
int main()
{
    Nodo * Lista = nullptr;
    Menu(Lista);
    return 0;
}
