#include <iostream>
using namespace std ;

const int DF = 100 ;
struct Producto
{
    string nombre ;
    float precio ;
    int cantidad ;
};
void ordenar_array(Producto array[], int dl)
{
    Producto aux ;
    for (int i = 0; i < dl ; i++)
    {
        for (int j = 0 ; j < dl - 1; j++ )
        {
            if (array[j].precio > array[j+1].precio)
            {
                aux = array[j + 1];
                array[j + 1] = array[j] ;
                array[j] = aux;

            }
        }
    }
}
void cargar_array(Producto array[],int & dl)
{
    char seguir ;
    do 
    {
        cout << "Producto: " ;
        cin >> array[dl].nombre ;
        cout << "Precio: " ;
        cin >> array[dl].precio ;
        cout << "Cantidad: " ; 
        cin >> array[dl].cantidad ;
        dl ++ ;
        if (dl >= DF)
        {
            cout << "Se alcanzo el limite de Productos." ;
            break ;
        }
        cout << "Desea ingresar otro Producto [S/N] ";
        cin >> seguir ;
        seguir = toupper(seguir) ;
    }
    while(seguir != 'N' && dl < DF) ;
}
void imprimir_array(Producto array[],int dl)
{
    if (dl > 0)
    {
    
        cout <<  "Productos ingresados en el inventario: " << endl;
        for(int i = 0; i < dl ; i++)
        {
            cout << "Nombre: " << array[i].nombre << "  ";
            cout << "Precio: $" << array[i].precio << "  ";
            cout << "Cantidad: " << array[i].cantidad << "  " ;
            cout << endl ;
        }
    }
    else
    {
        cout << "No se ingreso ningun Producto al inventario. "<< endl ;
    }
}
int main()
{
    Producto Productos [DF] = {} ;
    int dl = 0; 
    cargar_array(Productos,dl);
    ordenar_array(Productos,dl);
    imprimir_array(Productos,dl);
    return 0 ;
}