#include "headers/asignacion.h"

using namespace std;

void cargarPartidos(list<pair<Equipo,Equipo>> & partidos){
	int equipo1, equipo2, i = 0, cantidadPartidos = 0;

	cout<<"Cantidad De Partidos: ";
	cin>>cantidadPartidos;
	while(i < (cantidadPartidos * 2)){
		cout<<"Ingrese el Equipo 1: ";
		cin>>equipo1;

		cout<<"Ingrese el Equipo 2: ";
		cin>>equipo2;

		partidos.push_back({Equipo(i, equipo1), Equipo(i + 1, equipo2)});
		i+=2;
	}
}

void backTracking(list<Arbitro> & arbitros, list<pair<Equipo,Equipo>> partidos, Solucion Actual, Solucion & solucion){
	if(partidos.empty()){
		if(Actual.puntajeTotal > solucion.puntajeTotal){
			solucion = Actual;
		}
	}else{
		pair<Equipo,Equipo> p = { partidos.front().first, partidos.front().second };
		partidos.pop_front();
		for(list<Arbitro>::iterator it = arbitros.begin(); it != arbitros.end(); it++){
			if(!it->getSeleccionado()){
				Actual.arbitros.push_back(it->getArbitro());
				Actual.puntajeTotal += it->getPuntaje(p.first.getId()) + it->getPuntaje(p.second.getId());
				it->setSeleccionado(true);

				backTracking(arbitros, partidos, Actual, solucion);

				Actual.arbitros.pop_back();
				Actual.puntajeTotal -= it->getPuntaje(p.first.getId()) + it->getPuntaje(p.second.getId());
				it->setSeleccionado(false);
			}
		}
	}
}

void encontrarArbitroOptimo(Solucion & solucion){

	Solucion Actual;
	Actual.puntajeTotal = 0;
	Actual.arbitros = {};

	list<pair<Equipo, Equipo>> partidos;

	cargarPartidos(partidos);

	srand(time(0));

	list<Arbitro> arbitros = {
		Arbitro(0, partidos.size() * 2),
		Arbitro(1, partidos.size() * 2),
		Arbitro(2, partidos.size() * 2),
	};

	cout<<endl<<"----------------------------------- Puntajes --------------------------------"<<endl;
	for(list<Arbitro>::iterator it = arbitros.begin(); it != arbitros.end(); it++){
		cout<<it->toString()<<endl;
	}
	cout<<"-----------------------------------==========--------------------------------"<<endl<<endl;

	backTracking(arbitros, partidos, Actual, solucion);

	cout<<"Arbitros: ";
	for(list<int>::const_iterator it = solucion.arbitros.begin(); it != solucion.arbitros.end(); it++){ cout<<*it<<" "; }
	cout<<endl<<"Putaje Total: "<<solucion.puntajeTotal<<endl;
}
