#ifndef caballo_atila
#define caballo_atila

#include <vector>
#include <iostream>
#include <utility>
#include <list>

using namespace std;

class Visitados{
	public:
		int cantidad;
		std::vector<std::vector<bool>> visitado;
		void modificarVisitado(int x, int y, bool valor, int cantidad);

};


void encontrarRecorrido(std::list<pair<int,int>> & solucion);

#endif
