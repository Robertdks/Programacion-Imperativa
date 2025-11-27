#include <iostream>
using namespace std ;

int SumaCuadrados(int n)
{
    if (n == 0)
    {
        return 0 ;
    }
    return n*n + SumaCuadrados(n - 1) ;
}
int main ()
{
    int n ;
    cout <<"Ingrese un numero: " ;
    cin >> n ;
    cout << "Suma de cuadrados del numero "<< n <<" es: "<< SumaCuadrados(n) << endl ; 
    return 0 ;
}