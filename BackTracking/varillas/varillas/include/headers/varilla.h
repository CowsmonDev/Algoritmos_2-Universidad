//
// Created by agust on 10/12/2022.
//

#ifndef VARILLAS_VARILLA_H
#define VARILLAS_VARILLA_H

#include <vector>

struct Solucion{
    int cant_varillas;
    std::vector<float> solucion;
};

void devolverVarillas(Solucion & solucion, float M);

#endif //VARILLAS_VARILLA_H
