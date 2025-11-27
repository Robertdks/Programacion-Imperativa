#include <iostream>
using namespace std ;

int Sumatoria(int n)
{
    if (n == 0) // caso base
    {
        return 0 ;
    }
    return Sumatoria(n-1) + n ;
}
int main ()
{
    int n ;
    cout <<"Ingrese un numero para ver la sumatoria de esta :" ;
    cin >> n ;
    cout <<"La sumatoria del numero es: "<< Sumatoria(n) ;
    return 0 ;
}