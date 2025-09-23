#include <iostream>
using namespace std ;

void cargar_array(int array[], int df , int & dl)
{
    int aux = 0;
    cout << "Ingrese un numero '0'  para finalizar : ";
    cin >> aux ;
    while(aux != 0 && dl < df)
        {
            if(aux > 0 && aux < 100000)
            {
                array[dl] = aux ;
                dl ++ ;
            }
            else
            {
                cout << "Error! ingrese un numero valido rango del numero (0 , 100000)." << endl ;
            }
            cout << "Ingrese un numero '0'  para finalizar : ";
            cin >> aux ;
        }

}
void ordenar_array(int array[] , int dl)
{
    int aux = 0;
    for(int i = 0; i < dl ; i++)
    {
        for(int j = 0 ; j < dl - 1 ; j ++)
        {
            if (array [j] > array[j + 1])
            {
                aux = array [j + 1];
                array[j + 1] = array [j] ;
                array [j] = aux ;
            }
        }
    }
}
void imprimir_array(int array [], int dl)
{
    for(int i = 0; i < dl ; i++)
    {
        cout << array[i] << " " << endl ;    
    }
}
int main ()
{
    const int df = 100 ;
    int dl = 0;
    int numeros [df] = {};
    cargar_array(numeros,df,dl) ;
    ordenar_array(numeros,dl);
    imprimir_array(numeros,dl);
    return 0 ;
}