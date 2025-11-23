#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Alumno 
{
    string Nombre ;
    string apellido ;
    int DNI ;
    int legajo ;
    int notas [3] ;
};
struct Nodo 
{
    Alumno dato ;
    Nodo * siguiente ;
} ;
void InsertarNodo(Nodo * & Lista , Nodo * Nuevo)
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
int  VerificarDatos(int n)
{
    while ( n < 0)
    {
        cout << "Error Ingrese un valor valido!!! :"  ;
        cin >> n ;
    }
    return n ;
}
void CargarNotas(Nodo * & Nuevo)
{
    for (int i  = 0 ; i < 3 ; i++)
    {
        cout <<"Ingrese la nota numero " << i +1 << " : " ;
        cin >>Nuevo->dato.notas[i] ;
        while (Nuevo->dato.notas[i] < 0 || Nuevo->dato.notas[i] > 10)
        {
            cout <<"Error! Nota invalida, vuelta a intentarlo nuevamente " <<endl;
            cout <<"Ingrese la nota numero "<< i +1<< " : " ;
            cin >> Nuevo->dato.notas[i] ;
        }
    }
}
void CargarLista(Nodo * & Lista)
{
    int num ;
    cout <<"Ingrese el numero de DNI [0] para finalizar: ";
    cin >> num ;
    num = VerificarDatos(num) ;
    while (num != 0)
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato.DNI = num ;
        cout << "Ingrese el Nombre: " ;
        getline(cin>>ws,Nuevo->dato.Nombre) ;
        cout << "Ingrese el apellido: ";
        getline(cin>>ws,Nuevo->dato.apellido) ;
        Nuevo->dato.legajo = num ;
        cout << "Numero de legajo :  "<< num << endl; 
        CargarNotas(Nuevo) ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese el numero de DNI [0] para finalizar: ";
        cin >> num ;
    }
}
bool VerificarNotas(Nodo * Lista)
{
    for (int n = 0; n < 3 ; n++)
    {
        if (Lista->dato.notas[n] < 7)
        {
            return false ;
        }
    }
    return true ;
}
void MostrarAprobados(Nodo * Lista)
{
    Nodo * temp = Lista ;
    while (temp != nullptr)
    {
        if (VerificarNotas(temp))
        {
            cout << "Nombre y Apellido: " << temp->dato.Nombre <<", " << temp->dato.apellido << endl ;
            cout << "Numero de DNI: " << temp->dato.DNI << endl ;
            cout <<"================================================================"<< endl ;
        }
        temp = temp->siguiente ;
    }
}
void PromedioAprobado(Nodo * Lista)
{
    int total = 0 ;
    int cantidad = 0;
    while (Lista != nullptr)
    {
        total ++ ;
        if (VerificarNotas(Lista))
        {
            cantidad ++ ;
        }
        Lista = Lista->siguiente ;
        
    }
    float porcentaje = (cantidad * 100.0f) / total;
    cout << "El promedio de aprobados es de: %" << porcentaje << endl;
}
void Menu(Nodo *&Lista)
{
    int opcion;

    do
    {
        cout << "\n=========== MENU ===========\n";
        cout << "1) Cargar alumnos\n";
        cout << "2) Mostrar alumnos aprobados\n";
        cout << "3) Mostrar porcentaje de aprobados\n";
        cout << "4) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                cout << "\n--- CARGA DE ALUMNOS ---\n";
                CargarLista(Lista);
                break;

            case 2:
                cout << "\n--- ALUMNOS APROBADOS ---\n";
                MostrarAprobados(Lista);
                break;

            case 3:
                cout << "\n--- PORCENTAJE DE APROBADOS ---\n";
                PromedioAprobado(Lista);
                break;

            case 4:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 4);
}
int main ()
{
    Nodo * Lista = nullptr ;
    Menu(Lista) ;

    return 0 ;
}