#include "ExamenDavid.h"

ExamenDavid::ExamenDavid(int nivelEnemigo) :  Enemigo (nivelEnemigo)
{
	level = nivelEnemigo;
	health = 20 * level;
}
void ExamenDavid::ReciveDamage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        cout << "Enemigo derrotado!" << endl;
    }
}

int ExamenDavid::getLevel()
{
    return level;
}

bool ExamenDavid::Defeated()
{
    return health <= 0;
}

void ExamenDavid::printStatus()
{
    cout << "Nivel del enemigo: " << level << endl;
    cout << "Salud del enemigo: " << health << endl;
}

int ExamenDavid::Attack(int lvlPersonaje)
{
    int dbase = 4;
    int dvar = rand() % 9 + 1;
    int damage = (dvar + dbase) * level;
    //int damage = (rand()% lvlPersonaje + 2) * level;
    cout << "¡El enemigo ataca !" << "\n Inflige : " << damage << endl;
    //Agregarle la opción de la habilidad q reduce daño
    return damage;
}

float ExamenDavid::DineroOtorgadoalMorir()
{

    int numeroAleatorio = rand() % 1000 + 100;
    float numeroDecimal = numeroAleatorio / 100;

    // Calculate decimal number between 0.3 and 0.7
    float ExtraGold = 0.3 + numeroDecimal * (0.7 - 0.3);
    return ExtraGold;
}

int ExamenDavid::ExpOtorgadoalMorir(int lvlP)
{

    int numeroAleatorio = rand() % lvlP + 2;
    return numeroAleatorio;
}


ExamenDavid::~ExamenDavid()
{
}