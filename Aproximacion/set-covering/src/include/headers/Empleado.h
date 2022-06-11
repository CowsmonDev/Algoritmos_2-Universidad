#ifndef header_empleados
#define header_empleados

#include <list>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Empleado{
	
	public:
		Empleado(){};
		Empleado(string empleado){
			this->empleado = empleado;
			this->seleccionado = false;
		};
		Empleado(string empleado, set<string> habilidades){
			this->empleado = empleado;
			this->seleccionado = false;
			this->habilidades = habilidades;
		};
		virtual ~Empleado(){};

		int getCantidadHabilidades(){ return this->habilidades.size(); };
		string getEmpleado(){ return this->empleado; };
		bool getSeleccionado(){ return this->seleccionado; };
		set<string> getHabilidades(){ return this->habilidades; };

		void setSeleccionado(bool seleccionado){ this->seleccionado = seleccionado; };

		bool operator<(Empleado & other){ return (getCantidadHabilidades() < other.getCantidadHabilidades()); };
		bool operator==(Empleado & other){ return (this->empleado == other.getEmpleado()); };

	private:
		set<string> habilidades;
		bool seleccionado;
		string empleado;
};

#endif