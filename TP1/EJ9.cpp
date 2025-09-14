#include <iostream>
using namespace std ;

void imprimir_arreglo(int arreglo[],int Dlogico)
{
    for(int i = 0 ; i  < Dlogico ; i++)
    {
        cout << arreglo [i] << " " ;
    }
    cout << endl ;
}
bool eliminar_ocurrencias(int arreglo [] , int & Dlogico , int dato)
{
    int cantidad = 0 ;
    int aux = 0 ;
    for(int i = 0 ; i < Dlogico ; i++)
    {
        if (arreglo[i] == dato)
        {
            for (int j = i; j < Dlogico; j++)
            {
                aux = arreglo [j + 1] ;
                arreglo[j] = aux ;
            }
            Dlogico -- ;
            i-- ; //Para revisar el mismo lugar porque hicimos un recorrido de valores
            cantidad ++ ;
        }
    }
    if(cantidad > 0)
    {
        return true ;
    }
    return false ;
}
void cargar_arreglo(int arreglo[],int Dfisica, int & Dlogica)
{
    int aux = 0 ;
    cout << "Ingrese un numero entero '0 para fianlizar': " << endl ;
    cin >> aux ;
    while(aux != 0 && Dlogica < Dfisica)
    {
        arreglo[Dlogica] = aux ;
        Dlogica ++ ;
        cout << "Ingrese un numero entero '0 para fianlizar': " << endl ;
        cin >> aux ;
    }
}
int main()
{
    const int Dfisica = 100 ;
    int Dlogica = 0;
    int dato = 0;
    int numeros [Dfisica] = {} ;
    cargar_arreglo(numeros,Dfisica,Dlogica) ;
    cout << "Ingrese un numero a eliminar: " << endl;
    cin >> dato;
    if(eliminar_ocurrencias(numeros,Dlogica,dato))
    {
        cout << "Se encontro el numero: '"<< dato << "' y se elimino correctamente del arreglo." << endl ;
        cout << "Nuevo arreglo: ";
        imprimir_arreglo(numeros,Dlogica); ;
    }
    else
    {
        cout << "No se encontro el numero: '"<< dato << "' por lo tanto no se elimino ningun elemento."<< endl ;
        cout << "Arreglo ingresado: " ;
        imprimir_arreglo(numeros,Dlogica); 
    }
    return 0;
}