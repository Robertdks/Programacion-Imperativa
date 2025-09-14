#include <iostream>
using namespace std ;
bool verificar_simetria(int matriz[][3], int filas, int columnas)
{
    //para que una matriz sea simetrica se necesita:
    // 1. La matriz debe ser cuadrada --> filas = columnas.
    // 2. La matriz debe ser igual a su transpuesta.
    // Primero verificamos que la matriz sea cuadrada:
    if (filas == columnas )
    {
        for (int i = 0; i < filas ; i++)
        {
            for(int j = 0; j < columnas ; j++)
            {
                if (matriz[i][j]!=matriz[j][i])
                {
                    return false ;
                }
            }
        }
    }
    return true ; // vamos asumir que la matriz que nos ingresan siempre va ser cuadrada.
}
void cargar_matriz(int matriz [][3],int filas , int columnas)
{
    for(int i = 0 ;i < filas ; i++)
    {
        for (int j = 0; j < columnas ; j++)
        {
            cout << "Ingrese un numero en la posicion [" << i <<"][" <<j<< "] : " ;
            cin >> matriz [i][j];
        }
        cout << endl ;
    }
}
void imprimir_matriz(int matriz [][3], int filas , int columnas)
{
    for(int i = 0; i < filas ; i++)
    {
        for(int j = 0; j < columnas ; j++)
        {
            cout << matriz[i][j] << "  ";
        }
        cout << endl ;
    }
}
int main()
{
    const int filas = 3 ;
    const int columnas = 3 ;
    int matriz [filas][columnas] = {} ;
    cargar_matriz(matriz,filas,columnas);
    if(verificar_simetria(matriz,filas,columnas))
    {
        cout << "La matriz: " << endl ;
        imprimir_matriz(matriz,filas,columnas);
        cout << endl << "Es simetrica." << endl ;
    }
    else
    {
        cout << "La matriz: " << endl ;
        imprimir_matriz(matriz,filas,columnas);
        cout << endl << "No es simetrica "<< endl ;
    }
    
}