#include <iostream>
#include <string>
#include <limits>
using namespace std ;

struct Nodo 
{
    int dato ;
    Nodo * siguiente ;
};
void Continuar() // Limpia la terminal y espera a que el usuario continue con la ejecución, mejora la interaccion entre el usuario y el programa
{
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
    cin.get(); // espera a que el usuario presione Enter
    system("clear") ;
}
void InsertarFinal(Nodo * & Fin , Nodo * Nuevo)
{
    if (Fin == nullptr)
    {
        Nuevo->siguiente = Nuevo ;
        Fin = Nuevo ;
    }
    else
    {
        Nuevo->siguiente = Fin->siguiente ;
        Fin->siguiente = Nuevo ;
    }
    Fin = Nuevo ;
}
void CargarLista(Nodo * & Fin)
{
    int aux ;
    cout <<"Ingrese un numero [0] para finalizar: ";
    cin >> aux ;
    while (aux != 0)
    {
        Nodo * Nuevo = new Nodo();
        Nuevo->dato= aux ;
        Nuevo->siguiente = nullptr ;;
        InsertarFinal(Fin, Nuevo) ;
        cout <<"Ingrese un numero [0] para finalizar: ";
        cin >> aux ;
    }
}
void MostrarLista(Nodo * Fin)
{
   if (Fin != nullptr)
    {
        Nodo * aux = Fin->siguiente ;
        do
        {
            cout << aux->dato << " " ;
            aux = aux->siguiente ;
        }
        while (aux != Fin->siguiente);
    }
    else
    {
        cout << "La lista se encuentra vacia !" << endl ;
    } 
}
int main ()
{
    Nodo * Fin = nullptr ;
    CargarLista (Fin) ;
    Continuar () ;
    MostrarLista(Fin) ;
    Continuar();
    return 0 ;
}