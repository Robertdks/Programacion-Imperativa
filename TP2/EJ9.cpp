#include <iostream>
#include <string>
using namespace std ;
const int MAX_ALUMNOS = 5000;
struct Estudiante
{
    int calificacion [3] ;
    string nombre ;
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
bool apto(int dl)
{
    Estudiante notas[dl];
    float suma = 0;
    for (int  i = 0; i < 3; i++)
    {
        if(notas[dl].calificaion[i] < 5)
        {
            return false ;
        }
    return true ;
    
}
void cargar_nota(Estudiante array[], int & dl)
{
    string aux ;
    cout << "Nombre: " ;
    getline(cin,aux);
    while(mayuscula(aux) != "FIN" && dl < MAX_ALUMNOS)
    {
        array[dl].nombre = aux ;
        for(int i = 0; i < 3 ; i++)
        {
            cout << i + 1 <<" Cuatrimestre: ";
            cin >> array[dl].calificacion[i];
        }
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
        if(apto(dl)
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
