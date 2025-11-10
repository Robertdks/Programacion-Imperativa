#include <iostream>
#include <string>
#include <limits>
using namespace std ;
struct Nodo
{
    int dato ;
    Nodo * siguiente ;
};
void Continuar()
{
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
    cin.get(); // espera a que el usuario presione Enter
    system("clear") ;
}
int CargarNumero()
{
    int numero ;
    cout <<"Ingrese un numero: " ;
    cin >> numero ;
    return numero ;
}
Nodo * VerificarLista(Nodo * Lista, int numero)
{
    Nodo * temp = Lista ;
    while (temp != nullptr && temp->dato != numero)
    {
        temp = temp->siguiente ;
    }
    return temp ;

}
void EliminarOcurrencias(Nodo * & Lista, int numero)
{   
    Nodo * Eliminar ;
    Nodo * aux = Lista ;
    while(aux != nullptr)
    {
        if (Lista->dato == numero)
        {
            Eliminar = Lista ;
            Lista = Lista->siguiente ;
            aux = aux->siguiente ;
            delete Eliminar ;   
        }
        else
        {
            if (aux->siguiente != nullptr && aux->siguiente->dato == numero)
            {
                Eliminar = aux->siguiente ;
                aux->siguiente = aux->siguiente->siguiente ;
                delete Eliminar ;
            }
            else
            {
                aux = aux->siguiente ;
            }
        }
    } 
    
}
void IngresarNodo(Nodo *& Lista, Nodo * Nuevo)
{
    if (Lista == nullptr)
    {
        Lista = Nuevo ;
        return ;
    }
    Nodo * temp = Lista ;
    while (temp->siguiente != nullptr)
    {
        temp = temp->siguiente ;
    }
    temp->siguiente = Nuevo ;
}
void CargarLista(Nodo *& Lista)
{
    int numero ;
    cout << "Ingrese un numero [-1] para finalizar: " ;
    cin >> numero ;
    while(numero != -1)
    {
        Nodo * Nuevo = new Nodo();
        Nuevo->dato = numero ;
        Nuevo->siguiente = nullptr ;
        IngresarNodo(Lista,Nuevo) ;
        cout << "Ingrese un numero [-1] para finalizar: " ;
        cin >> numero ;
    }
}
void MostrarLista(Nodo *& Lista)
{
    Nodo * aux = Lista ;
    while (aux != nullptr)
    {
        cout << aux->dato << " " ;
        aux = aux->siguiente ;
    }
    cout << "NULL" << endl ;
}
void menu (Nodo * & Lista)
{
    char opcion ;
    int numero ;
    do{
    cout <<"==========================================="<< endl ;
    cout <<"                    MENU                  "<< endl ;
    cout <<"==========================================="<< endl ;
    cout <<"[A] Ingresar numeros a la lista."<< endl ;
    cout <<"[B] Eliminar ocurrencias de la lista"<< endl ;
    cout <<"[C] Mostrar Lista" << endl ;
    cout <<"[D] Salir "<< endl ;
    cout <<"===========================================" << endl ;
    cout <<"Ingrese la opcion .." ;
    cin >> opcion ;
    system("clear") ;
        switch (toupper(opcion))
        {
        case 'A':
            CargarLista(Lista) ;
            cout << "Lista cargado con exito." << endl ;
            Continuar() ;
            break;
        case 'B':
            numero = CargarNumero();
            if(VerificarLista(Lista,numero))
            {
                EliminarOcurrencias(Lista,numero) ;
                cout << "Ocurrencia de " << numero <<" eliminado con exito. "<< endl ;
            }
            else
            {
                cout <<"El numero "<< numero << " no se encuentra en la lista." << endl ;
            }
            Continuar();
            
            break;
        case 'C': 
            cout << "Numeros de la lista:" << endl ;
            MostrarLista(Lista) ;
            Continuar() ;
            break;
        case 'D':
            cout << "Saliendo ..........."<< endl ;
            break;
        default:
            cout <<"Error ingrese una opcion valido!" ;
            Continuar() ;
            break;
        }
    }
    while(toupper(opcion) != 'D') ;
}
int main ()
{
    Nodo * Lista = nullptr ;
    menu(Lista);
    return 0;
}