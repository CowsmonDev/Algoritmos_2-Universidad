#include <iostream>
#include "include/headers/devolver_cajones.h"

using namespace std;

int main()
{

    list<Cajon> soluciones;

    cajonesFirstFit(soluciones, 1);
    mostrarElementos(soluciones);

    cout<<endl<<"================"<<endl;

    cajonesFirstFitDecreasing(soluciones, 1);
    mostrarElementos(soluciones);

    cout<<endl<<"================"<<endl;

    cajonesNextFit(soluciones, 1);
    mostrarElementos(soluciones);

    return 0;
}
