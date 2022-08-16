#include "Reinas.h"
#include <cmath>
/*
bool poda (int reinas[], int nro_reina) {
    int index = 0;
    while ( index < nro_reina ) {
        //dos reinas en la misma columna o en diagonal
        if ((reinas[index] == reinas[nro_reina]) || (nro_reina - index == abs(reinas[nro_reina] - reinas[index])))
            return true;
        index++;
    }
    return false;
}

bool backNReinas (int reinas[], int nro_reina, int cantidad_reinas) {
    if (nro_reina == cantidad_reinas) {
        return true;
    } else {
        int columna = 0;
        bool solucion = false;
        while (columna < cantidad_reinas && !solucion) {
            reinas[nro_reina]= columna;

            if (!poda(reinas, nro_reina)) {
                solucion = backNReinas(reinas, nro_reina + 1, cantidad_reinas);
            }

        columna++;
        }
        return solucion;
    }
}

bool resolver_back_reinas(unsigned int cantidad_reinas, int reinas[]) {
    for(unsigned int index=0; index < cantidad_reinas; index++)
        reinas[index] = 0;
    return backNReinas(reinas, 0, cantidad_reinas);
}*/

