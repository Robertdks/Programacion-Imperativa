#include <iostream>
using namespace std ;

void cargar_array(int array[], int df , int & dl)
{
    int aux = 0;
    cout << "Ingrese un numero '0' para finalizar: " ;
    cin >> aux ;
    while(aux != 0 && dl < df)
    {
        array[dl] = aux ;
        dl++ ;
        cout << "Ingrese un numero '0' para finalizar: " ;
        cin >> aux ;
    }
}
void ordenar_array(int array [], int dl)
{
    int aux = 0;
    for(int i = 0; i < dl ; i++)
    {
        for(int j = 0; j < dl - 1 ; j++)
        {
            if(array [j] > array[j+1])
            {
                aux = array [j + 1] ;
                array [j + 1] = array[j];
                array[j] = aux ;
            }
        }
    }
}
void imprimir_array(int array[], int dl)
{
    for(int i = 0; i < dl ; i++)
    {
        cout << array[i] << " ";
    }
}
bool buscar_elemento(int arreglo [] , int dl, int dato)
{
    for(int i =  0; i < dl ; i++)
    {
        if (dato == arreglo[i])
        {
            return true ;
        }
    }
    return false ;
}
int main()
{
    const int df = 100 ;
    int dl = 0;
    int numeros [df] = {} ;
    int numero = 0;
    cargar_array(numeros,df,dl);
    ordenar_array(numeros,dl);
    cout << "Ingresa un numemro a buscar en el arreglo: " ;
    cin >> numero ;
    if(buscar_elemento(numeros,dl,numero))
    {
        cout << "El numero " << numero << " se encuentra en el arreglo." << endl ;
    }
    else
    {
        cout << "El numero "<< numero << " no se encuentra en el arreglo." << endl ;
    }
    return 0 ;
}