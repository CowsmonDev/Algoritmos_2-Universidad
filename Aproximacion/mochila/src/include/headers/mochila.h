#ifndef __mochila
#define __mochila

#include <list>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Para esta clase vamos a utilizar el problema de la mochila simplificado donde la utilidad es igual a su peso
**/
class ObjetoMochila {
	public:
		ObjetoMochila(int id, float peso){
			this->id = id;
			this->beneficio = peso;
			this->peso = peso;
		}

		int getId() const { return this->id; }
		int getBeneficio() const { return this->beneficio; }
		int getPeso() const { return this->peso; }

		string toString() const { return "Elemento: " + to_string(this->id) + ", Peso: " + to_string(this->peso) + ", Beneficio: " + to_string(this->beneficio); }

		bool operator==(const ObjetoMochila & other){ return (this->id == other.getId()); }
		bool operator<(const ObjetoMochila & other){ return (this->beneficio < other.getBeneficio()); }


	private:
		int id;
		float beneficio;
		float peso;
};

class Mochila{
	public:
		Mochila(float capacidad){
			this->capacidad = capacidad;
			this->ocupado = 0;
		};

		void agregarObjeto(ObjetoMochila & objeto){
			objetos.push_back(objeto);
			ocupado += objeto.getPeso();
		}

		void eliminarSegundo(){
			list<ObjetoMochila>::iterator it = ++objetos.begin();
			this->ocupado -= it->getPeso();
			objetos.erase(it);
		}
		void vaciarMochila(){
			this->objetos.clear();
			this->ocupado = 0;
		}

		string toString(){
			string obj = "{\n";
			for(list<ObjetoMochila>::iterator it = objetos.begin(); it != objetos.end(); it++){
				obj += " 	" + it->toString() + "\n";
			}
			obj += "}\n";
			return "------------- Mochila -------------\nOcupado: " + to_string(this->ocupado) + "\nCapacidad: " + to_string(this->capacidad) + "\nObjetos: " + obj;
		}

		float getOcupado() const{ return this->ocupado; }
		float getCapacidad() const { return this->capacidad; }
		list<ObjetoMochila> getObjetos() const { return this->objetos; }
		bool operator<(const Mochila & other){ return (this->ocupado < other.getOcupado()); }

		Mochila & operator=(const Mochila & other){
			this->ocupado = other.getOcupado();
			this->capacidad = other.getCapacidad();
			list<ObjetoMochila> l = other.getObjetos();
			this->objetos.swap(l);
			return *this;
		}

	private:
		float ocupado;
		float capacidad;
		list<ObjetoMochila> objetos;
};

void obtenerMochilaAproximada(Mochila & mochila, list<ObjetoMochila> & objetos, int k);

#endif // __mochila define header
