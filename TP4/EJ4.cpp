#include <iostream>
using namespace std ;

int digitos (int n)
{
    if (n == 0)
    {
        return 0 ;
    }
    return digitos(n / 10) + 1 ;
}

int main()
{   
    int numero ;
    cout << "Ingrese un numero: "  ;
    cin >> numero ;
    cout << digitos (numero) ;
}

//HACEMOS HASTA EL EJERCICIO 7  DE RECURSIVIDAD