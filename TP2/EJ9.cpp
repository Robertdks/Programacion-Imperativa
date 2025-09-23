#include <iostream>
#include <string>
using namespace std ;
const int MAX_ALUMNOS = 5000;
struct Nota
{
    int primer ;
    int segundo ;
    int tercer ;
};
struct Estudiante
{
    string nombre ;
    Nota calificacion ;
};
string mayuscula(string palabra)
{
    int aux = 0;
    aux = palabra.length();
    for(int i = 0; i < aux ; i++)
    {
        palabra[i] = toupper(palabra[i]);
    }
    return palabra ;
}
void cargar_nota(Estudiante array[], int & dl)
{
    string aux ;
    cout << "Nombre: " ;
    getline(cin,aux);
    while(mayuscula(aux) != "FIN" && dl < MAX_ALUMNOS)
    {
        array[dl].nombre = aux ;
        cout << "Nota del primer cuatrimestre: ";
        cin >> array[dl].calificacion.primer ;
        cout << "Nota del segundo cuatrimestre: ";
        cin >> array[dl].calificacion.segundo ;
        cout << "Nota del tercer cuatrimestre: ";
        cin >> array[dl].calificacion.tercer ;
        dl++;
        cout <<"\nDatos registrados exitosamente!.";
        cout << "\nNombre: " ;
        cin.ignore();
        getline(cin,aux);
    }
}
void mostrar_calificaiones(Estudiante array [], int dl)
{
    for (int i = 0; i < dl ; i++)
    {
        if(array[i].calificacion.primer > 5 && array[i].calificacion.segundo > 5 && array[i].calificacion.tercer > 5)
        {
            cout << "Estudiante: " << array [i].nombre << " ";
            cout << "Calificacion: APTO" << endl ;;
        }
        else
        {
            cout << "Estudiante: " << array[i].nombre << " ";
            cout << "Calificacion: NO APTO"<< endl ;
        }
    }
}

int main ()
{
    int dl = 0;
    Estudiante estudiantes [MAX_ALUMNOS] = {};
    cargar_nota(estudiantes,dl);
    mostrar_calificaiones(estudiantes,dl);
    return true ;
}