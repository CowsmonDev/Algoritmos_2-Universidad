#include <set>
#include <cfloat>
#include "headers/varilla.h"

using namespace std;

//varilla.pop(i);
//llamado recursivo
//varilla.push(i);

bool Poda(Solucion & solucion, const Solucion& Actual){
    if(Actual.cant_varillas >= solucion.cant_varillas){
        return true;
    }
    return false;
}


void setCovering(Solucion & solucion, Solucion Actual, vector<float> varillas, float M, float acumulador, int nivel){
    if(varillas.size() == nivel){
        if(solucion.cant_varillas > Actual.cant_varillas)
            solucion = Actual;
    }else{
        for(int i=0; i<varillas.size(); i++){
            //varillas
            int bandera_cant_varillas = 0;
            float valor = varillas.at(i);
            if(valor >= 0){
                if((acumulador + valor) > M){ //Comprueba si tiene que agregar una nueva varilla
                    Actual.cant_varillas++;
                    bandera_cant_varillas = -1;
                    acumulador = 0;
                }
                if(!Poda(solucion, Actual)){
                    acumulador += valor; // Agregar el valor de la varilla a el acumulador
                    varillas[i] = -1; // Marca la varilla como visitada
                    Actual.solucion.push_back(valor); // la varilla a solucion

                    setCovering(solucion, Actual, varillas, M, acumulador, (nivel + 1));

                    varillas[i] = valor;
                    acumulador -= valor;
                    Actual.solucion.pop_back();
                }
                Actual.cant_varillas -= bandera_cant_varillas;
            }
        }
    }
}

void devolverVarillas(Solucion & solucion, float M){

    vector<float> varillas = { 0.2, 0.5, 0.8, 2, 1.5, 0.2, 2.5, 0.1 };

    solucion.cant_varillas = FLT_MAX;

    Solucion Actual;
    Actual.cant_varillas = 1;

    setCovering(solucion, Actual, varillas, M, 0, 0);
    cout<<solucion.cant_varillas<<endl;

    cout<<"costo: "<<solucion.cant_varillas<<endl;
	cout<<"Orden de Corte: "<<endl;

	int contador = 1;
	for(vector<float>::const_iterator it = solucion.solucion.begin(); it < solucion.solucion.end(); it++)
		cout<<"Medida - "<<contador++<<": "<<*it<<endl;

}
