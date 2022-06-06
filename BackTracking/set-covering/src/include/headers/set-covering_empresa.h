#ifndef set_covering_empresa
#define set_covering_empresa

#include <list>
#include <utility>
struct SolucionEmpresa{
	int cantidad_empleados;
	//std::map<std::string,int> solucion;
	std::list<std::pair<std::string, int>> solucion;
};

void devolverEmpleados(SolucionEmpresa & solucion);

#endif
