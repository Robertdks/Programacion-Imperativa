#include <iostream>
using namespace std ;

void cargar_matriz(int matriz[][3],int filas, int columnas)
{
    for(int i  = 0; i < filas ; i++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {
            cout << "Ingrese un numero " << "[" << i << "]" << "[" << j <<"] : ";
            cin >> matriz[i][j] ;
            cout << endl ;
        }
    }
}
void imprimir_matriz(int matriz[][3],int filas, int columnas)
{
    for(int i = 0 ; i < filas ; i ++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl ;
    }
}
void suma_matriz(int matriz[][3],int matriz2[][3], int filas, int columnas, int suma[][3])
{
    for(int i = 0; i < filas ; i++)
    {
        for(int j = 0; j < columnas ; j++)
        {
            suma[i][j] = matriz[i][j]+matriz2[i][j];
        }
    }
}
int main()
{
    const int filas = 3 ;
    const int columnas = 3 ;
    int matriz[filas][columnas] ={};
    int matriz2[filas][columnas]= {};
    int suma[filas][columnas]={};
    cargar_matriz(matriz,filas,columnas);
    cargar_matriz(matriz2,filas,columnas);
    suma_matriz(matriz,matriz2,filas,columnas,suma);
    imprimir_matriz(suma,filas,columnas);
    return 0 ;
}
