#include <iostream>
using namespace std ;

struct Nodo
{
    int dato ;
    Nodo * Siguiente ;
};

void InsertarNodo(Nodo * & Cabeza, Nodo * Nuevo)
{
    if (Cabeza == nullptr)
    {
        Cabeza = Nuevo ;
    }
    else
    {
        Nodo * temp = Cabeza ;
        while (temp->Siguiente != nullptr)
        {
            temp = temp->Siguiente ;
        }
        temp->Siguiente = Nuevo ;
    }
}
void CargarLista(Nodo * & Cabeza)
{
    int num ;
    cout <<"Ingrese un numero [-n] para finalizar: ";
    cin >> num ;
    while (num > 0)
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato = num ;
        Nuevo->Siguiente = nullptr ;
        InsertarNodo(Cabeza,Nuevo) ;
        cout <<"Ingrese un numero [-n] para finalizar: ";
        cin >> num ;
    }
    cout <<"Datos registrados con exito!"<< endl ;
}
Nodo * VerificarNumero(Nodo * Cabeza, int num)
{
    Nodo * temp = Cabeza ;
    while (temp != nullptr)
    {
        if (temp->dato == num)
        {
            return temp ;
        }
        temp = temp->Siguiente ;
    }
    return nullptr ;
}
void BuscarNumero(Nodo * Cabeza)
{
    int num ;
    if (Cabeza != nullptr)
    {   
        cout <<"Ingrese el numero a buscar: ";
        cin >> num ;
        if (VerificarNumero(Cabeza,num) != nullptr)
        {
            cout << "El numero " << num << " si se encontro en la Lista."<< endl ;
        }
        else
        {
            cout <<"El numero "<< num << " no se encontro en la Lista."<< endl ;
        }
    }
    else
    {
        cout <<"La Cabeza se encuentra vacia, primero agrege los valores!!" << endl ;
    }
}
void InformarOcurrencia(Nodo * Cabeza)
{
    int num = 0 ;
    int cantidad ;
    cout <<"Ingrese el numero que desea buscar la ocurrencia: ";
    cin >> num ;
    if (VerificarNumero(Cabeza,num) != nullptr)
    {
        while(Cabeza != nullptr)
        {
            if (Cabeza->dato == num)
            {
                cantidad ++ ;
            }
            Cabeza = Cabeza->Siguiente;
        }
        cout << "La cantidad de ocurrencias de "<< num <<" es de: "<< cantidad ;
    }
    else
    {
        cout <<"No se encontro el numero en la Lista!" << endl ;
    }
}
void SepararNodos(Nodo * & Cabeza , Nodo * & Pares , Nodo * & Impares)
{
    Nodo * temp = Cabeza ;
    while (temp != nullptr)
    {
        Nodo * Nuevo = new Nodo () ;
        Nuevo->dato = temp->dato ;
        Nuevo->Siguiente = nullptr ;
        if (temp->dato % 2 == 0)
        {
            InsertarNodo(Pares,Nuevo);
        }
        else
        {
            InsertarNodo(Impares,Nuevo);
        }
        temp = temp->Siguiente ;
    }
    temp = Cabeza;
    while (temp != nullptr)
    {
        Nodo * borrar = temp;
        temp = temp->Siguiente;
        delete borrar;
    }
    Cabeza = nullptr; // la lista original queda vacía
}
void SepararLista(Nodo * & Cabeza, Nodo * & Pares , Nodo * & Impares)
{
    if (Cabeza != nullptr)
    {
        SepararNodos(Cabeza, Pares, Impares) ;
        cout <<"Lista separada con exito!!" << endl ;
    }
    else
    {
        cout << "Error! La Cabeza se encuentra vacia."<< endl ;
    }
}
void MostrarLista(Nodo * Lista)
{
    if(Lista != nullptr)
    {
        Nodo * temp = Lista ;
        while(temp != nullptr)
        {
            cout << temp->dato <<"  " ; 
            temp = temp->Siguiente ;
        }
        cout << endl ;
    }
    else
    {
        cout << "La lista se encuentra vacia!!" << endl ;
    }
}
void Menu (Nodo * & Cabeza, Nodo * & Pares, Nodo * & Impares)
{
     int opcion;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Cargar lista\n";
        cout << "2. Buscar numero\n";
        cout << "3. Informar ocurrencia de un numero\n";
        cout << "4. Separar lista en pares e impares\n";
        cout << "5. Mostrar lista original\n";
        cout << "6. Mostrar lista de pares\n";
        cout << "7. Mostrar lista de impares\n";
        cout << "0. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CargarLista(Cabeza);
            break;

        case 2:
            BuscarNumero(Cabeza);
            break;

        case 3:
            InformarOcurrencia(Cabeza);
            break;

        case 4:
            SepararLista(Cabeza, Pares, Impares);
            Cabeza = nullptr; // La lista original se destruye
            break;

        case 5:
            MostrarLista(Cabeza);
            break;

        case 6:
            MostrarLista(Pares);
            break;

        case 7:
            MostrarLista(Impares);
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida!" << endl;
        }

    } while (opcion != 0);
}
int main ()
{
    Nodo * Lista = nullptr ;
    Nodo * Pares = nullptr ;
    Nodo * Impares = nullptr ;
    Menu(Lista,Pares,Impares) ;
    return 0 ;
}