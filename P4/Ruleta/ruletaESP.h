// P4
// Espacio de nombres ruleta
#ifndef RULETAESP_H
#define RULETAESP_H

namespace ruleta {

	#include <list>	// AQUI O FUERA ??
	#include <string> // AQUI O FUERA ??

	using namespace std; // ??

	// PERSON CLASS
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

	// BET STRUCT
	struct Apuesta {
		int tipo;
		string valor;
		int cantidad;
	};

	// PLAYER CLASS
	class Jugador: public Persona {
	private:
		int dinero_;
		string cod_;
		list <Apuesta> apuestas_;
	public:
		inline Jugador(string nif, string code, string name="", string ap="", int age=0, 
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

	// CRUPIER CLASS
	class Crupier : public Persona {
	private:
		string cod_;
	public:
		inline Crupier(string nif, string code, string name="", string ap="", int age=0, string dir="",
			    string loc="", string prov="", string country="") : Persona(nif, name, ap, age, 
			    dir, loc, prov, country) { cod_=code; }
		void setCodigo(string code);
		inline string getCodigo() const { return cod_; }
	};

	// ROULETTE CLASS
	class Ruleta {
	private:
		int banca_, bola_, lanzamientos_;
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

		void getEstadoRuleta(int &numJugadores, int &dineroTotal, int &lanzamientos, 
			int &gananciasBanca);

		/**OWN METHODS**/

		void getPremiosJugador(list <Jugador> :: iterator player, int &gananciasBanca);
	};
}

#endif