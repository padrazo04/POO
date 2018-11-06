//jugador.cc
//Body of class Jugador
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>

#include "jugador.h"

using namespace std;

void Jugador::setCodigo(string code) {
	cod_=code;
}

void Jugador::setDinero(int money) {
	dinero_=money;
}

void Jugador::setApuestas() {
	apuestas_.clear();
	Apuesta aux;
	char codigo[10], value[10], amount[10];
	string nombrefichero= getDNI() + ".txt";
	ifstream f1(nombrefichero.c_str());

	if(f1.is_open()) {
		while(f1.getline(codigo, 10, ',')) {
			f1.getline(value, 10, ',');
			f1.getline(amount, 10, '\n');
			aux.tipo=atoi(codigo);
			aux.valor=value;
			aux.cantidad=atoi(amount);
			apuestas_.push_back(aux);
		}
		f1.close();
	} else cout << "Unable to open file" << endl;
}