#include <iostream>
using namespace std ;

void ordenar_array(int array[], int dl)
{
    int aux = 0 ;
    for (int i = 0 ; i < dl ; i++)
    {
        for (int j = 0; j < dl -1 ; j++)
        {
            if (array[j] > array [j + 1] )
            {
                aux = array[j + 1] ;
                array [j + 1] = array [j];
                array [j] = aux ;
            }
        }
    }
}
void cargar_array(int array[], int & dl , int df)
{
    int aux = 0 ;
    cout << "Ingrese un numero '0' para finalizar: " ;
    cin >> aux ;
    while( aux != 0 && dl < df)
    {
        array[dl] = aux ;
        dl ++ ;
        cout << "Ingrese un numero '0' para finalizar: " ;
        cin >> aux ;
    }
}

int busqueda_binaria(int array [], int dl , int dato)
{
    int medio = 0;
    int inicio = 0;
    int final = dl - 1;
    int resultado = 0;
    while(inicio <= final)
    {
        medio = (inicio + final) / 2;
        if(array[medio] == dato)
        {
            resultado = medio ;
            final =  medio  - 1;
        }
        if(array[medio] < dato)
        {
            inicio = medio + 1 ;
        }
        else 
        {
            final = medio - 1 ;
        }
    }
    return resultado ;
}
void imprimir_array(int array[], int dl )
{
    for(int i = 0; i < dl ; i++)
    {
        cout << array[i] <<" ";
    }
}
int main ()
{
    const int df = 100;
    int dl = 0;
    int numeros [df] = {};
    int numero = 0;
    int posicion = 0;
    cargar_array(numeros,dl,df);
    ordenar_array(numeros,dl);
    imprimir_array(numeros,dl);
    cout << "Ingrese un numero a buscar: " ;
    cin >> numero ;
    posicion = busqueda_binaria(numeros,dl,numero) ;
    if (posicion != -1)
    {
        cout << "El numero "<< numero << " se ecuentra en el arreglo en la posicion:  " << posicion << endl ;
    }
    else
    {
        cout << "El numero "<< numero << " no se encontro en el arreglo. "<< endl ;
    }
    return 0 ;
}