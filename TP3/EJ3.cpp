#include <iostream>
using namespace std ;

int main()
{
    char * x = new char ;
    char * z = x ;
//a) Almacenar el carácter 'M' en el espacio de memoria apuntado por x.
    *x = 'M' ;
//b) Imprimir el carácter apuntado por x.
    cout << *x << endl ;
//c) Almacenar el carácter 'P' en el espacio de memoria apuntado por z.
    *z = 'p' ;
//d) Imprimir el carácter apuntado por z y luego el apuntado por x.
    cout << *x <<" "<< *z << endl;
//¿Qué carácter crees que imprimirá cada una y por qué?
    //va imprimir p y p
//e) Eliminar el dato apuntado por x.
    delete x ;
//¿Qué sucedería si a continuación se intentara imprimir *z y por qué?
    // No se va a imprimir por que z = x ;
//f) Obtener un nuevo espacio de memoria para un char, almacenando su dirección en x.
    x = new char ;
    char * a ;
    a = x ; 
//g) Permitir al usuario ingresar un char por teclado y almacenarlo en el nuevo espacio apuntado por x.
    cout << "Ingrese un valor: " ;
    cin >> *a ;
//h) Si el carácter ingresado por el usuario en el inciso anterior es '*', imprimir "asterisco".
    if (*a == '*')
    {
        cout <<"El caracter ingresado es: " << *a << endl ;
    }
//Hoja 2 de 7 Área Algoritmos y Lenguajes | Escuela de Tecnología | UNNOBA
return 0 ;

}