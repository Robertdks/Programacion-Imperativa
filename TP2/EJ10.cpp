#include <iostream> 
#include <string>
#include <cstdlib> 
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
    int calificacion[4];
    int inacistencias ;
    int asistencias ;
};
struct Estudiante
{
    string legajo  ;
    Persona personal;
    Dato academico ;
};
string mayuscula(string palabra)
{
    int aux = palabra.length();
    for (int i = 0; i < aux;i++)
    {
        palabra [i] = toupper (palabra [i] ) ;
    }
    return palabra ;
}
float promedio_general (Estudiante array [], int dl)
{
    float suma = 0;
    for (int i = 0 ; i < dl ; i ++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            suma += array[i].academico.calificacion[j] ;
        }
    }
    return suma / dl ;
}
float promedio (Estudiante array[], int indice)
{
    float suma = 0 ; 
    for(int i = 0; i < 4 ; i++)
    {
        suma += array[indice].academico.calificacion[i];
    }
    return suma / 4 ;
}
void cargar_nota(Estudiante notas[],int dl)
{
    for(int i = 0; i < 4 ;i ++)
    {
        cout << i + 1  << " Cuatrimestre: ";
        cin >>notas[dl].academico.calificacion[i]; 
    }
}
void cargar_array(Estudiante array [], int & dl )
{
    string aux ;
    cout << "Ingrese el Nombre [ FIN ] para finalizar: " ;
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
        array[dl].legajo = array[dl].personal.DNI ;
        cargar_nota(array,dl) ;
        cout << "Cantidad de asistencias: " ;
        cin >> array[dl].academico.asistencias;
        cout << "Cantidad de inasistencias: " ;
        cin >> array[dl].academico.inacistencias ;
        dl ++ ;
        system("clear");
        cout << "Datos cargados con exito !" << endl ;
        cout << "Ingrese el Nombre [ FIN ] para finalizar: " ;
        getline(cin>>ws,aux) ;

    }
}
void Asistencia(Estudiante array[],int dl)
{
        for (int i = 0; i < dl ; i++)
        {
            if(array[i].academico.inacistencias > 5) 
            {  
                cout << "Nombre y Apellido: "  ;
                cout << array[i].personal.nombre <<" " ;
                cout << array[i].personal.apellido << endl ;
                cout << "DNI: " ;
                cout <<array[i].personal.DNI << endl ;
            }
        }
}
void Promedio_superior(Estudiante array[], int dl)
{
    cout << "Estudiantes con promedio mayor al de promedio general: " << endl ;
    for(int i = 0; i < dl ; i++)
    {
        if (promedio_general(array,dl) < promedio(array,i))
        {
            cout << "Numero de Legajo: " ;
            cout << array[dl].legajo ;
        }
    }
}
void opcionD(Estudiante array[], int dl)
{
    for(int i = 0; i < dl ; i++)
    {
        if (promedio(array,i) > 9)
        {
            cout << "Legajo: " << array[i].legajo << endl; 
        }
    }
}
bool opcionE(Estudiante array [], int & dl, string numero)
{
    string aux ;
    for(int i = 0; i < dl ; i++)
    {
        if (array[i].legajo == numero)
        {
            for(int j = 0; i < dl - 1; j++)
            {
                array[j] = array [j + 1];
            }
            dl -- ;
            return true ;
        }
    }
    return false  ;
}
void menu(Estudiante array [], int & dl) 
{
    string legajo ;
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
        system("clear") ;
        opcion = toupper(opcion);
        switch (opcion)
        {
        case 'A':
            cargar_array(array,dl) ;
            system("clear");
            break;
        case 'B':
            Asistencia(array,dl) ;
            break;
        case 'C':
            Promedio_superior(array,dl);
            break;
        case 'D':
            opcionD(array,dl);
            break;
        case 'E':
            cout << "Ingrese el legajo: ";
            getline(cin>>ws,legajo);
            if(opcionE(array,dl,legajo))
            {
                system("clear");
                cout <<"Estudiante eliminado!" << endl ;
            }
            else
            {
                system("clear");
                cout << "No se encontro el estudiante" << endl;
            }
            break;
        case 'F':
            cout << "Seccion finaliza, vuelva pronto" << endl;
            break;
        default:
            cout << "Error! ingrese una opcion valida" << endl;
            break;
        }
    } while (opcion != 'F');
}
int main ()
{
    Estudiante estudiantes[MAX_ALUMNOS] ;
    int cant_estudiante = 0;
    menu(estudiantes,cant_estudiante) ;
    return 0 ;
}