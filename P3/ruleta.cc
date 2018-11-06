//ruleta.cc
//Body of class roulette
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "ruleta.h"
#include "jugador.h"

Ruleta::Ruleta (Crupier crupi): crupier_(crupi) {
	bola_=-1;
	banca_=1000000;
	srand(time(NULL));
}

bool Ruleta::setBanca(int x) {
	/*x <= 0 ? return false : banca_=x ;
	return true;*/
	if(x <= 0) 
		return false;
	else { 
		banca_=x;
		return true;
	}
}

bool Ruleta::setBola(int x) {
	/*-1 < x < 37 ? banca_=x : return false;
	return true;*/
	if(x<0 || x > 36)
		return false;
	else { 
		bola_=x;
		return true;
	}
}

bool Ruleta::addJugador(Jugador player) {
	list <Jugador> :: iterator i;      // "i" is an iterator for the list jugador
	for(i=jugadores_.begin() ; i != jugadores_.end() ; i++) {
		if((*i).getDNI() == player.getDNI())
			return false;
	}
	jugadores_.push_back(player);
	string nombrefichero = player.getDNI() + ".txt";
	fstream f1(nombrefichero.c_str(), ios::in);

	if(!f1) {	//Si no existe, crea un fichero vacío
		f1.close();
		f1.open(nombrefichero.c_str(), ios::out);
		f1.close();
		return true;
	} else {	//Si ya existe, no lo modifica
		f1.close();
		return false;
	}
}

int Ruleta::deleteJugador(string nif) {
	if(jugadores_.empty()==1) return -1;

	list <Jugador> :: iterator i;      // "i" is an iterator for the list jugador
	for(i=jugadores_.begin() ; i != jugadores_.end() ; i++) {
		if((*i).getDNI() == nif){
			jugadores_.erase(i);
			return 1;
		}
	}

	return -2;
}

int Ruleta::deleteJugador(Jugador player) {
	if(jugadores_.empty()==1) return -1;

	list <Jugador> :: iterator i;      // "i" is an iterator for the list jugador
	for(i=jugadores_.begin() ; i != jugadores_.end() ; i++) {
		if((*i).getDNI() == player.getDNI()){
			jugadores_.erase(i);
			return 1;
		}
	}

	return -2;
}

void Ruleta::escribeJugadores() {
	ofstream f1("jugadores.txt");

	list <Jugador> :: iterator i;

	for(i=jugadores_.begin() ; i!=jugadores_.end() ; i++) {
		f1 << (*i).getDNI() << "," << (*i).getCodigo();
		f1 << "," << (*i).getNombre() << "," << (*i).getApellidos();
		f1 << "," << (*i).getDireccion() << "," << (*i).getLocalidad();
		f1 << "," << (*i).getProvincia() << "," << (*i).getPais();
		f1 << "," << (*i).getDinero() << endl;
	}

	f1.close();
}

void Ruleta::leeJugadores() {
	ifstream f1("jugadores.txt");

	jugadores_.clear();

	Jugador aux("11111111Z","El mejor");

	char dni[10], codigo[10], nombre[30], apellidos[30];
	char direccion[30], localidad[30], provincia[30];
	char pais[30], dinero[10];

	if(f1.is_open()) {
		while(f1.getline(dni, 10, ',')) {
			f1.getline(codigo, 10, ',');
			f1.getline(nombre, 10, ',');
			f1.getline(apellidos, 10, ',');
			f1.getline(direccion, 10, ',');
			f1.getline(localidad, 10, ',');
			f1.getline(provincia, 10, ',');
			f1.getline(pais, 10, ',');
			f1.getline(dinero, 10, '\n');
			aux.setDNI(dni);
			aux.setCodigo(codigo);
			aux.setNombre(nombre);
			aux.setApellidos(apellidos);
			aux.setDireccion(direccion);
			aux.setLocalidad(localidad);
			aux.setProvincia(provincia);
			aux.setPais(pais);
			aux.setDinero(atoi(dinero));
			jugadores_.push_back(aux);
		}
		f1.close();	
	} else cout << "Unable to open file" << endl;

}

void Ruleta::giraRuleta() {
	setBola(rand()%37);
}

void Ruleta::getPremios() {
	list <Jugador> :: iterator i;

	int gananciasBanca=0;

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
		string nombrefichero = (*i).getDNI() + ".txt";
		ifstream f1(nombrefichero.c_str());

		char codigo[10], value[10], amount[10];

		int premio=0;

		if(f1.is_open()) {
			while(f1.getline(codigo,10,',')) {
				f1.getline(value,10,',');
				f1.getline(amount,10,'\n');
				switch(atoi(codigo)) {
					case 1:
						if(atoi(value)==getBola()) {
							premio+=atoi(amount)*35;
							gananciasBanca-=atoi(amount)*35;
						}
						else {
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
						}
						break;
					case 2: {
						if(getBola()==0) {
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
							break;
						}
						string result;
						if(getBola()==(1||3||5||7||9||12||14||16||18||19||21||23||25||27||30||32||34||36))
							result="rojo";
						else result="negro";

						if(strcmp(result.c_str(),value)==0) {
							premio+=atoi(amount);
							gananciasBanca-=atoi(amount);
						}
						else {
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
						}
					} break;
					case 3: {
						if(getBola()==0) {
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
							break;
						}
						string result;
						if((getBola()%2)==0)
							result="par";
						else result="impar";

						if(strcmp(result.c_str(),value)==0) {
							premio+=atoi(amount);
							gananciasBanca-=atoi(amount);
						}
						else {
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
						}
					} break;
					case 4: {
						if(getBola()==0) { 
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
							break;
						}
						string result;
						if(getBola()<=18)
							result="bajo";
						else result="alto";

						if(strcmp(result.c_str(),value)==0) {
							premio+=atoi(amount);
							gananciasBanca-=atoi(amount);
						}
						else {
							premio-=atoi(amount);
							gananciasBanca+=atoi(amount);
						}
					} break;
					//default: //Apuesta no valida
				}
			} 
			(*i).setDinero((*i).getDinero()+premio);
			f1.close();
		} else exit(EXIT_FAILURE);
	} 
	escribeJugadores();
	setBanca(getBanca()+gananciasBanca);
}
