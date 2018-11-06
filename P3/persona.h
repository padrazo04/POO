//persona.h
//The class that represents a person
#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
private:
	string dni_, nombre_, apellidos_, direccion_;
	string localidad_, provincia_, pais_;
	int edad_; 
public:
	Persona(string nif, string name="", string ap="", int age=0, string dir="", 
			string loc="", string prov="", string country="");
	void setDNI(string nif);
	inline string getDNI() const {return dni_;}
	void setNombre(string name);
	inline string getNombre() const {return nombre_;}
	void setApellidos(string ap);
	inline string getApellidos() const {return apellidos_;}
	bool setEdad(int age);
	inline int getEdad() const {return edad_;}
	void setDireccion(string dir);
	inline string getDireccion() const {return direccion_;}
	void setLocalidad(string loc);
	inline string getLocalidad() const {return localidad_;}
	void setProvincia(string prov);
	inline string getProvincia() const {return provincia_;}
	void setPais(string country);
	inline string getPais() const {return pais_;}
	string getApellidosyNombre() const;
	bool mayor();
};

#endif
