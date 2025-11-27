#include <iostream>
#include <string>

using namespace std ;

bool Palindromo(string palabra,  int n , int a)
{
    if (a >= n)
    {
        return true  ;
    }
    if ( palabra[n] == palabra [a])
    {
        return Palindromo(palabra, n - 1, a + 1);
    }
    else
    {
        return false ;
    }
}
int main ()
{
    string texto ;
    cout <<"Ingrese una palabra: " ;
    cin >> texto ;
    if (Palindromo(texto, texto.length() - 1, 0)
)
    {
        cout <<"Es palindromo" << endl ;
    }
    else
    {
        cout <<"No es palindromo" << endl ;
    }
}