#ifndef objeto
#define objeto

#include <iostream>

using namespace std;

class Objeto{

	public:
		Objeto(string nombre, float size){
			this->nombre = nombre;
			this->size = size;
		};

		string getNombre(){ return this->nombre; }
		float getSize(){ return this->size; }

	private: 
		string nombre;
		float size;
};

#endif //