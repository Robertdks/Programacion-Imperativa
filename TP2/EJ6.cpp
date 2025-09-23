#include <iostream>
using namespace std ;

struct zapato
{
    string estilo ;
    double precio ;
} ;

int main ()
{   
    zapato zapato1 ,zapato2 ;
    cout << "Estilo: " ;
    cin >> zapato1.estilo ;
    cout << "Precio: " ;
    cin >> zapato1.precio ;
    zapato2 = zapato1 ;
    cout << zapato1.estilo << " ";
    cout << zapato1.precio  << endl ;
    cout << zapato2.estilo <<" ";
    cout << zapato2.precio << endl ;
    return 0 ;
}