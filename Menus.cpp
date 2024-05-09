#include "Menus.h"
#include <vector>
#include <sstream>
#include <fstream>
#include "Guerrero.h"
#include "Arquero.h"
#include "Ladron.h"
#include "Mago.h"
#include "Item.h"
#include "EnemigosBase.h"
#include "ExamenDavid.h"

//string modificaCadena(string, int, UNPERSONAJe&);
void GUARDADO(int INDEX, string NAME, Genero GENERO, Raza RAZA, Orientacion ORIENTACION, ClaseB CLASEBASE, int NIVEL, float DINEROS, int PUNTOSHABILIDAD, int ESTAMINa, int MaNa, int INTELECTO, int FUERZA, int AGILIDAD, int EXPERIENCIA, bool H1, bool H2, bool H3, vector<Item> TODOinventario);
void CrearPersonaje(string&name, int&genero, int&raza, int&orientacion, int&ClaseBase);
int LecturaArchivo(int& index, string& name, int& genero, int& raza, int& orientacion, int& ClaseBase, int& nivel, float& gold, int& pHabilidad, int& ESTAMINA, int& MANA, int& intelecto, int& fuerza , int& Agilidad, int& EXp, bool& Habilidad1, bool& Habilidad2, bool& Habilidad3, vector<Item>& inventarioProvicional, bool& mty);
//void GuardarGuerrero(Guerrero miGuerrero);
//void GuardarArquero();
//void GuardarLadron();
//void GuardarMago();

//Variables globales y con valores predeterminados

string name;
int genero = 1;
int raza = 1;
int orientacion = 1;
int ClaseBase = 1;
int nivel = 1;
float gold = 100;
int pHabilidad = 0;
int ESTAMINA = 50;
int MANA = 50;
int intelecto;
int fuerza;
int Agilidad;
int EXp = 0;
bool Habilidad1 = false;
bool Habilidad2 = false;
bool Habilidad3 = false;
Item espada("Espada", Arma, 0, 100.0, 0, 0, 1);
Item arco("Arco del Aprendiz", Arma, 0, 100.0, 0, 0, 1);
Item daga("Daga", Arma, 0, 100.0, 0, 0, 1);
Item varita("Varita del Mago", Arma, 0, 100.0, 0, 0, 1);
vector<Item> inventarioProvicional{};
int index = 0;
bool mty = true;
bool LecturaAcargar = false;

struct UNPERSONAJe
{
    int ind;
    string nomb;
    Genero gene;
    Raza razz;
    Orientacion orie;
    ClaseB clase;
    int niv;
    int dinerou;
    int hpt;
    int lifeee;
    int manaaaa;
    int intelectooooo;
    int fuerzaaaaa;
    int agilidaddd;
    int expe;
    bool h1tem;
    bool h2tem;
    bool h3tem;
};


Menu::Menu() {
    opcionActual = -1;
    estadoMenu = 0;
}

Menu::~Menu() {}

void Menu::mostrarMenu() {
    setlocale(LC_ALL, "");// Configura escriba en español
    system("cls");// Limpia la pantalla
    cout << "**MENÚ**" << endl;
    for (int i = 0; i < datos[estadoMenu].size(); i++) {
        cout << "\t" << (i + 1) << ". " << datos[estadoMenu][i] << endl;// Imprime las opciones del menú
    }
    cout << endl << "Ingrese una opción: ";
    cin >> opcionActual;
}

int Menu::getOpcionActual() {
    return opcionActual;
}

void Menu::navegarMenu(int opcion) {
    setlocale(LC_ALL, "");
    

    switch (estadoMenu) {
    case 0: // Menu Inicio
        if (opcion == 1) {
            estadoMenu = 1;// Si la opción seleccionada es 1, cambia al menú principal (estado 1)
        }
        else if (opcion == 2) {
            exit(0);// Si la opción seleccionada es 2, sale del juego
        }
        break;
    case 1: // Menu Principal
        if (opcion == 1) {
            // Iniciar partida
           system("cls");
           
           CrearPersonaje(name, genero, raza, orientacion, ClaseBase); 
           //int numeroLineas = 0;
           //ifstream archivo("save_file.txt");
           //string linea;

           //// Leer cada línea del archivo para asignar id
           //while (getline(archivo, linea)) {
           //    numeroLineas++;
           //}

           //archivo.close();

           //index = numeroLineas;
           //cout << index << endl;
            
           
            estadoMenu = 2;
        }
        else if (opcion == 2) {
            // Cargar partida
            LecturaAcargar = true;
            int rturn = LecturaArchivo(index, name, genero, raza, orientacion, ClaseBase, nivel, gold, pHabilidad,  ESTAMINA,  MANA,  intelecto,  fuerza,  Agilidad, EXp, Habilidad1, Habilidad2,  Habilidad3, inventarioProvicional, mty);
            if (rturn == 0) { estadoMenu = 2; }
            else{ estadoMenu = 0; } // Si la carga de la partida falla, vuelve al menú de inicio
        }
        else if (opcion == 3) {
            estadoMenu = 0;// Vuelve al menú de inicio
        }
        break;
    case 2: // Menu de juego
        cout << "**~ Menu del Juego ~**" << endl;
        //Asegura que los valores si sean enumeradores

        Genero generoEnum = static_cast<Genero>(genero);
        Raza razaEnum = static_cast<Raza>(raza);
        Orientacion orientacionEnum = static_cast<Orientacion>(orientacion);
        ClaseB claseBaseEnum = static_cast<ClaseB>(ClaseBase);


        if (ClaseBase == 1) {


            if (mty) {
                inventarioProvicional.push_back(espada);
                mty = false;
            }
            //static Guerrero miGuerrero("Himmel", Masculino, SerHumano, Bueno,Guerreros, 30, 10000.3, 50, 1000, 1000, 10, 10, 10, inventarioProvicional, 500000, true, true, true); //static = correr una vez =)

            // Creando la instancia con los valores convertidos
            static Guerrero miGuerrero(name, generoEnum, razaEnum, orientacionEnum, claseBaseEnum, nivel, gold, pHabilidad, ESTAMINA, MANA, intelecto, fuerza, Agilidad, inventarioProvicional, EXp, Habilidad1, Habilidad2, Habilidad3); //Falta agregar arma a su inventario y que los valores sean defult o los leidos 
            if (miGuerrero.getEST() <= 0)
            {
                int nuevaestamina = 50 + (miGuerrero.getLVL() * 10);
                int nuevamana = 50 + (miGuerrero.getLVL() * 10);
                miGuerrero.PostMortum(nuevaestamina, nuevamana);
            }


                if (opcion == 1) {
                    // Ver estadísticas
                    miGuerrero.mostrarInformacion();

                }
                else if (opcion == 2) {
                    // Comprar equipo
                    miGuerrero.tiendaEquipo(); //Ya existen los productos, aun no hay inventario por lo tanto no puede meter nada
                }
                else if (opcion == 3) {
                    // Gastar puntos de habilidad
                    miGuerrero.tiendaHabilidad(); // Esta clase no la encuentra mi vc intentar de nuevo
                }
                else if (opcion == 4) {
                    // Ir a una aventura
                    srand(time(nullptr));
                    int numScenarios = rand() % 9 + 2; // Generar aleatoriamente el número de escenarios (2 - 10)
                    cout << "Comienza la aventura con " << numScenarios << " escenarios." << endl << endl;
                    int expTemporal = 0;
                    int hayUnjefe = rand() % 10 + 1;

                    for (int i = 1; i <= numScenarios; ++i) {
                        int numEnemies = 0;
                        if (!miGuerrero.noSigueVivo())
                        {
                            int maxEn = miGuerrero.getLVL() + 1;
                            numEnemies = rand() % maxEn + 1;
                        }

                        cout << "Escenario " << i << ": Enfrentando a " << numEnemies << " enemigos." << endl << endl;
                        cout << "Antes de empezar su estatus es: " << endl;
                        miGuerrero.StatusActual();
                        cout << endl << endl;

                        //Pensando en como hacer la batalla
                        for (int j = 0; j < numEnemies; j++)
                        {
                            cout << "Aparece enemigo #" << j+1 << endl;
                            Enemigo enemigo(miGuerrero.getLVL());
                            enemigo.printStatus();
                            cout << endl << endl;
                            while (!enemigo.Defeated() && !miGuerrero.noSigueVivo())
                            {
                                enemigo.ReciveDamage(miGuerrero.Atacar(enemigo.getLevel()));
                                miGuerrero.estaminaPerdida(enemigo.Attack(miGuerrero.getLVL()));
                                /*miGuerrero.Atacar(enemigo);
                                enemigo.AttackG(miGuerrero);*/
                                miGuerrero.StatusActual();
                                cout << endl << endl;
                                enemigo.printStatus();
                                cout << endl << endl;
                            }
                            if (enemigo.Defeated()) {
                                cout << "Has derrotado a el enemigo!" << endl;
                                expTemporal = enemigo.ExpOtorgadoalMorir(miGuerrero.getLVL()) + 1;
                                miGuerrero.DineroGAnado(enemigo.DineroOtorgadoalMorir());
                                miGuerrero.IncrentoExp(expTemporal);
                                miGuerrero.levelUp();
                                cout << "Pressiona ENTER para continuar..." << endl; 
                                cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                                cin.get(); // Espera a que el usuario presione ENTER
                            }
                            if (miGuerrero.noSigueVivo()) {
                                cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                                miGuerrero.ConsecuenciasMuerte();
                                cout << "Pressiona ENTER para continuar..." << endl; 
                                cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                                cin.get(); // Espera a que el usuario presione ENTER
                                break;
                            }
                        }

                        if (!miGuerrero.noSigueVivo())
                        {
                            // Preguntar si el jugador quiere abandonar la aventura
                            int choice;
                            cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                            cin >> choice;

                            if (choice == 1) {
                   
                                //Falta guardar en archivos
                                GUARDADO(index, miGuerrero.getName(), miGuerrero.getGenero(), miGuerrero.getRaza(), miGuerrero.getOr(), claseBaseEnum, miGuerrero.getLVL(), miGuerrero.getGOLD(), miGuerrero.getpH(), miGuerrero.getEST(), miGuerrero.getMANA(), miGuerrero.getINTELECTO(), miGuerrero.getFUERZA(), miGuerrero.getAGILIDAD(), miGuerrero.getEXP(), miGuerrero.getAtaquePotenteActive(), miGuerrero.getDefensadeHierroActive(), miGuerrero.getGritoGuerraActive(), miGuerrero.getINVENTARIO());
                                //GuardarGuerrero(miGuerrero);
                                cout << "Tus datos se han guardado adecuadamente" << endl;
                                break;
                            }
                            
                                
                            
                        }
                    }
                     

                    if (hayUnjefe == 5) {
                        for (int j = 0; j < 1; j++)
                        {
                            cout << "¿Pensabas que tu aventura se había acabado ? Un estruendo y el cielo se oscurece. El examen de David aparece. Parece que tu aventura tiene un último obstaculo" << endl;
                            cout << "Antes de empezar su estatus es: " << endl;
                            miGuerrero.StatusActual();
                            cout << endl << endl;
                            ExamenDavid DAVID(miGuerrero.getLVL());
                            while (!DAVID.Defeated() && !miGuerrero.noSigueVivo())
                            {
                                DAVID.ReciveDamage(miGuerrero.Atacar(DAVID.getLevel()));
                                miGuerrero.estaminaPerdida(DAVID.Attack(miGuerrero.getLVL()));
                                /*miGuerrero.Atacar(enemigo);
                                enemigo.AttackG(miGuerrero);*/
                                miGuerrero.StatusActual();
                                cout << endl << endl;
                                DAVID.printStatus();
                                cout << endl << endl;
                            }
                            if (DAVID.Defeated()) {
                                cout << "Has derrotado a el enemigo!" << endl;
                                expTemporal = DAVID.ExpOtorgadoalMorir(miGuerrero.getLVL()) + 1;
                                miGuerrero.DineroGAnado(DAVID.DineroOtorgadoalMorir());
                                miGuerrero.IncrentoExp(expTemporal);
                                miGuerrero.levelUp();
                                cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                                cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                                cin.get(); // Espera a que el usuario presione ENTER
                            }
                            if (miGuerrero.noSigueVivo()) {
                                cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                                miGuerrero.ConsecuenciasMuerte();
                                cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                                cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                                cin.get(); // Espera a que el usuario presione ENTER
                                break;
                            }
                            if (!miGuerrero.noSigueVivo())
                            {
                                // Preguntar si el jugador quiere abandonar la aventura
                                int choice;
                                cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                                cin >> choice;

                                if (choice == 1)
                                {

                                    //Falta guardar en archivos
                                    GUARDADO(index, miGuerrero.getName(), miGuerrero.getGenero(), miGuerrero.getRaza(), miGuerrero.getOr(), claseBaseEnum, miGuerrero.getLVL(), miGuerrero.getGOLD(), miGuerrero.getpH(), miGuerrero.getEST(), miGuerrero.getMANA(), miGuerrero.getINTELECTO(), miGuerrero.getFUERZA(), miGuerrero.getAGILIDAD(), miGuerrero.getEXP(), miGuerrero.getAtaquePotenteActive(), miGuerrero.getDefensadeHierroActive(), miGuerrero.getGritoGuerraActive(), miGuerrero.getINVENTARIO());
                                    //GuardarGuerrero(miGuerrero);
                                    cout << "Tus datos se han guardado adecuadamente" << endl;
                                    break;
                                }
                            }

                        }
                    }
                   
                    

                }
                else if (opcion == 5) {
                    GUARDADO(index, miGuerrero.getName(), miGuerrero.getGenero(), miGuerrero.getRaza(), miGuerrero.getOr(), claseBaseEnum, miGuerrero.getLVL(), miGuerrero.getGOLD(), miGuerrero.getpH(), miGuerrero.getEST(), miGuerrero.getMANA(), miGuerrero.getINTELECTO(), miGuerrero.getFUERZA(), miGuerrero.getAGILIDAD(), miGuerrero.getEXP(), miGuerrero.getAtaquePotenteActive(), miGuerrero.getDefensadeHierroActive(), miGuerrero.getGritoGuerraActive(), miGuerrero.getINVENTARIO());
                    //GuardarGuerrero(miGuerrero);
                    cout << "Tus datos se han guardado adecuadamente" << endl;
                    
                }
                else if (opcion == 6) {
                    mty = true;
                    inventarioProvicional.clear();
                    estadoMenu = 1;
                }
                break;
            

        }
        else if (ClaseBase == 2) {
            if (mty) {
            inventarioProvicional.push_back(arco);
            mty = false;
            }
            static Arquero miArquero(name, generoEnum, razaEnum, orientacionEnum, claseBaseEnum, nivel, gold, pHabilidad, ESTAMINA, MANA, intelecto, fuerza, Agilidad, inventarioProvicional, EXp, Habilidad1, Habilidad2, Habilidad3);
            if (opcion == 1) {
                // Ver estadísticas
                miArquero.mostrarInformacion();

            }
            else if (opcion == 2) {
                // Comprar equipo
                miArquero.tiendaEquipo();
            }
            else if (opcion == 3) {
                // Gastar puntos de habilidad
                miArquero.tiendaHabilidad();
            }
            else if (opcion == 4) {
                // Ir a una aventura
                srand(time(nullptr));
                int numScenarios = rand() % 9 + 2; // Generar aleatoriamente el número de escenarios (2 - 10)
                cout << "Comienza la aventura con " << numScenarios << " escenarios." << endl << endl;
                int expTemporal = 0;
                int hayUnjefe = rand() % 10 + 1;

                for (int i = 1; i <= numScenarios; ++i) {
                    int numEnemies = 0;
                    if (!miArquero.noSigueVivo())
                    {
                        int maxEn = miArquero.getLVL() + 1;
                        numEnemies = rand() % maxEn + 1;
                    }

                    cout << "Escenario " << i << ": Enfrentando a " << numEnemies << " enemigos." << endl << endl;
                    cout << "Antes de empezar su estatus es: " << endl;
                    miArquero.StatusActual();
                    cout << endl << endl;

                    //Pensando en como hacer la batalla
                    for (int j = 0; j < numEnemies; j++)
                    {
                        cout << "Aparece enemigo #" << j + 1 << endl;
                        Enemigo enemigo(miArquero.getLVL());
                        enemigo.printStatus();
                        cout << endl << endl;
                        while (!enemigo.Defeated() && !miArquero.noSigueVivo())
                        {
                            enemigo.ReciveDamage(miArquero.Atacar(enemigo.getLevel(),numEnemies-j,enemigo.getLife()));
                            miArquero.estaminaPerdida(enemigo.Attack(miArquero.getLVL()));
                            /*miGuerrero.Atacar(enemigo);
                            enemigo.AttackG(miGuerrero);*/
                            miArquero.StatusActual();
                            cout << endl << endl;
                            enemigo.printStatus();
                            cout << endl << endl;
                        }
                        if (enemigo.Defeated()) {
                            cout << "Has derrotado a el enemigo!" << endl;
                            expTemporal = enemigo.ExpOtorgadoalMorir(miArquero.getLVL()) + 1;
                            miArquero.DineroGAnado(enemigo.DineroOtorgadoalMorir());
                            miArquero.IncrentoExp(expTemporal);
                            miArquero.levelUp();
                            cout << "Pressiona ENTER para continuar..." << endl;
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                        }
                        if (miArquero.noSigueVivo()) {
                            cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                            miArquero.ConsecuenciasMuerte();
                            cout << "Pressiona ENTER para continuar..." << endl;
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                            break;
                        }
                    }

                    if (!miArquero.noSigueVivo())
                    {
                        // Preguntar si el jugador quiere abandonar la aventura
                        int choice;
                        cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                        cin >> choice;

                        if (choice == 1) {

                            //Falta guardar en archivos
                            GUARDADO(index, miArquero.getName(), miArquero.getGenero(), miArquero.getRaza(), miArquero.getOr(), claseBaseEnum, miArquero.getLVL(), miArquero.getGOLD(), miArquero.getpH(), miArquero.getEST(), miArquero.getMANA(), miArquero.getINTELECTO(), miArquero.getFUERZA(), miArquero.getAGILIDAD(), miArquero.getEXP(), miArquero.getDisparoRapidoActive(), miArquero.getOjodeHalconActive(), miArquero.getRafagadeFlechasActive(), miArquero.getINVENTARIO());
                            //GuardarGuerrero(miGuerrero);
                            cout << "Tus datos se han guardado adecuadamente" << endl;
                            break;
                        }



                    }
                }


                if (hayUnjefe == 5) {
                    for (int j = 0; j < 1; j++)
                    {
                        cout << "¿Pensabas que tu aventura se había acabado ? Un estruendo y el cielo se oscurece. El examen de David aparece. Parece que tu aventura tiene un último obstaculo" << endl;
                        cout << "Antes de empezar su estatus es: " << endl;
                        miArquero.StatusActual();
                        cout << endl << endl;
                        ExamenDavid DAVID(miArquero.getLVL());
                        while (!DAVID.Defeated() && !miArquero.noSigueVivo())
                        {
                            DAVID.ReciveDamage(miArquero.Atacar(DAVID.getLevel(), 1, DAVID.getLife()));
                            miArquero.estaminaPerdida(DAVID.Attack(miArquero.getLVL()));
                            /*miGuerrero.Atacar(enemigo);
                            enemigo.AttackG(miGuerrero);*/
                            miArquero.StatusActual();
                            cout << endl << endl;
                            DAVID.printStatus();
                            cout << endl << endl;
                        }
                        if (DAVID.Defeated()) {
                            cout << "Has derrotado a el enemigo!" << endl;
                            expTemporal = DAVID.ExpOtorgadoalMorir(miArquero.getLVL()) + 1;
                            miArquero.DineroGAnado(DAVID.DineroOtorgadoalMorir());
                            miArquero.IncrentoExp(expTemporal);
                            miArquero.levelUp();
                            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                        }
                        if (miArquero.noSigueVivo()) {
                            cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                            miArquero.ConsecuenciasMuerte();
                            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                            break;
                        }
                        if (!miArquero.noSigueVivo())
                        {
                            // Preguntar si el jugador quiere abandonar la aventura
                            int choice;
                            cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                            cin >> choice;

                            if (choice == 1) {

                                //Falta guardar en archivos
                                GUARDADO(index, miArquero.getName(), miArquero.getGenero(), miArquero.getRaza(), miArquero.getOr(), claseBaseEnum, miArquero.getLVL(), miArquero.getGOLD(), miArquero.getpH(), miArquero.getEST(), miArquero.getMANA(), miArquero.getINTELECTO(), miArquero.getFUERZA(), miArquero.getAGILIDAD(), miArquero.getEXP(), miArquero.getDisparoRapidoActive(), miArquero.getOjodeHalconActive(), miArquero.getRafagadeFlechasActive(), miArquero.getINVENTARIO());
                                //GuardarGuerrero(miGuerrero);
                                cout << "Tus datos se han guardado adecuadamente" << endl;
                                break;
                            }



                        }
                    }
                }
            }
            else if (opcion == 5) {
                // Guardar partida
               // GuardarArquero(miArquero);
                cout << "Tus datos se han guardado adecuadamente" << endl;
                GUARDADO(index, miArquero.getName(), miArquero.getGenero(), miArquero.getRaza(), miArquero.getOr(), claseBaseEnum, miArquero.getLVL(), miArquero.getGOLD(), miArquero.getpH(), miArquero.getEST(), miArquero.getMANA(), miArquero.getINTELECTO(), miArquero.getFUERZA(), miArquero.getAGILIDAD(), miArquero.getEXP(), miArquero.getDisparoRapidoActive(), miArquero.getOjodeHalconActive(), miArquero.getRafagadeFlechasActive(), miArquero.getINVENTARIO());
            }
            else if (opcion == 6) {
                mty = true;
                inventarioProvicional.clear();
                estadoMenu = 1;

            }
            break;
        }
        else if (ClaseBase == 3) {
            // MAGO
            if (mty) {
                inventarioProvicional.push_back(varita);
                mty = false;
            }
            static Mago miMago(name, generoEnum, razaEnum, orientacionEnum, claseBaseEnum, nivel, gold, pHabilidad, ESTAMINA, MANA, intelecto, fuerza, Agilidad, inventarioProvicional, EXp, Habilidad1, Habilidad2, Habilidad3);
            if (opcion == 1) {
                // Ver estadísticas
                miMago.mostrarInformacion();

            }
            else if (opcion == 2) {
                // Comprar equipo
                miMago.tiendaEquipo();
            }
            else if (opcion == 3) {
                // Gastar puntos de habilidad
                miMago.tiendaHabilidad();
            }
            else if (opcion == 4) {
                // Ir a una aventura
                srand(time(nullptr));
                int numScenarios = rand() % 9 + 2; // Generar aleatoriamente el número de escenarios (2 - 10)
                cout << "Comienza la aventura con " << numScenarios << " escenarios." << endl << endl;
                int expTemporal = 0;
                int hayUnjefe = rand() % 10 + 1;

                for (int i = 1; i <= numScenarios; ++i) {
                    int numEnemies = 0;
                    if (!miMago.noSigueVivo())
                    {
                        int maxEn = miMago.getLVL() + 1;
                        numEnemies = rand() % maxEn + 1;
                    }

                    cout << "Escenario " << i << ": Enfrentando a " << numEnemies << " enemigos." << endl << endl;
                    cout << "Antes de empezar su estatus es: " << endl;
                    miMago.StatusActual();
                    cout << endl << endl;

                    //Pensando en como hacer la batalla
                    for (int j = 0; j < numEnemies; j++)
                    {
                        cout << "Aparece enemigo #" << j + 1 << endl;
                        Enemigo enemigo(miMago.getLVL());
                        enemigo.printStatus();
                        cout << endl << endl;
                        while (!enemigo.Defeated() && !miMago.noSigueVivo())
                        {
                            enemigo.ReciveDamage(miMago.Atacar(enemigo.getLevel(), numEnemies - j, enemigo.getLife()));
                            miMago.estaminaPerdida(enemigo.Attack(miMago.getLVL()));
                            /*miGuerrero.Atacar(enemigo);
                            enemigo.AttackG(miGuerrero);*/
                            miMago.StatusActual();
                            cout << endl << endl;
                            enemigo.printStatus();
                            cout << endl << endl;
                        }
                        if (enemigo.Defeated()) {
                            cout << "Has derrotado a el enemigo!" << endl;
                            expTemporal = enemigo.ExpOtorgadoalMorir(miMago.getLVL()) + 1;
                            miMago.DineroGAnado(enemigo.DineroOtorgadoalMorir());
                            miMago.IncrentoExp(expTemporal);
                            miMago.levelUp();
                            cout << "Pressiona ENTER para continuar..." << endl;
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                        }
                        if (miMago.noSigueVivo()) {
                            cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                            miMago.ConsecuenciasMuerte();
                            cout << "Pressiona ENTER para continuar..." << endl;
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                            break;
                        }
                    }

                    if (!miMago.noSigueVivo())
                    {
                        // Preguntar si el jugador quiere abandonar la aventura
                        int choice;
                        cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                        cin >> choice;

                        if (choice == 1) {

                            //Falta guardar en archivos
                            GUARDADO(index, miMago.getName(), miMago.getGenero(), miMago.getRaza(), miMago.getOr(), claseBaseEnum, miMago.getLVL(), miMago.getGOLD(), miMago.getpH(), miMago.getEST(), miMago.getMANA(), miMago.getINTELECTO(), miMago.getFUERZA(), miMago.getAGILIDAD(), miMago.getEXP(), miMago.getBoladeFuegoActive(), miMago.getRayodeHieloActive(), miMago.getFuegoRadianteActive(), miMago.getINVENTARIO());
                            //GuardarGuerrero(miGuerrero);
                            cout << "Tus datos se han guardado adecuadamente" << endl;
                            break;
                        }



                    }
                }


                if (hayUnjefe == 5) {
                    for (int j = 0; j < 1; j++)
                    {
                        cout << "¿Pensabas que tu aventura se había acabado ? Un estruendo y el cielo se oscurece. El examen de David aparece. Parece que tu aventura tiene un último obstaculo" << endl;
                        cout << "Antes de empezar su estatus es: " << endl;
                        miMago.StatusActual();
                        cout << endl << endl;
                        ExamenDavid DAVID(miMago.getLVL());
                        while (!DAVID.Defeated() && !miMago.noSigueVivo())
                        {
                            DAVID.ReciveDamage(miMago.Atacar(DAVID.getLevel(), 1, DAVID.getLife()));
                            miMago.estaminaPerdida(DAVID.Attack(miMago.getLVL()));
                            /*miGuerrero.Atacar(enemigo);
                            enemigo.AttackG(miGuerrero);*/
                            miMago.StatusActual();
                            cout << endl << endl;
                            DAVID.printStatus();
                            cout << endl << endl;
                        }
                        if (DAVID.Defeated()) {
                            cout << "Has derrotado a el enemigo!" << endl;
                            expTemporal = DAVID.ExpOtorgadoalMorir(miMago.getLVL()) + 1;
                            miMago.DineroGAnado(DAVID.DineroOtorgadoalMorir());
                            miMago.IncrentoExp(expTemporal);
                            miMago.levelUp();
                            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                        }
                        if (miMago.noSigueVivo()) {
                            cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                            miMago.ConsecuenciasMuerte();
                            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                            break;
                        }
                        if (!miMago.noSigueVivo())
                        {
                            // Preguntar si el jugador quiere abandonar la aventura
                            int choice;
                            cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                            cin >> choice;

                            if (choice == 1) {

                                //Falta guardar en archivos
                                GUARDADO(index, miMago.getName(), miMago.getGenero(), miMago.getRaza(), miMago.getOr(), claseBaseEnum, miMago.getLVL(), miMago.getGOLD(), miMago.getpH(), miMago.getEST(), miMago.getMANA(), miMago.getINTELECTO(), miMago.getFUERZA(), miMago.getAGILIDAD(), miMago.getEXP(), miMago.getBoladeFuegoActive(), miMago.getRayodeHieloActive(), miMago.getFuegoRadianteActive(), miMago.getINVENTARIO());
                                //GuardarGuerrero(miGuerrero);
                                cout << "Tus datos se han guardado adecuadamente" << endl;
                                break;
                            }



                        }
                    }
                }
            }
            else if (opcion == 5) {
                // Guardar partida
               // GuardarArquero(miArquero);
                cout << "Tus datos se han guardado adecuadamente" << endl;
                GUARDADO(index, miMago.getName(), miMago.getGenero(), miMago.getRaza(), miMago.getOr(), claseBaseEnum, miMago.getLVL(), miMago.getGOLD(), miMago.getpH(), miMago.getEST(), miMago.getMANA(), miMago.getINTELECTO(), miMago.getFUERZA(), miMago.getAGILIDAD(), miMago.getEXP(), miMago.getBoladeFuegoActive(), miMago.getRayodeHieloActive(), miMago.getFuegoRadianteActive(), miMago.getINVENTARIO());
            }
            else if (opcion == 6) {
                mty = true;
                inventarioProvicional.clear();
                estadoMenu = 1;
            }
            break;

        }
        else if (ClaseBase == 4) {
            // Ladron 
            if (mty) {
            inventarioProvicional.push_back(daga);
            mty = false;
            }
            static Ladron miLadron(name, generoEnum, razaEnum, orientacionEnum, claseBaseEnum, nivel, gold, pHabilidad, ESTAMINA, MANA, intelecto, fuerza, Agilidad, inventarioProvicional, EXp, Habilidad1, Habilidad2, Habilidad3);
            if (opcion == 1) {
                // Ver estadísticas
                miLadron.mostrarInformacion();

            }
            else if (opcion == 2) {
                // Comprar equipo
                miLadron.tiendaEquipo();
            }
            else if (opcion == 3) {
                // Gastar puntos de habilidad
                miLadron.tiendaHabilidad();
            }
            else if (opcion == 4) {
                // Ir a una aventura
                srand(time(nullptr));
                int numScenarios = rand() % 9 + 2; // Generar aleatoriamente el número de escenarios (2 - 10)
                cout << "Comienza la aventura con " << numScenarios << " escenarios." << endl << endl;
                int expTemporal = 0;
                int hayUnjefe = rand() % 10 + 1;

                for (int i = 1; i <= numScenarios; ++i) {
                    int numEnemies = 0;
                    if (!miLadron.noSigueVivo())
                    {
                        int maxEn = miLadron.getLVL() + 1;
                        numEnemies = rand() % maxEn + 1;
                    }

                    cout << "Escenario " << i << ": Enfrentando a " << numEnemies << " enemigos." << endl << endl;
                    cout << "Antes de empezar su estatus es: " << endl;
                    miLadron.StatusActual();
                    cout << endl << endl;

                    //Pensando en como hacer la batalla
                    for (int j = 0; j < numEnemies; j++)
                    {
                        cout << "Aparece enemigo #" << j + 1 << endl;
                        Enemigo enemigo(miLadron.getLVL());
                        enemigo.printStatus();
                        cout << endl << endl;
                        while (!enemigo.Defeated() && !miLadron.noSigueVivo())
                        {
                            enemigo.ReciveDamage(miLadron.Atacar(enemigo.getLevel(), numEnemies - j, enemigo.getLife()));
                            miLadron.estaminaPerdida(enemigo.Attack(miLadron.getLVL()));
                            /*miGuerrero.Atacar(enemigo);
                            enemigo.AttackG(miGuerrero);*/
                            miLadron.StatusActual();
                            cout << endl << endl;
                            enemigo.printStatus();
                            cout << endl << endl;
                        }
                        if (enemigo.Defeated()) {
                            cout << "Has derrotado a el enemigo!" << endl;
                            expTemporal = enemigo.ExpOtorgadoalMorir(miLadron.getLVL()) + 1;
                            miLadron.DineroGAnado(enemigo.DineroOtorgadoalMorir());
                            miLadron.IncrentoExp(expTemporal);
                            miLadron.levelUp();
                            cout << "Pressiona ENTER para continuar..." << endl;
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                        }
                        if (miLadron.noSigueVivo()) {
                            cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                            miLadron.ConsecuenciasMuerte();
                            cout << "Pressiona ENTER para continuar..." << endl;
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                            break;
                        }
                    }

                    if (!miLadron.noSigueVivo())
                    {
                        // Preguntar si el jugador quiere abandonar la aventura
                        int choice;
                        cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                        cin >> choice;

                        if (choice == 1) {

                            //Falta guardar en archivos
                            GUARDADO(index, miLadron.getName(), miLadron.getGenero(), miLadron.getRaza(), miLadron.getOr(), claseBaseEnum, miLadron.getLVL(), miLadron.getGOLD(), miLadron.getpH(), miLadron.getEST(), miLadron.getMANA(), miLadron.getINTELECTO(), miLadron.getFUERZA(), miLadron.getAGILIDAD(), miLadron.getEXP(), miLadron.getGolpeSigilosoActive(), miLadron.getConcentracionActive(), miLadron.getPunnaladaLetalActive(), miLadron.getINVENTARIO());
                            //GuardarGuerrero(miGuerrero);
                            cout << "Tus datos se han guardado adecuadamente" << endl;
                            break;
                        }



                    }
                }


                if (hayUnjefe == 5) {
                    for (int j = 0; j < 1; j++)
                    {
                        cout << "¿Pensabas que tu aventura se había acabado ? Un estruendo y el cielo se oscurece. El examen de David aparece. Parece que tu aventura tiene un último obstaculo" << endl;
                        cout << "Antes de empezar su estatus es: " << endl;
                        miLadron.StatusActual();
                        cout << endl << endl;
                        ExamenDavid DAVID(miLadron.getLVL());
                        while (!DAVID.Defeated() && !miLadron.noSigueVivo())
                        {
                            DAVID.ReciveDamage(miLadron.Atacar(DAVID.getLevel(), 1, DAVID.getLife()));
                            miLadron.estaminaPerdida(DAVID.Attack(miLadron.getLVL()));
                            /*miGuerrero.Atacar(enemigo);
                            enemigo.AttackG(miGuerrero);*/
                            miLadron.StatusActual();
                            cout << endl << endl;
                            DAVID.printStatus();
                            cout << endl << endl;
                        }
                        if (DAVID.Defeated()) {
                            cout << "Has derrotado a el enemigo!" << endl;
                            expTemporal = DAVID.ExpOtorgadoalMorir(miLadron.getLVL()) + 1;
                            miLadron.DineroGAnado(DAVID.DineroOtorgadoalMorir());
                            miLadron.IncrentoExp(expTemporal);
                            miLadron.levelUp();
                            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                        }
                        if (miLadron.noSigueVivo()) {
                            cout << "Has sido derrotado. Pierdes la mitad de tu dinero." << endl;
                            miLadron.ConsecuenciasMuerte();
                            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
                            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
                            cin.get(); // Espera a que el usuario presione ENTER
                            break;
                        }
                        if (!miLadron.noSigueVivo())
                        {
                            // Preguntar si el jugador quiere abandonar la aventura
                            int choice;
                            cout << "¿Quieres abandonar la aventura y guardar? Si no se guarda la partida y muere perdera todo (1 para si /2 para no): ";
                            cin >> choice;

                            if (choice == 1) {

                                //Falta guardar en archivos
                                GUARDADO(index, miLadron.getName(), miLadron.getGenero(), miLadron.getRaza(), miLadron.getOr(), claseBaseEnum, miLadron.getLVL(), miLadron.getGOLD(), miLadron.getpH(), miLadron.getEST(), miLadron.getMANA(), miLadron.getINTELECTO(), miLadron.getFUERZA(), miLadron.getAGILIDAD(), miLadron.getEXP(), miLadron.getGolpeSigilosoActive(), miLadron.getConcentracionActive(), miLadron.getPunnaladaLetalActive(), miLadron.getINVENTARIO());
                                //GuardarGuerrero(miGuerrero);
                                cout << "Tus datos se han guardado adecuadamente" << endl;
                                break;
                            }



                        }
                    }
                }
            }
            else if (opcion == 5) {
                // Guardar partida
               // GuardarArquero(miArquero);
                cout << "Tus datos se han guardado adecuadamente" << endl;
                GUARDADO(index, miLadron.getName(), miLadron.getGenero(), miLadron.getRaza(), miLadron.getOr(), claseBaseEnum, miLadron.getLVL(), miLadron.getGOLD(), miLadron.getpH(), miLadron.getEST(), miLadron.getMANA(), miLadron.getINTELECTO(), miLadron.getFUERZA(), miLadron.getAGILIDAD(), miLadron.getEXP(), miLadron.getGolpeSigilosoActive(), miLadron.getConcentracionActive(), miLadron.getPunnaladaLetalActive(), miLadron.getINVENTARIO());
                //GuardarGuerrero(miGuerrero);
            }
            else if (opcion == 6) {
                mty = true;
                inventarioProvicional.clear();
                estadoMenu = 1;
            }
            break;


        }
        else {
            cout << "No existe";
        }
        
        
        
    }
}
Tipo string_to_TIPO(const string& word) {
    if (word == "Arma") {
        return Tipo::Arma;
    }
    if (word == "Amuleto") {
        return Tipo::Amuleto;
    }
    if (word == "Armadura") {
        return Tipo::Armadura;
    }
    if (word == "Botas") {
        return Tipo::Botas;
    }
    if (word == "Casco") {
        return Tipo::Casco;
    }
    if (word == "Pocion") {
        return Tipo::Pocion;
    }
}

void CrearPersonaje(string& name, int& genero, int& raza, int& orientacion, int& ClaseBase) {
    
    cout << "Creando personaje" << endl << endl;
    cout << "Nombre: ";
    cin >> name;
    cout << "\nSeleccione 1 para Masculino, 2 para Femenino, 3 para otro: ";
    cin >> genero;
    cout << "\nSeleccione 1 para SerHumano, 2 para Elfo, 3 para Enano y 4 para Orco: ";
    cin >> raza;
    cout << "\nSeleccione 0 para Bueno, 1 para Neutro, 2 para Malo: ";
    cin >> orientacion;
    cout << "\nSeleccione 1 para Guerrero, 2 para Arquero, 3 para Mago y 4 para Ladrón: ";
    cin >> ClaseBase;
}

int LecturaArchivo(int& index, string& name, int& genero, int& raza, int& orientacion, int& ClaseBase, int& nivel, float& gold, int& pHabilidad, int& ESTAMINA, int& MANA, int& intelecto, int& fuerza, int& Agilidad, int& EXp, bool& Habilidad1, bool& Habilidad2, bool& Habilidad3, vector<Item>& inventarioProvicional, bool& mty) {
    cout << "Ingrese el nombre de su personaje" << endl;
    string n;
    cin >> n;
    string path = n + ".txt";
    // Aquí abrimos el archivo
    ifstream InputFile(path, ios::in);
    if (!InputFile) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return -1;
    }
    string linea;
    getline(InputFile, linea);
    
        istringstream line_steam(linea);
        string campo;
        getline(line_steam, campo, ',');
        name = campo;
        getline(line_steam, campo, ',');
        genero = stoi(campo);
        getline(line_steam, campo, ',');
        raza = stoi(campo);
        getline(line_steam, campo, ',');
        orientacion = stoi(campo);
        getline(line_steam, campo, ',');
        ClaseBase = stoi(campo);
        getline(line_steam, campo, ',');
        nivel = stoi(campo);
        getline(line_steam, campo, ',');
        gold = stof(campo);
        getline(line_steam, campo, ',');
        pHabilidad = stoi(campo);
        getline(line_steam, campo, ',');
        ESTAMINA = stoi(campo);
        getline(line_steam, campo, ',');
        MANA = stoi(campo);
        getline(line_steam, campo, ',');
        intelecto = stoi(campo);
        getline(line_steam, campo, ',');
        fuerza = stoi(campo);
        getline(line_steam, campo, ',');
        Agilidad = stoi(campo);
        getline(line_steam, campo, ',');
        EXp = stoi(campo);
        getline(line_steam, campo, ',');
        Habilidad1 = stoi(campo);
        getline(line_steam, campo, ',');
        Habilidad2 = stoi(campo);
        getline(line_steam, campo, ',');
        Habilidad3 = stoi(campo);
    

    while (getline(InputFile, linea)) {
        istringstream line_stream(linea);
        string nombreItem;
        string tipoStr;
        string rarezaStr;
        string valorStr;
        string modificadorStr;
        string incrementoStr;
        string cantidadStr;

        getline(line_stream, nombreItem, ',');
        getline(line_stream, tipoStr, ',');
        getline(line_stream, rarezaStr, ',');
        getline(line_stream, valorStr, ',');
        getline(line_stream, modificadorStr, ',');
        getline(line_stream, incrementoStr, ',');
        getline(line_stream, cantidadStr, ',');

        Tipo tipo = string_to_TIPO(tipoStr);
        int rareza = stoi(rarezaStr);
        float valor = stof(valorStr);
        int modificador = stoi(modificadorStr);
        int incremento = stoi(incrementoStr);
        int cantidad = stoi(cantidadStr);

        // Crear el objeto Item y agregarlo al inventario
        Item item(nombreItem, tipo, rareza, valor, modificador, incremento, cantidad);
        inventarioProvicional.push_back(item);
    }
    mty = false;
    InputFile.close();
    return 0;
    

    /*ifstream archivo_lectura;
    archivo_lectura.open("save_file.txt", std::ios::in);
    vector<string> lineas;
    // Leer el archivo y almacenar las líneas en el vector
    if (archivo_lectura.is_open()) {
        string linea;
        while (getline(archivo_lectura, linea)) {
            lineas.push_back(linea);
        }
        archivo_lectura.close();
    }
    else {
        cout << "Error al abrir el archivo." << endl;
        return  -1;
    }
    // Imprimir las líneas
    cout << "Información en el archivo:" << endl;
    cout << "El primer numero es el id de la partida" << endl;
    for (size_t i = 0; i < lineas.size(); ++i) {
        cout << "Partida " << i << ": " << lineas[i] << endl;
    }

    // Pedir al usuario que ingrese un índice
    int indice_usuario;
    cout << "Ingrese el id de la partida que desea obtener, si no ve inforáción ingrese -1 (menos uno): ";
    cin >> indice_usuario;

    // Verificar si el índice ingresado es válido
    if (indice_usuario < 0 || indice_usuario > static_cast<int>(lineas.size())) {
        cout << "Índice inválido. Por favor ingrese un valor entre 0 y " << lineas.size() << endl;
        return -1;
    }

    // Mostrar la línea correspondiente al índice ingresado
    cout << "Línea " << indice_usuario << ": " << lineas[indice_usuario] << endl;

    // Separar valores de la línea seleccionada
    stringstream ss(lineas[indice_usuario]); //**Un stringstream es un flujo de datos de entrada y salida que se utiliza para operar en cadenas, tratándolas como secuencias de caracteres.**
    string token;                           //**token para almacenar cada uno de los valores separados por comas
    // Leer el id de la partida
    getline(ss, token, ',');                //**Luego, se utiliza la función getline de stringstream (ss) para leer el contenido de ss hasta encontrar una coma (,) y almacenarlo en token
    index = stoi(token);
    // Leer el nombre
    getline(ss, name, ',');
    //Genero
    getline(ss, token, ',');
    genero = stoi(token);
    //Raza
    getline(ss, token, ',');
    raza = stoi(token);
    //Orientación
    getline(ss, token, ',');
    orientacion = stoi(token);
    //Clasebase
    getline(ss, token, ',');
    ClaseBase = stoi(token);
    //nivel
    getline(ss, token, ',');
    nivel = stoi(token);
    //Dinero
    getline(ss, token, ',');
    gold = stof(token);         //Para decimal
    //pH
    getline(ss, token, ',');
    pHabilidad = stoi(token);
    //Estamina
    getline(ss, token, ',');
    ESTAMINA = stoi(token);
    //Mana
    getline(ss, token, ',');
    MANA = stoi(token);
    //Intelecto
    getline(ss, token, ',');
    intelecto = stoi(token);
    //Fuerza
    getline(ss, token, ',');
    fuerza = stoi(token);
    //Agilidad
    getline(ss, token, ',');
    Agilidad = stoi(token);
    //Experiencia
    getline(ss, token, ',');
    EXp = stoi(token);
    //Habilidades 1, 2 ,3
    getline(ss, token, ',');
    Habilidad1 = stoi(token);
    getline(ss, token, ','); 
    Habilidad2 = stoi(token);
    getline(ss, token, ','); 
    Habilidad3 = stoi(token);


    // Leer el archivo de inventario
    ifstream archivo_inventario;
    archivo_inventario.open("inventario_file.txt");
    vector<string> lineasInventario;
    // Leer el archivo y almacenar las líneas en el vector
    if (archivo_inventario.is_open()) {
        string linea;
        while (getline(archivo_inventario, linea)) {
            lineasInventario.push_back(linea);
        }
        archivo_inventario.close();
    }
    else {
        cout << "Error al abrir el archivo de inventario." << endl;
        return -1;
    }

    // Procesar el inventario
    // Si el índice de usuario es válido
    if (indice_usuario < 0 || indice_usuario >= static_cast<int>(lineasInventario.size())) {
        cout << "Índice de inventario inválido." << endl;
        return -1;
    }

    // Obtener la línea correspondiente al índice de usuario
    //string linea_inventario_seleccionada = lineasInventario[indice_usuario];
    //stringstream ssInventario(linea_inventario_seleccionada);
    //string token1;
    //int ignore1 = -1;
    //int ignore2 = -1;
    //getline(ss, token1, ',');
    //ignore1 = stoi(token1);
    //getline(ss, token1, ',');
    //ignore2 = stoi(token1);

    //string nombre_objeto;
    //int tipo_objeto;
    //int rareza_objeto;
    //float precio_objeto;
    //int modificador_objeto;
    //int incremento_objeto;
    //int cantida_objeto;

    //while (getline(ssInventario, token1, ',')) {

    //    getline(ssInventario, nombre_objeto, ',');

    //    getline(ssInventario, token1, ',');
    //    tipo_objeto = stoi(token1);

    //    getline(ssInventario, token1, ',');
    //    rareza_objeto = stoi(token1);

    //    getline(ssInventario, token1, ',');
    //    precio_objeto = stof(token1);

    //    getline(ssInventario, token1, ',');
    //    modificador_objeto = stoi(token1);

    //    getline(ssInventario, token1, ',');
    //    incremento_objeto = stoi(token1);

    //    getline(ssInventario, token1, ',');
    //    cantida_objeto = stoi(token1);

    //    Tipo tipoEnum = static_cast<Tipo>(tipo_objeto);

    //    // Guardar el objeto en el inventario
    //    Item nuevoObjeto(nombre_objeto, tipoEnum, rareza_objeto, precio_objeto, modificador_objeto, incremento_objeto, cantida_objeto);

    //    inventarioProvicional.push_back(nuevoObjeto);


    //    mty = false;

    //    return 0;*/
    //}

}


string tipo_to_string(Tipo aux) {
    cout << "HOLIIIIIIIIIII" << endl;
    if(Tipo::Arma == aux)
    {
        return "Arma";
    }
    else if (Tipo::Armadura == aux)
    {
        return "Armadura";
    }
    else if (Tipo::Botas == aux)
    {
        return "Botas";
    }
    else if (Tipo::Amuleto == aux)
    {
        return "Amuleto";
    }
    else if (Tipo::Casco == aux)
    {
        return "Casco";
    }
    else if (Tipo::Pocion == aux)
    {
        return "Pocion";
    }
    else {
        return "Error";
    }

}

//Tipo string_to_TIPO(const string&);
//Genero string_to_genero(const string&);
//Raza string_to_raza(const string&);
//Orientacion string_to_orientacion(const string&);
//ClaseB string_to_claseb(const string&);
void GUARDADO(int INDEX, string NAME, Genero GENERO, Raza RAZA, Orientacion ORIENTACION, ClaseB CLASEBASE, int NIVEL, float DINEROS, int PUNTOSHABILIDAD, int ESTAMINa, int MaNa, int INTELECTO, int FUERZA, int AGILIDAD, int EXPERIENCIA, bool H1, bool H2, bool H3, vector<Item> TODOinventario ){

    string path = NAME + ".txt";
    ofstream OutputFile(path, ios::out);
    if (!OutputFile) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    // Escribir los datos del personaje
    OutputFile << NAME << ",";
    OutputFile << GENERO << ",";
    OutputFile << RAZA << ",";
    OutputFile << ORIENTACION << ",";
    OutputFile << CLASEBASE << ",";
    /*OutputFile << genero_to_string(GENERO) << ",";
    OutputFile << raza_to_string(RAZA) << ",";
    OutputFile << orientacion_to_string(ORIENTACION) << ",";
    OutputFile << claseb_to_string(CLASEBASE) << ",";*/
    OutputFile << NIVEL<< ",";
    OutputFile << DINEROS << ",";
    OutputFile << PUNTOSHABILIDAD << ",";
    OutputFile << ESTAMINa << ",";
    OutputFile << MaNa << ",";
    OutputFile << INTELECTO << ",";
    OutputFile << FUERZA << ",";
    OutputFile << AGILIDAD << ",";
    OutputFile << EXPERIENCIA << ","; 
    OutputFile << H1 << ",";
    OutputFile << H2 << ",";
    OutputFile << H3 << endl;

    // Escribir el inventario
    for (int i = 0; i < TODOinventario.size(); i++)
         {
        
         Item itemaux = TODOinventario[i];
         OutputFile << itemaux.getName() << ",";
         cout<< itemaux.getName() <<endl;
         OutputFile << tipo_to_string(itemaux.getTIPO()) << ",";
         cout << itemaux.getTIPO() << endl;
         cout<< tipo_to_string(itemaux.getTIPO()) <<endl;
         OutputFile << itemaux.getRareza() << ",";
         cout<< itemaux.getRareza() <<endl;
         OutputFile << itemaux.getPrecio() << ",";
         cout<< itemaux.getPrecio() <<endl;
         OutputFile << itemaux.getmodificador() << ",";
         cout<< itemaux.getmodificador() <<endl;
         OutputFile << itemaux.getINc() << ",";
         cout<< itemaux.getINc() <<endl;
         OutputFile << itemaux.getCantidad() << ",";
         cout << itemaux.getCantidad() << endl;

         OutputFile << endl;

             }
        //     //archivo << endl;
    OutputFile.close();
   

    //ofstream oFile;
    //ifstream iFile;
    //vector<UNPERSONAJe> un_personaje;
    //bool Jala;
    //Jala = true;
    //try
    //{
    //    iFile.open("save_file.txt");
    //    if (!iFile) {
    //        try
    //        {
    //            oFile.open("save_file.txt", fstream::out);
    //            if (!oFile)
    //                throw std::runtime_error("No se pudo abrir archivo.txt para escritura");
    //            oFile << INDEX << ";" << NAME << ";" << GENERO << ";" << RAZA << ";" << ORIENTACION << ";" << CLASEBASE << ";" << NIVEL << ";" << DINEROS << ";" << PUNTOSHABILIDAD << ";" << ESTAMINa << ";" << MaNa << ";" << INTELECTO << ";" << FUERZA << ";" << AGILIDAD << ";" << EXPERIENCIA << ";" << H1 << ";" << H2 << ";" << H3  << endl;
    //            Jala = false;
    //            oFile.close();
    //        }
    //        catch (const std::exception& e)
    //        {
    //            cerr << "Ocurrio un error al escribir en archivo.txt: " << e.what() << endl;
    //        }
    //    }
    //    if (Jala) {
    //        string line;
    //        while (getline(iFile, line))
    //        {
    //            cout << line << endl;
    //            UNPERSONAJe instdatos;
    //            string tempLine = line;
    //            tempLine = modificaCadena(tempLine, 1, instdatos);
    //            tempLine = modificaCadena(tempLine, 2, instdatos);
    //            tempLine = modificaCadena(tempLine, 3, instdatos);
    //            tempLine = modificaCadena(tempLine, 4, instdatos);
    //            tempLine = modificaCadena(tempLine, 5, instdatos);
    //            tempLine = modificaCadena(tempLine, 6, instdatos);
    //            tempLine = modificaCadena(tempLine, 7, instdatos);
    //            tempLine = modificaCadena(tempLine, 8, instdatos);
    //            tempLine = modificaCadena(tempLine, 9, instdatos);
    //            tempLine = modificaCadena(tempLine, 10, instdatos);
    //            tempLine = modificaCadena(tempLine, 11, instdatos);
    //            tempLine = modificaCadena(tempLine, 12, instdatos);
    //            tempLine = modificaCadena(tempLine, 13, instdatos);
    //            tempLine = modificaCadena(tempLine, 14, instdatos);
    //            tempLine = modificaCadena(tempLine, 15, instdatos);
    //            tempLine = modificaCadena(tempLine, 16, instdatos);
    //            tempLine = modificaCadena(tempLine, 17, instdatos);
    //            tempLine = modificaCadena(tempLine, 18, instdatos);
    //            tempLine = modificaCadena(tempLine, 19, instdatos);

    //            un_personaje.push_back(instdatos);
    //        }
    //        bool patidaencontrada;
    //        patidaencontrada = false;
    //        for (auto instadatos : un_personaje)
    //        {
    //            if (instadatos.ind == INDEX) {
    //                patidaencontrada = true;
    //                instadatos.niv = NIVEL;
    //                instadatos.dinerou = DINEROS;
    //                instadatos.hpt = PUNTOSHABILIDAD;
    //                instadatos.lifeee = ESTAMINa;
    //                instadatos.manaaaa = MaNa;
    //                instadatos.intelectooooo = INTELECTO;
    //                instadatos.fuerzaaaaa = FUERZA;
    //                instadatos.agilidaddd = AGILIDAD;
    //                instadatos.expe = EXPERIENCIA;
    //                instadatos.h1tem = H1;
    //                instadatos.h2tem = H2;
    //                instadatos.h3tem = H3;

    //            }
    //        }
    //        if (patidaencontrada) {
    //            try
    //            {
    //                oFile.open("save_file.txt", fstream::out);
    //                if (!oFile)
    //                    throw std::runtime_error("No se pudo abrir archivo.txt para escritura");
    //                for (auto instadatos : un_personaje)
    //                {
    //                    oFile << instadatos.ind << ";" << instadatos.nomb << ";" << instadatos.gene << ";" << instadatos.razz << ";" << instadatos.orie << ";" << instadatos.clase << ";" << instadatos.niv << ";" << instadatos.dinerou << ";" << instadatos.hpt << ";" << instadatos.lifeee << ";" << instadatos.manaaaa << ";" << instadatos.intelectooooo << ";" << instadatos.fuerzaaaaa << ";" << instadatos.agilidaddd << ";" << instadatos.expe << ";" << instadatos.h1tem << ";" << instadatos.h2tem << ";" << instadatos.h3tem  << endl;
    //                }
    //                Jala = false;
    //                oFile.close();
    //            }
    //            catch (const std::exception& e)
    //            {
    //                cerr << "Ocurrio un error al escribir en archivo.txt: " << e.what() << endl;
    //            }
    //        }
    //        if (!patidaencontrada) {
    //            oFile.open("save_file.txt", fstream::app); // app es para escribir al final del archivo
    //            if (!oFile)
    //                throw std::runtime_error("No se pudo abrir archivo.txt para a adir");
    //            oFile << INDEX << ";" << NAME << ";" << GENERO << ";" << RAZA << ";" << ORIENTACION << ";" << CLASEBASE << ";" << NIVEL << ";" << DINEROS << ";" << PUNTOSHABILIDAD << ";" << ESTAMINa << ";" << MaNa << ";" << INTELECTO << ";" << FUERZA << ";" << AGILIDAD << ";" << EXPERIENCIA << ";" << H1 << ";" << H2 << ";" << H3 << endl;
    //            
    //            fstream Oarchivo;
    //            Oarchivo.open("inventario_file.txt", ios::app);

    //                   for (int i = 0; i < TODOinventario.size(); i++)
    //                      {
    //                       Oarchivo << index << ",";
    //                       Oarchivo << i << ",";
    //                       Item itemaux = TODOinventario[i];
    //                       Oarchivo << itemaux.getName() << ",";
    //                       Oarchivo << itemaux.getTIPO() << ",";
    //                       Oarchivo << itemaux.getRareza() << ",";
    //                       Oarchivo << itemaux.getPrecio() << ",";
    //                       Oarchivo << itemaux.getmodificador() << ",";
    //                       Oarchivo << itemaux.getINc() << ",";
    //                       Oarchivo << itemaux.getCantidad() << ",";
    //                       Oarchivo << endl;

    //                     }

    //            Oarchivo.close();
    //            oFile.close();
    //        }
    //    }

    //    iFile.close();
    //}
    //catch (const std::exception& e)
    //{
    //    cerr << "Ocurrio un error al leer de archivo.txt: " << e.what() << endl;
    //}
    //cout << "Partida Guardada" << endl;



   // // Guardar partida
   // fstream Oarchivo; // Abrir el archivo para lectura y escritura
   ///* ifstream Iarchivo; // Archivo temporal para escribir los datos actualizados
   // bool existencia = true;*/
   // int hmany = 0;
   // int numeroLineas = 0;
   // ifstream archivo("save_file.txt");
   // string linea;

   // // Leer cada línea del archivo para asignar id
   // while (getline(archivo, linea)) {
   //     numeroLineas++;
   // }

   // archivo.close();

   // hmany = numeroLineas;
   // 
   // if (hmany == INDEX) {
   //     Oarchivo.open("save_file.txt", ios::app); // ios::app -> append // Crea una linea abajo

   //     Oarchivo << INDEX << ",";
   //     Oarchivo << NAME << ",";
   //     Oarchivo << GENERO << ",";
   //     Oarchivo << RAZA << ",";
   //     Oarchivo << ORIENTACION << ",";
   //     Oarchivo << CLASEBASE << ",";
   //     Oarchivo << NIVEL << ",";
   //     Oarchivo << DINEROS << ",";
   //     Oarchivo << PUNTOSHABILIDAD << ",";
   //     Oarchivo << ESTAMINa << ",";
   //     Oarchivo << MaNa << ",";
   //     Oarchivo << INTELECTO << ",";
   //     Oarchivo << FUERZA << ",";
   //     Oarchivo << AGILIDAD << ",";
   //     Oarchivo << EXPERIENCIA << ",";
   //     Oarchivo << H1 << ",";
   //     Oarchivo << H2 << ",";
   //     Oarchivo << H3 << ",";
   //     Oarchivo << endl;
   //     Oarchivo.close();

   //     Oarchivo.open("inventario_file.txt", ios::app);

   //     for (int i = 0; i < TODOinventario.size(); i++)
   //     {
   //         Oarchivo << index << ",";
   //         Oarchivo << i << ",";
   //         Item itemaux = TODOinventario[i];
   //         Oarchivo << itemaux.getName() << ",";
   //         Oarchivo << itemaux.getTIPO() << ",";
   //         Oarchivo << itemaux.getRareza() << ",";
   //         Oarchivo << itemaux.getPrecio() << ",";
   //         Oarchivo << itemaux.getmodificador() << ",";
   //         Oarchivo << itemaux.getINc() << ",";
   //         Oarchivo << itemaux.getCantidad() << ",";
   //         Oarchivo << endl;

   //     }
   //     //archivo << endl;
   //     Oarchivo.close();
   // }
   // else {

   // }
   
    //// Guardar partida
    //fstream archivo;
    //archivo.open("save_file.txt", ios::in | ios::out); // Abrir en modo lectura y escritura
    //bool encontrado = false;
    //string linea;
    //while (getline(archivo, linea)) {
    //    // Buscar el índice en el archivo
    //    size_t pos = linea.find(to_string(INDEX) + ",");
    //    if (pos != string::npos) {
    //        // Si se encuentra el índice, sobrescribir la línea
    //        archivo.seekp(static_cast<long>(archivo.tellg()) - static_cast<long>(linea.length()) - 1); // Retroceder al inicio de la línea
    //        archivo << INDEX << ",";
    //        archivo << NAME << ",";
    //        archivo << GENERO << ",";
    //        archivo << RAZA << ",";
    //        archivo << ORIENTACION << ",";
    //        archivo << CLASEBASE << ",";
    //        archivo << NIVEL << ",";
    //        archivo << DINEROS << ",";
    //        archivo << PUNTOSHABILIDAD << ",";
    //        archivo << ESTAMINa << ",";
    //        archivo << MaNa << ",";
    //        archivo << INTELECTO << ",";
    //        archivo << FUERZA << ",";
    //        archivo << AGILIDAD << ",";
    //        archivo << EXPERIENCIA << ",";
    //        archivo << H1 << ",";
    //        archivo << H2 << ",";
    //        archivo << H3 << ",";
    //        archivo << endl;
    //        encontrado = true;
    //        break;
    //    }
    //}
    //// Si no se encontró el índice, añadir una nueva línea al final del archivo
    //if (!encontrado) {
    //    archivo.clear();
    //    archivo.seekp(0, ios::end); // Ir al final del archivo
    //    archivo << INDEX << ",";
    //    archivo << NAME << ",";
    //    archivo << GENERO << ",";
    //    archivo << RAZA << ",";
    //    archivo << ORIENTACION << ",";
    //    archivo << CLASEBASE << ",";
    //    archivo << NIVEL << ",";
    //    archivo << DINEROS << ",";
    //    archivo << PUNTOSHABILIDAD << ",";
    //    archivo << ESTAMINa << ",";
    //    archivo << MaNa << ",";
    //    archivo << INTELECTO << ",";
    //    archivo << FUERZA << ",";
    //    archivo << AGILIDAD << ",";
    //    archivo << EXPERIENCIA << ",";
    //    archivo << H1 << ",";
    //    archivo << H2 << ",";
    //    archivo << H3 << ",";
    //    archivo << endl;
    //}
    //archivo.close();

    // Guardar inventario
    //archivo.open("inventario_file.txt", ios::app);
    //archivo.clear();
    //archivo.seekp(0, ios::end); // Ir al final del archivo
    //for (size_t i = 0; i < TODOinventario.size(); ++i) {
    //    archivo << INDEX << ",";
    //    archivo << i << ",";
    //    Item itemaux = TODOinventario[i];
    //    archivo << itemaux.getName() << ",";
    //    archivo << itemaux.getTIPO() << ",";
    //    archivo << itemaux.getRareza() << ",";
    //    archivo << itemaux.getPrecio() << ",";
    //    archivo << itemaux.getmodificador() << ",";
    //    archivo << itemaux.getINc() << ",";
    //    archivo << itemaux.getCantidad() << ",";
    //    archivo << endl;
    //}
    //archivo.close();
}

//void GuardarGuerrero(Guerrero miGuerrero){
//    // Buscar la posición del índice en el archivo
//    //int posicion = buscarIndice(index);
//    // Guardar partida
//    ofstream archivo;
//    archivo.open("save_file.txt", ios::app); // ios::app -> append // Crea una linea abajo
//    // Verificar si el archivo está vacío
//    if (!archivo.eof()) {
//        // Agregar un salto de línea
//        archivo << endl;
//    }
//    if (true)
//    {
//
//        archivo << index << ",";
//        archivo << miGuerrero.getName() << ",";
//        archivo << genero << ",";
//        archivo << raza << ",";
//        archivo << orientacion << ",";
//        archivo << ClaseBase << ",";
//        archivo << miGuerrero.getLVL() << ",";
//        archivo << miGuerrero.getGOLD() << ",";
//        archivo << miGuerrero.getpH() << ",";
//        archivo << miGuerrero.getEST() << ",";
//        archivo << miGuerrero.getMANA() << ",";
//        archivo << 1 << ",";
//        archivo << 2 << ",";
//        archivo << 3 << ",";
//        archivo << miGuerrero.getEXP() << ",";
//        archivo << miGuerrero.getAtaquePotenteActive() << ",";
//        archivo << miGuerrero.getDefensadeHierroActive() << ",";
//        archivo << miGuerrero.getGritoGuerraActive() << ",";
//        archivo << endl;
//        archivo.close();
//
//        archivo.open("inventario_file.txt", ios::app);
//        if (!archivo.eof()) {
//            // Agregar un salto de línea
//            archivo << endl;
//        }
//        archivo << index << ",";
//        archivo << index << ",";
//        for (int i = 0; i < miGuerrero.getLongInventario(); i++)
//        {
//            Item itemaux = miGuerrero.getItem(i);
//            archivo << itemaux.getName() << ",";
//            archivo << itemaux.getName() << ",";
//            archivo << itemaux.getName() << ",";
//            archivo << itemaux.getPrecio() << ",";
//            archivo << itemaux.getName() << ",";
//            archivo << itemaux.getName() << ",";
//            archivo << itemaux.getCantidad() << ",";
//
//        }
//        //archivo << endl;
//        archivo.close();
//    }
//
//}

//string modificaCadena(string cadena, int elemento, UNPERSONAJe& m)
//{
//    // Encuentra el primer punto y coma
//    size_t pos = cadena.find(";");
//
//    // Extrae el valor antes del punto y coma o el final de la cadena si no hay punto y coma
//    string value;
//    if (pos != string::npos)
//    {
//        value = cadena.substr(0, pos);
//        // Elimina el valor ya procesado del string, junto con el punto y coma
//        cadena = cadena.substr(pos + 1);
//    }
//    else
//    {
//        value = cadena; // Si no hay punto y coma, asume que el resto de la cadena es el ultimo valor
//    }
//
//    switch (elemento)
//    {
//    case 1:
//        m.ind = stoi(value);
//    case 2:
//        m.nomb = value;
//        break;
//    case 3:
//        int genValue = static_cast<int>(m.gene);
//        genValue = stoi(value);
//        break;
//    case 4:
//        int RaValue = static_cast<int>(m.razz);
//        RaValue = stoi(value);
//        break;
//    case 5:
//        int OrValue = static_cast<int>(m.orie);
//        OrValue = stoi(value);
//        break;
//    case 6:
//        int CValue = static_cast<int>(m.clase);
//        CValue = stoi(value);
//        break;
//    case 7:
//        m.niv = stoi(value);
//        break;
//    case 8:
//        m.dinerou = stoi(value);
//        break;
//    case 9:
//        m.hpt = stoi(value);
//        break;
//    case 10:
//        m.lifeee = stoi(value);
//        break;
//    case 11:
//        m.manaaaa = stoi(value);
//        break;
//    case 12:
//        m.intelectooooo = stoi(value);
//        break;
//    case 13:
//        m.fuerzaaaaa = stoi(value);
//        break;
//    case 14:
//        m.agilidaddd = stoi(value);
//        break;
//    case 15:
//        m.expe = stoi(value);
//        break;
//    case 16:
//        m.h1tem = stoi(value);
//        break;
//    case 17:
//        m.h2tem = stoi(value);
//        break;
//    case 18:
//        m.h3tem = stoi(value);
//        break;
//    default:
//        break;
//    }
 //   return cadena;
//}
// Función para buscar la posición de un índice en el archivo



int buscarIndice(int index) {
    int posicion = -1;
    ifstream archivo("save_file.txt");
    string linea;
    int lineaActual = 1;

    // Leer cada línea del archivo
    while (getline(archivo, linea)) {
        // Obtener el índice de la línea actual
        int indiceLinea = stoi(linea.substr(0, linea.find(",")));

        // Si el índice coincide, guardar la posición
        if (indiceLinea == index) {
            posicion = lineaActual;
            break;
        }

        lineaActual++;
    }

    archivo.close();

    return posicion;
}
    


