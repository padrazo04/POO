//juego.cc
//The main program that tests the functioning of the class Dados
#include <iostream>
#include "dados.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Dados d;	//Se ejecuta el constructor
	const Dados bermejo;
	cout << d.getDado1() << endl;
	cout << d.getDado2() << endl;

	d.lanzamiento();
	cout << d.getDado1() << endl;
	cout << d.getDado2() << endl;

	d.setDado1(3);
	d.setDado2(6);
	cout << d.getDado1() << endl;
	cout << d.getDado2() << endl;

	d.setDado1(0);
	d.setDado2(7);
	cout << d.getDado1() << endl;
	cout << d.getDado2() << endl;

	cout << "SUMA: " << d.getSuma() << endl;
	cout << "RESTA: " << d.getDiferencia() << endl;
	cout << "MEDIA DEL D1: " << d.getMedia1() << endl;
	cout << "MEDIA DEL D2: " << d.getMedia2() << endl;

	/*cout << d.d1_ << endl;
	cout << d.d2_ << endl;
	Da error de compilacion*/

	return 0;
}