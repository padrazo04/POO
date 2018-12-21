// ej9.cc
// Prueba del insertador y del extractor en la clase Dados
// g++ ej9.cc dados.h dados.c
#include <iostream>

#include "dados.h"

int main() {
	Dados midado, midado2;

	midado.lanzamiento();

	cout << midado << endl << endl;

	midado2.setDado1(3);
	midado2.setDado2(4);

	cout << midado << endl << midado2 << endl;

	cin >> midado;

	cout << midado << endl;
	return 0;
}