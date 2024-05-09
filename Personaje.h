#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"Item.h"
#include "Habilidad.h"


using namespace std;

enum Genero {
    Masculino = 1,
    Femenino,
    Otro
};

enum Raza {
    SerHumano = 1,
    Elfo,
    Enano,
    Orco
};

enum Orientacion {
    Bueno,
    Neutro,
    Malo
};

enum ClaseB {
    Guerreros = 1,
    Arqueros,
    Magos,
    Ladrones
};

class Personaje {
public:
    Personaje(string n, Genero g, Raza r, Orientacion o, ClaseB CB, int lv, float gold, int pH, int e, int m, int i, int f, int a, vector<Item> cosas, int xP);
    ~Personaje();   //agregar inventario

 

protected:
    string nombre;
    Genero genero;
    Raza raza;
    Orientacion orientacion;
    ClaseB claseBase;

    int nivel;
    float dinero;
    int puntosHabilidad;
    int estamina;
    int mana;
    int intelecto;
    int fuerza;
    int agilidad;
    int experiencia;

    vector<Item> inventario{};
};
