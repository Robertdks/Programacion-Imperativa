#include<iostream>
#include <string>
using namespace std ;
void alta_usuario(string arreglo [], int Dfisica, int & Dlogico)
{
    string temp ;
    int dni = 0;
    cout << "Ingrese el DNI '0' para finalizar: " << endl ;
    cin >> dni ;
    while(dni != 0 && Dlogico < Dfisica)
    {
        temp = to_string(dni) ;
        if (temp.length() == 8)
        {
            arreglo[Dlogico] = temp ;
            Dlogico ++ ;
            cout << "Usuario registrado con exito!."<< endl ;
        }
        else
        {
            cout << "Error, ingrese un DNI valido." << endl ;
        }
        cout << "Ingrese el DNI '0' para finalizar: " << endl ;
        cin >> dni ;
    }
}
void mostrar_usuarios (string arreglo[], int Dlogico) 
{
    for(int i = 0 ; i < Dlogico ; i++)
    {
        cout << arreglo[i] << endl ;
    }
}
bool eliminar_usuario(string arreglo[], int & Dlogico, int dni)
{
    string aux = " " ;
    for(int i = 0 ; i < Dlogico ; i++)
    {
        if(stoi(arreglo[i]) == dni)
        {
            for (int j = i ; j < Dlogico; j++)
            {
                aux = arreglo[j + 1] ;
                arreglo[j] = aux ;
            }
            Dlogico -- ;
            return true ;
        }
    }
    return false ;
}
void cargar_dni(int & dni)
{
    string aux ;
    cout << "Ingrese el DNI: " << endl ;
    cin >> dni ;
    aux = to_string(dni) ;
    while(aux.length() != 8)
    {
        cout << "Error ingrese un DNI valido." << endl ;
        cin >> dni ;
        aux = to_string(dni);
    }
}
bool buscar_usuario(string arreglo[], int Dlogico, int dni)
{
    for (int i = 0 ; i < Dlogico ; i++)
    {
        if (stoi(arreglo[i]) == dni)
        {
            return true ;
        }
    }
    return false ;
}
int main()
{
    char caracter ;
    int dni = 0;
    const int Dfisica = 200 ;
    int Dlogico = 0 ;
    string Usuarios [Dfisica] ={} ;
    do
    {
        cout << "BIENVENIDO AL PORTAL DE REGISTROS" << endl ;
        cout << "'A' - Registrar usuarios." << endl ;
        cout << "'B' - Elimianar un usuario." << endl ;
        cout << "'C' - Buscar un usuario." << endl ;
        cout << "'D' - Mostrar usuario." << endl ;
        cout << "'E' - Salir del programa." << endl ;
        cout << "ingrese una opcion: "<< endl ;
        cin >> caracter ;
        caracter = toupper(caracter);
        switch (caracter)
        {
        case 'A':
            alta_usuario(Usuarios,Dfisica,Dlogico);
            break;
        case 'B':
            cargar_dni(dni);
            if(eliminar_usuario(Usuarios,Dlogico,dni))
            {
                cout << "El usuario se elimino con exito!." << endl ;
            }
            else 
            {
                cout << "No se encontro el usuario." << endl ;
            }
            break;
        case 'C':
            cargar_dni(dni);
            if(buscar_usuario(Usuarios,Dlogico,dni))
            {
                cout << "Cuota al dia." << endl ;
            }
            else 
            {
                cout << "Socio con deuda" << endl ;
            }
            break;
        case 'D':
            mostrar_usuarios(Usuarios,Dlogico);
            break;
        case 'E' :
                cout << "Gracias por usar el programa." << endl ;
            break;
        default:
            cout << "Ingrese un valor valido!"<< endl ;
            break;
        }
    } while (caracter != 'E');
    return 0 ;
}