#include <iostream> 
#include <string>
using namespace std ;

const  int MAX_INVITADOS = 150 ;
struct Persona
{
    string nombre ;
    string apellido ;
    int edad ;
    char genero ;
};
string mayuscula(string palabra)
{
    int aux = palabra.length();
    for (int i = 0; i < aux; i++)
    {
        palabra[i] = toupper(palabra[i]) ;
    }
    return palabra ;
}
void cargar_invitados(Persona array[], int &  dl, int df)
{
    string aux ;
    cout << "Nombre: " ;
    getline(cin,aux) ;
    while(mayuscula(aux) != "ZZZ" && dl < df)
    {
        array[dl].nombre = aux ;
        cout << "Apellido: " ;
        getline(cin,array[dl].apellido) ;
        cout << "edad: " ;
        cin >> array[dl].edad;
        cout << "Genero [M/F]: ";
        cin >> array[dl].genero;
        dl ++ ;
        cout << "Invitado registrado!." ;
        cout << "\nNombre: ";
        cin.ignore() ;
        getline(cin,aux) ;
    }
}
void mostrar_mujer(Persona array[],int dl)
{
    for (int i = 0; i < dl ;i++)
    {
        if (array[i].edad <= 20 && toupper(array[i].genero) == 'F' )
        {
            cout << "\nNombre: "<<array[i].nombre;
            cout << " Apellido: "<<array[i].apellido;
            cout << " Edad: "<<array[i].edad;
            cout << " Genero: "<<array[i].genero;
        }
    }
}
bool eliminar(Persona array[], int & dl , string nombre, string apellido)
{
    for (int i = 0; i < dl ; i++)
    {
        if (nombre == array[i].nombre && apellido == array[i].apellido)
        {
            for(int j = i; j < dl - 1; j++)
            {
                array[j] = array[j + 1];
            }
            dl -- ;
            return true ;
        }
    }
    return false ;
}
int main ()
{
    int cant_invitados = 0 ;
    string nombre ;
    string apellido ;
    Persona invitados [MAX_INVITADOS] = {} ;
    cargar_invitados(invitados,cant_invitados,MAX_INVITADOS);
    cout << "La cantidad de invitados que van a asistir es de: " << cant_invitados ;
    mostrar_mujer(invitados,cant_invitados);
    cout << "Ingrese el nombre de la persona que desea buscar: " ;
    getline(cin,nombre);
    cout << "Ahora ingrese el apellido de la persona:" ;
    getline(cin,apellido);
    if(eliminar(invitados,cant_invitados,nombre,apellido))
    {
        cout << "El invitado se elimino con exito!" ;
    }
    else
    {
        cout << "Error no se pudo eliminar el invitado.";
        cout <<"\nPosibles errores: " ;
        cout <<"\nLa persona no se encuenta en la lista.";
        cout <<"\nEl mal ingreso de los datos.";
    }
    return 0 ;
}
