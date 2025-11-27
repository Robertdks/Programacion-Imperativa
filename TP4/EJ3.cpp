#include <iostream>
using namespace std ;

void Inverso (int n)
{
    if (n / 10 == 0)
    {
        cout << n ;
    }
    else
    {
        cout << n % 10 ;
        return Inverso(n / 10) ;
    }
}
int main ()
{
    int n ;
    cout <<"Ingrese un numero: " ;
    cin >> n ;
    cout <<"Inverso = " ;
    Inverso(n) ;
    return 0 ;
}