#include <iostream>
#include "ReinasExtendido.h"

using namespace std;

int ** crear_tablero_puntaje(unsigned int cantidad_reinas) {
    int ** tablero = new int*[cantidad_reinas];
    for (unsigned int i=0; i < cantidad_reinas; i++)
        tablero[i] = new int[cantidad_reinas];
    return tablero;
}


void cargar_tablero_puntaje(int ** tablero) {
    //Este proceso debería ser dinámico
    tablero[0][0] = 3;
    tablero[0][1] = 8;
    tablero[0][2] = 4;
    tablero[0][3] = 9;
    tablero[1][0] = 4;
    tablero[1][1] = 5;
    tablero[1][2] = 10;
    tablero[1][3] = 8;
    tablero[2][0] = 5;
    tablero[2][1] = 3;
    tablero[2][2] = 4;
    tablero[2][3] = 2;
    tablero[3][0] = 4;
    tablero[3][1] = 2;
    tablero[3][2] = 5;
    tablero[3][3] = 3;
}

int main()
{
    unsigned int cantidad_reinas = 0;
    cout << "Ingrese la cantidad de reinas del tablero: ";
    //cin >> cantidad_reinas;
    cantidad_reinas = 4;
    int reinas[cantidad_reinas];

    int ** tablero = crear_tablero_puntaje(cantidad_reinas);
    cargar_tablero_puntaje(tablero);

    Solucion solucion = resolver_back_reinas(tablero, cantidad_reinas);

    if (solucion.puntaje < INT_MAX) {
        cout << "El tablero se pudo resolver." << endl;
        cout << "El puntaje obtenido es: " << solucion.puntaje << endl;
        cout << "Cantidad de estados: " << solucion.cantidad_estados << endl;
        for(unsigned int i=0; i < cantidad_reinas; i++)
            cout << "Reina " << i << " en columna: " << solucion.reinas[i] << endl;
    } else {
        cout << "No hay solución para el tablero.";
    }
    cout << endl;
    return 0;
}
