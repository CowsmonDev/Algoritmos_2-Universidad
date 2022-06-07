#include <iostream>
#include "headers/set-covering_empresa.h"
#include <set>
#include <vector>

using namespace std;

bool poda(set<string> habilidades, string lenguaje, int cantidadActual, int cantidadSolucion){
	if(cantidadActual < cantidadSolucion)
		if(habilidades.find(lenguaje) != habilidades.end())
			return false;
	return true;
}
		/*el par controla si la persona ya fue requerida*/
void setCovering(vector<pair<bool,set<string>>> & tablero, list<string> lenguaje, SolucionEmpresas Actual, SolucionEmpresas & solucion){
	if (lenguaje.empty())
		solucion = Actual;
	else{
		string lenguajeActual = lenguaje.front(); lenguaje.pop_front();

		bool bandera = false;
		for(int i = 0; i < tablero.size(); i++){
			if(!poda(tablero.at(i).second, lenguajeActual, Actual.cantidad_empleados, solucion.cantidad_empleados)){
				if(!tablero.at(i).first){
					Actual.cantidad_empleados++;
					tablero[i].first = true;
					bandera = true;
				}
				Actual.solucion.push_back({lenguajeActual,i});
				setCovering(tablero,lenguaje,Actual,solucion);
				if(bandera){
					Actual.cantidad_empleados--;
					tablero[i].first = false;
				}
				Actual.solucion.pop_back();
				bandera = false;
			}
		}
	}
}

void devolverEmpleados(SolucionEmpresas & solucion){
	SolucionEmpresas Actual;
	Actual.cantidad_empleados = 0;

	solucion.cantidad_empleados = INT_MAX; //serializo la solucion para evitar errores

	list<string> lenguaje({"Java", "Prolog", "Ruby", "C++", "Fortran", "JavaScript", "Python", "Perl", "Smalltalk", "PHP", "Typescript", "Pascal"});

	//solucion: 0, 4, 7 - 3 personas;
	vector<pair<bool,set<string>>> tablero = {
		{false,set<string>({"Java", "Prolog", "C++", "Fortran"})},
		{false,set<string>({"C++", "Python", "PHP"})},
		{false,set<string>({"Prolog", "Ruby"})},
		{false,set<string>({"Prolog", "Fortran", "Perl", "Typescript"})},
		{false,set<string>({"Ruby", "JavaScript", "Smalltalk"})},
		{false,set<string>({"Fortran", "JavaScript", "Perl", "Smalltalk", "Typescript", "Pascal"})},
		{false,set<string>({"PHP", "Typescript", "Pascal"})},
		{false,set<string>({"Python", "Perl", "Smalltalk", "PHP", "Typescript", "Pascal"})}
	};

	setCovering(tablero,lenguaje,Actual, solucion);

	cout<<solucion.cantidad_empleados<<endl;

}
