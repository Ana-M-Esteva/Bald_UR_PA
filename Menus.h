#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Menu {

private:
    // Vectores que representan los diferentes menús del juego
    vector<string> inicial = { "Iniciar", "Salir" };
    vector<string> principal = { "Comenzar Partida", "Cargar Partida", "Salir" };
    vector<string> juego = { "Ver Estadísticas", "Comprar Equipo", "Gastar Puntos de Habilidad", "Ir a una Aventura", "Guardar partida", "Salir" };
    // Vector principal que contiene los menús
    vector<vector<string>> datos = { inicial, principal, juego };
    int opcionActual;
    int estadoMenu; // 0: Menu Inicio, 1: Menu Principal, 2: Menu de juego , 3: Menu de tienda

public:
    Menu();
    ~Menu();


    // Método para mostrar el menú actual
    void mostrarMenu();

    // Vector principal que contiene los menús
    int getOpcionActual();

    // Método para navegar entre los menús
    void navegarMenu(int opcion);
};