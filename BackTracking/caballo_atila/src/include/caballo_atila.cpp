#include "headers/caballo_atila.h"

void Visitados::modificarVisitado(int x, int y, bool valor, int cantidad){
	visitado[x][y] = valor;
	cantidad += cantidad;
}

bool poda(vector<vector<bool>> visitado, pair<int,int> siguiente, bool sol){
	if((visitado.size() > siguiente.first) && (visitado.at(siguiente.first).size() > siguiente.second))
        if(!visitado.at(siguiente.first).at(siguiente.second) && !sol){
                return false;
        }
		//return ((visitado.at(siguiente.first).at(siguiente.second)) || sol);
	return true;
}

bool backTracking(list<pair<int,int>> & solucion,vector<pair<int,int>> & movimientos, pair<int,int> origen, Visitados visitados){
	bool sol = false;
	if(solucion.empty() || (origen != solucion.front())){
		pair<int,int> siguiente;
		solucion.push_back(origen);

		for(vector<pair<int,int>>::const_iterator it = movimientos.begin(); it != movimientos.end(); it++){
			siguiente.first = (it->first + origen.first);
			siguiente.second = (it->second + origen.second);
			if(!poda(visitados.visitado, siguiente, sol)){
				visitados.modificarVisitado(siguiente.first,siguiente.second, true, 1);
				sol = backTracking(solucion,movimientos, siguiente, visitados);
				visitados.modificarVisitado(siguiente.first,siguiente.second, false, -1);
			}
		}

		if(!sol)
			solucion.pop_back();

		return sol;

	}else return (solucion.size() != (visitados.cantidad * visitados.cantidad));
}

void encontrarRecorrido(list<pair<int,int>> & solucion){

	Visitados visitados;
	visitados.cantidad = 5;
	visitados.visitado = {
		{false, false, false, true, false, false},
		{false,true, false, false,false,true},
		{false,false,true, false,false,false},
		{false,false,false,false,true,false},
		{false,false,false,false,false,false},
		{false,false,false,false,false,false}
	};

	vector<pair<int,int>> movimientos = {
		make_pair(1,0),
		make_pair(-1,0),
		make_pair(0,1),
		make_pair(0,-1),
	};

	backTracking(solucion,movimientos, pair<int,int>(0,0),visitados);

	/*vector<vector<int>> sol ={
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};

	cout<<solucion.size();
	int i = 0;
	for(list<pair<int,int>>::const_iterator it = solucion.begin(); it != solucion.end(); it++){
		sol[it->first][it->second] = i++;
	}

	for (vector<vector<int>>::const_iterator it = sol.begin(); it != sol.end(); it++){
		cout<<endl;
		for(vector<int>::const_iterator it_2 = it->begin(); it_2 != it->end(); it_2++){
			cout<<*it_2<<" ";
		}
	}*/

}
