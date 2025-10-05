#include <iostream>
#include <string>
#include <cstdlib>
using namespace std ;
const int MAX_CLIENTES = 1000 ;

struct Persona
{
    string nombre ;
    int dni ;
    string apellido ;
    long cumpleaños [2] ;
};

struct Cliente
{
    Persona persona ;
    string mail ;
    int Cantidad ;
};

string mayuscula(string texto)
{
    int aux = texto.length() ;
    for (int i = 0; i < aux ;i ++)
    {
        texto[i] = toupper(texto[i]) ;
    }
    return texto ;
}
void ingresar_fecha(Cliente clientes[],int dl)
{
    string fecha [2] = {"Mes","Dia"};
    for (int i = 0; i < 2 ;i++)
    {
        cout << fecha[i] <<" :";
        cin >> clientes[dl].persona.cumpleaños[i] ;

    }
}
void ordenar_array(Cliente clientes[], int dl)
{
    Cliente aux ;
    for (int i = 0; i < dl -1 ; i++)
    {
        for(int j =  0; j < dl - i - 1 ;j++)
        {
            if(clientes[j].persona.dni > clientes[j+1].persona.dni)
            {
                aux = clientes [j] ;
                clientes [j] = clientes [j + 1] ;
                clientes[j + 1] = aux ;
            }
        }
    }
}
void cargar_array(Cliente clientes[], int & dl, int DF)
{
    string aux ;
    cout << "Ingrese el nombre [Z] para finalizar: " ;
    getline(cin>>ws,aux) ;
    while (mayuscula(aux) != "Z" && dl < DF)
    {
        clientes[dl].persona.nombre = aux ;
        cout <<"Ingrese el apellido: " ;
        cin >> clientes[dl].persona.apellido ;
        cout <<"Ingrese el numero de dni: ";
        cin >> clientes[dl].persona.dni;    
        cout <<"Ingrese el cumpleaños [MM/DD]" << endl ;
        ingresar_fecha(clientes,dl) ;
        cout << "Ingrese el mail (usuario@gmail.com): ";
        getline(cin>>ws,clientes[dl].mail) ;
        cout <<"Ingrese el total de compras en el año: ";
        cin >> clientes[dl].Cantidad ;
        dl ++ ;
        ordenar_array(clientes,dl) ;
        cout << "Ingrese el nombre [Z] para finalizar: " ;
        getline(cin>>ws,aux) ;
    }
}
void contador_de_meses(Cliente clientes[],int contador_meses[], int dl)
{
        for (int i = 0; i < dl ; i++)
    {
        int mes = clientes[i].persona.cumpleaños[0];
        if( mes >= 1 && mes <= 12)
        {
            contador_meses[mes - 1] ++ ; //Me va a sumar el mes en la  poosicion.
        }
    }
}
void mostrar_fecha_cumpleaños(Cliente clientes[], int dl)
{
    string Meses[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"} ;
    int contador_meses[12] = {0} ; 
    contador_de_meses(clientes,contador_meses,dl) ;
    for (int i = 0; i < 12 ;i++)
    {
        cout << Meses[i] << " :" << contador_meses[i] ;
    }

}
void mostrar_clientes(Cliente clientes[],int dl)
{
    for (int i = 0; i < dl ; i++)
    {
        cout << "Nombre y Apellido: "<< clientes[i].persona.nombre <<" "<<clientes[i].persona.apellido << endl ;
        cout <<"Numero de DNI: " << clientes[i].persona.dni << endl ;
    }
}
int main ()
{
    Cliente clientes [MAX_CLIENTES] ;
    int cant_clientes = 0;
    cargar_array(clientes,cant_clientes,MAX_CLIENTES);
    mostrar_clientes(clientes,cant_clientes) ;
    return 0 ;
}