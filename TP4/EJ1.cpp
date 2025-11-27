#include <iostream>
using namespace std;

int Multiplicacion(int n, int m)
{
    if (n == 0)
    {
        return 0 ;
    }
    return m + Multiplicacion ( m, n-1 ) ;
}
int main ()
{
    int n ;
    int m ;
    cout <<"Ingrese el numero: ";
    cin >> m ;
    cout <<"Por que numero desea multiplicarlo ? : " ;
    cin >> n ;
    cout << n <<" x "<< m <<" = "<< Multiplicacion(n,m) ;
    return 0 ;
}
// La funcion hace una multiplicación !