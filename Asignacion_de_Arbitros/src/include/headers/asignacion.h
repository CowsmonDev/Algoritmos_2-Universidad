#ifndef ARBITROS_H_INCLUDE
#define ARBITROS_H_INCLUDE

#include <vector>

class Partido{
	public:
	    Partido(int Equipo_1, int Equipo_2);
        int equipo_1;
        int equipo_2;


};

struct Solucion{
	int puntaje;
	std::vector<int> arbitros;
};

void encontrarArbitroOptimo(std::vector<std::vector<int>> tablero, std::vector<Partido> partidos, Solucion & solucion);

#endif
