#include <iostream>
using namespace std ;
void cargar_matriz(int matriz [7][10])
{
    for(int i = 0 ; i < 7 ; i++)
    {
        for(int j = 0; j < 10 ; j++)
        {
            cout << "Ingrese un numero " << "["<<i<<"]"<< "["<<j<<"]" << ": " ;
            cin >> matriz[i][j] ;
            cout << endl ;
        }
    }
}
void imprimir_matriz(int matriz[7][10])
{
    for(int i = 0 ; i < 7 ; i++)
    {
        for(int j = 0 ;j < 10; j++ )
        {
            cout << matriz[i][j]<<" ";
        }
        cout << endl ;
    }
}
int buscar_mayor(int matriz[7][10])
{
    int mayor = 0 ;
    for(int i = 0 ; i < 7; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            if(mayor < matriz[i][j])
            {
                mayor = matriz[i][j];
            }
        }
    }
    return mayor ;
}
int main()
{
    //int aux = 0 ;
    const int filas = 7 ;
    const int columnas = 10 ;
    //int suma = 0 ;
    int arreglo[filas][columnas] = {};
    arreglo[1][4]= 2 ;
    arreglo[2][4] = 1 ;
    arreglo[3][2] = 7 ;
    /*for (int  i = 0; i < columnas; i++)
    {
        arreglo[3][i] = 5 ;
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << arreglo[i][j] << " ";
        }
        cout << endl ;
    }*/
    /*for (int i = 0; i < filas; i++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {
            cout << arreglo[i][j] << " " ;
        }
        cout << endl ;
    }  
    cout << endl << endl << endl ; 
    for(int i = 0 ; i < filas ; i++)
    {
        aux = arreglo[i][4];
        arreglo[i][4] = arreglo[i][2] ;
        arreglo[i][2] = aux ;
    }
    for (int i = 0; i < filas; i++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {
            cout << arreglo[i][j] << " " ;
        }
        cout << endl ;
    }*/
   cargar_matriz(arreglo);
    /*for(int i = 0 ; i < columnas ; i++)
    {
        suma += arreglo[1][i] + arreglo[5][i] ;
    }
    cout <<"La suma de la fila 2 y fila 6 es: " << suma << endl ;
    imprimir_matriz(arreglo) ;
    for(int i = 0 ; i < filas ; i++)
    {
        cout << arreglo[i][2] << " ";
    }*/
    cout << "El numero con  valor mas grande de la matriz es: " << buscar_mayor(arreglo) << " ."<< endl;
    return 0 ;
}