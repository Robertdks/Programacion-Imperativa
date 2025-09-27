#include <iostream> 
#include <string>
using namespace std ;

const int  MAX_ALUMNOS = 1000 ;
struct Persona 
{
    string nombre ;
    string apellido;
    int edad ;
    string DNI ;
};
struct Dato
{
    int calificacion[2];
    int inacistencias ;
    int asistencias ;
};

struct Estudiante
{
    string legajo  ;
    Persona personal;
    Dato academico ;
};
int legajo(int legajo)
{
    if (legajo != 0)
    {
        return legajo ++ ;
    }
    
    return legajo = 1  ;
}
string mayuscula(string palabra)
{
    for (int i = 0; i < palabra.length();i++)
    {
        palabra [i] = toupper (palabra [i] ) ;
    }
    return palabra ;
}
void cargar_array(Estudiante array [], int dl )
{
    string aux ;
    cout << "Nombre ingrese 'FIN' para finalizar: " ;
    getline(cin>>ws,aux) ;
    while(mayuscula(aux)!= "FIN")
    {
        array[dl].personal.nombre = aux ;
        cout << "Apellido: ";
        getline(cin>>ws,array[dl].personal.apellido);
        cout << "Edad: ";
        cin >> array[dl].personal.edad;
        cout << "DNI: " ;
        getline(cin>>ws,array[dl].personal.DNI);
    }   
}
void menu()
{
    char opcion ;
    do
    {
        cout << "======= UNIVERSIDAD =======" << endl;
        cout << " [A] Ingresar un estudiante" << endl;
        cout << " [B] Mostrar alumnos con mas de 5 inasistencias" << endl;
        cout << " [C] Mostrar legajos con nota >= promedio general" << endl;
        cout << " [D] Mostrar legajos con nota >= 9" << endl;
        cout << " [E] Eliminar estudiante por legajo" << endl;
        cout << " [F] Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        opcion = toupper(opcion);
        switch (opcion)
        {
        case 'A':
            
            break;
        case 'B':
            
            break;
        case 'C':
            
            break;
        case 'D':
            
            break;
        case 'E':
            
            break;
        case 'F':
            cout << "/nSeccion finaliza, vuelva pronto" ;
            break;
        default:
            cout << "/nError! ingrese una opcion valida";
            break;
        }
    } while (opcion != 'F');
}
int main ()
{
    Estudiante estudiantes[MAX_ALUMNOS] ;
    int cant_estudiante = 0;

}