#include "headers/asignacion.h"
#include <iostream>

using namespace std;

Partido::Partido(int Equipo_1, int Equipo_2){
	equipo_1 = Equipo_1;
	equipo_2 = Equipo_2;
}

void backTrancking(vector<vector<int>> tablero, vector<Partido> partidos, int nro_partido, Solucion & Actual, Solucion & solucion){
	if(tablero.size()/2 <= nro_partido)
		if(Actual.puntaje > solucion.puntaje) 
			solucion = Actual;
	else
		for (int columna = 0; columna < tablero.at(nro_partido).size(); columna++){
			Actual.arbitros[nro_partido] = columna;
			Actual.puntaje += tablero.at(partidos.at(nro_partido).equipo_1).at(columna) + tablero.at(partidos.at(nro_partido).equipo_2).at(columna);
			backTrancking(tablero, partidos, ++nro_partido, Actual, solucion);
			nro_partido--;
			Actual.puntaje -= tablero.at(partidos.at(nro_partido).equipo_1).at(columna) + tablero.at(partidos.at(nro_partido).equipo_2).at(columna);
		}
}

void encontrarArbitroOptimo(vector<vector<int>> tablero, vector<Partido> partidos, Solucion & solucion){
	Solucion Actual;
	Actual.arbitros = {0,0};
	Actual.puntaje = 0;
	backTrancking(tablero, partidos, 0, Actual, solucion);
}