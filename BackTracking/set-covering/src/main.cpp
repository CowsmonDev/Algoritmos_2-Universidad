#include <iostream>
#include "include/headers/set-covering_llaves.h"

using namespace std;

int main()
{

    Solucion solucion;
    solucion.cant_llaves = INT_MAX;

    devolverLlaves(solucion);

    return 0;
}
