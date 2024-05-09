#pragma once
#include "Personaje.h"
#include "Item.h"
#include "EnemigosBase.h"

class Ladron : public Personaje {

public:
	Ladron(string nombre, Genero genero, Raza raza, Orientacion orientacion, ClaseB claseBase, int nivel, float dinero, int puntosHabilidad, int estamina, int mana, int intelecto, int fuerza, int agilidad, vector<Item> inventario, int experiencia, bool getGolpeSigilosoActive, bool ConcentracionActive, bool FuegoRadianteActive);
	~Ladron();

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
	bool getGolpeSigilosoActive();
	bool getConcentracionActive();
	bool getPunnaladaLetalActive();
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
	int GolpeSigiloso(int enemigolvl, int extra);
	void Concentracion(int enemigolvl);
	int PunnaladaLetal(int enemigolvl, int toten, int enh); //Falta por plantear
	int Atacar(int enemigolvl, int toten, int enh);
private:
	vector<Item> tienda;

	bool GolpeSigilosoActive;
	bool ConcentracionActive; // Indica si la puede usar el usuario
	bool PunnaladaLetalActive; // Indica si la puede usar el usuario

	int ConcentracionTurns; // Número de turnos restantes 
	int PunnaladaLetalTurns; // Número de turnos restantes 

	bool Uncuarto;

}; 
