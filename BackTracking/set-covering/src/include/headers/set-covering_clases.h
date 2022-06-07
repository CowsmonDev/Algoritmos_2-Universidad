#ifndef set_covering_clase
#define set_covering_clase

#include <iostream>
#include <set>
#include <list>

using namespace std;

struct SolucionClases{
	int cantidad_empleados;
	list<pair<string, int>> solucion;
};

class Empleado{
	public:
		Empleado(){};
		Empleado(int empleado, bool seleccionado, set<string> habilidades);
		virtual ~Empleado(){};
		void imprimirEmpleado();
		set<string> habilidades;
		bool seleccionado;
		int empleado;
};

void devolverEmpleados(SolucionClases & solucion);

#endif