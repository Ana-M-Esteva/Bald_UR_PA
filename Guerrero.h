#pragma once
#include "Personaje.h"
#include "Item.h"
#include "EnemigosBase.h"



class Guerrero : public Personaje {
public:
	Guerrero(string nombre, Genero genero, Raza raza, Orientacion orientacion, ClaseB claseBase, int nivel, float dinero, int puntosHabilidad, int estamina, int mana, int intelecto, int fuerza, int agilidad, vector<Item> inventario, int experiencia, bool AtaquePotenteActive, bool DefensadeHierroActive, bool GritoGuerraActive);
	~Guerrero();

	void mostrarInformacion();
	void tiendaEquipo();
	void tiendaHabilidad();
	void comprarItem(Item& item);
	bool noSigueVivo();
	void IncrentoExp(int x);
	void estaminaPerdida(int eP);
	int Ataque(int enemigolvl, int extra);
	int AtaquePotente(int enemigolvl, int extra);
	void DefensadeHierro(int enemigolvl);
	int GritoGuerra(int enemigolvl);
	void ConsecuenciasMuerte();
	void levelUp();
	void DineroGAnado(float gold);
	void StatusActual();
	string getName();
	Genero getGenero();
	Raza getRaza();
	Orientacion getOr();
	int getLVL();
	float getGOLD();
	int getpH();
	int getEST();
	int getMANA();
	int getEXP();
	int getINTELECTO();
	int getFUERZA();
	int getAGILIDAD();
	bool getAtaquePotenteActive();
	bool getDefensadeHierroActive();
	bool getGritoGuerraActive();
	int getLongInventario();
	vector<Item> getINVENTARIO();
	Item getItem(int i);
	int Atacar(int enemigolvl);
	void PostMortum(int ne, int nm);


private:
	vector<Item> tienda;


	bool AtaquePotenteActive; // Indica si la Ataque Potente la puede usar el usuario
	bool DefensadeHierroActive; // Indica si la Defensa de Hierro la puede usar el usuario
	bool GritoGuerraActive; // Indica si el Grito de Guerra la puede usar el usuario

	int DefensadeHierroTurns; // Número de turnos restantes para la Defensa de Hierro
	int GritoGuerraTurns; // Número de turnos restantes para el Grito de Guerra

	bool EnUsoDefensadeHierro;
	bool EnUsoGritoGuerra;

	bool MitadD;
};
