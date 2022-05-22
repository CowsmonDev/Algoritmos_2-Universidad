#include "headers/asignacion_tareas.h"
#include <iostream>

using namespace std;

void backTracking(vector<vector<int>> tablero,int nro_persona, Solucion & Actual, Solucion & solucion){
	if (nro_persona == tablero.size()){
		if(Actual.costo < solucion.costo)
			solucion = Actual;
	}else{
		for(int indice_tarea = 0; indice_tarea < tablero.at(nro_persona).size(); indice_tarea++){
			Actual.solucion[nro_persona] = indice_tarea;
			Actual.costo += tablero.at(nro_persona).at(indice_tarea);
			backTracking(tablero, ++nro_persona, Actual, solucion);
			nro_persona--;
			Actual.costo -= tablero.at(nro_persona).at(indice_tarea);
		}
	}
}

void asignacion_tareas(Solucion & solucion){
	Solucion Actual;
	Actual.costo = 0;
	Actual.solucion = {0,0,0,0};

	vector<vector<int>> tablero = {
		{50,20,22,15},
		{20,10,47,10},
		{15,45,51,12},
		{12,23,5,52}
	};

	backTracking(tablero, 0, Actual, solucion);
	cout<<"costo: "<<solucion.costo<<endl;
	cout<<"Asignacion de Tareas: "<<endl;

	int contador = 1;
	for(vector<int>::const_iterator it = solucion.solucion.begin(); it < solucion.solucion.end(); it++)
		cout<<"Persona " <<contador++<<" Tarea: "<<*it + 1<<endl;

}
