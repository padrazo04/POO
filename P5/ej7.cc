// ej7.cc
// Usa una plantilla para imprimir un vector

#include <iostream>

using namespace std;

template <class T>
void imprimeVector(T *v, int n) {
	for(int i=0; i<n; i++)
		cout << v[i] << ", ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int a[5] = {4,2,62,7,3};
	float b[5] = {4.5,2.6,7.0,3,4.3};
	char c[5] = "info";

	imprimeVector(a, 5);
	imprimeVector(b, 5);
	imprimeVector(c, 5);

	return 0;
}