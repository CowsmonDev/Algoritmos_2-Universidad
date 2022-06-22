#include "headers/mochila.h"

void agregarAdicionales(Mochila & mochila_actual, list<ObjetoMochila>::reverse_iterator it, list<ObjetoMochila> & objetos){
	it++;
	while((it != objetos.rend()) && ((mochila_actual.getOcupado() + it->getPeso()) <= mochila_actual.getCapacidad()) ){
		mochila_actual.agregarObjeto(*it);
		it++;
	}
}

void obtenerMochilaAproximada(Mochila & mochila, list<ObjetoMochila> & objetos, int k){
	objetos.sort();

	Mochila mochila_actual(mochila.getCapacidad());
	list<ObjetoMochila>::reverse_iterator it_a;
	int j =0;

	for(list<ObjetoMochila>::reverse_iterator it = objetos.rbegin(); j++ <= objetos.size() - k; it++){
		mochila_actual.vaciarMochila();
		mochila_actual.agregarObjeto(*it);
		it_a = it;
		it_a++;

		for(int i = k - 1; i != 0; i--){
			mochila_actual.agregarObjeto(*it_a);
			it_a++;
		}

		bool terminar = false;

		if(mochila_actual.getOcupado() <= mochila_actual.getCapacidad()){
			//agregar adicionales
			agregarAdicionales(mochila_actual, it_a,objetos);
			terminar = true;
		}

		//este bucle quita iterativante el segundo elemento, y agrega un nuevo elemento al final

		if(k > 1)
			while(it_a != objetos.rend() && !terminar){
				if(!(mochila_actual.getObjetos().back() == *it_a)){
					mochila_actual.eliminarSegundo();//eliminar el segundo
					mochila_actual.agregarObjeto(*it_a);
					if(mochila_actual.getOcupado() <= mochila_actual.getCapacidad()){
						//agregar adicionales
						agregarAdicionales(mochila_actual, it_a,objetos);
						terminar = true;
					}
				}
				it_a++;

			}
		if(terminar && (mochila.getOcupado() < mochila_actual.getOcupado()))
			mochila = mochila_actual;

	}
}
