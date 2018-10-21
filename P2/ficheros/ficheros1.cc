#include <iostream>
#include <fstream>
#include <string>
//#include <ofstream> No existe
//#include <ifstream> No existe
//#include <stdlib.h>

//using namespace std;

int main() {

	std::ofstream f1;	//fichero de salida (donde se escribe)
	std::ifstream f2;	//fichero de entrada (donde se lee)
	std::fstream f3;	//fichero de E/S

	std::string patata;

	char cadena1[128] ;

	f1.open("prueba.txt");	//crea el fichero prueba.txt , si ya existe lo machaca
	f1 << "Hola manko gordo, 34, 56, Hola, 5.3\n";
	f1.close();

	/*
	std::cout << "Introduce el nombre del fichero" << std::endl;
	std::cin >> patata;
	f2.open(patata.c_str());	//para abrir con un str
	*/
	
	f3.open("prueba.txt");

	//f2.getline(patata,10, ',');
	f3 >> cadena1;

	/*
		MÉTODO: getline(cadena_en_la_que_guarda, tamanyo, caracter_para_finalizar)
	*/

	f3.getline(cadena1, 128, ',') ;	//Lee hasta el ultimo caracter antes de la coma

	std::cout << cadena1 ;

	f3.close();


}