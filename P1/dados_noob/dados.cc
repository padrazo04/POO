//dados.cc
//Cuerpo de los métodos de la clase dados
#include <cstdlib>
#include <ctime>

#include "dados.h"

Dados::Dados() {
	srand(time(NULL));
	d1_=1;
	d2_=1;
	lanzd1_=0;
	lanzd2_=0;
	valoresd1_=0;
	valoresd2_=0;
	for(int i=0 ; i<5 ; i++) {
		ult5d1_[i]=0;
		ult5d2_[i]=0;
	}
}

void Dados::lanzamiento() {
	d1_=rand()%6+1;
	d2_=rand()%6+1;
	lanzd1_++;
	lanzd2_++;
	valoresd1_+=d1_;
	valoresd2_+=d2_;

	for(int i=4 ; i>0 ; i--) {
		ult5d1_[i]=ult5d1_[i-1];
		ult5d2_[i]=ult5d2_[i-1];
	}
	ult5d1_[0]=d1_;
	ult5d2_[0]=d2_;
}

bool Dados::setDado1(int x) {
	if((x<7) && (x>0)) {
		d1_=x;
		lanzd1_++;
		valoresd1_+=d1_;
		for(int i=4 ; i>0 ; i--)
			ult5d1_[i]=ult5d1_[i-1];
		ult5d1_[0]=d1_;
		return true;
	} else return false;
}

bool Dados::setDado2(int x) {
	if((x<7) && (x>0)) {
		d2_=x;
		lanzd2_++;
		valoresd2_+=d2_;
		for(int i=4 ; i>0 ; i--)
			ult5d2_[i]=ult5d2_[i-1];
		ult5d2_[0]=d2_;
		return true;
	} else return false;
}

int Dados::getDiferencia() const {
	if(d1_>d2_)
		return (d1_-d2_);
	else return (d2_-d1_);	
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
	for (int i = 0 ; i < 5 ; i++)
		v[i]=ult5d1_[i];
}

void Dados::getUltimos2(int *v) const {
	for (int i = 0 ; i < 5 ; i++)
		v[i]=ult5d2_[i];
}