#include "Menus.h"

int main() {
    srand(time(NULL));
    Menu menu;

    while (true) {
        menu.mostrarMenu();
        menu.navegarMenu(menu.getOpcionActual());
    }

    return 0;
}
