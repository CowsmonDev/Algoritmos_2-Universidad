#include <iostream>
#include "include/headers/mochila.h"

using namespace std;

int main()
{

    list<ObjetoMochila> objetos = {
        //ObjetoMochila(9, 9),
        //ObjetoMochila(4, 4),
        //ObjetoMochila(7, 7),
        //ObjetoMochila(2, 2),
        ObjetoMochila(5, 5),
        ObjetoMochila(8, 8),
        ObjetoMochila(1, 1),
        ObjetoMochila(3, 3),
        ObjetoMochila(6, 6)
    };

    Mochila mochila(10);

    obtenerMochilaAproximada(mochila, objetos, 2);

    cout<<mochila.toString()<<endl;

    return 0;
}
