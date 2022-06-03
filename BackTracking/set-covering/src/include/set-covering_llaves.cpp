
#include <iostream>
#include "headers/set-covering_llaves.h"

using namespace std;

bool poda(vector<vector<int>> & tablero, int nro_cerradura, int nro_llave){
	return (tablero.at(nro_cerradura).at(nro_llave) == 0); 
}

void setCovering(vector<vector<int>> tablero, int nro_cerradura, set<int> llaves_usadas, Solucion Actual, Solucion & solucion){
	if(nro_cerradura == tablero.size()){
		if(Actual.cant_llaves < solucion.cant_llaves)
			solucion = Actual;
	}else
		for (int nro_llave = 0; nro_llave < tablero.at(nro_cerradura).size(); nro_llave++){
			if(!poda(tablero, nro_cerradura, nro_llave)){
				if(llaves_usadas.find(nro_llave) == llaves_usadas.end()){
					Actual.cant_llaves++;
					llaves_usadas.insert(nro_llave);
				}
				Actual.solucion[nro_cerradura] = nro_llave;
				setCovering(tablero, ++nro_cerradura, llaves_usadas, Actual, solucion);
				nro_cerradura--;
			}
		}
}

void devolverLlaves(Solucion & solucion){
	Solucion Actual;
	Actual.cant_llaves = 0;
	Actual.solucion = {0,0,0,0};

	vector<vector<int>> tablero = {
		{1,0,1,1},
		{0,1,1,0},
		{0,1,0,1},
		{1,0,0,0},
	};

	set<int> llaves_usadas;

	setCovering(tablero,0,llaves_usadas,Actual, solucion);

	cout<<"costo: "<<solucion.cant_llaves<<endl;
	cout<<"Asignacion de Tareas: "<<endl;

	int contador = 1;
	for(vector<int>::const_iterator it = solucion.solucion.begin(); it < solucion.solucion.end(); it++)
		cout<<"Cerradura: " <<contador++<<" Llave: "<<*it + 1<<endl;
}