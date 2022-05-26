#include "headers/asignacion.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>    // std::generate

using namespace std;

Partido::Partido(int Equipo_1, int Equipo_2){
	equipo_1 = Equipo_1;
	equipo_2 = Equipo_2;
}

void llenar_tablero_partidos(vector<Partido> & partidos, int cantidad_partidos){
	int equipo_1, equipo_2;

	for (int i = 0; i < cantidad_partidos; i++){
		cout<<endl<<"Equipo 1: ";
		cin>>equipo_1;
		cout<<"Equipo 2: ";
		cin>>equipo_2;
		cout<<endl;
		partidos.push_back(Partido(equipo_1, equipo_2));
	}
}

void backTrancking(vector<vector<int>> tablero, vector<Partido> partidos, int nro_partido, Solucion & Actual, Solucion & solucion){
	if(partidos.size() <= nro_partido){
		if(Actual.puntaje > solucion.puntaje){
			solucion = Actual;
		}
	}else{
		int arbitro = 0;
		while(arbitro  < tablero.size()){
                //agregar un set de visitado...
            if(Actual.arbitros[nro_partido] == -1){
                    Actual.arbitros[nro_partido] = arbitro;
                    Actual.puntaje += tablero.at(arbitro).at(partidos.at(nro_partido).equipo_1) + tablero.at(arbitro).at(partidos.at(nro_partido).equipo_2);

                    backTrancking(tablero, partidos, nro_partido + 1, Actual, solucion);

                    Actual.arbitros[nro_partido] = -1;
                    Actual.puntaje -= tablero.at(arbitro).at(partidos.at(nro_partido).equipo_1) + tablero.at(arbitro).at(partidos.at(nro_partido).equipo_2);
                    arbitro++;
            }

		}


	}
}

int ran(){ return rand() % 10; }

void encontrarArbitroOptimo(Solucion & solucion){

	int cantidad_partidos, cantidad_arbitros = 0;

	cout<<"Cantidad De Partidos: ";
	cin>> cantidad_partidos;
	cout<<"Cantidad De Arbitros: ";
	cin>> cantidad_arbitros;
	while(cantidad_partidos > cantidad_arbitros){
		cout<<"La Cantidad debe ser igual o mayor que la cantidad de partidos"<<endl;
		cin>> cantidad_arbitros;
	}

	/** Inicializa el vector partido y lo llena con la disposicion solicitada por el usuarioz **/
	vector<Partido> partidos;
	llenar_tablero_partidos(partidos, cantidad_partidos);

	srand(time(0));
	vector<vector<int>> tablero(cantidad_arbitros,vector<int>(cantidad_partidos*2)); //inicializa el vector tablero sin valores y con ciertas dimensiones

	/** Genera numeros Aleatorios para el tablero de puntajes **/
	for(vector<vector<int>>::iterator it = tablero.begin(); it != tablero.end(); it++)
		generate(it->begin(), it->end(), ran);


    for(vector<vector<int>>::const_iterator it = tablero.begin(); it != tablero.end(); it++){
        cout<<"Fila: ";
        for(vector<int>::const_iterator it_2 = it->begin(); it_2 != it->end(); it_2++){
            cout<<" "<<*it_2;
        }
        cout<<endl;
    }

	Solucion Actual;
	Actual.arbitros = vector<int>(cantidad_partidos, -1);
	Actual.puntaje = 0;


	for(vector<Partido>::const_iterator it = partidos.begin(); it != partidos.end(); it++){
        cout<<"Partido: "<<it->equipo_1<<" vs "<<it->equipo_2<<endl;
	}


	backTrancking(tablero, partidos, 0, Actual, solucion);
	cout<<solucion.puntaje<<endl;

}
