//ruleta.cc
//Body af class roulette
<<<<<<< HEAD
#include <iostream>		// cout object
#include <string>		// string object
#include <list>			// push_back(), empty(), erase() 
#include <fstream>		// ifstream, ofstream and fstream objects, getline()
#include <cstdlib>		// exit, rand
#include <ctime>		// srand
#include <cstring>		// strcmp()

#include "ruleta.h"		// Header of roulette
#include "jugador.h"	// Jugador object
=======
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "ruleta.h"
#include "jugador.h"
>>>>>>> b68a61545bb82cb393a7761073b67604167a1f33

Ruleta::Ruleta (Crupier crupi): crupier_(crupi) {
	bola_=-1;
	banca_=1000000;
	srand(time(NULL));	// Needed to use function rand() correctly
}

bool Ruleta::setBanca(int x) {
	if(x <= 0) 
		return false;
	else { 
		banca_=x;
		return true;
	}
}

bool Ruleta::setBola(int x) {
	if(x<0 || x > 36)
		return false;
	else { 
		bola_=x;
		return true;
	}
}

bool Ruleta::addJugador(Jugador player) {
	list <Jugador> :: iterator i;      	// "i" is an iterator for the list jugador

	for(i=jugadores_.begin() ; i != jugadores_.end() ; i++) {
		if((*i).getDNI() == player.getDNI())
			return false;
	}

	jugadores_.push_back(player);		//adds a player at the end of the list
	string nombrefichero = player.getDNI() + ".txt";
	fstream f1(nombrefichero.c_str(), ios::in);	//open the file at reading mode

	if(!f1) {	//If the file doesn't exist, it creates a new one
		f1.close();
		f1.open(nombrefichero.c_str(), ios::out);
		f1.close();
		return true;
	} else {	//If the file already exists, it doesn't modify the file and closes it
		f1.close();
		return false;
	}
}

int Ruleta::deleteJugador(string nif) {
	if(jugadores_.empty()==1) return -1;

	list <Jugador> :: iterator i;      // "i" is an iterator for the list jugador
	for(i=jugadores_.begin() ; i != jugadores_.end() ; i++) {
		if((*i).getDNI() == nif){
			jugadores_.erase(i);		// Erase the element with i address and scroll to left the rest of elements 
			return 1;
		}
	}

	return -2;	// If for loop finishes, it means that player isn't in the list
}

// It is not problem that both functions have the same name. C++ knows the
// function that we are calling because of the parameters

int Ruleta::deleteJugador(Jugador player) {
	if(jugadores_.empty()==1) return -1;

	list <Jugador> :: iterator i;      	// "i" is an iterator for the list jugador
	for(i=jugadores_.begin() ; i != jugadores_.end() ; i++) {
		if((*i).getDNI() == player.getDNI()){
			jugadores_.erase(i);		// Erase the element with i address and scroll to left the rest of elements 
			return 1;
		}
	}

	return -2;	// If for loop finishes, it means that player isn't in the list
}

void Ruleta::escribeJugadores() {
	ofstream f1("jugadores.txt");

	list <Jugador> :: iterator i;

	for(i=jugadores_.begin() ; i!=jugadores_.end() ; i++) {
		f1 << (*i).getDNI() << "," << (*i).getCodigo();		// Write each parameter at the file
		f1 << "," << (*i).getNombre() << "," << (*i).getApellidos();
		f1 << "," << (*i).getDireccion() << "," << (*i).getLocalidad();
		f1 << "," << (*i).getProvincia() << "," << (*i).getPais();
		f1 << "," << (*i).getDinero() << endl;		// Finish the line with an endline
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
		while(f1.getline(dni, 10, ',')) {	// First, read the file and save data in char arrays
			f1.getline(codigo, 10, ',');
			f1.getline(nombre, 10, ',');
			f1.getline(apellidos, 10, ',');
			f1.getline(direccion, 10, ',');
			f1.getline(localidad, 10, ',');
			f1.getline(provincia, 10, ',');
			f1.getline(pais, 10, ',');
			f1.getline(dinero, 10, '\n');
			aux.setDNI(dni);				// Then set the player with the values
			aux.setCodigo(codigo);
			aux.setNombre(nombre);
			aux.setApellidos(apellidos);
			aux.setDireccion(direccion);
			aux.setLocalidad(localidad);
			aux.setProvincia(provincia);
			aux.setPais(pais);
			aux.setDinero(atoi(dinero));
			jugadores_.push_back(aux);		// Finally, adds the player at the end of the list
		}
		f1.close();	// Don't forget to close the file!
	} else cout << "Unable to open file" << endl;

}

void Ruleta::giraRuleta() {
	setBola(rand()%37);		// Returns a number between 0 and 36
}

void Ruleta::getPremios() {
	list <Jugador> :: iterator i;

	int gananciasBanca=0;	// Profit or loss of the bank

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++)	// Go down the list and evaluates the bets of each player
		getPremiosJugador(i, gananciasBanca);				// Update each player
	escribeJugadores();										// Update the players file
	setBanca(getBanca()+gananciasBanca);					// Update the capital of the bank
}

// This member receives the iterator to target the player and the capital of the bank (by references)
void Ruleta::getPremiosJugador(list <Jugador> :: iterator player, int &gananciasBanca) {
	string nombrefichero = (*player).getDNI() + ".txt";
	ifstream f1(nombrefichero.c_str());					// Open the file "DNI.txt"

	char codigo[10], value[10], amount[10];	// Char arrays to read the file

	int premio=0;		// Profit or loss of each player

	if(f1.is_open()) {	// Check that file has been opened
		while(f1.getline(codigo,10,',')) {
			f1.getline(value,10,',');
			f1.getline(amount,10,'\n');		// Save data in char arrays to evaluate the bets
			switch(atoi(codigo)) {			// Evaluate the type of bets
				case 1:		// Bet on a number
					if(atoi(value)==getBola()) {	// Evaluates if player's bet is correct
						premio+=atoi(amount)*35;	
						gananciasBanca-=atoi(amount)*35;// If the player wins, bank loses
					}
					else {
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);	// If the player loses, bank wins
					}
				break;
				case 2: {	// Bet on a color
					if(getBola()==0) {	// With number 0, the player loses
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);
						break;
					}
					string result;
					if(getBola()==(1||3||5||7||9||12||14||16||18||19||21||23||25||27||30||32||34||36))	
						result="rojo";	// All red numbers in roulette
					else result="negro";

					if(strcmp(result.c_str(),value)==0) {	// Evaluates if player's bet is correct
						premio+=atoi(amount);
						gananciasBanca-=atoi(amount);	// If the player wins, bank loses
					}
					else {
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);	// If the player loses, bank wins
					}
				} break;
				case 3: {	// Bet on even/odd number (par/impar)
					if(getBola()==0) {	// With number 0, the player loses
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);		
						break;
					}
					string result;
					if((getBola()%2)==0)
						result="par";
					else result="impar";

					if(strcmp(result.c_str(),value)==0) {	// Evaluates if player's bet is correct
						premio+=atoi(amount);
						gananciasBanca-=atoi(amount);	// If the player wins, bank loses
					}
					else {
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);	// If the player loses, bank wins
					}
				} break;
				case 4: {	// Bet on a small/tall number
					if(getBola()==0) { 	// With number 0, the player loses
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);
						break;
<<<<<<< HEAD
					}
					string result;
					if(getBola()<=18)
						result="bajo";
					else result="alto";

					if(strcmp(result.c_str(),value)==0) {	// Evaluates if player's bet is correct
						premio+=atoi(amount);
						gananciasBanca-=atoi(amount);	// If the player wins, bank loses
					}
					else {
						premio-=atoi(amount);
						gananciasBanca+=atoi(amount);	// If the player loses, bank wins
					}	
				} break;
				//default: //Invalid bet
			}
		} 
		(*player).setDinero((*player).getDinero()+premio);	// Update the player's money
		f1.close();									// Don't forget to close the file
	} else exit(EXIT_FAILURE);						// If the file couldn't open, exit with value of error
}
=======
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
>>>>>>> b68a61545bb82cb393a7761073b67604167a1f33
