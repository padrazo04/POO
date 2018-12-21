//persona.cc
//Body of the methods of the class C++
#include <string>

#include "persona.h"

using namespace std;

Persona::Persona(string nif, string name, string ap, int age, 
				 string dir, string loc, string prov, string country) {
	dni_=nif;
	nombre_=name;
	apellidos_=ap;
	edad_=age;
	direccion_=dir;
	localidad_=loc;
	provincia_=prov;
	pais_=country;
}

void Persona::setDNI(string nif) {
	dni_=nif;
}

void Persona::setNombre(string name) {
	nombre_=name;
}

void Persona::setApellidos(string ap) {
	apellidos_=ap;
}

bool Persona::setEdad(int age) {
	if(age >= 0) {
		edad_=age;
		return true;	
	} else return false;
}

void Persona::setDireccion(string dir) {
	direccion_=dir;
}

void Persona::setLocalidad(string loc) {
	localidad_=loc;
}

void Persona::setProvincia(string prov) {
	provincia_=prov;
}

void Persona::setPais(string country) {
	pais_=country;
}

string Persona::getApellidosyNombre() const {
	return (apellidos_+", "+nombre_);
}

bool Persona::mayor() {
	return(edad_>=18 ? true : false);
}