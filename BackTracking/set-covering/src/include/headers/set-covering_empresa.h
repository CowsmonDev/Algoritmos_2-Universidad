#ifndef set_covering_empresa
#define set_covering_empresa

#include <list>
#include <utility>
#include <iostream>
struct SolucionEmpresas{
	int cantidad_empleados;
	//std::map<std::string,int> solucion;
	std::list<std::pair<std::string, int>> solucion;
};

void devolverEmpleados(SolucionEmpresas & solucion);

#endif
