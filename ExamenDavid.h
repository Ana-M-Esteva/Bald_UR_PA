#pragma once
#include "EnemigosBase.h"

class ExamenDavid : public Enemigo
{
public:
	ExamenDavid(int nivelEnemigo);
	~ExamenDavid();
    void ReciveDamage(int damage);
    int getLevel();
    bool Defeated();
    void printStatus();
    int Attack(int lvlPersonaje);
    float DineroOtorgadoalMorir();
    int ExpOtorgadoalMorir(int lvlG);

private:
	int level;
	int health;

};

