#include <iostream>
#include <string>
using namespace std ;

struct Nodo 
{
    string dato ;
    Nodo * Siguiente ;
};
string Mayuscula(string texto)
{
    int longitud = texto.length();
    for(int i= 0; i < longitud ; i++)
    {
        texto[i] = toupper(texto[i]) ;
    }
    return texto ;
}
void EnlazarNodo(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Lista = Nuevo ;
    }
    else
    {
        Nodo * temp = Lista ;
        while (temp->Siguiente != nullptr )
        {
            temp = temp->Siguiente ;
        }
        temp->Siguiente = Nuevo ;
    }
}
void CargarLista(Nodo * & Lista)
{
    string aux ;
    cout << "Ingrese un nombre [X] para finalizar: " ;
    getline(cin>>ws,aux) ;
    while (Mayuscula(aux) != "X")
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato = aux ;
        Nuevo->Siguiente = nullptr ;
        EnlazarNodo(Lista,Nuevo) ;
        cout << "Ingrese un nombre [X] para finalizar: " ;
        getline(cin>>ws,aux) ;
    }
}
Nodo * Verificar(Nodo * Lista, string nombre)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        if (Mayuscula(temp->dato) == Mayuscula(nombre))
        {
            return temp ;
        }
        temp = temp->Siguiente ;
    }
    return nullptr ;
}
void BuscarUsuario(Nodo * Lista)
{
    string Nombre ;
    cout << "Ingrese el nombre a buscar: ";
    getline(cin >> ws,Nombre) ;
    if (Verificar(Lista,Nombre))
    {
        cout << Nombre << " Si se encuentra en la lista. " << endl ;
    }
    else
    {
        cout << Nombre << " No se encontro en la lista." << endl ;
    }  
}
void EliminarNodo(Nodo * & Lista, string Nombre)
{
    Nodo * temp = Lista ;
    Nodo * Eliminar ;
    if (Mayuscula(temp->dato) == Mayuscula(Nombre))
    {
        Eliminar = temp ;
        Lista = temp->Siguiente ;
        delete Eliminar ;
        return ;
    }
    while (temp->Siguiente != nullptr && Mayuscula(temp->Siguiente->dato) != Mayuscula(Nombre))
    {
        temp = temp->Siguiente;
    }
    // Si no existe, aunque Verificar() diga que sí, evita un crash
    if (temp->Siguiente == nullptr)
    {
       return;
    }
    // Eliminar el nodo
    Eliminar = temp->Siguiente;
    temp->Siguiente = temp->Siguiente->Siguiente;
    delete Eliminar;
}
void EliminarUsuario(Nodo * & Lista)
{
    string Nombre ;
    cout <<"Ingrese el nombre a eliminar: ";
    getline(cin>>ws,Nombre);

    if (Verificar(Lista,Nombre) != nullptr)
    {
        EliminarNodo(Lista,Nombre) ;
        cout << Nombre << " a sido eliminado con exito! " << endl ;
    }
    else
    {
        cout <<"Error! " << Nombre << "No se encontro en la Lista, por favor verificar y volver a intentarlo. "<< endl ;
    }
}
void MostrarLista(Nodo * Lista)
{
    if(Lista != nullptr)
    {
    Nodo * temp = Lista ;
    cout <<"Lista de Usuarios" <<endl ;
    while (temp != nullptr)
    {
        cout << temp->dato <<"  " ;
        temp = temp->Siguiente ;
    }
    cout << endl ;
    }
    else
    {
        cout <<"La lista Se ecuentra vacia."<< endl ;
    }
}
void Menu (Nodo * & Lista)
{
    char opcion ;
    do
    {
        cout <<"======================================="<< endl ;
        cout <<"                    Menu               "<< endl ;
        cout <<"======================================="<< endl ;
        cout <<"[A] - Cargar Usuarios"<< endl ;
        cout <<"[B] - Verificiar Usuarios"<< endl ;
        cout <<"[C] - Mostrar Lista de usuarios"<< endl ;
        cout <<"[D] - Elimar un Usuario"<< endl ;
        cout <<"[E] - Salir del programa"<< endl ;
        cout <<"Ingrese una opcion .. "; 
        cin >> opcion ;
        opcion = toupper (opcion) ;
        switch (opcion)
        {
        case 'A':
            CargarLista(Lista);
            cout << "carga exitosa de usuarios ! " << endl ;
            break;
        case 'B':
            BuscarUsuario(Lista) ;
            break;
        case 'C':
            MostrarLista(Lista) ;
            break;
        case 'D':
            EliminarUsuario(Lista);
            break;
        case 'E':
            cout <<"Saliendo....."<< endl ;
            break;
        default:
            cout <<"Ingrese un valor valido !!"<< endl ;
            break;
        }
    } while (opcion != 'E');
    
}
int main ()
{
    Nodo * Lista = nullptr ;
    Menu(Lista) ;
    return 0 ;
}