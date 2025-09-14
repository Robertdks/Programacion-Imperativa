#include <iostream>
using namespace std ;

int cantidad_ocurrencias(int arreglo[],int Dlogica , int dato)
{
    int cantidad = 0 ;
    for (int i = 0 ; i < Dlogica ; i ++)
    {
        if(arreglo[i] == dato)
        {
            cantidad ++ ;
        }
    }
    return cantidad ;
}
void cargar_arreglo (int arreglo [],int Dfisica, int & Dlogica)
{
    int aux = 0 ;
    cout << "Ingrese un numero '0 para finalizar': " << endl ;
    cin >> aux ;
    while(aux != 0 && Dlogica < Dfisica)
    {
        arreglo[Dlogica] = aux ;
        Dlogica ++ ;
        cout << "Ingrese un numero '0 para finalizar': " << endl ;
        cin >> aux ;
    }
}
int main ()
{
    const int Dfisica = 10 ;
    int Dlogica = 0 ;
    int numeros [Dfisica] = {};
    int dato = 0;
    cargar_arreglo(numeros,Dfisica,Dlogica) ;
    cout << endl ;
    cout << "Ingrese un numero: " << endl ;
    cin >> dato ;
    cout << "Cantidad de ocurrencias de " << dato << " son: "<< cantidad_ocurrencias(numeros,Dlogica,dato);
    return 0 ;
}