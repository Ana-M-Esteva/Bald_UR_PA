#pragma once
#include "Personaje.h"
#include "Item.h"
#include "EnemigosBase.h"

class Mago : public Personaje {

public:
	Mago(string nombre, Genero genero, Raza raza, Orientacion orientacion, ClaseB claseBase, int nivel, float dinero, int puntosHabilidad, int estamina, int mana, int intelecto, int fuerza, int agilidad, vector<Item> inventario, int experiencia, bool BoladefuegoidoActive, bool RayodeHieloActive, bool FuegoRadianteActive);
	~Mago();

	void mostrarInformacion();
	void tiendaEquipo();
	void comprarItem(Item& item);
	void tiendaHabilidad();

	string getName();
	Genero getGenero();
	Raza getRaza();
	Orientacion getOr();
	int getLVL();
	float getGOLD();
	int getpH();
	int getEST();
	int getMANA();
	int getINTELECTO();
	int getFUERZA();
	int getAGILIDAD();
	int getEXP();
	bool getBoladeFuegoActive();
	bool getRayodeHieloActive();
	bool getFuegoRadianteActive();
	int getLongInventario();
	Item getItem(int i);
	vector<Item> getINVENTARIO();

	void levelUp();
	void DineroGAnado(float gold);
	void StatusActual();
	void ConsecuenciasMuerte();
	void PostMortum(int ne, int nm);
	bool noSigueVivo();
	void IncrentoExp(int x);
	void estaminaPerdida(int eP);

	int Ataque(int enemigolvl, int extra);
	int BoladeFuego(int enemigolvl, int extra);
	void RayodeHielo(int enemigolvl);
	int FuegoRadiante(int enemigolvl, int toten, int enh); //Falta por plantear
	int Atacar(int enemigolvl, int toten, int enh);
private:
	vector<Item> tienda;

	bool BoladeFuegoActive;
	bool RayodeHieloActive; // Indica si la puede usar el usuario
	bool FuegoRadianteActive; // Indica si la puede usar el usuario

	int RayodeHieloTurns; // Número de turnos restantes 
	int FuegoRadianteTurns; // Número de turnos restantes 

	bool EnUsoRayodeHielo;
	bool EnUsoFuegoRadiante;

	bool All2;

};