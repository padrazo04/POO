//dados.h
//The class dados represents the throw of 2 dice
#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <vector>

using namespace std;

class Dados {
private:
	int d1_, d2_;
	int lanzd1_, lanzd2_;
	float valoresd1_, valoresd2_;
	vector <int> ult5d1_;	//vector <int> ult5d1_(5); NO SIRVE
	vector <int> ult5d2_;
public:
	Dados();
	void lanzamiento();
	inline int getLanzamientos1() const {return lanzd1_;}
	inline int getLanzamientos2() const {return lanzd2_;}
	inline int getDado1() const {return d1_;}
	inline int getDado2() const {return d2_;}
	bool setDado1(int x);
	bool setDado2(int x);
	inline int getSuma() const {return d1_+d2_;}
	inline int getDiferencia() const {return (d1_>d2_ ? d1_-d2_ : d2_-d1_);}
	float getMedia1() const ;
	float getMedia2() const ;
	void getUltimos1(int *v) const;
	void getUltimos2(int *v) const;

	friend ostream& operator<<(ostream &stream, const Dados& dado);
	friend istream& operator>>(istream &stream, Dados& dado);
};

#endif