//guess.cc
//A program that the user has to adivinate a number
#include <iostream>	//stdio de C++
#include <cstdlib>	//Libreria de C, se le pone una c al principio y se quita el .h
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int randomnum=(rand()%10)+1;
	//cout<<a;
	int usernum;
	do {
		cout << "Intente adivinar un numero entre 1 y 10: ";
		cin >> usernum;

		if(usernum < randomnum)
			cout << "\nSu numero es menor que el numero oculto\n\n";
		else if(usernum > randomnum)
			cout << "\nSu numero es mayor que el numero oculto\n\n";
	} while(usernum!=randomnum);

	cout<< "Numero Correcto. Bye Bye\n";

	return 0;
}