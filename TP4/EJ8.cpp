#include <iostream>
using namespace std ;

void InvertirTexto(string texto,int n)
{
    if (n < 0)
    {
        return;
    }
    cout << texto [n] ;
    return InvertirTexto(texto,n - 1); 
}
int main ()
{
    string texto ;
    cout <<"Ingrese  el texto a invertir: " ;
    getline(cin>>ws,texto) ;
    cout <<"La texto invertida es: " ;
    InvertirTexto(texto,texto.length() - 1) ;
    return 0 ;
}