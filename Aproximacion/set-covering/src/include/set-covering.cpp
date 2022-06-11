#include "headers/set-covering.h"

void seleccionar_postulantes(set<string> lenguajes, list<Empleado> empleados, list<Empleado> & solucion){
	empleados.sort();
	for(list<Empleado>::iterator it = empleados.begin(); it !=empleados.end(); it++){
		cout<<it->getEmpleado()<<endl;
	}
	while((lenguajes.size()) > 0 && (empleados.size() > 0)){

		Empleado e = empleados.back(); empleados.pop_back();
		set<string> habilidades = e.getHabilidades();
		for(set<string>::iterator it = habilidades.begin(); it != habilidades.end(); it++){ 
			if(lenguajes.find(*it) != lenguajes.end()){
				lenguajes.erase(*it);
				e.setSeleccionado(true);
			}
		}
		if(e.getSeleccionado())
			solucion.push_back(e);
	}
}

void devolverEmpleados(list<Empleado> & solucion){
	set<string> lenguajes({JAVA, PROLOG, RUBY, C, FORTRAN, JAVASCRIPT, PYTHON, PERL, SMALLTALK, PHP, TYPESCRIPT, PASCAL});

	//solucion: 1, 5, 8 - 3 personas;
	//eliminar el empleado una vez seleccionado
	list<Empleado> empleados = {
		Empleado("Jose", {JAVA, PROLOG, C, FORTRAN}),
		Empleado("Agustin", {C, PYTHON, PHP}),
		Empleado("Dylan", {PROLOG, RUBY}),
		Empleado("Jonathan", {PROLOG, FORTRAN, PERL, TYPESCRIPT}),
		Empleado("Ezequiel", {RUBY, JAVASCRIPT, SMALLTALK}),
		Empleado("Santiago", {FORTRAN, JAVASCRIPT, PERL, SMALLTALK, TYPESCRIPT, PASCAL}),
		Empleado("Ian", {PHP, TYPESCRIPT, PASCAL}),
		Empleado("Rodrigo", {PYTHON, PERL, SMALLTALK, PHP, TYPESCRIPT, PASCAL})
	};

	seleccionar_postulantes(lenguajes, empleados, solucion);

	cout<<"-------------------------------- Empleados --------------------------------"<<endl;
	for(list<Empleado>::iterator it = solucion.begin(); it !=solucion.end(); it++){
		cout<<it->getEmpleado()<<endl;
	}

}
