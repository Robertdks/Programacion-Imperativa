#include <iostream>
using namespace std ;
void mas_uno(int arreglo [], int Dlogica )
{
    for (int i = 0 ; i < Dlogica ; i++)
    {
        arreglo [i] ++ ;
    }
}
void cargar_arreglo (int arreglo [] , int Dfisica , int & Dlogica)
{
    int aux = 0 ;
    cout << "Ingrese un numero '0 para finalizar': " << endl ;
    cin >> aux ;
    while (aux !=0 && Dlogica < Dfisica )
    {
        arreglo [Dlogica] = aux ;
        Dlogica ++ ;
        cout << "Ingrese un numero '0 para finalizar': " << endl ;
        cin >> aux ;
    }
}
void imprimir_arreglo (int arreglo[], int Dlogica)
{
    for (int i = 0 ; i < Dlogica ; i++ )
    {
        cout << arreglo [i] << " " ;
    }
}
int main ()
{
    const int Dfisica = 10 ;
    int Dlogica = 0 ;
    int numeros [Dfisica] = {};
    cargar_arreglo(numeros,Dfisica,Dlogica) ;
    mas_uno(numeros,Dlogica) ;
    imprimir_arreglo(numeros,Dlogica) ;
    return 0 ;
}