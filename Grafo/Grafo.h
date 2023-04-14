#ifndef GRAFO_H_
#define GRAFO_H_

#include <map>
#include <set>
#include <list>

using namespace std;

template <typename C> class Grafo
{
public:
	class Arco{ //Declaracion de los arcos del Grafo
		public:
			Arco(){};
			Arco(int destino, const C & costo){
				this->destino = destino;
				this->costo = costo;
			}
			int getAdyacente() const{  return this->destino; }
			const C & getCosto() const{ return this->costo; }
			void setCosto(C costo){ this->costo = costo; }
			bool operator==(typename Grafo<C>::Arco otroArco) const{ return (this->destino == otroArco.getAdyacente()); }
			bool operator<(typename Grafo<C>::Arco otroArco) const{	return (this->costo <= otroArco.getCosto()); }
		private:
			int destino;
			C costo;
	}; // class Arco

public:
	// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
	Grafo(){ }
	Grafo(const map<int,set<Arco>> & otroGrafo){ this->coleccion = otroGrafo; }

	~Grafo(){}

	Grafo & operator = (const map<int,set<Arco>> & nuevo_mapa){
		this->coleccion = nuevo_mapa;
		return *this;
	}

	// Devuelve true si la cantidad de vértices es cero
	bool esta_vacio() const{ return (coleccion.begin() == coleccion.end()); }

	// Indica la cantidad de vértices del grafo
	int devolver_longitud() const{ return coleccion.size(); }

	bool existe_vertice(int vertice) const{	return (coleccion.find(vertice) !=coleccion.end()); }

    /***
     * Comprueba si existe el arco entre un origen y un destino
     * @param origen vertice Origen
     * @param destino vertice Destino
     * @return retorna True o False dependiendo si encontro o no el arco entre el vertice y el destino dado
     */
	bool existe_arco(int origen, int destino) const{
		typename map<int, set<Arco>>::const_iterator it = coleccion.find(origen);
		return (it != coleccion.end()) && (it->second.find(Grafo<C>::Arco(destino, 0)) != it->second.end());
	}

	// PRE CONDICION: existe_arco(origen, destino)
    /***
     * Obtiene el costo entre un vertice dado y un destino dado
     * @param origen Vertice origen
     * @param destino Verticde destino
     * @return Devuelve el valor del arco
     */
	const C & costo_arco(int origen, int destino) const{
		typename map<int, set<Grafo<C>::Arco>>::const_iterator it = coleccion.find(origen);
		if(it != coleccion.end()){
			typename set<Grafo<C>::Arco>::const_iterator it_adyacente = it->second.find(Grafo<C>::Arco(destino, 0));
			if(it_adyacente != it->second.end())
				return it_adyacente->getCosto();
		}
		return -1;
	}

	void devolver_vertices(list<int> & vertices) const{
		for(auto a: coleccion)
			vertices.push_back(a.first);
	}

    /***
     * Devuelve una lista de Adyacentes de un vertice dado
     * @param origen El vertice del que se quiere conocer sus adyacentes
     * @param adyacentes Estructura donde se quiere almacenar todos los adyacentes obtenidos
     */
	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const{
		typename map<int,set<Grafo<C>::Arco>>::const_iterator it = coleccion.find(origen);
		if(it == coleccion.end()){
			for(auto a : it->second)
				adyacentes.push_back(a);
		}
	}

	Arco devolver_adyacente(int origen) const{ 
		typename map<int,set<Grafo<C>::Arco>>::const_iterator it = coleccion.find(origen);
		if(it == coleccion.end()){
			if(it->second.size() != 0){
				return *it->second.begin();
			}
		}
		return Arco(-1,-1);
	}

	void agregar_vertice(int vertice){ coleccion.insert({vertice, set<Grafo<C>::Arco>()}); }

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice){
		typename map<int,set<Grafo<C>::Arco>>::const_iterator it = coleccion.find(vertice);
		if(it != coleccion.end())
			coleccion.erase(it);
	}

	// PRE CONDICION: existeArco(origen, destino)
    /***
     Modifica el costo de un arco especifico en el grafo
     * @param origen Vertice existente al que se le quiere modificar el arco
     * @param destino Vertice destino existente cuyo costo desde origen se quiere modificar
     * @param costo Nuevo costo entre el origen y el destino
     */
	void modificar_costo_arco(int origen, int destino,C costo){
		typename map<int, set<Grafo<C>::Arco>>::iterator it_vertices = coleccion.find(origen);
		if(it_vertices != coleccion.end()){
			typename set<Grafo<C>::Arco>::iterator it_arcos = it_vertices->second.find(Grafo<C>::Arco(destino, 0));
			if(it_arcos != it_vertices->second.end()){}
				//it_arcos->setCosto(costo);
				//*it_arcos.setCosto(costo);
		}
	}

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
    /*** Agrega un arco a un vertice especifico, comprueba que el vertice exista
     *
     * @param origen Vertice existente al que se le quiere agregar un arco
     * @param destino Vertice destino existente al que se le quiere agregar la conexion con origen
     * @param costo el costo asociado al nuevo arco
     */
	void agregar_arco(int origen, int destino, const C & costo){
		typename map<int,set<Grafo<C>::Arco>>::iterator it_vertices = coleccion.find(origen);
		if(it_vertices != coleccion.end()){
			it_vertices->second.insert(Grafo<C>::Arco(destino,costo));
		}
	}

	// POST CONDICION: !existeArco(origen, destino)
    /***
     * Elimina un arco especifico sobre un vertice
     * @param origen Vertice sobre el cual se desea eliminar el arco
     * @param destino Vertice destino al cual se le quiere eliminar su conexion con origen
     */
	void eliminar_arco(int origen, int destino){
		typename map<int, set<Grafo<C>::Arco>>::iterator it_vertices = coleccion.find(origen);
		if(it_vertices != coleccion.end())
			it_vertices->second.erase(Grafo<C>::Arco(destino,0));
	}

    /***
     * Elimina todos los arcos de un vertice dado
     * @param origen el vertice al que se le quiere eliminar los arcos
     */
	void eliminar_arcos(int origen){
		typename map<int, set<Grafo<C>::Arco>>::iterator it_vertices = coleccion.find(origen);
		if(it_vertices != coleccion.end())
			it_vertices->second.clear();
	}

    /***
     * Itera sobre todo el mapa y sus elementos y elimina todos los vertices y arcos
     */
	void vaciar(){
		for (typename map<int ,set<Grafo<C>::Arco>>::iterator it_vertices=coleccion.begin(); it_vertices != coleccion.end(); ++it_vertices){
			for (typename set<Grafo<C>::Arco>::iterator it_arcos=it_vertices->second.begin(); it_arcos != it_vertices->second.end(); ++it_arcos){
				it_vertices->second.erase(it_arcos);
			}
		}
	}

	void dfs_forest(list<int> & orden_dfs)const{
		set<int> visitados;
		for(typename map<int,set<Grafo<C>::Arco>>::const_iterator it_vertices = coleccion.begin(); it_vertices != coleccion.end(); ++it_vertices){
			if(visitados.find(it_vertices->first) == visitados.end())
				dfs(it_vertices->first, visitados, orden_dfs);

		}
	}


private:
	/*
	 * Definir la estructura interna
	 */

	void dfs(int origen, set<int> & visitados, list<int> & orden_dfs)const{
		orden_dfs.push_front((orden_dfs.empty())? -1 : origen);
		visitados.insert(origen);
		typename map<int,set<Grafo<C>::Arco>>::const_iterator it_vertices = coleccion.find(origen);
		for(typename set<Grafo<C>::Arco>::const_iterator it_arcos = it_vertices->second.begin(); it_arcos != it_vertices->second.end(); ++it_arcos)
			if(visitados.find(it_arcos->getAdyacente()) == visitados.end())
				dfs(it_arcos->getAdyacente(), visitados, orden_dfs);
	}

    /***
     * Este atributo es la estructura en la que basamos los nodos del Grafo
     * @attention en este caso coleccion es un mapa que en la clave contiene el numero de vertice y como dato contiene
     * todos los arcos a otros vertices
     * es un set debido a que los vertices destino no tienen ningun orden en particular
    ***/
	map<int, set<Arco>> coleccion;

}; // class Grafo


#endif /* GRAFO_H_ */
