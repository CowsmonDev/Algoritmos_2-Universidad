#include <iostream>
#include "include/headers/Grafo.h"

using namespace std;

int main()
{

    Grafo<int> g;

    g.agregar_vertice(1);
    g.agregar_vertice(2);
    g.agregar_vertice(3);
    g.agregar_vertice(4);
    g.agregar_vertice(5);
    g.agregar_vertice(6);
    g.agregar_vertice(7);

    g.agregar_arco(1,2,20);
    g.agregar_arco(1,3,30);
    g.agregar_arco(1,5,50);
    g.agregar_arco(1,6,60);

    list<int> v;
    g.devolver_vertices(v);

    for(auto e : v){
        cout<<e<<endl;
    };

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

    list<Grafo<int>::Arco> la;
    g.devolver_adyacentes(1,la);

    for(auto a : la){
        cout<<a.getAdyacente()<<endl;
    };

    return 0;
}
