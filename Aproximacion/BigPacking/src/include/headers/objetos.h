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

		bool operator<(Objeto & other){
			return (this->size < other.size);
		};
		string toString() const{ return "Nombre: " + this->nombre + " Capacidad: " + std::to_string(this->size); }


		string getNombre(){ return this->nombre; }
		float getSize(){ return this->size; }

	private:
		string nombre;
		float size;
};

#endif //
