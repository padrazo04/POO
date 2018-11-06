//dados.cc
//Cuerpo de los métodos de la clase dados
#include <cstdlib>
#include <ctime>
#include <vector>

#include "dados.h"

using namespace std;

Dados::Dados() {
	srand(time(NULL));
	d1_=1;
	d2_=1;
	lanzd1_=0;
	lanzd2_=0;
	valoresd1_=0;
	valoresd2_=0;
	ult5d1_.resize(5,0);
	ult5d2_.resize(5,0);
}

void Dados::lanzamiento() {
	setDado1(rand()%6+1);
	setDado2(rand()%6+1);
}

bool Dados::setDado1(int x) {
	if((x<7) && (x>0)) {
		d1_=x;
		lanzd1_++;
		valoresd1_+=d1_;
		ult5d1_.insert(ult5d1_.begin(), x);
		ult5d1_.pop_back();
		return true;
	} else return false;
}

bool Dados::setDado2(int x) {
	if((x<7) && (x>0)) {
		d2_=x;
		lanzd2_++;
		valoresd2_+=d2_;
		ult5d2_.insert(ult5d2_.begin(), x);
		ult5d2_.pop_back();
		return true;
	} else return false;
}

int Dados::getDiferencia() const {
	return(d1_>d2_ ? d1_-d2_ : d2_-d1_);
}

float Dados::getMedia1() const {
	if(lanzd1_== 0)
		return 0;
	return valoresd1_/(float)lanzd1_;
}

float Dados::getMedia2() const {
	if(lanzd2_== 0)
		return 0;
	return valoresd2_/(float)lanzd2_;
}

void Dados::getUltimos1(int *v) const {
	for(int i=0 ; i<(int)ult5d1_.size() ; i++)
		v[i]=ult5d1_[i];
}

void Dados::getUltimos2(int *v) const {
	for(int i=0 ; i<(int)ult5d2_.size() ; i++)
		v[i]=ult5d2_[i];
}