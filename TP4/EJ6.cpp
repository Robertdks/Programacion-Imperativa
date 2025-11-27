#include <iostream>
using namespace std ;

int Multiplicacion(int n, int m)
{
    if (m == 0)
    {
        return 0 ;
    }
    return n + Multiplicacion(n , m - 1) ;
}
int main ()
{
    int n ;
    int m ;
    cout <<"Ingrese un numero: ";
    cin >> n ;
    cout << "Ingrese el numero por el cual decide multiplicar: " ;
    cin >> m ;
    cout << n << " x " << m << " = "<< Multiplicacion(n,m) ;
    return 0 ; 
}