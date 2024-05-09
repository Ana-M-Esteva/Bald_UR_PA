#include "Guerrero.h"

Guerrero::Guerrero(string n, Genero g, Raza r, Orientacion o, ClaseB CB, int lv, float gold, int pH, int e, int m, int i, int f, int a, vector<Item> inv, int exp, bool APActive, bool DHA, bool GGA)
    : Personaje(n, g, r, o, CB, lv, gold, pH, e, m, i, f, a, inv, exp) {
    AtaquePotenteActive = APActive;
    DefensadeHierroActive = DHA;
    GritoGuerraActive = GGA;

    DefensadeHierroTurns = 0;
    GritoGuerraTurns = 0;
    EnUsoDefensadeHierro = false;
    EnUsoGritoGuerra = false;
    MitadD = false;

} //Pasa atrivutos // Faltan las habilidades 

Guerrero::~Guerrero() {

}


Item HachadeBattalla("Hacha de Batalla", Arma, 1, 800, 1, 2, 1);
Item CascodeGuerrero("Casco de Guerrero", Casco, 1, 600, 0, 1, 1);
Item ArmaduraReforzada("Armadura Reforzada", Armadura, 2, 1000, 1, 2, 1);
Item BotasconPuas("Botas con Púas", Botas, 1, 550, 0, 1, 1);
Item EscudodeBatalla("Escudo de Batalla", Amuleto, 1, 750, 1, 1, 1);
Item BotasdeGuerra("Botas de Guerra", Botas, 2, 650, 2, 1, 1);
Item CorornadeGuerrero("Corona de Guerrero", Casco, 3, 700, 0, 2, 1);
Item EspadadelGladiador("Espada del Gladiador", Arma, 2, 800, 1, 1, 1);
Item HierbasMedicinales("Hierbas Medicinales", Pocion, 0, 25, 3, 10, 50); //Falta modificar
Item ElixirdelasHadas("Elixir de las Hadas", Pocion, 1, 35, 4, 10, 50); //Falta modificar

//AGREGAR HABILIDADES?
void Guerrero::mostrarInformacion() {
    cout << "**Guerrero**" << endl << endl;
    cout << "Nombre: " << nombre << endl;
    if (genero == Masculino) {
        cout << "Genero: Hombre" << endl;
    }
    else if(genero == Femenino) {
        cout << "Genero: Mujer" << endl;
    }
    else if(genero == Otro) {
        cout << "Genero: ???" << endl;
    }

    if (raza == SerHumano) {
        cout << "Raza: Ser Humano" << endl;
    }
    else if (raza == Elfo) {
        cout << "Raza: Elfo" << endl;
    }
    else if (raza == Enano) {
        cout << "Raza: Enano" << endl;
    }
    else if (raza == Orco) {
        cout << "Raza: Orco" << endl;
    }

    if (orientacion == Bueno) {
        cout << "Orientación: Bueno" << endl;
    }
    else if (orientacion == Neutro) {
        cout << "Orientación: Neutro" << endl;
    }
    else if (orientacion == Malo) {
        cout << "Orientación: Malo" << endl;
    }
   
    cout << "Nivel: " << nivel << endl;
    cout << "Experiencia: " << experiencia << endl;
    cout << "Dinero: " << dinero << endl;
    cout << "Puntos de Habilidad: " << puntosHabilidad << endl;
    cout << "Estamina: " << estamina << endl;
    cout << "Mana: " << mana << endl;
    cout << "Intelecto: " << intelecto << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Agilidad: " << agilidad << endl<<endl;

    for (int i = 0; i < inventario.size(); i++) {
       inventario[i].ImprimirItem();
    }

    cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje 
    cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
    cin.get(); // Espera a que el usuario presione ENTER
}

void Guerrero::tiendaEquipo()
{
    setlocale(LC_ALL, "");
    

    //Comparar con el inventario del jugado para que si tiene dicho objeto salga reducido el número
    vector<Item> allItems {HachadeBattalla, CascodeGuerrero, ArmaduraReforzada, BotasconPuas, EscudodeBatalla, BotasdeGuerra, CorornadeGuerrero, EspadadelGladiador, HierbasMedicinales, ElixirdelasHadas };
    bool seguirComprando = true;
    
        for (int i = 0; i < allItems.size(); i++)
        {
            for (int j = 0; j < inventario.size(); j++)
            {
                if (allItems[i].getName() == inventario[j].getName() && allItems[i].getCantidad() >= 0)
                {
                    cout << i << ". ";
                    allItems[i].reducirCantidad();
                }
            }

        }
        while (seguirComprando)
        {
        cout << "_-- Tienda de Fuerza --_ " << endl << endl;
        cout << "Actualmente usted tiene: " << dinero << "G" << endl;

        for (int i = 0; i < allItems.size(); i++) {
            cout << i << ".";
            allItems[i].ImprimirItem();
        }

        int op;
        do {
            cout << "¿Desea comprar un item? (1 - Sí, 2 - No): ";
            cin >> op;
        } while (op != 1 && op != 2);

        if (op == 1) {
            int op2;
            do {
                cout << "Ingrese el número del item que desea comprar: ";
                cin >> op2;
            } while (op2 < 0 || op2 >= allItems.size());

            if (allItems[op2].getCantidad() > 0) {
                if (dinero >= allItems[op2].getPrecio()) {
                    comprarItem(allItems[op2]);
                    cout << "¡Artículo comprado exitosamente!" << endl;
                }
                else {
                    cout << "No tienes suficiente dinero para comprar este item." << endl;
                }
            }
            else {
                cout << "Lo siento, el item seleccionado está agotado." << endl;
            }
        }
        else {
            seguirComprando = false;
            cout << "Gracias por visitar la tienda, vuelva pronto." << endl;
        }
    }

    cout << "Presione ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
}


    //cout << "Si quiere comprar oprima 1, de lo contrario oprima 2" << endl;
    //int op = 0;
    //if (op == 1) {

    //    cout << "Ingrese el número asociado al producto que desea comprar" << endl;
    //    int op2 = -1;
    //    cin >> op2;
    //    if (dinero >= allItems[op2].getPrecio()) {
    //        cout << "¡Artículo vendido!" << endl;
    //    }
    //    else {
    //        cout << "La bruja de la tienda se ha enojado ya que no tiene suficiente oro. Corra por su vida. Regrese cuando tenga suficiente" << endl;
    //    }
    //}
    //else {
    //    cout << "Cerrando tienda, vuelva pronto" << endl;
    //}
    //cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
    //cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
    //cin.get(); // Espera a que el usuario presione ENTER


void Guerrero::tiendaHabilidad()
{
    cout << "Bienvenido sea. Gaste sus puntos y active sus poderes" << endl;
    cout << "Actualmente usted tiene: " << puntosHabilidad << "pH" << endl;
    cout << "Las habilidades siguientes son aquellas que tiene o podra obtener:" << endl;
    cout << "0. Ataque " << "\t" << "Activa" << endl;
    cout << "1. Ataque Potente" << "\t";
    if (AtaquePotenteActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 5 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "2. Defensa de Hierro" << "\t";
    if (DefensadeHierroActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 12 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "3. Grito de Guerra" << "\t";
    if (GritoGuerraActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 25 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
   
    int op;
    do {
        cout << "¿Desea comprar una habilidad? (1 - Sí, 2 - No): ";
        cin >> op;
    } while (op != 1 && op != 2);
    if (op == 1) {
        int skillIndex = -1;
        int end = 1;
        while (end == 1)
        {
            cout << "Ingrese el numero asociado a la habilidad" << endl;
            cin >> skillIndex;
            switch (skillIndex) {
            case 1:
                cout << "Para activar esta habilidad requiere 5 pH" << endl;
                if (puntosHabilidad >= 5 && AtaquePotenteActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 5;
                    AtaquePotenteActive = true;
                    cout << "Habilidad ACTIVADA !!!  ";
                }
                else if (puntosHabilidad < 5) {
                    cout << "Insuficiente cantidad de puntos";
                }
                else {
                    cout << "Esta habilidadad ya esta activa";
                }
                break;
            case 2:
                cout << "Para activar esta habilidad requiere 12 pH" << endl;
                if (puntosHabilidad >= 12 && DefensadeHierroActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 12;
                    DefensadeHierroActive = true;
                    cout << "Habilidad ACTIVADA !!!  ";
                }
                else if (puntosHabilidad < 12) {
                    cout << "Insuficiente cantidad de puntos";
                }
                else {
                    cout << "Esta habilidadad ya esta activa";
                }
                break;
            case 3:
                cout << "Para activar esta habilidad requiere 25 pH" << endl;
                if (puntosHabilidad >= 25 && GritoGuerraActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 25;
                    GritoGuerraActive = true;
                    cout << "Habilidad ACTIVADA  !!!  ";
                }
                else if (puntosHabilidad < 25) {
                    cout << "Insuficiente cantidad de puntos";
                }
                else {
                    cout << "Esta habilidadad ya esta activa";
                }
                break;
            case 0:
                cout << "Esta habilidad está activada" << endl;
                break;
            default:
                cout << "Habilidad no válida." << endl;
                break;
            }
            cout << "Para cerrar su compra presione 0. Si quiere continuar presione 1. :";
            cin >> end;
        }
    }
}

void Guerrero::comprarItem(Item& item)
{
    dinero -= item.getPrecio();
    Item auxi = item;
    auxi.justOne();
    item.reducirCantidad();

    bool encontrado = false;
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].getName() == item.getName()) {
            inventario[i].incrementarCantidad();
            
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        inventario.push_back(auxi);
        if (auxi.getmodificador() == 0) {

            intelecto = intelecto + auxi.getINc();

        }
        else if (auxi.getmodificador() == 1)
        {
            fuerza = fuerza + auxi.getINc();
        }
        else if (auxi.getmodificador() == 2)
        {
            agilidad = agilidad + auxi.getINc();
        }
    }

    cout << endl;
    for (int i = 0; i < inventario.size(); i++) {
        inventario[i].ImprimirItem();
    }
    cout << endl;
}

bool Guerrero::noSigueVivo()
{
    return estamina < 0;
}

void Guerrero::IncrentoExp(int x)
{
    experiencia += x;
    cout << "Tu experiencia es equivalente a : " << experiencia;
}

void Guerrero::estaminaPerdida(int eP)
{
    if (MitadD == false) {
        estamina = estamina - eP;  
    }
    else {
        cout << "Habilidad encendida, la reducción a tu estamina es menor" << endl;
        estamina = estamina - (eP/2);
    }
    if (estamina <= 0)
    {
        cout << "La batalla fue dificil. ¡Has muerto! Pierdes la mitad de tu dinero y con ello todo tu inventario a exepción de tu primer arma." << endl;
    }
}

int Guerrero::Ataque(int enemigolvl, int extra)
{
    int dbase = 3;
    int dvar = rand() % 5 + 1;
    int danno = (dvar + dbase) * nivel;
   // int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return danno + extra;

}

int Guerrero::AtaquePotente(int enemigolvl, int extra)
{
    int dbase = 4;
    int dvar = rand() % 9 + 1;
    int danno = (dvar + dbase) * nivel;
    //int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return (2*danno) + extra;
}

void Guerrero::DefensadeHierro(int enemigolvl)
{
    DefensadeHierroTurns = 5;
    MitadD = true;
    
}

int Guerrero::GritoGuerra(int enemigolvl)
{
    GritoGuerraTurns = 7;
    int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + 6 << endl;
    return danno;
}

void Guerrero::ConsecuenciasMuerte()
{
    dinero = dinero / 2;
}

void Guerrero::levelUp()
{
    // Vector con los límites de experiencia para cada nivel
    vector<int> experienciaNiveles = 
    {7, 23, 47, 110, 220, 450, 800, 1300, 2000, 2900, 4000, 5500, 7500, 10000, 13000, 17000, 21000, 25000, 29000, 33000, 37000, 41000, 45000, 49000, 53000, 57000, 61000, 65000, 70000};

    // Recorrer el vector para encontrar el nivel actual
    for (int i = 0; i < experienciaNiveles.size(); i++) {
        if (experiencia < experienciaNiveles[i]) {
            int var = nivel;
            nivel = i + 1;
            if (nivel > var) {
                puntosHabilidad = puntosHabilidad + 1;
                mana = mana + 5;
                estamina = estamina + 5;
            }
            // Mensaje de subida de nivel
            cout << "¡Felicidades! Tu nivel es " << nivel << endl;
            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
            cin.get(); // Espera a que el usuario presione ENTER
            break;
        }
    }

    cout << "Tu nivel:  " << nivel << "  Tu experiencia:  " << experiencia << endl;
    

//    if (experiencia < 7) {
//        nivel = 1;
//    }
//    else if (7 <= experiencia && experiencia < 23)
//    {
//        nivel = 2;
//    }
//    else if (23 <= experiencia && experiencia < 47)
//    {
//        nivel = 3;
//    }
//    else if (47 <= experiencia && experiencia < 110)
//    {
//        nivel = 4;
//    }
//    else if (110 <= experiencia && experiencia < 220)
//    {
//        nivel = 5;
//    }
//    else if (220 <= experiencia && experiencia < 450)
//    {
//        nivel = 6;
//    }
//    else if (450 <= experiencia && experiencia < 800)
//    {
//        nivel = 7;
//    }
//    else if (800 <= experiencia && experiencia < 1300)
//    {
//        nivel = 8;
//    }
//    else if (1300 <= experiencia && experiencia < 2000)
//    {
//        nivel = 9;
//    }
//    else if (2000 <= experiencia && experiencia < 2900)
//    {
//        nivel = 10;
//    }
//    else if (2900 <= experiencia && experiencia < 4000)
//    {
//        nivel = 11;
//    }
//    else if (4000 <= experiencia && experiencia < 5500)
//    {
//        nivel = 12;
//    }
//    else if (5500 <= experiencia && experiencia < 7500)
//    {
//        nivel = 13;
//    }
//    else if (7500 <= experiencia && experiencia < 10000)
//    {
//        nivel = 14;
//    }
//    else if (10000 <= experiencia && experiencia < 13000)
//    {
//        nivel = 15;
//    }
//    else if (13000 <= experiencia && experiencia < 17000)
//    {
//        nivel = 16;
//    }
//    else if (17000 <= experiencia && experiencia < 21000)
//    {
//        nivel = 17;
//    }
//    else if (21000 <= experiencia && experiencia < 25000)
//    {
//        nivel = 18;
//    }
//    else if (25000 <= experiencia && experiencia < 29000)
//    {
//        nivel = 19;
//    }
//    else if (29000 <= experiencia && experiencia < 33000)
//    {
//        nivel = 20;
//    }
//    else if (33000 <= experiencia && experiencia < 37000)
//    {
//        nivel = 21;
//    }
//    else if (37000 <= experiencia && experiencia < 41000)
//    {
//        nivel = 22;
//    }
//    else if (41000 <= experiencia && experiencia < 45000)
//    {
//        nivel = 23;
//    }
//    else if (45000 <= experiencia && experiencia < 49000)
//    {
//        nivel = 24;
//    }
//    else if (49000 <= experiencia && experiencia < 53000)
//    {
//        nivel = 25;
//    }
//    else if (53000 <= experiencia && experiencia < 57000)
//    {
//        nivel = 26;
//    }
//    else if (57000 <= experiencia && experiencia < 61000)
//    {
//    nivel = 27;
//    }
//    else if (61000 <= experiencia && experiencia < 65000)
//    {
//    nivel = 28;
//    }
//    else if (65000 <= experiencia && experiencia < 70000)
//    {
//    nivel = 29;
//    }
//    else if ( experiencia <= 70000)
//    {
//    nivel = 30;
//    }
    
}

void Guerrero::DineroGAnado(float gold)
{
    dinero = dinero + gold;
}

void Guerrero::StatusActual()
{
    cout << "Nivel: " << nivel << endl;
    cout << "Estamina: " << estamina << endl;
    cout << "Mana: " << mana << endl;
}

string Guerrero::getName() {
    return nombre;
}

Genero Guerrero::getGenero() {
    return genero;
}

Raza Guerrero::getRaza() {
    return raza;
}

Orientacion Guerrero::getOr() {
    return orientacion;
}

int Guerrero::getLVL()
{
    return nivel;
}

float Guerrero::getGOLD() {
    return dinero;
}

int Guerrero::getpH() {
    return puntosHabilidad;
}

int Guerrero::getEST() {
    return estamina;
}

int Guerrero::getMANA() {
    return mana;
}

int Guerrero::getEXP() {
    return experiencia;
}

int Guerrero::getINTELECTO() {
    return intelecto;
}

int Guerrero::getFUERZA() {
    return fuerza;
}

int Guerrero::getAGILIDAD() {
    return agilidad;
}

bool Guerrero::getAtaquePotenteActive() {
    return AtaquePotenteActive;
}

bool Guerrero::getDefensadeHierroActive() {
    return DefensadeHierroActive;
}

bool Guerrero::getGritoGuerraActive() {
    return GritoGuerraActive;
}

int Guerrero::getLongInventario() {
    return inventario.size();
}

Item Guerrero::getItem(int i){
    return inventario[i];

}

vector<Item> Guerrero::getINVENTARIO() {
    return inventario;
}

int Guerrero::Atacar(int enemigolvl)
{
    int extra = 0;
    bool hayP = false;
    bool hayH = false;
    cout << DefensadeHierroTurns << endl;
    cout << GritoGuerraTurns << endl;

    cout << "Es tu turno de atacar !" << endl;
    cout << "Eliga como quiere atacar. Actualmente tiene : " << mana << endl;
    cout << "0. Ataque " << "\t" << "Uso de mana = 2 puntos" << endl;

    if (AtaquePotenteActive == true)
    {
        cout << "1. Ataque Potente" << "\t" << "Uso de mana = 5 puntos" << endl;
    }

    if (DefensadeHierroActive == true)
    {
        cout << "2. Defensa de Hierro" << "\t" << "Uso de mana = 10 puntos" << endl;
    }

    if (GritoGuerraActive == true)
    {
        cout << "3. Grito de Guerra" << "\t" << "Uso de mana = 20 puntos" << endl;
    }

    if ( DefensadeHierroTurns > 0)
    {
        MitadD = true;
        --DefensadeHierroTurns;
    }
    else {
        MitadD = false;
    }
    if (GritoGuerraTurns > 0)
    {
        extra = enemigolvl*0.5;
        cout << extra;
        --GritoGuerraTurns;
    }
    else {
        extra = 0;
    }
    for (int j = 0; j < inventario.size(); j++)
    {
        if ("Hierbas Medicinales" == inventario[j].getName() && inventario[j].getCantidad() > 0)
        {
            hayH = true;
            cout<< "4. Hierbas Medicinales" << "\t" << "Uso de una implica perder la oportunidad de atacar" << endl;
        }
        if ("Elixir de las Hadas" == inventario[j].getName() && inventario[j].getCantidad() > 0)
        {
            hayP = true;
            cout << "5. Elixir de las Hadas" << "\t" << "Uso de una implica perder la oportunidad de atacar" << endl;
        }
    }
    int moduloAtaque = 0;
    int seleccion = -1;
    cout << "Eliga el número asociado a la habilidad: " << endl;
    cin >> seleccion;
    if  (mana > 0){
        switch (seleccion)
        {
        case 0:
            if (mana > 1)
            {
                mana = mana - 2;
                moduloAtaque = Ataque(enemigolvl, extra);//LLAMAR HABILIDAD

            }
            break;
        case 1:
            if (mana > 4 && AtaquePotenteActive == true)
            {
                mana = mana - 5;
                moduloAtaque = AtaquePotente(enemigolvl, extra); //LLAMAR HABILIDAD
                
            }
            break;
        case 2:
            if (mana > 9 && DefensadeHierroActive == true)
            {
                mana = mana - 10;
                cout << "Has activado Defensa de Hierro" << endl;
                DefensadeHierro(enemigolvl);//LLAMAR HABILIDAD
            }
            break;
        case 3:
            if (mana > 19 && GritoGuerraActive == true)
            {
                mana = mana - 20;
                cout << "Has activado Grito de Guerra" << endl;
                moduloAtaque = GritoGuerra(enemigolvl);
            }
            break;
        case 4:
            if (hayH == true)
            {
                for (int j = 0; j < inventario.size(); j++)
                {
                    if ("Hierbas Medicinales" == inventario[j].getName())
                    {
                        inventario[j].reducirCantidad();
                        estamina = estamina + 10;
                    }
                }
            }
            break;
        case 5:
            if (hayP == true)
            {
                for (int j = 0; j < inventario.size(); j++)
                {
                    if ("Elixir de las Hadas" == inventario[j].getName())
                    {
                        inventario[j].reducirCantidad();
                        mana = mana + 10;
                    }
                }
            }
            break;
        default:
            break;
        }
    }
    else {
        cout << "Ya no tienes mana" << endl;
    }

    return moduloAtaque;

}

void Guerrero::PostMortum(int ne, int nm) {

    estamina = ne;
    mana = nm;
}
