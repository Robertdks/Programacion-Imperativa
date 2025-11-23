#include <iostream>
#include <string>
#include <cctype>
using namespace std ;
struct Auto
{
    int velocidad ;
    string patente ;
    string radar ;
} ;
struct Nodo 
{
    Auto dato ;
    Nodo * siguiente ;
};
string Mayuscula(string texto)
{
    int n = texto.length();
    for (int i = 0; i < n ; i++)
    {
        texto[i] = toupper(texto[i]) ;
    }
    return texto ;
}
void RegistrarRadar(Nodo * & Nuevo )
{
    int n ;
    do
    {
        cout <<"1 - Sur  2 - Medio  3 - Norte " << endl ;
        cout <<"Seleccione una opcion: " ;
        cin >> n ;
        switch (n)
        {
        case 1:
            Nuevo->dato.radar = "Sur" ;
            break;
        case 2:
            Nuevo->dato.radar = "Medio" ;
            break;
        case 3:
            Nuevo->dato.radar = "Norte" ;
            break;
        default:
            cout <<"Error!, ingrese una opcion valida!" << endl;
            break;
        }
    } while (n != 1 && n != 2 && n != 3);
}
void InsertarNodo(Nodo * & Lista, Nodo * Nuevo)
{
    if (Lista == nullptr || Lista->dato.patente > Nuevo->dato.patente)
    {
        Nuevo->siguiente = Lista ;
        Lista = Nuevo ;
        return ;
    }
    Nodo * temp = Lista ;
    while (temp->siguiente != nullptr && temp->siguiente->dato.patente < Nuevo->dato.patente)
    {
        temp = temp->siguiente ;
    }
    Nuevo->siguiente = temp->siguiente ;
    temp->siguiente = Nuevo ;   
}
void RegistrarVelocidad(Nodo *  & Nuevo)
{
    cout << "Ingrese la velocidad del auto [km/h] : " ;
    cin >> Nuevo->dato.velocidad;
    while (Nuevo->dato.velocidad < 0)
    {
        cout <<"Error! Ingrese una velocidad valida!" << endl ;
        cout << "Ingrese la velocidad del auto [km/h] : " ;
        cin >> Nuevo->dato.velocidad;
    }
}
void VerificarPatente(Nodo * & Nuevo)
{
    int n = 5 ;
    int np = Nuevo->dato.patente.length() ;
    while ( np != n)
    {
        cout << "Error, Ingrese un patente valido!" ;
        getline(cin>>ws,Nuevo->dato.patente) ;
    }   
}
void CargarLista(Nodo * & Lista)
{
    string patente ;
    cout <<"Ingrese la patente del auto [AAA99] para finalizaar: ";
    getline(cin>>ws,patente);
    while (Mayuscula(patente)!= "AAA99")
    {
        Nodo * Nuevo = new Nodo ();
        Nuevo->dato.patente = patente ;
        VerificarPatente(Nuevo) ;
        RegistrarRadar(Nuevo);
        RegistrarVelocidad(Nuevo) ;
        Nuevo->siguiente = nullptr ;
        InsertarNodo(Lista,Nuevo) ;
        cout <<"Ingrese la patente del auto [AAA99] para finalizar: ";
        getline(cin>>ws,patente);
    }

}
Nodo * GenerarNodo(Nodo * temp )
{
    Nodo * Nuevo = new Nodo () ;
    Nuevo->dato = temp->dato ;
    Nuevo->siguiente = nullptr ;
    return Nuevo ;  
}
void FiltrarLista(Nodo *  Lista , Nodo * & Radar1, Nodo * & Radar2 , Nodo *& Radar3)
{
    Nodo * temp = Lista ;
    char radar ;
    while (temp != nullptr)
    {
        radar = toupper(temp->dato.radar[0]) ;
        switch (radar)
        {
        case 'S':
            InsertarNodo(Radar1,GenerarNodo(temp)) ;
            break;
        case 'M':
            InsertarNodo(Radar2,GenerarNodo(temp)) ;
            break;
        case 'N':
            InsertarNodo(Radar3,GenerarNodo(temp)) ;
            break;
        }
        temp = temp->siguiente ;

    }
    
}
void MostrarLista(Nodo * Lista)
{
    if(Lista != nullptr)
    {
        Nodo * temp = Lista ;
        while (temp != nullptr)
        {
            cout <<"Patente: "<< temp->dato.patente << endl;
            cout <<"Radar: "<<temp->dato.radar << endl;
            cout <<"Velocidad: "<<temp->dato.velocidad <<" Km/h" <<endl ;
            temp = temp->siguiente ;
        }
    }
    else
    {
        cout <<"La Lista se encuentra vacia!!" << endl ;    ;
    }
}
void MostrarMenu(Nodo * & Lista, Nodo * & RadarSur, Nodo * & RadarMedio, Nodo *& RadarNorte) 
{
    int opcion;

    do {
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "1. Cargar lista de autos\n";
        cout << "2. Filtrar listas por radar (Sur, Medio, Norte)\n";
        cout << "3. Mostrar lista completa\n";
        cout << "4. Mostrar lista Radar Sur\n";
        cout << "5. Mostrar lista Radar Medio\n";
        cout << "6. Mostrar lista Radar Norte\n";
        cout << "0. Salir\n";
        cout << "====================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                CargarLista(Lista);
                break;

            case 2:
                FiltrarLista(Lista, RadarSur, RadarMedio, RadarNorte);
                cout << "Listas generadas correctamente.\n";
                break;

            case 3:
                cout << "\n--- LISTA COMPLETA ---\n";
                MostrarLista(Lista);
                break;

            case 4:
                cout << "\n--- RADAR SUR ---\n";
                MostrarLista(RadarSur);
                break;

            case 5:
                cout << "\n--- RADAR MEDIO ---\n";
                MostrarLista(RadarMedio);
                break;

            case 6:
                cout << "\n--- RADAR NORTE ---\n";
                MostrarLista(RadarNorte);
                break;

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 0);

}
int main() 
{
    Nodo * Lista = nullptr;
    Nodo * RadarSur = nullptr;
    Nodo * RadarMedio = nullptr;
    Nodo * RadarNorte = nullptr;
    MostrarMenu(Lista,RadarSur,RadarMedio,RadarNorte) ;
    return 0;
}
