// contador.cc
// Cuerpo de la clase Contador
// Body of Accountant class

#include "contador.h"

Contador::Contador(int valor, int min, int max) {
	if(max<min or valor<min or valor>max) {
		valor_ = 0;
		min_ = 0;
		max_ = 1000;
	} else {
		valor_ = valor;
		min_ = min;
		max_ = max;
	}

	numOperaciones_=0;
}

Contador& Contador::operator=(const int x) {
	if(x>=min_ and x<=max_)
		valor_=x;
	else if (x<min_) valor_ = min_;
	else valor_ = max_;
	return *this;
}

Contador& Contador::operator=(const Contador ob){
	valor_=ob.valor_;
	min_=ob.min_;
	max_=ob.max_;
	return *this;
}

Contador& Contador::operator++(void) {	//Prefijo: ++ob
	if(valor_ < max_) {
		valor_++;
		numOperaciones_++;
	}
	return *this;
}

// Los postfijos no pueden devolver referencias, pues apuntan
// a variables locales
Contador Contador::operator++(int) {	// Postfijo: ob++
	Contador temp = *this;
	if(valor_ < max_) {	// No se puede poner valor_++, pues compararía primero
		valor_++;
		numOperaciones_++;
	}
	return temp;
}

Contador& Contador::operator--(void) {	// Prefijo --ob
	if(valor_ > min_)
		valor_--;
	return *this;
}

Contador Contador::operator--(int) {	// Postfijo ob--;
	Contador temp = *this;
	if(valor_ > min_)
		valor_--;
	return temp;
}

Contador operator+(const Contador ob, const int x) {
	Contador aux;

	if((x+ob.get()) > ob.max_) {
		aux=ob;
		aux.valor_=ob.max_;
	} else {
		aux=ob;
		aux.valor_=ob.get()+x;
	}

	return aux;
}

Contador operator+(const int x, const Contador ob) {
	Contador aux;

	if((x+ob.get()) > ob.max_) {
		aux=ob;
		aux.valor_=ob.max_;
	} else {
		aux=ob;
		aux.valor_=x+ob.get();
	}

	return aux;
}

Contador operator-(const Contador ob, const int x) {
	Contador aux;

	if((ob.get()-x) < ob.min_) {
		aux=ob;
		aux.valor_=ob.min_;
	} else {
		aux=ob;
		aux.valor_=ob.valor_-x;
	}

	return aux;
}

Contador operator-(const int x, const Contador ob) {
	Contador aux;

	if((x-ob.get()) < ob.min_) {
		aux=ob;
		aux.valor_=ob.min_;
	} else {
		aux=ob;
		aux.valor_=x-ob.valor_;
	}

	return aux;
}

bool Contador::undo(int n) {
	if(n<0 or n>numOperaciones_)
		return false;
	for(int i=0; i<n; i++) 
		(*this)--;	//Utiliza la sobrecarga de operadores
	return true;
}