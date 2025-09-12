#include <iostream>
using namespace std ;

bool elimar_elemento(int arreglo[],int & Dlogica, int dato )
{
    int aux = 0;
    for (int i = 0; i < Dlogica; i++)
    {
        if(arreglo[i]==dato)
        {
            for (int j = i; j < Dlogica; j++)
            {
                aux =  arreglo [j + 1];
                arreglo [j] = aux ;
            }
            Dlogica -- ;
            return true ;
        }
    }
    return false ;
}
void cargar_arreglo(int arreglo[],int Dfisica , int &  Dlogica)
{
    int aux = 0;
    cout << "Ingrese un numero '0 para finalizar': " << endl ;
    cin >> aux ;
    while (aux != 0 && Dlogica < Dfisica)
    {
        arreglo[Dlogica] = aux ;
        Dlogica ++ ;
        cout << "Ingrese un numero '0 para finalizar': " << endl ;
        cin >> aux ;
    }
}
void imprimir_Arreglo (int arreglo[],int Dlogico)
{
    for(int i = 0; i < Dlogico ; i++)
    {
        cout << arreglo[i] << " " ;
    }
}
int main()
{
    const int Dfisica = 10 ;
    int Dlogica = 0 ;
    int dato = 0 ;
    int numeros [Dfisica] = {};
    cargar_arreglo(numeros,Dfisica,Dlogica);
    cout << "Ingrese el numero que desea elimianar del arreglo: "<< endl ;
    cin >> dato ;
    if(elimar_elemento(numeros,Dlogica,dato))
    {
        cout << "Elemento encontrado y eliminado con exito!. " << endl ;
    }
    else 
    {
        cout << "Elemento no encontrado." << endl ;
    }
    imprimir_Arreglo(numeros , Dlogica) ;
    return 0 ;
}