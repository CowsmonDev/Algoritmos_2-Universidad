#include "headers/vertex_cover.h"
#include <list>

using namespace std;

void vertexCover(Grafo<int> & g, set<int> & solucion){
	list<int> vertices;
	g.devolver_vertices(vertices);
	for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++){
		list<Grafo<int>::Arco> a; 
		g.devolver_adyacentes(*it, a);

		if(solucion.find(*it) != solucion.end()){
			solucion.insert(*it);
			g.eliminar_arcos(*it);
		}

		bool terminar = false;
		for(list<Grafo<int>::Arco>::iterator it_a = a.begin(); (it_a != a.end()) && !terminar; it_a++){
			if(solucion.find(it_a->getAdyacente()) != solucion.end()){
				solucion.insert(it_a->getAdyacente());
				g.eliminar_arcos(it_a->getAdyacente());
				terminar = true;
			}
		}
	}
}