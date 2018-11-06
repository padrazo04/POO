//persona.h
//The class that represents a roulette
#ifndef RULETA_H
#define RULETA_H

#include <list>

//#include "../P2/jugador.h"  <-- Inclusión de librería mediante la path
#include "jugador.h"
#include "crupier.h"

class Ruleta {
private:
	int banca_;
	int bola_;
	list <Jugador> jugadores_;
	Crupier crupier_;
public:
	Ruleta(Crupier crupi);
	inline int getBanca() const {return banca_;}
	inline int getBola() const {return bola_;}
	inline Crupier getCrupier() const {return crupier_;}
	inline list <Jugador> getJugadores() const {return jugadores_;}
	bool setBanca(int x);
	bool setBola(int x);
	inline void setCrupier(Crupier crupi) {crupier_=crupi;}
	bool addJugador(Jugador player);
	int deleteJugador(string nif);
	int deleteJugador(Jugador player);
	void escribeJugadores();
	void leeJugadores();
	void giraRuleta();
	void getPremios();
};

#endif