#include <iostream>
#include "Lanchas.h"
using namespace std;

int dado;
int nitroJugador;
int opcion;

int lanzamientoDado() {
	return dado = rand() % (7 - 1) + 1;
}



void runStart() {
	cout << "Bienvenido a la gran carrera final de lanchas de España.\n";

}


int main() {
	srand(time(NULL));
	
	runStart();

	lanchas lancha1(0, 0, 1, "Joel");
	lanchas lancha2(0, 0, 1, "Corredor Aspirante");

	cout << "Empieza la carrera\n" << endl;

	for (size_t i = 1; i <= 5; i++)
	{	
		cout << "El jugador " << lancha1.getNameRunner() << " va a una velocidad de " << lanzamientoDado() << " marchas\n" << endl;
		cout << "Ahora este jugador lleva una velocidad de " << lancha1.speedActual(dado) << " marchas\n" << endl;
		
		cout << "Por el momento este jugador lleva recorrida una distancia de " << lancha1.distanciaParcial() << " metros\n" << endl;
		

		lancha1.usoNitro(opcion);

		cout << "El jugador " << lancha2.getNameRunner() << " va a una velocidad de " << lanzamientoDado() << " marchas\n" << endl;
		cout << "Ahora este jugador lleva una velocidad de " << lancha2.speedActual(dado) << " marchas\n" << endl;
		cout << "Por el momento este jugador lleva recorrida una distancia de " << lancha2.distanciaParcial() << " metros\n" << endl;
		
		lancha2.usoNitro(opcion);

	}
	cout << "La carrera ha finalizado y es hora de ver quien ha ganado\n" << endl;
	if (lancha1.getFinalDistancy() > lancha2.getFinalDistancy())
	{
		cout << " EL GANADOR DE LA CARRERA ES " << lancha1.getNameRunner() << " ¡GRAN CARRERA!\n" << endl;
	}
	else {
		cout << " EL GANADOR DE LA CARRERA ES " << lancha2.getNameRunner() << " ¡GRAN CARRERA!\n" << endl;
	}
}



