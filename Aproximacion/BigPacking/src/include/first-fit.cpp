#include "headers/first-fit.h"

void devolverCajones(list<Cajon> & cajones, float capacidad){
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

	int i = 1;
	for(list<Cajon>::iterator it = cajones.begin(); it != cajones.end(); it++){
		cout<<"Cajon: "<<i++<<" Ocupada: "<<it->ocupada<< " De " << it->capacidad<<endl;
		for(list<Objeto>::iterator it_o = it->objetos.begin(); it_o != it->objetos.end(); it_o++){
			cout<<"Nombre: "<<it_o->getNombre()<<" Size: "<<it_o->getSize()<<endl;
		}
	}
}
