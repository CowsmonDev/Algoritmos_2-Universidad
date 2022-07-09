#ifndef ARBITROS_H_INCLUDE
#define ARBITROS_H_INCLUDE

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Equipo{
	public:
		Equipo(){}
		Equipo(int id, int numero){
			this->id = id;
			this->numero = numero;
		}
		int getId()const{ return this->id; }
		int getNumero()const{ return this->numero; }
		bool operator==(const Equipo& other){ return id == other.getId(); }
		Equipo & operator=(const Equipo& other){
			this->id = other.getId();
			this->numero = other.getNumero();
			return *this;
		}
	private:
		int id;
		int numero;
};

class Arbitro{
	public:
		Arbitro(){};
		Arbitro(int id, int cantidadArbitros){
			this->arbitro = id;
			this->seleccionado = false;

			this->puntaje = vector<int>(cantidadArbitros);
			generate(this->puntaje.begin(), this->puntaje.end(), []{return rand() % 10;} );

		}

		int getArbitro(){ return this->arbitro; }

		bool getSeleccionado(){ return this->seleccionado; }
		void setSeleccionado(bool seleccionado){ this->seleccionado = seleccionado;}

		void setPuntaje(vector<int> puntaje){ this->puntaje = puntaje; }
		int getPuntaje(int equipo){ return this->puntaje.at(equipo); }
		vector<int> getPuntaje(){ return this->puntaje; }

		string toString(){
			string retorno = "";
			retorno += "Arbitro " + to_string(arbitro) + ": ";
			for(vector<int>::iterator it = puntaje.begin(); it != puntaje.end(); it++){
				retorno += to_string(*it) + " ";
			}
			return retorno;
		}

	private:
		int arbitro;
		bool seleccionado;
		vector<int> puntaje;
};

struct Solucion{
	int puntajeTotal;
	list<int> arbitros;
};

void encontrarArbitroOptimo(Solucion & solucion);


#endif
