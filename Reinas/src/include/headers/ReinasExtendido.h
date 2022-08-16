#ifndef REINASEXTENDIDO_H
#define REINASEXTENDIDO_H
#include <vector>

struct Solucion {
    int puntaje;
    std::vector<int> reinas;
    int cantidad_estados;
};

Solucion resolver_back_reinas(int ** tablero, unsigned int cantidad_reinas);

#endif // REINASEXTENDIDO_H
