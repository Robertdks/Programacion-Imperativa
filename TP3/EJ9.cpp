#include <iostream>
#include <string>
#include <limits>
using namespace std ;

struct Nodo 
{
    int dato ;
    Nodo * siguiente ;
} ;
void Continuar() // Limpia la terminal y espera a que el usuario continue con la ejecución, mejora la interaccion entre el usuario y el programa
{
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
    cin.get(); // espera a que el usuario presione Enter
    system("clear") ;
}
int IngresarNumero()
{
    int numero ;
    cout <<"Ingrese un numero: ";
    cin >> numero ;
    return numero ;
}
bool  VerificarNumero(Nodo * Lista, int numero)
{
    Nodo * temp = Lista ;
    while (temp != nullptr && temp->dato != numero)
    {
        if (temp->dato % numero == 0)
        {
            return true ;
        }
        temp = temp->siguiente ;
    }
    return false ;
} 
void InsertarNodo(Nodo *& Lista, Nodo * Nuevo) //Se encarga de hacer el enlace en la posición correcta
{
    if(Lista == nullptr || Nuevo->dato > Lista->dato)
    {
        Nuevo->siguiente = Lista ;
        Lista = Nuevo ;
    }
    else
    {
        Nodo * temp = Lista ;
        while (temp->siguiente != nullptr && temp->siguiente->dato > Nuevo->dato)
        {
            temp = temp->siguiente ;
        }
        Nuevo->siguiente = temp->siguiente ;
        temp->siguiente = Nuevo ;
    }
}
void CargarLista(Nodo *& Lista) //Se encarga de crear el nuevo nodo y llenar la lista
{
    int aux ;
    while (aux != 0)
    {
        cout <<"Ingrese un numero [0] para finalizar: ";
        cin >> aux ;
        Nodo * Nuevo = new Nodo();
        Nuevo->dato = aux ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
    }
    
}
void EliminarOcurrencias(Nodo *& Lista, int numero) // Esta función se va a encargar de elimar las ocurrencias de la lista
{
    if (VerificarNumero(Lista,numero)) // verificamos para que el elemento si se encuentre en la lista
    {
        Nodo * Eliminar ;
        Nodo * aux = Lista ;
        while(aux != nullptr)
        {
            if (Lista->dato % numero == 0)
        {
            Eliminar = Lista ;
            Lista = Lista->siguiente ;
            aux = aux->siguiente ;
            delete Eliminar ;   
        }
        else
        {
            if (aux->siguiente != nullptr && aux->siguiente->dato % numero == 0) 
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
    else
    {
        cout << "No se encontraron multiplos del numero ingresado. " << endl ;
    }
}
void MostrarLista(Nodo * Lista) //Imprime la Lista
{
    Nodo * aux = Lista ;
    while(aux != nullptr)
    {
        cout <<aux->dato <<" " ;
        aux = aux->siguiente ;
    }
    cout << "Null" ;
}
void Menu(Nodo *& Lista)
{
    int numero ;
    char opcion ;
    do
    {
        cout <<"====================================="<< endl ;
        cout <<"                  MENU               "<< endl ;
        cout <<"====================================="<< endl ;
        cout <<"[A] Ingresar numeros a la Lista."<< endl ;
        cout <<"[B] Mostrar Lista."<< endl ;
        cout <<"[C] Eliminar ocurrencia de los multiplos de un numero."<< endl ;
        cout <<"[D] Salir"<< endl;
        cout << "Ingrese la opcion..." ;
        cin >> opcion ;
        system("clear");
        switch (toupper(opcion))
        {
        case 'A':
            CargarLista(Lista);
            Continuar();
            break;
        case 'B':
            MostrarLista(Lista);
            Continuar();
            break;
        case 'C':   
            numero = IngresarNumero();
            EliminarOcurrencias(Lista,numero) ;
            break;
        case 'D':
            cout << "Saliendo....." ;
            break;
        default:
            cout << "Error! Ingrese una opcion valida!" << endl ;
            Continuar();
            break;
        }
    } while ('D' != toupper(opcion));

    
}
int main()
{
    Nodo * Lista = nullptr ;
    Menu(Lista) ;
    return 0 ;
}