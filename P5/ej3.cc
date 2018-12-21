// ej3.cc
// Este programa pide elementos de un vector al usurio, los ordena y los muestra
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector <int> v(10);

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

	sort(v.begin(), v.end());

	cout << "Vector ordenado:" << endl;
	cout << "v = {";
	for(unsigned int i=0; i<v.size()-1; i++) {
		cout << v[i] << ",";
	} cout << v[v.size()-1] << "}" << endl;

	return 0;
}