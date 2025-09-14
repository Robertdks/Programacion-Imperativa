#include <iostream>
using namespace std ;

int main ()
{
    int num = 0 ;
    int temp = 0 ;
    int cantidad [10] = {0} ;
    int digito = 0 ;
    do
    {
        cout << "Ingrese un numero: " ;
        cin >> num ;
        cout << endl ;
        temp = abs(num) ; // En caso de que nos ingresen numeros negativos
        while (temp > 0)
        {
            digito = temp % 10 ;
            cantidad [digito] ++ ;
            temp = temp / 10 ;
        }

    } while (num != 0);
    for (int i = 0; i < 10; i++)
    {
        if(cantidad [i] > 0)
        {
            cout << "Cantidad de "<< i << " :" << cantidad[i] << endl;
        }
    }
    return 0 ;
}