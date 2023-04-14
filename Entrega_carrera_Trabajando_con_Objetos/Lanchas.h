#pragma once
#include "iostream"

class lanchas
{
private: 
	int speed; 
	int finalDistancy;
	int nitro; 
	std::string nameRunner;


public: 

	//constructor
	lanchas(int pSpeed, int pFinalDistancy, int pNitro, std::string pNameRunner);

	//getters
	int getSpeed();
	int getFinalDistancy();
	int getNitro();
	std::string getNameRunner();

	//setters 
	void setSpeed(int pSpeed);
	void setFinalDistancy(int pFinalDistancy);
	void setNitro(int pNitro);
	void setNameRunner(std::string pNameRunner);

	//metodo propio
	void printStatistics();
	int speedActual(int dado);
	int distanciaParcial();
	void usoNitro(int opcion);
};

