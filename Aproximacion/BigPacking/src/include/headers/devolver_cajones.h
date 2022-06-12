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

void mostrarElementos(list<Cajon> & cajones);

void cajonesFirstFit(list<Cajon> & cajones, float capacidad);

void cajonesFirstFitDecreasing(list<Cajon> & cajones, float capacidad);

void cajonesNextFit(list<Cajon> & cajones, float capacidad);

#endif