#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Tipo
{
	Arma,
	Armadura,
	Botas,
	Amuleto,
	Casco,
	Pocion
};



class Item
{
public:
	Item( string nombre, Tipo tipo, int rareza, int valor, int modificador, int incremento, int cantidad);
	~Item();
	void ImprimirItem();
	string getName();
	Tipo getTIPO();
	int getRareza();
	float getPrecio();
	int getmodificador();
	int getINc();
	int getCantidad();
	void reducirCantidad();
	void incrementarCantidad();
	void justOne();


private:
	string nombre;
	Tipo tipo; // Arma, Armadura, Botas, Amuleto, Casco
	int rareza; // Común, Poco común, Raro, Legendario
	float valor;  //Cuanto en gold
	int modificador; // mana = 0; estamina = 1; intelecto = 2; fuerza = 3; agilidad = 4;
	int incremento; 
	int cantidad;
};

