#include "Personaje.h"

Personaje::Personaje(string n, Genero g, Raza r, Orientacion o, ClaseB CB, int lv, float gold, int pH, int e, int m, int i, int f, int a, vector<Item> cosas, int XP) {
    nombre = n;
    genero = g;
    raza = r;
    orientacion = o;
    claseBase = CB;

    nivel = lv;
    dinero = gold;
    puntosHabilidad = pH;
    estamina = e;
    mana = m;
    intelecto = i;
    fuerza = f;
    agilidad = a;
    inventario = cosas;
    experiencia = XP;
}

Personaje::~Personaje() {}
