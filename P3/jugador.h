//jugador.h 
//The class that represents a player
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <list>

#include "persona.h"

using namespace std;

struct Apuesta {
	int tipo;
	string valor;
	int cantidad;
};

class Jugador: public Persona {
private:
	int dinero_;
	string cod_;
	list <Apuesta> apuestas_;
public:
	Jugador(string nif, string code, string name="", string ap="", int age=0, 
			string dir="", string loc="", string prov="", string country="") :
			Persona (nif, name, ap, age, dir, loc, prov, country) {
		cod_=code;
		dinero_=1000;
	}
	void setCodigo(string code);
	inline string getCodigo() const {return cod_;}
	void setDinero(int money);
	inline int getDinero() const {return dinero_;}
	void setApuestas();
	inline list <Apuesta> getApuestas() const {return apuestas_;}
};

#endif