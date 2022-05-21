#include "ReinasExtendido.h"

#include "Reinas.h"
#include <cmath>
#include <vector>

using namespace std;

bool poda (vector<int> reinas, int nro_reina) {
    int index = 0;
    while ( index < nro_reina ) {
        //dos reinas en la misma columna o en diagonal
        if ((reinas[index] == reinas[nro_reina]) || (nro_reina - index == abs(reinas[nro_reina] - reinas[index])))
            return true;
        index++;
    }
    return false;
}

void backNReinas (int ** tablero, int nro_reina, int cantidad_reinas, Solucion & actual, Solucion & mejor, int & cantidad_estados) {
    cantidad_estados++;

    // Estado solucion / final
    if (nro_reina == cantidad_reinas) {
        //Ver si la solución encontrada (actual) es mejor que la "mejor" solución hasta el momento.
        if (actual.puntaje < mejor.puntaje)
            mejor = actual;
    } else {
        int columna = 0;
        while (columna < cantidad_reinas) {
            actual.puntaje += tablero[nro_reina][columna];
            actual.reinas[nro_reina]= columna;

            if (!poda(actual.reinas, nro_reina) && (actual.puntaje < mejor.puntaje)) {
                backNReinas(tablero, nro_reina + 1, cantidad_reinas, actual, mejor, cantidad_estados);
            }

            actual.puntaje -= tablero[nro_reina][columna];
            actual.reinas[nro_reina]= 0;

        columna++;
        }
    }
}

Solucion resolver_back_reinas(int ** tablero, unsigned int cantidad_reinas) {
    Solucion mejor;
    mejor.puntaje = INT_MAX;
    mejor.reinas = vector<int>(cantidad_reinas, 0);

    Solucion actual;
    actual.puntaje = 0;
    actual.reinas = vector<int>(cantidad_reinas, 0);

    int cantidad_estados = 0;
    backNReinas(tablero, 0, cantidad_reinas, actual, mejor, cantidad_estados);
    mejor.cantidad_estados = cantidad_estados;

    return mejor;
}


