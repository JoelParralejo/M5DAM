#pragma once
#include "lanchas.h"
#include "iostream"


//constructor
lanchas::lanchas(int pSpeed, int pFinalDistancy, int pNitro, std::string pNameRunner) {
	
	speed = pSpeed;
	finalDistancy = pFinalDistancy;
	nitro = pNitro; 
	nameRunner = pNameRunner;
}

//getters 
int lanchas::getSpeed() {
	return speed;
}

int lanchas::getFinalDistancy() {
	return finalDistancy; 
}

int lanchas::getNitro() {
	return nitro; 
}

std::string lanchas::getNameRunner() {
	return nameRunner;
}

//setters 
void lanchas::setSpeed(int pSpeed) {
	speed = pSpeed;
}

void lanchas::setFinalDistancy(int pFinalDistancy) {
	finalDistancy = pFinalDistancy;
}

void lanchas::setNitro(int pNitro) {
	nitro = pNitro;
}

void lanchas::setNameRunner(std::string pNameRunner) {
	nameRunner = pNameRunner;
}

//metodos propios
void lanchas::printStatistics() {
	std::cout << getNameRunner() << " ha recorrido una distancia de " << getFinalDistancy() << ". " << std::endl;
}

int lanchas::speedActual(int dado) {
	speed = getSpeed() + dado;
	return speed;
}

int lanchas::distanciaParcial() {
	finalDistancy = getFinalDistancy() + (speed * 100);
	return finalDistancy;
}

void lanchas::usoNitro(int opcion)
{
	if (getNitro() == 1) {
		std::cout << "¿Quieres usar el nitro? (1: Sí, 2: No): ";
		std::cin >> opcion;
		if (opcion == 1) {
			setNitro(0);
			int aleatorio = rand() % 2;
			if (aleatorio == 0) {
				setSpeed(getSpeed() / 2);
				std::cout << "La velocidad de " << getNameRunner() << " se ha dividido por la mitad" << std::endl;
			}
			else {
				setSpeed(getSpeed() * 2);
				std::cout << "La velocidad de " << getNameRunner() << " se ha multiplicado por dos" << std::endl;
			}
		}
	}

}