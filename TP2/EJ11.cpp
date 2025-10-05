#include <iostream>
#include <string>
#include <cstdlib>
using namespace std ;
const int DF = 1000 ;
struct Persona 
{
    string nombre ;
    string apellido ;
    char genero ;
    long fecha_nacimiento[3] ;
};
struct Documento
{
    string numero;
    string tipo_documento;
};

struct Dato
{
    Documento documento;
    Persona persona ;
    string direccion ;
};
string mayuscula(string texto)
{
    int aux = texto.length();
    for (int i = 0; i < aux ;i++)
    {
        texto[i] = toupper(texto[i]);
    }
    return texto ;
}
string mostrar_genero(char genero )
{
    if (toupper(genero) == 'M')
    {
        return "Masculino";
    }
    else 
    {
        return "Femenino";
    }
}
bool Tipo_documento (Dato array[], int dl)
{
    int opcion ;
    cout << " [1] DNI" << endl;
    cout << " [2] Pasaporte" << endl;
    cout << " [3] Otro" << endl ;
    cout << " Opcion: " ;
    cin >> opcion ;
    system("clear");
    switch (opcion)
    {
        case 1 :
           cout << "DNI: " ;
           array[dl].documento.tipo_documento= "DNI";
           getline(cin >>ws, array[dl].documento.numero);
           return true ;
         break ;
        case 2 :
            cout << "Pasaporte: ";
            array[dl].documento.tipo_documento = "Pasaporte" ;
            getline(cin >>ws ,array[dl].documento.numero);
            return true ;
         break ;
        case 3 :
            cout << "Ingrese el Lista de documento: ";
            getline(cin >> ws,array[dl].documento.tipo_documento) ;
            cout << "Ingrese el Numero: " ;
            getline(cin >>ws, array[dl].documento.numero);
            return true ;
         break ;
        default :
            cout << "Error! Ingrese una opcion valida" << endl ;
            return false ;
         break ;

    }
    return false ;
}
void ingresar_fecha(Dato array[], int dl)
{
    string fecha [3] = {"Año","Mes","Dia"} ;
    for (int i = 0; i < 3 ; i++)
    {
        cout << fecha[i] <<": ";
        cin >> array[dl].persona.fecha_nacimiento[i];
    }
    system("clear");
}
void mostrar_fecha(Dato array[],  int posicion)
{
    for(int i = 0 ; i < 3 ;i++)
    {
        cout << array[posicion].persona.fecha_nacimiento[i] ;
        if(i != 2)
        {
            cout << "/";
        }
    }
    cout << endl ;
}
void cargar_array(Dato array [], int & dl, int DF)
{
    string aux ;
    cout << "Ingrese el nombre [Fin] para finalizar: ";
    getline(cin>>ws,aux);
    while(mayuscula(aux) != "FIN" && dl < DF)
    {
        array[dl].persona.nombre = aux ;
        cout << "Ingrese el apellido: " ;
        getline(cin>>ws,array[dl].persona.apellido);
        cout << "Ingrese el genero [F/M]: ";
        cin >> array[dl].persona.genero ;
        cout << "Ingrese la fecha de nacimiento: " << endl;
        ingresar_fecha(array,dl);
        cout << "Ingrese el Lista de documento " << endl ;
        if(Tipo_documento(array,dl) != true)
        {
            while (Tipo_documento(array,dl) != true); 
        }
        cout << "Ingrese su Direccion: " ;
        getline(cin >>ws,array[dl].direccion );
        dl ++;
        cout << "Ingrese el nombre [Fin] para finalizar: ";
        getline(cin>>ws,aux);
    }
}
void mostrar_personas(Dato array[], int dl)
{
    cout << "----- Lista de Personas ingresadas -----" << endl ;
    for (int i = 0; i < dl ; i++)
    {
        cout << "Nombre y Apellido: " << array[i].persona.nombre<< " " << array[i].persona.apellido << endl;
        cout << "Direccion: " <<array[i].direccion << endl ;
        cout << "Fecha de nacimiento: " ;
        mostrar_fecha(array,i);
        cout << "Tipo de documento: " << array[i].documento.tipo_documento << endl;
        cout << "Numero de documento: " <<array[i].documento.numero << endl;
        cout << "Sexo: " << mostrar_genero(array[i].persona.genero) << endl ;
    }
}
void cant_filtro (Dato array [], int dl, int & cantidad ,char genero)
{
    for (int i = 0; i < dl ;i ++)
    {
        if (array[i].persona.genero == genero)
        {
            cantidad ++ ;
        }
    }

}
void filtrar (Dato array [],int dl, char genero)
{
    int cantidad = 0;
    int aux = 0;
    cant_filtro(array,dl,cantidad,genero) ;
    Dato Lista[cantidad] ;
    for (int i = 0; i < dl ; i++)
    {
        if(array[i].persona.genero == genero)
        {
            Lista[aux] = array[i];
            aux ++ ;
        }
    }
    cout <<"Lista de personas con genero  " << mostrar_genero(genero) << endl;
    cout << endl ;
    for(int i = 0;  i < cantidad ; i ++)
    {
        cout <<"Nombre y Apellido: "<<Lista[i].persona.nombre <<" "<<Lista[i].persona.apellido << endl;
        cout <<"Fecha de Nacimiento: ";
        mostrar_fecha(Lista,i) ;
        cout <<"Direccion: "<<Lista[i].direccion<< endl ;
        cout <<"Tipo de documento "<<Lista[i].documento.tipo_documento <<endl ;
        cout <<"Numero de documento: "<<Lista[i].documento.numero <<endl ;
        cout <<"Genero "<<mostrar_genero(Lista[i].persona.genero) <<endl ;
    }
}
void buscar_persona(Dato arreglo[], int dl, string numero_documento)
{
    for(int i = 0; i < dl ; i++)
    {
        if (arreglo[i].documento.numero == numero_documento)
        {
            cout << "---- Persona encontrada ----" << endl ;
            cout <<"Nombre y Apellido: " << arreglo[i].persona.nombre << " "<< arreglo[i].persona.apellido << endl;
            cout << "Fecha de nacimiento: " ;
            mostrar_fecha(arreglo,i) ;
            cout <<"Tipo de documento: " <<arreglo[i].documento.tipo_documento << endl ;
            cout <<"Numero de documento: " << arreglo[i].documento.numero << endl;
            cout <<"Direccion: " << arreglo[i].direccion ;
            cout << "genero: " << mostrar_genero(arreglo[i].persona.genero)<< endl;

        }
    }
}
void menu(Dato arreglo[], int & dl , int DF)
{
    char opcion ;
    char genero ;
    string numero ;
    do 
    {
        cout << "--- Bienvenido --- " << endl ;
        cout << " [A] - Ingresar datos" << endl ;
        cout << " [B] - Mostrar datos ingresados" << endl ;
        cout << " [C] - Filtrar" << endl ;
        cout << " [D] - Buscar Persona " << endl ;
        cout << " [E] - Salir" << endl ;
        cout << " Ingrese una opcion: " ;
        cin >> opcion ;
        opcion = toupper(opcion);
        switch (opcion)
        {
        case 'A':
            cargar_array(arreglo,dl,DF) ;
            system("clear");
            break;
        case 'B':
            system("clear");
            mostrar_personas(arreglo,dl);
            break;
        case 'C':
            cout <<"Ingrese el genero que desea filtrar: " ;
            cin >> genero ;
            system("clear");
            genero = toupper(genero);
            if (genero == 'M')
            {
                filtrar(arreglo,dl,genero);
            }
            else
            {
                filtrar(arreglo,dl,genero) ;
            }
            break;
        case 'D':
            cout << "Ingrese el Numero de documento: ";
            cin >> numero ;
            system("clear");
            buscar_persona(arreglo,dl,numero);
            break;
        case 'E':
            system("clear");
            cout <<"Hasta luego!" << endl ;
            break;
        default:
            system("clear");
            cout << "Error! ingrese una opcion valida" ;
            break;
        }
    } while(opcion != 'E') ;
}
int main()
{ 
    Dato arreglo[DF] ;
    int dl = 0;
    menu(arreglo,dl,DF) ;
    return 0;
}