#include "Item.h"



Item::Item(string n, Tipo t, int r, int v, int mod, int inc, int cant)
{
	nombre = n;
	tipo = t;
	rareza = r;
	valor = v;
	modificador = mod;
	incremento = inc;
	cantidad = cant;
}

Item::~Item()
{
}

void Item::ImprimirItem()
{
	cout << "Nombre: " << nombre << "\t" << "Tipo: " << tipo << "\t" << "Rareza: " << rareza << "\t" << "Valor: " << valor << "G" << "\t" << "Modificador: " << modificador << "\t" << "Incremento: " << incremento << "\t" << "Cantidad: " << cantidad << endl;
}

string Item::getName()
{
	return nombre;
}

Tipo Item::getTIPO() {
	return tipo;
}

int Item::getRareza() {
	return rareza;
}

float Item::getPrecio()
{
	return valor;
}

int Item::getmodificador() {
	return modificador;
}

int Item::getINc(){
	return incremento;
}

int Item::getCantidad()
{
	return cantidad;
}


void Item::reducirCantidad()
{
	cantidad = cantidad -1;
}

void Item::incrementarCantidad()
{
	cantidad = cantidad +1;
}

void Item::justOne()
{
	cantidad = 1;
}


