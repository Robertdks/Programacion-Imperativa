#include <iostream>
#include <string>
#include <cstdlib>
using namespace std ;
const int MAX_EMPLEADOS = 2000 ;
const int MAX_SUCURSALES = 20 ;

struct Empleado
{
    string nombre ;
    string apellido ;
    string legajo ;
    string dni ;
};
struct Sucursal
{
    string nombre ;
    Empleado encargado ;
};
string mayuscula(string texto)
{
    int aux = texto.length();
    for(int i = 0; i < aux ;i++)
    {
        texto[i] = toupper(texto[i]) ;
    }
    return texto ;
}
void carga_de_empleados(Empleado empleados[], int & dl , int DF)
{
    string aux ;
    cout << "Ingrese el nombre [FIN] para finalizar el ingreso: ";
    getline(cin>>ws,aux) ;
    while(mayuscula(aux) != "FIN" && dl < DF)
    {
        empleados[dl].nombre = aux ;
        cout << "Ingrese el apellido:  " ;
        getline(cin >>ws, empleados[dl].apellido);
        cout << "Ingrese el DNI: " ;
        getline(cin >>ws,empleados[dl].dni);
        empleados[dl].legajo = empleados[dl].dni ;
        cout << "Legajo generado automaticamente: " ;
        cout << empleados[dl].legajo << endl ;
        dl ++ ;
        system("clear") ;
        cout << "Empleado cargado con exito !! " << endl ;
        cout << "Ingrese el nombre [FIN] para finalizar el ingreso: ";
        getline(cin>>ws,aux) ;
    }

}
int buscar_empleado(Empleado empleados [], int dl, string legajo)
{
    for (int i = 0; i < dl ; i++)
    {
        if (legajo == empleados[i].legajo)
        {
            return i ;
        }
    }
    return -1 ;
}
void asignar_encargao(Sucursal sucursal [],Empleado empleados[], int dl, int indice)
{
    string legajo ;
    int aux ;
    cout << "Ingrese el legajo del empleado que desea asignar como encargado a la sucursal." << endl;
    cout << "Legajo: " ;
    getline(cin >>ws,legajo) ;
    aux = buscar_empleado(empleados,dl,legajo);
    while (-1 == aux)
    {
        cout << "Error! - Ingrese un legajo valido!: " ;
        getline(cin >>ws,legajo) ; 
        aux = buscar_empleado(empleados,dl,legajo);
    }
    sucursal[indice].encargado = empleados[aux] ;
    cout <<"Encargado asignado con exito !! " << endl ;
}
void carga_sucursales(Sucursal sucursales[],int & dl_sucursales, int DF , Empleado empleados[], int  dl_empleados)
{
    string aux ;
    char opcion ;
    cout <<"Ingrese el nombre de la sucursal [FIN] para finalizar el ingreso: ";
    getline(cin >>ws,aux) ;
    while(mayuscula(aux) != "FIN" && dl_sucursales < DF)
    {
        sucursales[dl_sucursales].nombre = aux ;
        cout << "Desea asignar un encargado a esta sucursal [S/N] ? " ;
        cin >> opcion ;
        if (toupper(opcion) == 'S' )
        {
            asignar_encargao(sucursales,empleados,dl_empleados,dl_sucursales);
        }
        else
        {
            sucursales[dl_empleados].encargado.nombre = "No asignado" ;
        }
        dl_sucursales ++ ;
        cout <<"Ingrese el nombre de la sucursal [FIN] para finalizar el ingreso: ";
        getline(cin >>ws,aux) ;
    }
}
void mostrar_sucursales(Sucursal sucursales[],int dl)
{
    for (int i = 0; i < dl ; i++)
    {
        cout << "Nombre de la sucursal: " << sucursales[i].nombre << endl;
        cout << "Encargado : "<< sucursales[i].encargado.nombre <<" " << sucursales[i].encargado.apellido<< endl;
    }
}
void mostrar_empleados(Empleado empleados [], int dl)
{
    cout <<"======== Lista de empleado ========== "<< endl ;
    for(int i = 0; i < dl ;i++)
    {
        cout << "Legajo del empleado: " << empleados[i].legajo <<endl;
        cout << "Nombre y apellido: " << empleados[i].nombre <<" "<< empleados[i].apellido << endl;
        cout << "Numero de dni: " << empleados[i].dni << endl;
    }
}
void menu(Empleado empleados[], int & dl_empleados, Sucursal sucursales[], int & dl_sucursales)
{
     int opcion;

    do
    {
        cout << "===============================" << endl;
        cout << "        MENU PRINCIPAL         " << endl;
        cout << "===============================" << endl;
        cout << "1. Cargar empleados" << endl;
        cout << "2. Cargar sucursales" << endl;
        cout << "3. Mostrar sucursales" << endl;
        cout << "4. Mostrar empleados" << endl ;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpia el buffer para usar getline después

        system("clear"); // en Windows usar system("cls");

        switch(opcion)
        {
            case 1:
                carga_de_empleados(empleados, dl_empleados, MAX_EMPLEADOS);
                break;
            case 2:
                carga_sucursales(sucursales, dl_sucursales, MAX_SUCURSALES, empleados, dl_empleados);
                break;
            case 3:
                mostrar_sucursales(sucursales, dl_sucursales);
                break;
            case 4 :
                mostrar_empleados(empleados,dl_empleados) ;
                break ;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }

        if (opcion != 0)
        {
            cout << endl << "Presione ENTER para continuar...";
            cin.get();
            system("clear");
        }

    } while(opcion != 0);
}
int main ()
{
    Empleado empleados[MAX_EMPLEADOS];
    Sucursal sucursales[MAX_SUCURSALES];
    int dl_empleados = 0;
    int dl_sucursales = 0;

    menu(empleados,dl_empleados,sucursales,dl_sucursales) ;

    return 0 ;
}