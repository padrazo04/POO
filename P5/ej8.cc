// ej8.cc
// 

#include <iostream>

using namespace std;

template <class T> class MiClase {
	private:
		T x_, y_;
	public:
		inline MiClase(T a=0, T b=0) {x_=a; y_=b;}
		inline T div() {return x_/y_;}
		inline T sum() {return x_+y_;}
		inline T mayor() {return (x_>y_);}
		inline T menor() {return (x_ < y_);}
		inline void aumenta(T a, T b) {
			x_+=a;
			y_+=b;
		}	
};

int main() {
	MiClase <int> prueba1;
	MiClase <int> prueba2(5,10);

	prueba1.aumenta(3, 1);
	cout << prueba1.div() << endl; // Debe salir 3 

	cout << prueba2.sum() << endl; // Debe salir 15
	
	if(prueba1.mayor()) {
		cout << "El dato 1 es mayor que el dato 2" << endl;
	}

	if(prueba2.menor()) {
		cout << "El dato 1 es menor que el dato 2" << endl;
	}

	return 0;
}