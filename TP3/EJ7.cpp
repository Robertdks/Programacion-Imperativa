#include <iostream>
#include <string>
#include <limits> // para numeric_limits
using namespace std ;

struct Nodo
{
    int dato ;
    Nodo * siguiente ;
};

int IngresarNumero()
{
    int numero = 0;
    cout << "Ingrese un numero: " ;
    cin >> numero ;
    while (numero < 0)
    {
        cout <<"Error, el numero no puede ser negativo, ingrese otro: " ;
        cin >> numero ;
    }
    return numero ;
}
void Continuar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
    cin.get(); // espera a que el usuario presione Enter
    system("clear") ;
}
void InsertarNodo(Nodo * & Lista, Nodo * nodo)
{
    if(Lista == nullptr)
    {
        Lista = nodo ;
    }
    else
    {
        Nodo * temp = Lista ;
        while(temp->siguiente != nullptr) 
        {
            temp = temp->siguiente ;
        }
        temp->siguiente = nodo ;
    } 
}
void InsertarLista(Nodo *& Lista)
{
    int aux ;
    cout << "Ingrese un numero [-n] para finalizar: ";
    cin >> aux ;
    while(aux > 0)
    {
        Nodo * nuevo = new Nodo();
        nuevo->dato = aux ;
        nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,nuevo);
        cout << "Ingrese un numero [-n] para finalizar: ";
        cin >> aux ;
    }
}
Nodo * VerificarNumero(Nodo * Lista,int numero)
{
    Nodo * temp = Lista ;
    while (temp != nullptr && temp->dato != numero)
    {
        temp = temp->siguiente ;
    }
    return temp ;
}
void BuscarNumero (Nodo * Lista)
{
    int numero = IngresarNumero() ;
    if (VerificarNumero(Lista,numero) != nullptr)
    {
        cout << "El numero si se encuentra en la lista. "<< endl;
    }
    else
    {
        cout << "El numero no se ecuentra en la lista." << endl ;
    }
}

void InformarOcurrencia(Nodo * Lista)
{
    Nodo * temp = Lista ;
    int dato = IngresarNumero() ;
    int cantidad = 0;
    while (temp != nullptr)
    {
        if (temp->dato == dato)
        {
            cantidad ++ ;
        }
        temp = temp->siguiente ;
    }
    cout << "La cantidad de ocurrencia de " << dato << "es " << cantidad <<endl;
}
void ClasificarLista (Nodo *  Lista , Nodo * & Pares , Nodo *& Impares)
{
    Nodo * temp = Lista ;
    if (temp == nullptr)
    {
        cout << "La lista se encuentra vacia." << endl;
        return ;
    }
    Pares = nullptr ;
    Impares = nullptr ;

    while (temp != nullptr)
    {   Nodo * Nuevo = new Nodo ();
        Nuevo->dato = temp->dato ;
        Nuevo->siguiente = nullptr ;
        if (temp->dato % 2 == 0)
        {
            InsertarNodo(Pares,Nuevo);
        }
        else
        {
            InsertarNodo(Impares,Nuevo);
        }
        temp = temp->siguiente ;
    }
    cout << "Lista clasificada con exito !" ;
}
void Imprimir(Nodo * Lista)
{
    Nodo * aux = Lista ;
    if(aux == nullptr)
    {
        cout <<"La lista esta vacia."<< endl ;
        return ;
    }
    while(aux != nullptr)
    {
        cout << aux->dato << " " ;
        aux = aux->siguiente ;
    }
    cout << "NULL"<< endl;
}
void MostrarLista (Nodo * Lista1,Nodo * Lista2 , Nodo * Lista3)
{
    char opcion ;
    cout <<"Que lista desea imprimir ? " << endl;
    cout <<"[A] Lista Original."<< endl ;
    cout <<"[B] Lista de numeros pares."<< endl ;
    cout <<"[C] Lista de numeros impares."<< endl ;
    cout <<"[D] Imprimir las tres listas." << endl;
    cout <<"Ingrese una opcion: " ;
    cin >> opcion ;
    system("clear") ;
    switch (toupper(opcion))
    {
    case 'A':
        cout << "Lista Original: "<< endl ;
        Imprimir(Lista1) ;
        break;
    case 'B':
        cout << "Lista de numeros pares: " << endl ;
        Imprimir(Lista2);
        break;
    case 'C':
        cout << "Lista de numeros impares: "<< endl ;
        Imprimir(Lista3) ;
        break;
    case 'D':
        cout << "Lista Original: "<< endl ;
        Imprimir(Lista1) ;
        cout << "Lista de numeros pares: " << endl ;
        Imprimir(Lista2);
        cout << "Lista de numeros impares: "<< endl ;
        Imprimir(Lista3) ;
        break;
    default:
        cout << "Opcion invalida vuelva a intentarlo!" << endl;
        break;
    }
}
void menu (Nodo * & Lista,Nodo * & Pares , Nodo * & Impares)
{
    char opcion;

    do {
        cout << "\n======= MENU PRINCIPAL =======\n";
        cout << "[A] Insertar numeros en la lista\n";
        cout << "[B] Buscar un numero en la lista\n";
        cout << "[C] Informar ocurrencias de un numero\n";
        cout << "[D] Clasificar lista en pares e impares\n";
        cout << "[E] Mostrar listas\n";
        cout << "[F] Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("clear") ;
        switch (toupper(opcion)) {
            case 'A':
                InsertarLista(Lista);
                system("clear");
                cout <<"Numeros Ingresados con exito!" ;
                Continuar();
                break;
            case 'B':
                BuscarNumero(Lista);
                Continuar();
                break;
            case 'C':
                InformarOcurrencia(Lista);
                Continuar();
                break;
            case 'D':
                ClasificarLista(Lista, Pares, Impares);
                Continuar();
                break;
            case 'E':
                MostrarLista(Lista, Pares, Impares);
                Continuar();
                break;
            case 'F':
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 'F');
}
int main ()
{
    Nodo * Lista = nullptr ;
    Nodo * Pares = nullptr ;
    Nodo * Impares = nullptr ;
    menu(Lista,Pares,Impares);
    return 0;
}