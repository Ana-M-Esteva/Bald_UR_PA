#include"Mago.h"

Mago::Mago(string n, Genero g, Raza r, Orientacion o, ClaseB CB, int lv, float gold, int pH, int e, int m, int i, int f, int a, vector<Item> inv, int xP, bool BFctive, bool RHctive, bool RFA)
    : Personaje(n, g, r, o, CB, lv, gold, pH, e, m, i, f, a, inv, xP) {
    BoladeFuegoActive = BFctive; // Indica si la Ataque Potente la puede usar el usuario
    RayodeHieloActive = RHctive; // Indica si la Defensa de Hierro la puede usar el usuario
    FuegoRadianteActive = RFA; // Indica si el Grito de Guerra la puede usar el usuario

    RayodeHieloTurns = 0; // Número de turnos restantes 
    FuegoRadianteTurns = 0; // Número de turnos restantes 
    EnUsoRayodeHielo = false;
    EnUsoFuegoRadiante = false;

    All2 = false;
}

Mago::~Mago() {

}

void Mago::mostrarInformacion() {
    cout << "**Mago**" << endl << endl;
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

int Forh3 = 0;
int Howlong = 0;
Item TunicaMistica("Túnica Mística", Armadura, 1, 500, 1, 2, 1);
Item AnillodelHechicero("Anillo del Hechicero", Amuleto, 1, 600, 0, 1, 1);
Item SombreroEncantado("Sombrero Encantado", Casco, 2, 550, 1, 2, 1);
Item BotasHechizadas("Botas Hechizadas", Botas, 1, 450, 0, 1, 1);
Item CapadelSabio("Capa del Sabio", Armadura, 2, 800, 1, 1, 1);
Item AmuletoMagico("Amuleto Mágico", Amuleto, 2, 750, 2, 1, 1);
Item BastonArcano("Bastón Arcano", Arma, 3, 650, 0, 2, 1);
Item Tiara("Tiara del Maestro", Casco, 2, 900, 1, 1, 1);
Item hierbasmedicinales("Hierbas Medicinales", Pocion, 0, 25, 1, 10, 50); //Falta modificar
Item elixirdelashadas("Elixir de las Hadas", Pocion, 1, 35, 0, 10, 50); //Falta modificar
//
//vector<Item> allItems{ TunicaMistica, AmuletoMagico, SombreroEncantado, BotasHechizadas, CapadelSabio, AmuletoMagico, BastonArcano,Tiara };
//cout << "_-- Tienda Mágica --_ " << endl;
//cout << "Actualmente usted tiene: " << dinero << "G" << endl;
//
//for (int i = 0; i < allItems.size(); i++) {
//    allItems[i].ImprimirItem();
//}
//cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
//cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
//cin.get(); // Espera a que el usuario presione ENTER

void Mago::tiendaEquipo()
{
    setlocale(LC_ALL, "");


    //Comparar con el inventario del jugado para que si tiene dicho objeto salga reducido el número
    vector<Item> allItems{ TunicaMistica, AnillodelHechicero, SombreroEncantado, BotasHechizadas, CapadelSabio, AmuletoMagico, BastonArcano,Tiara, hierbasmedicinales, elixirdelashadas };
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
        cout << "_-- Tienda de Magos --_ " << endl << endl;
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

void Mago::comprarItem(Item& item) {
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

void Mago::tiendaHabilidad()
{
    cout << "Bienvenido sea. Gaste sus puntos y active sus poderes" << endl;
    cout << "Actualmente usted tiene: " << puntosHabilidad << "pH" << endl;
    cout << "Las habilidades siguientes son aquellas que tiene o podra obtener:" << endl;
    cout << "0. Ataque " << "\t" << "Activa" << endl;
    cout << "1. Bola de Fuego" << "\t";
    if (BoladeFuegoActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 5 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "2. Rayo de Hielo" << "\t";
    if (RayodeHieloActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 15 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "3. Fuego Radiante" << "\t";
    if (FuegoRadianteActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 24 pH" << endl;
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
                if (puntosHabilidad >= 5 && BoladeFuegoActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 5;
                    BoladeFuegoActive = true;
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
                cout << "Para activar esta habilidad requiere 15 pH" << endl;
                if (puntosHabilidad >= 15 && RayodeHieloActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 15;
                    RayodeHieloActive = true;
                    cout << "Habilidad ACTIVADA !!!  ";
                }
                else if (puntosHabilidad < 15) {
                    cout << "Insuficiente cantidad de puntos";
                }
                else {
                    cout << "Esta habilidadad ya esta activa";
                }
                break;
            case 3:
                cout << "Para activar esta habilidad requiere 24 pH" << endl;
                if (puntosHabilidad >= 24 && FuegoRadianteActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 24;
                    FuegoRadianteActive = true;
                    cout << "Habilidad ACTIVADA  !!!  ";
                }
                else if (puntosHabilidad < 24) {
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


string Mago::getName() {
    return nombre;
}

Genero Mago::getGenero() {
    return genero;
}

Raza Mago::getRaza() {
    return raza;
}

Orientacion Mago::getOr() {
    return orientacion;
}

int Mago::getLVL()
{
    return nivel;
}

float Mago::getGOLD() {
    return dinero;
}

int Mago::getpH() {
    return puntosHabilidad;
}

int Mago::getEST() {
    return estamina;
}

int Mago::getMANA() {
    return mana;
}

int Mago::getINTELECTO() {
    return intelecto;
}

int Mago::getFUERZA() {
    return fuerza;
}

int Mago::getAGILIDAD() {
    return agilidad;
}

int Mago::getEXP() {
    return experiencia;
}

bool Mago::getBoladeFuegoActive() {
    return BoladeFuegoActive;
}

bool Mago::getRayodeHieloActive() {
    return RayodeHieloActive;
}

bool Mago::getFuegoRadianteActive() {
    return FuegoRadianteActive;
}

int Mago::getLongInventario() {
    return inventario.size();
}

Item Mago::getItem(int i) {
    return inventario[i];

}

vector<Item> Mago::getINVENTARIO() {
    return inventario;
}



void Mago::levelUp()
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
            cout << "¡Felicidades! Tu nivel es: " << nivel << endl;
            cout << "Pressiona ENTER para continuar..." << endl; // Imprime un mensaje de opción no válida
            cin.ignore(); // Ignora el salto de línea pendiente en el búfer de entrada
            cin.get(); // Espera a que el usuario presione ENTER
            break;
        }
    }

    cout << "Tu nivel:  " << nivel << "Tu experiencia:  " << experiencia << endl;
    

}

void Mago::DineroGAnado(float gold)
{
    dinero = dinero + gold;
}

void Mago::StatusActual()
{
    cout << "Nivel: " << nivel << endl;
    cout << "Estamina: " << estamina << endl;
    cout << "Mana: " << mana << endl;
}

void Mago::ConsecuenciasMuerte()
{
    dinero = dinero / 2;
}

void Mago::PostMortum(int ne, int nm) {

    estamina = ne;
    mana = nm;
}

bool Mago::noSigueVivo()
{
    return estamina < 0;
}

void Mago::IncrentoExp(int x)
{
    experiencia += x;
    cout << "Tu experiencia es equivalente a : " << experiencia;
}

void Mago::estaminaPerdida(int eP)
{
    if (All2 == false) {
        estamina = estamina - eP;
    }
    else {
        cout << "Habilidad encendida, la reducción a tu estamina es 0. El enemigo esta congelado. Imagino atacrte." << endl;
        estamina = estamina - 0;
    }
    if (estamina <= 0)
    {
        cout << "La batalla fue dificil. ¡Has muerto! Pierdes la mitad de tu dinero y con ello todo tu inventario a exepción de tu primer arma." << endl;
    }
}

int Mago::Ataque(int enemigolvl, int extra)
{
    int dbase = 3;
    int dvar = rand() % 5 + 1;
    int danno = (dvar + dbase) * nivel;
    // int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return danno + extra;

}

int Mago::BoladeFuego(int enemigolvl, int extra)
{
    int dbase = 4;
    int dvar = rand() % 9 + 1;
    int danno = (dvar + dbase) * nivel;
    //int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return (2 * danno) + extra;

}

void Mago::RayodeHielo(int enemigolvl)
{
    RayodeHieloTurns = 2;
    All2 = true;

}

int Mago::FuegoRadiante(int enemigolvl, int toten, int enh) {
    FuegoRadianteTurns = 7;
    Forh3 = rand() % 12 + 1 * toten;
    Howlong = toten;
    return Forh3;
}

int Mago::Atacar(int enemigolvl, int toten, int enh)
{
    int extra = 0;
    bool hayH = false;
    bool hayP = false;
    cout << FuegoRadianteTurns << endl;
    cout << RayodeHieloTurns << endl;

    cout << "Es tu turno de atacar !" << endl;
    cout << "Eliga como quiere atacar. Actualmente tiene : " << mana << endl;
    cout << "0. Ataque " << "\t" << "Uso de mana = 2 puntos" << endl;

    if (BoladeFuegoActive == true)
    {
        cout << "1. Bola de Fuego" << "\t" << "Uso de mana = 5 puntos" << endl;
    }
    if (RayodeHieloActive == true)
    {
        cout << "2. Rayo de Hielo" << "\t" << "Uso de mana = 10 puntos" << endl;
    }
    if (FuegoRadianteTurns == true)
    {
        cout << "3. Fuego Radiante" << "\t" << "Uso de mana = 20 puntos" << endl;
    }
    if (RayodeHieloTurns > 0)
    {
        
        --RayodeHieloTurns;
    }
    else {
        extra = 0;
    }
    if (Howlong > toten) {
        FuegoRadiante(enemigolvl, toten, enh);
    }
    if (FuegoRadianteTurns > 0)
    {
        --FuegoRadianteTurns;
    }
    else {
        Forh3 = 0;

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
            if (mana > 4 && BoladeFuegoActive == true)
            {
                mana = mana - 5;
                moduloAtaque = BoladeFuego(enemigolvl, extra); //LLAMAR HABILIDAD

            }
            break;
        case 2:
            if (mana > 9 && RayodeHieloActive == true)
            {
                mana = mana - 10;
                cout << "Has activado Rayo de Hielo" << endl;
                RayodeHielo(enemigolvl);//LLAMAR HABILIDAD //Genera el extra
            }
            break;
        case 3:
            if (mana > 19 && FuegoRadianteActive == true)
            {
                mana = mana - 20;
                cout << "Has activado Fuego Radiante" << endl;
                moduloAtaque = FuegoRadiante(enemigolvl, toten, enh);
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

    return moduloAtaque + Forh3;

}