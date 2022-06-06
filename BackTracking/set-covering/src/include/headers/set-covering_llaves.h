#ifndef set_covering
#define set_covering
#include <set>
#include <vector>
struct Solucion{
	int cant_llaves;
	std::vector<int> solucion;
};

void devolverLlaves(Solucion & solucion);

#endif 