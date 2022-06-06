#include <iostream>
#include "include/headers/set-covering_llaves.h"
#include "include/headers/set-covering_empresa.h"

using namespace std;

int main()
{

    Solucion solucion;
    solucion.cant_llaves = INT_MAX;

    //devolverLlaves(solucion);

    SolucionEmpresa solucion2;
    devolverEmpleados(solucion2);

    return 0;
}
