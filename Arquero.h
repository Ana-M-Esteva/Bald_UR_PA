#pragma once
#include "Personaje.h"
#include "Item.h"
#include "EnemigosBase.h"

class Arquero : public Personaje {

public:
	Arquero(string nombre, Genero genero, Raza raza, Orientacion orientacion, ClaseB claseBase, int nivel, float dinero, int puntosHabilidad, int estamina, int mana, int intelecto, int fuerza, int agilidad, vector<Item> inventario, int experiencia, bool DisparoRapidoActive, bool OjodeHalconActive, bool RafagadeFlechasActive);
	~Arquero();

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
	bool getDisparoRapidoActive();
	bool getOjodeHalconActive();
	bool getRafagadeFlechasActive();
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
	int DisparoRapido(int enemigolvl, int extra);
	int OjodeHalcon(int enemigolvl);
	int RafagadeFlechas(int enemigolvl, int toten, int enh); //Falta por plantear
	int Atacar(int enemigolvl, int toten, int enh);

private:
	vector<Item> tienda;

	bool DisparoRapidoActive; // Indica si la puede usar el usuario
	bool OjodeHalconActive; // Indica si  la puede usar el usuario
	bool RafagadeFlechasActive; // Indica si la puede usar el usuario

	int OjodeHalconTurns; // Número de turnos restantes 
	int RafagadeFlechasTurns; // Número de turnos restantes 

	bool EnUsoOjodeHalcon;
	bool EnUsoRafagadeFlechas;

	int forh3;
	int howlong;

};
