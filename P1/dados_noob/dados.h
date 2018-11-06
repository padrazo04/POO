//dados.h
//The class dados represents the throw of 2 dice
#ifndef DADOS_H
#define DADOS_H

class Dados {
private:
	int d1_;
	int d2_;
	int lanzd1_;
	int lanzd2_;
	float valoresd1_;
	float valoresd2_;
	int ult5d1_[5];
	int ult5d2_[5];
public:
	Dados();	//constructor, funcion que se ejecuta automáticamente al declarar un objeto de la clase
	void lanzamiento();
	inline int getLanzamientos1() const {return lanzd1_;};
	inline int getLanzamientos2() const {return lanzd2_;};
	inline int getDado1() const {return d1_;};
	inline int getDado2() const {return d2_;};
	bool setDado1(int x);
	bool setDado2(int x);
	inline int getSuma() const {return d1_+d2_;};
	int getDiferencia() const ;
	float getMedia1() const ;
	float getMedia2() const ;
	void getUltimos1(int *v) const ;
	void getUltimos2(int *v) const;
};

#endif