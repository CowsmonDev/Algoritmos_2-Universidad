#include <iostream>
#include <vector>
#include "include/headers/asignacion.h"

using namespace std;

int main()
{

    Solucion solucion;
    solucion.puntajeTotal = 0;

    encontrarArbitroOptimo(solucion);

    return 0;
}
