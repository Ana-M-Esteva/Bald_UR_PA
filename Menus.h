#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Menu {

private:
    // Vectores que representan los diferentes men�s del juego
    vector<string> inicial = { "Iniciar", "Salir" };
    vector<string> principal = { "Comenzar Partida", "Cargar Partida", "Salir" };
    vector<string> juego = { "Ver Estad�sticas", "Comprar Equipo", "Gastar Puntos de Habilidad", "Ir a una Aventura", "Guardar partida", "Salir" };
    // Vector principal que contiene los men�s
    vector<vector<string>> datos = { inicial, principal, juego };
    int opcionActual;
    int estadoMenu; // 0: Menu Inicio, 1: Menu Principal, 2: Menu de juego , 3: Menu de tienda

public:
    Menu();
    ~Menu();


    // M�todo para mostrar el men� actual
    void mostrarMenu();

    // Vector principal que contiene los men�s
    int getOpcionActual();

    // M�todo para navegar entre los men�s
    void navegarMenu(int opcion);
};