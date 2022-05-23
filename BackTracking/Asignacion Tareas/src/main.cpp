#include <iostream>
#include "include/headers/asignacion_tareas.h"

using namespace std;

int main( )
{
    Solucion solucion;
    solucion.costo = INT_MAX;
    solucion.solucion = {0,0,0,0};
    asignacion_tareas(solucion);
    return 0;
}
