#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Guerrero.h"
#include "Arquero.h"

using namespace std;

class Enemigo
{
private:
    int level;
    int health;
public:
    ~Enemigo();
    Enemigo(int nivelEnemigo);
    void ReciveDamage(int damage);
    int getLevel();
    bool Defeated();
    void printStatus();
    int Attack(int lvlPersonaje);
    float DineroOtorgadoalMorir();
    int ExpOtorgadoalMorir(int lvlG);
    int getLife();

};
