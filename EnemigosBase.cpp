#include "EnemigosBase.h"


Enemigo::~Enemigo()
{
}

Enemigo::Enemigo(int nivelEnemigo)
{
    level = nivelEnemigo;
    health = 10 * level;
}

void Enemigo::ReciveDamage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        cout << "Enemigo derrotado!" << endl;
    }
}

int Enemigo::getLevel()
{
    return level;
}

bool Enemigo::Defeated()
{
    return health <= 0;
}

void Enemigo::printStatus()
{
    cout << "Nivel del enemigo: " << level << endl;
    cout << "Salud del enemigo: " << health << endl;
}

int Enemigo::Attack(int lvlPersonaje)
{
        int dbase = 2; 
        int dvar = rand() % 5 + 1;
        int damage = (dvar + dbase) * level;
        //int damage = (rand()% lvlPersonaje + 2) * level;
        cout << "¡El enemigo ataca !" << "\n Inflige : " << damage << endl;
        //Agregarle la opción de la habilidad q reduce daño
        return damage;
}

float Enemigo::DineroOtorgadoalMorir()
{
    
    int numeroAleatorio = rand()%100+1;
    float numeroDecimal = numeroAleatorio / 100;
    
    // Calculate decimal number between 0.3 and 0.7
    float ExtraGold =  0.3 + numeroDecimal * (0.7 - 0.3);
    return ExtraGold;
}

int Enemigo::ExpOtorgadoalMorir(int lvlP)
{

    int numeroAleatorio = rand() % lvlP + 1;
    return numeroAleatorio;
}

int Enemigo::getLife() {
    return health;
}
