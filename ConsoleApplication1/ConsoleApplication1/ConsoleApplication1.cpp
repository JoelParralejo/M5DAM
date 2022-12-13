// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std; 

//Atributos del enemigo 1
int enemyHP = 2000; 
string enemyname = "Malo"; 
bool enemyIsAlive = true;
int enemydamage; 

//Atributos del enemigo2
int enemy2HP = 2000; 
string enemyname2 = "Super Malo";
bool enemyIsAlive2 = true; 
int enemydamage2; 


//Atributos del heroe
string heroName; 
int heroDamage; 
int heroHP = 5000; 
bool heroIsAlive = true; 
int heroElection;
string specialherodamage;
int limit = 2; 

int main()
{


    cout << "El enemigo " << enemyname << " acaba de aparecer y tiene " << enemyHP << " puntos de vida\n";
    cout << "El enemigo dos " << enemyname2 << " acaba de aparecer y tiene " << enemy2HP << " puntos de vida\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroName; 
    cout << "El nombre del heroe es " << heroName << "\n";  
    
    while ((enemyIsAlive == true || enemyIsAlive2 == true) && heroIsAlive == true) {

       
            cout << "Que ataque especial quieres hacerle al enemigo? \n";
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

                

                




                cout << "A que enemigo quieres atacar?\n";
                cin >> heroElection;

                if (heroElection == 1)
                {
                    enemyHP = enemyHP - heroDamage;
                    cout << "Al enemigo le quedan " << enemyHP << " puntos de vida y a super malo " << enemy2HP << "puntos de vida\n";
                }
                else
                {
                    enemy2HP = enemy2HP - heroDamage;
                    cout << "A super malo le quedan " << enemy2HP << " puntos de vida y a malo " << enemyHP << "puntos de vida\n";
                }

                srand(time(NULL));
                enemydamage = 250 + rand() % (1200 - 0);
                enemydamage2 = 250 + rand() % (1200 - 0);

                if (enemyHP <= 0) {
                    enemyHP = 0;
                    enemyIsAlive = false;
                    cout << "El enemigo Malo ha sido derrotado\n";
                }


                if (enemyIsAlive) {
                    heroHP = heroHP - enemydamage;
                    cout << "Malo te ha hecho " << enemydamage << " puntos de danyo y te quedan " << heroHP << " puntos de vida\n";
                }

                if (enemy2HP <= 0) {
                    enemy2HP = 0;
                    enemyIsAlive2 = false;
                    cout << "Super malo ha sido derrotado\n";
                }


                if (enemyIsAlive2) {
                    heroHP = heroHP - enemydamage2;
                    cout << "Super malo te ha hecho " << enemydamage2 << " puntos de danyo y te quedan " << heroHP << " puntos de vida\n";
                }

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
