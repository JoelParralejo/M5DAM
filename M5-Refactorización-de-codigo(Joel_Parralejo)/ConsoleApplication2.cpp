// ConsoleApplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

//Atributos del enemigo 1
int enemyHP = 2000;
string enemyname = "Malo";
bool enemyIsAlive = true;
int enemydamage1;

//Atributos del enemigo2
int enemy2HP = 2000;
string enemyname2 = "Super Malo";
bool enemyIsAlive2 = true;
int enemydamage2;


//Atributos del heroe
string heroName;
int heroDamage;
int heroHP = 12000;
bool heroIsAlive = true;
int heroElection;
string specialherodamage;
int limit = 2;

void gameStart() {
    cout << "El enemigo " << enemyname << " acaba de aparecer y tiene " << enemyHP << " puntos de vida\n";
    cout << "El enemigo dos " << enemyname2 << " acaba de aparecer y tiene " << enemy2HP << " puntos de vida\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}

bool checkHeroLive() {
    if (heroHP <= 0) {
        cout << "Has derrotado al heroe " << heroName << "\n";
        heroHP = 0; 
        return true; 
        //heroIsAlive = false; 
    }
   
}



void checkAndAttack(int& eHP, bool& eIsAlive, int enemyDamage, string pEnemyName) {
    if (eHP <= 0) {
        eHP = 0;
        eIsAlive = false;
        cout << "El enemigo " << pEnemyName << " ha sido derrotado\n";
    }

    if (eIsAlive) {
        heroHP = heroHP - enemyDamage;
        cout << pEnemyName << " te ha hecho " << enemyDamage << " puntos de danyo y te quedan " << heroHP << " puntos de vida\n";
    }
}


int enemyelection() {
    cout << "A que enemigo quieres atacar?\n";
    cin >> heroElection;
    return heroElection;
}

void attackElection() {
    cout << "Que ataque especial quieres hacerle al enemigo? (laser, rodillazo, gancho, espada) \n";
    cin >> specialherodamage;

    if (specialherodamage == "laser") {
        heroDamage = 1500;

    }

    else if (specialherodamage == "rodillazo") {

        if (limit > 0) {
            heroDamage = 500;
            limit = limit - 1;

        }
        else if (limit == 0) {
            heroDamage = 0;
            cout << " no puedes hacer este ataque\n";
        }
    }
    else if (specialherodamage == "gancho") {
        heroDamage = 900;

    }

    else if (specialherodamage == "espada") {
        heroDamage = 1200;

    }

    else {
        cout << "Has errado el ataque\n";
        heroDamage = 0;
    }
}


void aleatorydamage(int& enemyDamage) {
    enemyDamage = 250 + rand() % (1200 - 0);
    if (enemyIsAlive == false) {
        enemydamage1 = 0;
    }
    else if (enemyIsAlive2 == false ) {
        enemydamage2 = 0;
    }
    
}



int main()
{
    gameStart();

    srand(time(NULL));

    while ((enemyIsAlive == true || enemyIsAlive2 == true) && heroIsAlive == true) {

       
        attackElection();


        enemyelection(); 

        /*Parametro por referencia*/
        aleatorydamage(enemydamage1); 

        aleatorydamage(enemydamage2); 

        if (heroElection == 1)
        {
            enemyHP = enemyHP - heroDamage;
            cout << "Al enemigo le quedan " << enemyHP << " puntos de vida y a super malo " << enemy2HP << "puntos de vida\n";
        }
        else if (heroElection == 2)
        {
            enemy2HP = enemy2HP - heroDamage;
            cout << "A super malo le quedan " << enemy2HP << " puntos de vida y a malo " << enemyHP << "puntos de vida\n";
        }
        else {
            cout << "Has fallado, no hay mas enemigos \n"; 
        }

        /*Parametro por referencia*/
        checkAndAttack(enemyHP, enemyIsAlive, enemydamage1, enemyname);
        checkAndAttack(enemy2HP, enemyIsAlive2, enemydamage2, enemyname2);
        
        checkHeroLive();

    }

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
