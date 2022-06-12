#ifndef __first_fit
#define __first_fit

#include "objetos.h"
#include <list>

using namespace std;

struct Cajon{
	float capacidad;
	float ocupada;
	list<Objeto> objetos;
};
void devolverCajones(list<Cajon> & cajones, float capacidad);

#endif