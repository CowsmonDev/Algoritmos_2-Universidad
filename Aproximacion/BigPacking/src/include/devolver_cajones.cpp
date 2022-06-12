#include "headers/devolver_cajones.h"

void mostrarElementos(list<Cajon> & cajones){
	int i = 0;
	for(Cajon c : cajones){
		cout<<"Cajon: "<<i++<<" Ocupada: "<<c.ocupada<< " De " << c.capacidad<<endl;
		for(Objeto o : c.objetos)
			cout<<o.toString()<<endl;
	}
}

void cajonesFirstFit(list<Cajon> & cajones, float capacidad){
	// inicializacion de cajones
	cajones.clear();
	Cajon cajon;
	cajon.capacidad = capacidad;
	cajon.ocupada = 0;

	cajones.push_back(cajon);

	list<Objeto> objetos = {
		Objeto("S1", 0.2),
		Objeto("S2", 0.5),
		Objeto("S3", 0.4),
		Objeto("S4", 0.4),
		Objeto("S5", 0.5),
		Objeto("S6", 0.8),
		Objeto("S7", 0.1),
		Objeto("S8", 0.1)
	};

	while(!objetos.empty()){
		Objeto o = objetos.front(); objetos.pop_front();

		list<Cajon>::iterator it = cajones.begin();
		while((it != cajones.end()) && (it->capacidad <= (it->ocupada + o.getSize()))){
			it++;
		}
		if(it == cajones.end()){
			cajon.ocupada = o.getSize();
			cajon.objetos = {o};
			cajones.push_back(cajon);
		}else{
			it->ocupada += o.getSize();
			it->objetos.push_back(o);
		}
	}
}

void cajonesFirstFitDecreasing(list<Cajon> & cajones, float capacidad){
	// inicializacion de cajones
	cajones.clear();
	Cajon cajon;
	cajon.capacidad = capacidad;
	cajon.ocupada = 0;

	cajones.push_back(cajon);

	list<Objeto> objetos = {
		Objeto("S1", 0.2),
		Objeto("S2", 0.5),
		Objeto("S3", 0.4),
		Objeto("S4", 0.4),
		Objeto("S5", 0.5),
		Objeto("S6", 0.8),
		Objeto("S7", 0.1),
		Objeto("S8", 0.1)
	};

	objetos.sort();

	while(!objetos.empty()){
		Objeto o = objetos.back(); objetos.pop_back();

		list<Cajon>::iterator it = cajones.begin();
		while((it != cajones.end()) && (it->capacidad <= (it->ocupada + o.getSize()))){
			it++;
		}
		if(it == cajones.end()){
			cajon.ocupada = o.getSize();
			cajon.objetos = {o};
			cajones.push_back(cajon);
		}else{
			it->ocupada += o.getSize();
			it->objetos.push_back(o);
		}
	}
}

void cajonesNextFit(list<Cajon> & cajones, float capacidad){
	// inicializacion de cajones
	cajones.clear();
	Cajon cajon;
	cajon.capacidad = capacidad;
	cajon.ocupada = 0;

	cajones.push_back(cajon);

	list<Objeto> objetos = {
		Objeto("S1", 0.2),
		Objeto("S2", 0.5),
		Objeto("S3", 0.4),
		Objeto("S4", 0.4),
		Objeto("S5", 0.5),
		Objeto("S6", 0.8),
		Objeto("S7", 0.1),
		Objeto("S8", 0.1)
	};

	while(!objetos.empty()){
		Objeto o = objetos.front(); objetos.pop_front();

		if(cajones.back().capacidad >= (cajones.back().ocupada + o.getSize())){
			cajones.back().ocupada += o.getSize();
			cajones.back().objetos.push_back(o);
		}else{
			cajon.ocupada = o.getSize();
			cajon.objetos = {o};
			cajones.push_back(cajon);
		}
	}
}