#include <iostream>
using namespace std ;
bool buscar_elemto(int matriz[][3],int filas , int columnas, int dato,int & filaEncontrada,int  & ColEncontrada)
{
    for (int i = 0; i < filas ; i++)
    {
        for (int j = 0; j < columnas ; j++)
        {
            if (matriz[i][j] == dato)
            {
                filaEncontrada = i ;
                ColEncontrada = j ;
                return true ;
            }
        }
    }
    return false ;
}
void cargar_matriz(int matriz[][3], int filas, int columnas)
{
    for(int i = 0 ;i < filas ; i++)
    {
        for(int j = 0; j < columnas ;j++)
        {
            cout << "Ingrese un numero posicion [" << i <<"]["<<j<<"] : " ;
            cin >> matriz [i][j] ;
        }
        cout << endl ;
    }
}
int main()
{
    const int filas = 3 ;
    const int columnas = 3 ;
    int matriz[filas][columnas]={};
    int dato = 0;
    int fila = 0 ;
    int columna = 0 ;
    cargar_matriz(matriz,filas,columnas);
    cout << "Ingrese un numero que desea buscar en la matriz: " ;
    cin >> dato ;
    cout << endl ;
    if(buscar_elemto(matriz,filas,columnas,dato,fila,columna))
    {
        cout << "El numero '"<< dato << "' se encuentra en el arreglo en la posicion: [" << fila << "][" << columna << "]" << endl ;
    }
    else
    {
        cout << "El numero '" << dato << "' no se encuentra en la matriz." <<endl ;
    }
    return 0 ;
}