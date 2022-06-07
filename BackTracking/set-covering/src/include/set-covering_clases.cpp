#include "headers/set-covering_clases.h"

using namespace std;

Empleado::Empleado(int empleado, bool seleccionado, set<string> habilidades){
	this->empleado = empleado;
	this->seleccionado = seleccionado;
	this->habilidades = habilidades;
}

void Empleado::imprimirEmpleado(){
	cout<<"Empleado: "<< this->empleado <<" Habilidades: ";
	for(set<string>::const_iterator it = habilidades.begin(); it != habilidades.end(); it++){
		cout<<*it<<" - ";
	}
	cout<<endl;
}

bool podaClases(set<string> habilidades, string lenguaje, int cantidadActual, int cantidadSolucion){
	if(cantidadActual < cantidadSolucion)
		if(habilidades.find(lenguaje) != habilidades.end())
			return false;
	return true;
}

void setCoveringClases(list<Empleado> & tablero, list<string> lenguaje, SolucionClases Actual, SolucionClases & solucion){
	if(lenguaje.empty()){
		solucion = Actual;
	}else{
		string lenguajeActual = lenguaje.front(); lenguaje.pop_front();
		bool bandera = false;
		for(list<Empleado>::iterator it = tablero.begin(); it != tablero.end(); it++){
			if(!podaClases(it->habilidades, lenguajeActual, Actual.cantidad_empleados, solucion.cantidad_empleados)){
				if(!it->seleccionado){
					Actual.cantidad_empleados++;
					it->seleccionado = true;
					bandera = true;
				}
				Actual.solucion.push_back({lenguajeActual,it->empleado});
				setCoveringClases(tablero, lenguaje, Actual, solucion);
				if(bandera){
					Actual.cantidad_empleados--;
					it->seleccionado = false;
				}
				Actual.solucion.pop_back();
				bandera = false;
			}
			
		}
	}

}

void devolverEmpleados(SolucionClases & solucion){

	SolucionClases Actual;
	Actual.cantidad_empleados = 0;

	solucion.cantidad_empleados = INT_MAX; //serializo la solucion para evitar errores

	list<string> lenguaje({"Java", "Prolog", "Ruby", "C++", "Fortran", "JavaScript", "Python", "Perl", "Smalltalk", "PHP", "Typescript", "Pascal"});

	//solucion: 1, 5, 8 - 3 personas;
	list<Empleado> tablero = {
		Empleado(1,false, {"Java", "Prolog", "C++", "Fortran"}),
		Empleado(2,false, {"C++", "Python", "PHP"}),
		Empleado(3,false, {"Prolog", "Ruby"}),
		Empleado(4,false, {"Prolog", "Fortran", "Perl", "Typescript"}),
		Empleado(5,false, {"Ruby", "JavaScript", "Smalltalk"}),
		Empleado(6,false, {"Fortran", "JavaScript", "Perl", "Smalltalk", "Typescript", "Pascal"}),
		Empleado(7,false, {"PHP", "Typescript", "Pascal"}),
		Empleado(8,false, {"Python", "Perl", "Smalltalk", "PHP", "Typescript", "Pascal"}),
	};
	setCoveringClases(tablero,lenguaje,Actual, solucion);

	cout<<solucion.cantidad_empleados<<endl;

	cout<<"-------------------- LISTA DE EMPLEADOS --------------------"<<endl;
	for(list<pair<string,int>>::const_iterator it = solucion.solucion.begin(); it != solucion.solucion.end(); it++){
		cout<<"Empleado: "<< it->second <<" Habilidad: " << it->first <<endl;
	}
}
