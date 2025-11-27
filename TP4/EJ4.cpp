#include <iostream>
using namespace std ;

int Digitos (int n)
{
    if (n == 0)
    {
        return 0 ;
    }
    return Digitos( n / 10) + 1 ; 
}
int main ()
{
    int n ;
    cout <<"Ingrese un numero: " ;
    cin >> n ;
    cout <<"La cantidad de digitos del numero " << n <<" es: "<< Digitos (n) << endl;
    return 0 ;
}