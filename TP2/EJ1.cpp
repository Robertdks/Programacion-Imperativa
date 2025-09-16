#include <iostream> 
#include <string>
using namespace std ;

void cargar_Array(string array [], int &  dl, int df)
{
    string aux ;
    cout << "Ingrese un color, 'F' para finalizar el ingreso de colores: ";
    cin >> array[dl] ;
    aux = array[dl] ;
    while(aux != "F" && dl < df)
    {
        dl ++ ;
        cout << "Ingrese un color, 'F' para finalizar el ingreso de colores: ";
        cin >> array[dl] ; 
        aux = array[dl] ;   
    }
}
void imprimir_array (string array[], int dl)
{
    for (int i = 0; i < dl; i++)
    {
        cout << array [i] << " ";
    }
}
bool buscar_color(string array[], int dl, string color)
{
    int aux = 0;
    for(int i = 0; i < dl; i++)
    {
        aux = array[i].compare(color) ;
        if (aux == 0)
        {
            return true ;
        }
    }
    return false ;
}
int main()
{
    const int df = 12;
    int dl = 0;
    string colores[df]= {};
    string color ;
    cargar_Array(colores,dl,df);
    cout << "Ingrese el color que desea buscar: ";
    cin >> color ;
    if(buscar_color(colores,dl,color))
    {
        cout << "El color " << color << " se encuentra en el arreglo." << endl ;
    }
    else
    {
        cout << "El color " << color << " no se encontro en el arreglo. "<< endl ;
    }
}