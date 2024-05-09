#include "Arquero.h"


Arquero::Arquero(string n, Genero g, Raza r, Orientacion o, ClaseB CB, int lv, float gold, int pH, int e, int m, int i, int f, int a, vector<Item> inv, int xP, bool DRActive, bool OHA, bool RFA)
    : Personaje(n, g, r, o, CB, lv, gold, pH, e, m, i, f, a, inv, xP) {
     DisparoRapidoActive = DRActive; // Indica si la Ataque Potente la puede usar el usuario
     OjodeHalconActive = OHA; // Indica si la Defensa de Hierro la puede usar el usuario
     RafagadeFlechasActive = RFA; // Indica si el Grito de Guerra la puede usar el usuario

     OjodeHalconTurns = 0; // Número de turnos restantes 
     RafagadeFlechasTurns = 0; // Número de turnos restantes 
     EnUsoOjodeHalcon = false;
     EnUsoRafagadeFlechas = false;
     forh3 = 0;
     howlong = 0;
}

Arquero::~Arquero() {

}

void Arquero::mostrarInformacion() {
    cout << "**Arquero**" << endl << endl;
    cout << "Nombre: " << nombre << endl;
    if (genero == Masculino) {
        cout << "Genero: Hombre" << endl;
    }
    else if (genero == Femenino) {
        cout << "Genero: Mujer" << endl;
    }
    else if (genero == Otro) {
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
    cout << "Agilidad: " << agilidad << endl << endl;

    for (int i = 0; i < inventario.size(); i++) {
        inventario[i].ImprimirItem();
    }

    cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
    cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
    cin.get(); // Espera a que el usuario presione ENTER
}


Item ArcoLargo("Arco Largo", Arma, 1, 500, 1, 2, 1);
Item CapuchadeOjodeHalcon("Capucha de Ojo de Halcón", Casco, 1, 550, 0, 1, 1);
Item ArmaduradeCuero("Armadura de Cuero", Armadura, 2, 600, 1, 2, 1);
Item BotasSilenciosas("Botas Silenciosas", Botas, 1, 450, 0, 1, 1);
Item CapadelBosque("Capa del Bosque", Casco, 3, 750, 1, 1, 1);
Item GuantesReforzados("Guantes Reforzados", Amuleto, 2, 550, 2, 1, 1);
Item BandanadePoder("Bandana de Poder", Casco, 3, 650, 0, 2, 1);
Item BallestadePrecision("Ballesta de Precisión", Arma, 2, 800, 1, 1, 1);
Item Hierbasmedicinales("Hierbas Medicinales", Pocion, 0, 25, 1, 10, 50); //Falta modificar
Item Elixirdelashadas("Elixir de las Hadas", Pocion, 1, 35, 0, 10, 50); //Falta modificar

void Arquero::tiendaEquipo()
{
    setlocale(LC_ALL, "");


    //Comparar con el inventario del jugado para que si tiene dicho objeto salga reducido el número
    vector<Item> allItems{ArcoLargo,CapuchadeOjodeHalcon,ArmaduradeCuero,BotasSilenciosas,CapadelBosque,GuantesReforzados,BandanadePoder,BallestadePrecision,Hierbasmedicinales,Elixirdelashadas};

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
        cout << "_-- Tienda de Arqueros --_ " << endl << endl;
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

void Arquero::comprarItem(Item& item) {
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
    }

    cout << endl;
    for (int i = 0; i < inventario.size(); i++) {
        inventario[i].ImprimirItem();
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
}

void Arquero::tiendaHabilidad()
{
    cout << "Bienvenido sea. Gaste sus puntos y active sus poderes" << endl;
    cout << "Actualmente usted tiene: " << puntosHabilidad << "pH" << endl;
    cout << "Las habilidades siguientes son aquellas que tiene o podra obtener:" << endl;
    cout << "0. Ataque " << "\t" << "Activa" << endl;
    cout << "1. Disparo Rapido" << "\t";
    if (DisparoRapidoActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 5 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "2. Ojo de Halcón" << "\t";
    if (OjodeHalconActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 18 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "3. Rafaga de Flechas" << "\t";
    if (RafagadeFlechasActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 27 pH" << endl;
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
                if (puntosHabilidad >= 5 && DisparoRapidoActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 5;
                    DisparoRapidoActive = true;
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
                cout << "Para activar esta habilidad requiere 18 pH" << endl;
                if (puntosHabilidad >= 18 && OjodeHalconActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 18;
                    OjodeHalconActive = true;
                    cout << "Habilidad ACTIVADA !!!  ";
                }
                else if (puntosHabilidad < 18) {
                    cout << "Insuficiente cantidad de puntos";
                }
                else {
                    cout << "Esta habilidadad ya esta activa";
                }
                break;
            case 3:
                cout << "Para activar esta habilidad requiere 27 pH" << endl;
                if (puntosHabilidad >= 27 && RafagadeFlechasActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 27;
                    RafagadeFlechasActive = true;
                    cout << "Habilidad ACTIVADA  !!!  ";
                }
                else if (puntosHabilidad < 27) {
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


string Arquero::getName() {
    return nombre;
}

Genero Arquero::getGenero() {
    return genero;
}

Raza Arquero::getRaza() {
    return raza;
}

Orientacion Arquero::getOr() {
    return orientacion;
}

int Arquero::getLVL()
{
    return nivel;
}

float Arquero::getGOLD() {
    return dinero;
}

int Arquero::getpH() {
    return puntosHabilidad;
}

int Arquero::getEST() {
    return estamina;
}

int Arquero::getMANA() {
    return mana;
}

int Arquero::getINTELECTO() {
    return intelecto;
}

int Arquero::getFUERZA() {
    return fuerza;
}

int Arquero::getAGILIDAD() {
    return agilidad;
}

int Arquero::getEXP() {
    return experiencia;
}

bool Arquero::getDisparoRapidoActive() {
    return DisparoRapidoActive;
}

bool Arquero::getOjodeHalconActive() {
    return OjodeHalconActive;
}

bool Arquero::getRafagadeFlechasActive() {
    return RafagadeFlechasActive;
}

int Arquero::getLongInventario() {
    return inventario.size();
}

Item Arquero::getItem(int i) {
    return inventario[i];

}

vector<Item> Arquero::getINVENTARIO() {
    return inventario;
}


void Arquero::levelUp()
{
    // Vector con los límites de experiencia para cada nivel
    vector<int> experienciaNiveles =
    { 7, 23, 47, 110, 220, 450, 800, 1300, 2000, 2900, 4000, 5500, 7500, 10000, 13000, 17000, 21000, 25000, 29000, 33000, 37000, 41000, 45000, 49000, 53000, 57000, 61000, 65000, 70000 };

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
            cout << "¡Felicidades! Tu  nivel  es: " << nivel << endl;
            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
            cin.get(); // Espera a que el usuario presione ENTER
            break;
        }
    }
    cout << "Tu nivel:  " << nivel << "Tu experiencia:  " << experiencia << endl;
   

}

void Arquero::DineroGAnado(float gold)
{
    dinero = dinero + gold;
}

void Arquero::StatusActual()
{
    cout << "Nivel: " << nivel << endl;
    cout << "Estamina: " << estamina << endl;
    cout << "Mana: " << mana << endl;
}

void Arquero::ConsecuenciasMuerte()
{
    dinero = dinero / 2;
}

void Arquero::PostMortum(int ne, int nm) {

    estamina = ne;
    mana = nm;
}

bool Arquero::noSigueVivo()
{
    return estamina < 0;
}

void Arquero::IncrentoExp(int x)
{
    experiencia += x;
    cout << "Tu experiencia es equivalente a : " << experiencia;
}

void Arquero::estaminaPerdida(int eP)
{
    estamina = estamina - eP;
    
    if (estamina <= 0)
    {
        cout << "La batalla fue dificil. ¡Has muerto! Pierdes la mitad de tu dinero y con ello todo tu inventario a exepción de tu primer arma." << endl;
    }
}

int Arquero::Ataque(int enemigolvl, int extra)
{
    int dbase = 3;
    int dvar = rand() % 5 + 1;
    int danno = (dvar + dbase) * nivel;
    // int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return danno + extra;

}

int Arquero::DisparoRapido(int enemigolvl, int extra)
{
    int dbase = 4;
    int dvar = rand() % 9 + 1;
    int danno = (dvar + dbase) * nivel;
    //int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return (2 * danno) + extra;

}

int Arquero::OjodeHalcon(int enemigolvl)
{
    OjodeHalconTurns = 7;
    return 0;
}

int Arquero::RafagadeFlechas(int enemigolvl, int toten, int enh) {
    RafagadeFlechasTurns = 5;
    forh3 = rand() % 10 + 1 * toten;
    howlong = toten;
    return forh3;
}

int Arquero::Atacar(int enemigolvl, int toten, int enh)
{
    int extra = 0;
    bool hayH = false;
    bool hayP = false;
    cout << OjodeHalconTurns << endl;
    cout << RafagadeFlechasTurns << endl;

    cout << "Es tu turno de atacar !" << endl;
    cout << "Eliga como quiere atacar. Actualmente tiene : " << mana << endl;
    cout << "0. Ataque " << "\t" << "Uso de mana = 2 puntos" << endl;

    if (DisparoRapidoActive == true)
    {
        cout << "1. Disparo Rapido" << "\t" << "Uso de mana = 5 puntos" << endl;
    }

    if (OjodeHalconActive == true)
    {
        cout << "2. Ojo de Halcon" << "\t" << "Uso de mana = 10 puntos" << endl;
    }

    if (RafagadeFlechasActive == true)
    {
        cout << "3. Rafaga de Flechas" << "\t" << "Uso de mana = 20 puntos" << endl;
    }

    if (OjodeHalconTurns > 0)
    {
        extra = enemigolvl * 0.5;
        cout << extra;
        --OjodeHalconTurns;
    }
    else {
        extra = 0;
    }
    if (howlong > toten) {
        RafagadeFlechas(enemigolvl, toten, enh);
    }
    if (RafagadeFlechasTurns > 0)
    { 
        --RafagadeFlechasTurns;
    }
    else {
        forh3 = 0;
        
    }
    for (int j = 0; j < inventario.size(); j++)
    {
        if ("Hierbas Medicinales" == inventario[j].getName() && inventario[j].getCantidad() > 0)
        {
            hayH = true;
            cout << "4. Hierbas Medicinales" << "\t" << "Uso de una implica perder la oportunidad de atacar" << endl;
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
    if (mana > 0) {
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
            if (mana > 4 && DisparoRapidoActive == true)
            {
                mana = mana - 5;
                moduloAtaque = DisparoRapido(enemigolvl, extra); //LLAMAR HABILIDAD

            }
            break;
        case 2:
            if (mana > 9 && OjodeHalconActive == true)
            {
                mana = mana - 10;
                cout << "Has activado Ojo de Halcon" << endl;
                OjodeHalcon(enemigolvl);//LLAMAR HABILIDAD //Genera el extra
            }
            break;
        case 3:
            if (mana > 19 && RafagadeFlechasActive == true)
            {
                mana = mana - 20;
                cout << "Has activado Rafaga de Flechas" << endl;
                moduloAtaque = RafagadeFlechas(enemigolvl, toten, enh);
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

    return moduloAtaque + forh3;

}
