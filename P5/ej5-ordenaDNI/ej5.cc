// ej5.cc
// Este programa ordena un vector de jugadores por DNI y lo muestra por pantalla.
// g++ ej5.cc persona.cc persona.h jugador.h jugador.cc -Wall
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "jugador.h"
#include "persona.h"

using namespace std;

bool ordenaDNI(Jugador a, Jugador b);

int main(int argc, char const *argv[])
{
	vector <Jugador> v;

	Jugador a("1111", "a"), b("2222", "b"), c("3333", "c");
	Jugador d("4444", "d"), e("5555", "e");

	v.push_back(e);
	v.push_back(a);
	v.push_back(d);
	v.push_back(c);
	v.push_back(b);

	cout << "El vector ahora mismo es:" << endl;
	for(unsigned int i=0; i<v.size(); i++) {
		cout << i << ": DNI: " << v[i].getDNI() << "\tCOD:" << v[i].getCodigo() << endl;
	}

	sort(v.begin(), v.end(), ordenaDNI);

	cout << endl << "Vector ordenado:" << endl;
	for(unsigned int i=0; i<v.size(); i++) {
		cout << i << ": DNI: " << v[i].getDNI() << "\tCOD:" << v[i].getCodigo() << endl;
	}

	return 0;
}

bool ordenaDNI(Jugador a, Jugador b) {
	return (a.getDNI() < b.getDNI());
}
