#include <iostream>
#include <vector>
#include "include/headers/asignacion.h"

using namespace std;

void cargar_tablero_puntaje(vector<vector<int>> & tablero) {
    tablero = {
        {4,7,8,9},
        {5,6,2,1},
        {7,5,3,2},
        {0,1,9,10}
    };
}

void cargar_tablero_partidos(vector<Partido> & partidos){

    partidos = {
        Partido(0,1),
        Partido(2,3)
    };
}

int main()
{

    vector<vector<int>> puntaje;
    cargar_tablero_puntaje(puntaje);

    vector<Partido> partidos;
    cargar_tablero_partidos(partidos);

    Solucion solucion;

    encontrarArbitroOptimo(puntaje, partidos, solucion);

    return 0;
}
