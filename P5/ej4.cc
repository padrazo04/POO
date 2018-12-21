// ej4.cc
// Este programa ordena un vector de forma ascendente o descendente y los muestra
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector <int> v(10);
	int opc;

	cout << "Introduzca los elementos del vector." << endl;

	for(unsigned int i=0; i<v.size(); i++) {
		cout << "v[" << i << "]= ";
		cin >> v[i];
	}

	cout << "El vector ahora mismo es:" << endl;
	cout << "v = {";
	for(unsigned int i=0; i<v.size()-1; i++) {
		cout << v[i] << ",";
	} cout << v[v.size()-1] << "}" << endl;

	cout << "Elija opcion ordenar:" << endl
		 << "1. Ascendente" << endl
		 << "Otro. Descendente" << endl
		 << "Opcion: ";
	cin >> opc;

	if(opc==1)
		sort(v.begin(), v.end(), less<int>());
	else sort(v.begin(), v.end(), greater<int>());

	cout << "Vector ordenado:" << endl;
	cout << "v = {";
	for(unsigned int i=0; i<v.size()-1; i++) {
		cout << v[i] << ",";
	} cout << v[v.size()-1] << "}" << endl;

	return 0;
}