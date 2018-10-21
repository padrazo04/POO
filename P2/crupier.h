//crupier.h
//The class that represents a croupier
#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include "persona.h"

using namespace std;

class Crupier : public Persona {
private:
	string cod_;
public:
	inline Crupier(string nif, string code, string name="", string ap="", int age=0, string dir="",
		    string loc="", string prov="", string country="") : Persona(nif, name, ap, age, 
		    dir, loc, prov, country) {cod_=code;}
	void setCodigo(string code);
	inline string getCodigo() const {return cod_;}
};

#endif