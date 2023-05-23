#pragma once
#include "Personaje.h"
#include <iostream>

class EnemigoFinal: public Personaje
{
private: 
	int superAttack;
	int megaPush;

public: 
	EnemigoFinal(int pHp, int pAtack, std::string pName, int pPosicionX, int pPosicionY,
		int pSuperAttack, int pMegaPush);

	//getters
	int getSuperAttack();
	int getMegaPush();

	//setters
	void setSuperAttack(int pSuperAttack);
	void setMegaPush(int pMegaPush);

	//metodos propios
};

