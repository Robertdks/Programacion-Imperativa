#include <iostream>
using namespace std ;

int Potencia(int n, int m)
{
    if (m == 0)
    {
        return 1 ;
    }
    return Potencia (n, m - 1) * n ;
}
int main()
{
    int n ; 
    int m ;
    cout <<"Ingrese un numero: " ;
    cin >> n ;
    cout <<"Ingrese el numero al que esta elevado: ";
    cin >> m ;
    cout <<"El resultado de " << n <<"^" << m <<" es:" << Potencia (n,m) ;
    return 0  ;
}