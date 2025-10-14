//Escribir y luego ejecutar las instrucciones necesarias para:
//a) Declarar una variable puntero a Venta y reservar memoria.
//b) Pedir al usuario que ingrese una cantidad vendida, descripción de producto y precio de producto,
//almacenando los datos en la Venta apuntada por el puntero declarado en el inciso anterior.
//c) Restar un 15% al precio del Producto guardado en la Venta apuntada por el puntero.
//d) Imprimir la descripción del producto dentro de la Venta y monto total (precio del producto * cantidad).
#include <iostream>
#include <iostream>
using namespace std ;

struct Producto
{
    string descripcion ;
    float precio ;
};
struct Venta
{
    Producto producto ;
    int cantidad ;
};
int main()
{
    float porcentaje = 0;
    Venta * venta = new Venta ;
    cout <<"Ingrese la cantidad vendida: " ;
    cin >> venta->cantidad ;
    cout <<"Ingrese la descripción del producto: " ;
    getline(cin >>ws, venta->producto.descripcion );
    cout << "Ingrese el precio del Producto: " ;
    cin >> venta->producto.precio ;
    porcentaje = venta->producto.precio * 15 / 100 ;
    venta->producto.precio = porcentaje ;
    cout << "Descripción del producto: " ;
    cout <<venta->producto.descripcion << endl ;
    cout <<"Monto total: $ " ;
    cout << venta->producto.precio * venta->cantidad << endl ;
    return 0 ;
}