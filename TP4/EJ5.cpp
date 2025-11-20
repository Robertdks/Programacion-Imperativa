#include <iostream>
using namespace std ;
void   Inverso (int n)
{
    if (n/10 == 0)
    {
        cout << n ;
    }
    else
    {
        cout << n % 10 ;
        Inverso(n / 10)  ;
    }
}
int main ()
{
    int n = 521 ;
    Inverso(n) ;
    cout << endl ;
    return 0 ;
}