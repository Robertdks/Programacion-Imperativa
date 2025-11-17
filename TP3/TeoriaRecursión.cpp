#include <iostream>
using namespace std ;
/*La recursividad en forma general, implica descomponer un problema complejo en versiones más  sencillas de si mismo, es decir sub-problemas
cuya naturaleza y resoluciój son las mismas que el original.
En ambito matematico e informatico, significa que una función se invoca a si misma en el cuerpo de su definición. Esto último es llamado caso
recursivo, es deci que una de las instrucciones que debe ejecutar la función es unvocarse a si misma.
Si la función se invoca a si misma, es lógico suponer que de alguna forma esto debe terminar, de otra forma estariamos en presencia de un bucle infinito.
Esta forma de detener la recursión es llamada caso base. Significa que se redujo el problema a un nivel talque  no es necesario o posible reducirlo aún
mas pero si e sposible ofrecer una respuesta definitiva al problema. Todos los algoritmos recursivos deben contar con al menos con un caso base
*/
/*
    Ejemplo sumatoria:

    suma(5)= suma(4) + 5
    suma(4)= suma(3) + 4
    suma(3)= suma(2) + 3
    suma(2)= suma(1) + 2
    suma(1)= suma(0) + 1
    ---------------------
    suma(0) = 0 --> Caso Base.
    int suma  (int n)
    {
        if (n == 0)
        {
            return 0 ;
        }
    }
    return suma(n - 1) + n ;
*/

int suma (int n) // Función recursiva de Sumatoria.
{
    if (n == 0)
    {
        return 0 ;
    }
    return suma (n - 1) + n ; 
}

int main ()
{
    cout << suma (5)  << endl ;
    return 0 ;
} 

/*
    Una función recursiva se llama a si misma hasta completar un objetivo.
*/