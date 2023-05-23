#include <iostream>
#include "EnemigoFinal.h"
#include "Personaje.h"
#include <conio.h>

const int MAP_SIZE = 5;


// Función para imprimir el mapa en la consola
void imprimirMapa(char mapa[][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            std::cout << mapa[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void comienzoBatalla(Personaje& jugador, Personaje& enemigo) {
    //Informacion de inicio
    std::cout << "Comienza la batalla contra " << enemigo.getName() << std::endl;
    std::cout << "Sera capaz nuestro heroe de hacer frente a este temible enemigo? Comprobemoslo" << std::endl;
    while (jugador.getHp() > 0 && enemigo.getHp() > 0)
    {
        //turno heroe
        std::cout << "Es turno de ataque del heroe" << std::endl; 
        enemigo.setHp(enemigo.getHp() - jugador.getAtack());
        std::cout << "El heroe ha lanzado su ataque y ha quitado un total de vida de " << jugador.getAtack() << std::endl;
        
        //comprobar si el enemigo esat vivo
        if (enemigo.getHp() <=0 )
        {
            std::cout << "El " << enemigo.getName() << " ha sido derrotado y el heore sigue su camino " << std::endl;
            break;
        }

        //turno enemigo
        std::cout << "Es turno del " << enemigo.getName() << std::endl;
        jugador.setHp(jugador.getHp() - enemigo.getAtack());
        std::cout << "El enemigo ha lanzado su ataque y le ha qutiado al heroe un total de vida de " << enemigo.getAtack() << std::endl;

        //comprobar si el jugador esta vivo
        if (jugador.getHp() <= 0) 
        {
            std::cout << " El jugador " << jugador.getName() << " ha sido derrotado y el heroe no ha conseguido su objetivo de salir del mapa. " << std::endl;
            break;
        }

        std::cout << std::endl;
        std::cout << " Vida del heroe = " << jugador.getHp() << std::endl;
        std::cout << " Vida del enemigo = " << enemigo.getHp() << std::endl;
        std::cout << std::endl;

        std::cout << "Para continuar, presiona la tecla enter." << std::endl; 
        _getch();
    }
}

void batallaFinal(Personaje& jugador, EnemigoFinal& EnemigoFinal) {
    std::cout << "Comienza la batalla contra " << EnemigoFinal.getName() << std::endl;
    std::cout << "Sera capaz nuestro heroe de hacer frente a este grandioso enemigo? Comprobemos si puede salir del mapa vivo..." << std::endl;
    while (jugador.getHp() > 0 && EnemigoFinal.getHp() > 0)
    {
        //turno heroe
        std::cout << "Es turno de ataque del heroe" << std::endl;
        EnemigoFinal.setHp(EnemigoFinal.getHp() - jugador.getAtack());
        std::cout << "El heroe ha lanzado su ataque y ha quitado un total de vida de " << jugador.getAtack() << std::endl; 

        //comprobar si el enemigo esat vivo
        if (EnemigoFinal.getHp() <= 0)
        {
            std::cout << "El " << EnemigoFinal.getName() << " ha sido derrotado y el heore sigue su camino " << std::endl;
            break;
        }

        //turno enemigo final 
        
        std::cout << "Es turno del " << EnemigoFinal.getName() << std::endl;
        int seleccionAtaque = rand() % 3 + 1;
        if (seleccionAtaque == 1)
        {
            jugador.setHp(jugador.getHp() - EnemigoFinal.getAtack());
            std::cout << "El enemigo ha lanzado su ataque y le ha qutiado al heroe un total de vida de " << EnemigoFinal.getAtack() << std::endl;
        }
        else if (seleccionAtaque == 2)
        {
            jugador.setHp(jugador.getHp() - EnemigoFinal.getSuperAttack());
            std::cout << "El enemigo ha lanzado su ataque y le ha qutiado al heroe un total de vida de " << EnemigoFinal.getSuperAttack() << std::endl;
        }
        else if (seleccionAtaque == 3)
        {
            jugador.setHp(jugador.getHp() - EnemigoFinal.getMegaPush());
            std::cout << "El enemigo ha lanzado su ataque y le ha qutiado al heroe un total de vida de " << EnemigoFinal.getMegaPush() << std::endl;
        }
        //comprobar si el jugador esta vivo 
        if (jugador.getHp() <= 0)
        {
            std::cout << " El jugador " << jugador.getName() << " ha sido derrotado y el heroe no ha conseguido su objetivo de salir del mapa. " << std::endl;
            break;
        }

        std::cout << std::endl;
        std::cout << " Vida del heroe = " << jugador.getHp() << std::endl;
        std::cout << " Vida del enemigo = " << EnemigoFinal.getHp() << std::endl;
        std::cout << std::endl;

        std::cout << "Para continuar, presiona la tecla enter." << std::endl;
        _getch();
    }
}

int main() {
    srand(time(NULL));

    //CREACION PERSONAJE
    Personaje jugador(100, 45, "Joel", 0, 0);

    //CREACION ENEMIGOS NORMALES
    Personaje enemigo1(100, rand() % 30 + 1, "Enemigo1", 0, 0);
    Personaje enemigo2(100, rand() % 30 + 1, "Enemigo2", 0, 0);
    Personaje enemigo3(100, rand() % 30 + 1, "Enemigo3", 0, 0);

    //CREACIÓN ENEMIGO FINAL
    EnemigoFinal EnemigoFinal(120, rand() % 50 + 1, "Villano", 0, 0, 80, 90);

    // Colocar enemigo 1 en una posición aleatoria del mapa sin que ocupe las mismas posiciones que los otros dos enemigos
    do {
        enemigo1.setPosicionX(rand() % MAP_SIZE);
        enemigo1.setPosicionY(rand() % MAP_SIZE);
    } while (enemigo1.getPosicionX() == jugador.getPosicionX() && enemigo1.getPosicionY() == jugador.getPosicionY());

    // Colocar enemigo 2 en una posición aleatoria del mapa sin que ocupe las mismas posiciones que los otros dos enemigos 
    do {
        enemigo2.setPosicionX(rand() % MAP_SIZE);
        enemigo2.setPosicionY(rand() % MAP_SIZE);
    } while ((enemigo2.getPosicionX() == jugador.getPosicionX() && enemigo2.getPosicionY() == jugador.getPosicionY())
        || (enemigo2.getPosicionX() == enemigo1.getPosicionX() && enemigo2.getPosicionY() == enemigo1.getPosicionY()));

    //Colocar enemigo 3 en el mapa sin que ocupe las mismas posiciones que los otros dos enemigos
    do {
        enemigo3.setPosicionX(rand() % MAP_SIZE);
        enemigo3.setPosicionY(rand() % MAP_SIZE);
    } while ((enemigo3.getPosicionX() == jugador.getPosicionX() && enemigo3.getPosicionY() == jugador.getPosicionY())
        || (enemigo3.getPosicionX() == enemigo1.getPosicionX() && enemigo3.getPosicionY() == enemigo1.getPosicionY())
        || (enemigo3.getPosicionX() == enemigo2.getPosicionX() && enemigo3.getPosicionY() == enemigo2.getPosicionY()));

    //Colocar enemigo final en el mapa sin que ocupe las mismas posiciones que los enemigos
    do {
        EnemigoFinal.setPosicionX(rand() % MAP_SIZE);
        EnemigoFinal.setPosicionY(rand() % MAP_SIZE);
    } while ((EnemigoFinal.getPosicionX() == jugador.getPosicionX() && EnemigoFinal.getPosicionY() == jugador.getPosicionY())
        || (EnemigoFinal.getPosicionX() == enemigo1.getPosicionX() && EnemigoFinal.getPosicionY() == enemigo1.getPosicionY())
        || (EnemigoFinal.getPosicionX() == enemigo2.getPosicionX() && EnemigoFinal.getPosicionY() == enemigo2.getPosicionY())
        || (EnemigoFinal.getPosicionX() == enemigo3.getPosicionX() && EnemigoFinal.getPosicionY() == enemigo3.getPosicionY()));

    char mapa[MAP_SIZE][MAP_SIZE] = {
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},  
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'}
    };

    // Colocar enemigos en el mapa
    mapa[enemigo1.getPosicionY()][enemigo1.getPosicionX()] = 'E';
    mapa[enemigo2.getPosicionY()][enemigo2.getPosicionX()] = 'E';
    mapa[enemigo3.getPosicionY()][enemigo3.getPosicionX()] = 'E';
    mapa[EnemigoFinal.getPosicionY()][EnemigoFinal.getPosicionX()] = 'V';

    int jugadorX = jugador.getPosicionX();  // Posición inicial del jugador en el eje X
    int jugadorY = jugador.getPosicionY();  // Posición inicial del jugador en el eje Y

    char tecla;
    bool gameover = false;

    while (!gameover) {
      system("cls");  // Limpia la consola antes de imprimir el mapa actualizado
        imprimirMapa(mapa);

        // Leer la tecla presionada
        tecla = _getch();

        // Mover el jugador
        switch (tecla) {
        case 'w':  // Flecha arriba
            if (jugadorY > 0) {
                mapa[jugadorY][jugadorX] = '*';
                jugadorY--;
                mapa[jugadorY][jugadorX] = 'P';
            }
            break;
        case 's':  // Flecha abajo
            if (jugadorY < MAP_SIZE - 1) {
                mapa[jugadorY][jugadorX] = '*';
                jugadorY++;
                mapa[jugadorY][jugadorX] = 'P';
            }
            break;
        case 'a':  // Flecha izquierda
            if (jugadorX > 0) {
                mapa[jugadorY][jugadorX] = '*';
                jugadorX--;
                mapa[jugadorY][jugadorX] = 'P';
            }
            break;
        case 'd':  // Flecha derecha
            if (jugadorX < MAP_SIZE - 1) {
                mapa[jugadorY][jugadorX] = '*';
                jugadorX++;
                mapa[jugadorY][jugadorX] = 'P';
            }
            break;
        case 'q':  // Tecla 'q' para salir del juego
            gameover = true;
            break;
        }

        if (jugadorX == enemigo1.getPosicionX() && jugadorY == enemigo1.getPosicionY()) {
            comienzoBatalla(jugador, enemigo1);
            
        }
        else if (jugadorX == enemigo2.getPosicionX() && jugadorY == enemigo2.getPosicionY()) {
            comienzoBatalla(jugador, enemigo2);
            
        }

        else if (jugadorX == enemigo3.getPosicionX() && jugadorY == enemigo3.getPosicionY()) {
            
            comienzoBatalla(jugador, enemigo3);
        }

        else if (jugadorX == EnemigoFinal.getPosicionX() && jugadorY == EnemigoFinal.getPosicionY()) {

            batallaFinal(jugador, EnemigoFinal);
            std::cout << "EL JUEGO HA LLEGADO A SU FIN" << std::endl;
            break;
        }
       
    }
}
