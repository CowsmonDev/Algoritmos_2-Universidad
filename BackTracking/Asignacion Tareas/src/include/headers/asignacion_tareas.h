#ifndef tareas
#define tareas
#include <vector>

struct Solucion{
	int costo;
	std::vector<int> solucion;
};

void asignacion_tareas(Solucion & solucion);

#endif