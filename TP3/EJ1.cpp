#include <iostream>
#include <string>
using namespace std ;
struct Persona 
{
    string nombre ;
    string apellido ;
    int edad ;
};

int main ()
{
    int * n , * n1 ;
    n = new int ; // Reservamos la dirección de memoria ;
    *n = 42 ; // Le asignamos el valor 42 a la dirección de memoria de n ;
    n1 = n ;
    cout << "numero: " << *n << endl ; //Imprime el numero 42 en pantalla ;
    cout << "numero: " << *n1 << endl ; //Imprime el numero 42 en pantalla ;
    cout << "Direccion de memoria de 'n': " << &n << endl; //Devuelve la dirección de memoria de n ;
    cout << "Direccion de memoria de 'n1': "<< &n1 << endl ; //Devuelve la dirección de memoria de n1 ;
    delete n   ; //Libera la dirección de memoria ;
    Persona *persona ;
    persona = new Persona;
    cout << "Ingrese el nombre: " ;
    getline(cin >> ws,persona->nombre) ;
    cout << "Ingrese el apellido: " ;
    getline(cin>>ws,persona->apellido) ;
    cout << "Ingrese la edad: " ;
    cin >> persona->edad ;
    system("clear") ;
    cout << "Nombre: "<< persona->nombre << endl;
    cout << "Apellido: "<< persona->apellido << endl ;
    cout << "Edad: " << persona->edad << endl;
    char continuar ;
    cout << "Continuar...[S]." << endl ;
    cin >> continuar ;
    system("clear") ;
    *n1 = 53 ;
    cout << "n = " << *n << endl ;
    cout << "n1 = " << *n1 << endl ;
    n = new int;
    *n = 88;
    cout << *n << endl;
    cout << *n1 << endl;
    cout << "FIN";

    return 0 ;

}


//Declaración:
// int * p  ; -> Puntero entero ;

//Asignación:
// p = new int ;

//Liberar:
// delete p ; 