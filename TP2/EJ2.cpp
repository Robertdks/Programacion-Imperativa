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
        for(int j = 0; j < dl ; j++)
        {
            if(array [i] > array[j+1])
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
int main()
{
    const int df = 100 ;
    int dl = 0;
    int numeros [df] = {} ;
    int numero = 0;
    cargar_array(numeros,df,dl);
    ordenar_array(numeros,dl);
    imprimir_array(numeros,dl);
    return 0 ;
}