#include <iostream>
using namespace std ;

const int FILAS = 5;
const int COLUMNAS = 10;

void ver_lugares(int matriz[FILAS][COLUMNAS],int fil,int col)
{
    for(int i = 0; i < fil ; i++)
    {
        for(int j=0; j < col ;j++)
        {
            if (matriz [i][j] == 0)
            {   
                cout << "[" << i << "][" << j << "] " ;
                cout << "free   " ;
            }
            else 
            {
                cout << "[" << i << "][" << j << "] " ;
                cout << "busy   ";
            }
        }
        cout << endl ;
    }
}
bool verificar_disponible(int matriz [FILAS][COLUMNAS],int fil, int col)
{
    for (int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col ;j++)
        {
            if (matriz [i][j] == 0)
            {
                return true ;
            }
        }
    }
    return false ;
}
void elegir_lugar(int matriz[FILAS][COLUMNAS],int fil,int col,int & fila, int & columna)
{
    ver_lugares(matriz,fil,col) ;
        cout << endl ;
        cout << "ingrese la posicion a vender[fila][columna]: " << endl ;
        cout << "fila: ";
        cin >> fila;
        cout << "columna: ";
        cin >> columna ;
        if(fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) //Verificacion para que no nos ingresen valores invalidos
        {
        cout << "Posición inválida. Por favor ingrese valores correctos.\n";
        return; // salir de la función sin modificar nada
        }
}
void vender_entrada(int matriz[FILAS][COLUMNAS],int fil, int col)
{
    int fila = 0;
    int columna = 0;
    if (verificar_disponible(matriz,fil,col))
    {
        cout << "Se encontro lugares libres, a continuacion se ven los mismos. "<< endl ;
        elegir_lugar(matriz,fil,col,fila,columna);
        if (matriz[fila][columna] == 0)
        {
        matriz[fila][columna] = 1;
        cout << "Venta realizado con exito! "<< endl ;
        }    
        else
        {
        cout << "El lugar se encuentra ocupado, por favor realice de nuevo la operacion. "<< endl ;
        }
    }
    else
    {
        cout << "No quedan lugares disponibles. "<< endl ;
    }
}
int main ()
{
    int matriz [FILAS][COLUMNAS] ={}; //.

    //Incorporamos un menu para que nuestro progama sea mas estructurado.
    //opciones del menu
    //ver lugares disponible.
    //vender entradas
    //Salir del portal de ventas
    // declaramos variables para llevar a cabo el menu
    char caracter ;
    do
    {
        cout <<" O P C I O N E S "<< endl ;
        cout <<"'A' Ver lugares disponibles. "<< endl ;
        cout <<"'B' Vender entradas. "<< endl ;
        cout <<"'C' Salir del portal de ventas."<< endl ;
        cin >> caracter ;
        caracter = toupper(caracter);
        switch (caracter)
        {
        case 'A':
            ver_lugares(matriz,FILAS,COLUMNAS);
            break;
        case 'B':
            vender_entrada(matriz,FILAS,COLUMNAS);
            break;
        case 'C':
            cout << "Venta terminada!"<< endl ;
            break;
        default:
            cout << "Ingrese una opcion valida"<< endl ;
            break;
        }
    } while (caracter != 'C');
   return 0 ; 
}