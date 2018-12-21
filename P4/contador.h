// contador.h
// Cabecera de la clase Contador
// Header of accountant class

#ifndef CONTADOR_H
#define CONTADOR_H

class Contador {
private:
	int valor_, min_, max_;
	int numOperaciones_;
public:
	// Al poner los parametros como const, autodocumentamos el codigo,
	// mejoramos el programa, e indicamos que los parametros no se 
	// no modifican dentro de la función.
	// -----
	// Using const parameters, we are improving the code and indicating
	// that these parameters will not be modified in the function
	Contador(const int valor=0, const int min=0, const int max=1000);

	inline int get() const {return valor_;}
	//void setValor(int val);
	//int getMin();
	//void setMin(int min);
	//int getMax();
	//void setMax(int max);

	// Los parametros son aquellos que se encuentran a la derecha
	// del operador. Devuelve una referencia para que en caso de 
	// asignación multiple no se dupliquen objetos y sea más eficiente
	// -----
	// The parameters are those that we found to the right of
	// the operator.
	Contador& operator=(const int x);
	Contador& operator=(const Contador ob);

	// En la segunda funcion se pasa un int aunque realmente no se
	// usa, es para distinguir las funciones
	// -----
	// Second function receives an int, however, it is not used, it's
	// only to recognize the functions
	Contador& operator++(void);
	Contador operator++(int);

	Contador& operator--(void);
	Contador operator--(int);

	// Si estas funciones no fuesen friend no se podria hacer
	// Contador a,b; a=10+b;
	// Pues los enteros no tienen definida la suma con Contadores
	// SOLUCION: Funciones friend que NO reciben el parámetro this
	// -----
	// If this functions hadn't been friend, the class would be
	// useless because of integers hasn't got add operation with accountant
	friend Contador operator+(const Contador ob, const int x);
	friend Contador operator+(const int x, Contador const ob);

	friend Contador operator-(const Contador ob, const int x);
	friend Contador operator-(const int x, const Contador ob);

	// Deshace las n ultimas operaciones
	// -----
	//Undo the n last operations
	bool undo(int n=1);
};

#endif