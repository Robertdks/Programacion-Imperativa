#include <iostream>
#include <string>
using namespace std ;

struct libro
{
    string titulo ;
    string autor ;
    string editorial ;
    int CantHojas ;
    int ISBN ;
};
string mayuscula(string  palabra)
{
    int aux = 0;
    aux = palabra.length();
    for(int i = 0; i < aux ; i++)
    {
        palabra [i] = toupper(palabra[i]);
    }
    return palabra ;
}
void cargar_libros(libro libros[],int df , int & dl)
{
    string aux ;
    cout << "Titulo: " ;
    getline(cin>>ws,aux);
    while (mayuscula(aux) != "EL HOBBIT" && dl < df)
    {
        libros[dl].titulo = aux ;
        cout << "Autor: " ;
        cin >> libros[dl].autor ;
        cout <<"Editorial: ";
        cin >> libros[dl].editorial ;
        cout << "Cantidad de hojas: ";
        cin >> libros[dl].CantHojas ;
        cout <<"ISBN: " ;
        cin >> libros[dl].ISBN ;
        cout << "\nLibro agregado con exito!.";
        dl ++ ;
        cout << "\nTitulo: " ;
        getline(cin>>ws,aux);
    }
    cout << "\nFinalizo la carga de libros." << endl;
}
void ver_libros(libro libros[],int dl)
{
    cout << "Libros cargados:" << endl;
    for (int i = 0; i < dl ; i++)
    {
        cout << "\n Titulo: " << libros[i].titulo << endl ;
        cout << "Autor: " << libros[i].autor << endl ;
        cout << "Editorial: " << libros[i].editorial << endl ;
        cout << "CantHojas: " << libros[i].CantHojas<< endl ;
        cout << "ISBN: " << libros[i].ISBN << endl ;
    }
}
int main()
{
    const int max_libros = 500 ;
    int cant_libros = 0;
    libro libros [max_libros] = {};
    cargar_libros(libros,max_libros,cant_libros);
    ver_libros(libros,cant_libros);
    return 0 ;
}