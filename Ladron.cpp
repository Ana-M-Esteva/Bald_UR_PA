#include "Ladron.h"

Ladron::Ladron(string n, Genero g, Raza r, Orientacion o, ClaseB CB, int lv, float gold, int pH, int e, int m, int i, int f, int a, vector<Item> inv, int xP, bool BFctive, bool RHctive, bool RFA)
    : Personaje(n, g, r, o, CB, lv, gold, pH, e, m, i, f, a, inv, xP) {
    GolpeSigilosoActive = BFctive; // Indica si la Ataque Potente la puede usar el usuario
    ConcentracionActive = RHctive; // Indica si la Defensa de Hierro la puede usar el usuario
    PunnaladaLetalActive = RFA; // Indica si el Grito de Guerra la puede usar el usuario

    ConcentracionTurns = 0; // Número de turnos restantes 
    PunnaladaLetalTurns = 0; // Número de turnos restantes 
    Uncuarto = false;


}

Ladron::~Ladron() {

}

void Ladron::mostrarInformacion() {
    cout << "**Ladron**" << endl << endl;
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

Item DagasGemelas("Dagas Gemelas", Arma, 1, 500, 0, 1, 1);
Item CapaSombria("Capa Sombría", Casco, 2, 600, 1, 2, 1);
Item GanchodeEscalada("Gancho de Escalada", Amuleto, 1, 550, 2, 1, 1);
Item BotasdeLadron("Botas de Ladrón", Botas,1, 450, 0, 1, 1);
Item BotasdelJEfe("Botas del Jefe", Botas,2, 750, 2, 1, 1);
Item TunicadeSigilo("Tunica de Sigilo", Armadura, 3, 800, 0, 2, 1);
Item Cimitarra("Cimitarra", Arma, 2, 650, 3, 1, 1);
Item MascaradelBandido("Máscara de Bandido", Casco,1, 550, 1, 1, 1);
Item hierbasmedicinaleS("Hierbas Medicinales", Pocion, 0, 25, 1, 10, 50); //Falta modificar
Item elixirdelashadaS("Elixir de las Hadas", Pocion, 1, 35, 0, 10, 50); //Falta modificar

void Ladron::tiendaEquipo()
{
    setlocale(LC_ALL, "");


    //Comparar con el inventario del jugado para que si tiene dicho objeto salga reducido el número
    vector<Item> allItems{ DagasGemelas, CapaSombria, GanchodeEscalada, BotasdeLadron, BotasdelJEfe, TunicadeSigilo, Cimitarra,MascaradelBandido, hierbasmedicinaleS, elixirdelashadaS };
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
        cout << "_-- Tienda de Ladron --_ " << endl << endl;
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

void Ladron::comprarItem(Item& item) {
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

void Ladron::tiendaHabilidad()
{
    cout << "Bienvenido sea. Gaste sus puntos y active sus poderes" << endl;
    cout << "Actualmente usted tiene: " << puntosHabilidad << "pH" << endl;
    cout << "Las habilidades siguientes son aquellas que tiene o podra obtener:" << endl;
    cout << "0. Ataque " << "\t" << "Activa" << endl;
    cout << "1. Bola de Fuego" << "\t";
    if (GolpeSigilosoActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 5 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "2. Rayo de Hielo" << "\t";
    if (ConcentracionActive == false)
    {
        cout << "Inactiva" << "\t" << "Costo: 14 pH" << endl;
    }
    else {
        cout << "Activa" << endl;;
    }
    cout << "3. Fuego Radiante" << "\t";
    if (PunnaladaLetalActive == false)
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
                if (puntosHabilidad >= 5 && GolpeSigilosoActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 5;
                    GolpeSigilosoActive = true;
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
                cout << "Para activar esta habilidad requiere 14 pH" << endl;
                if (puntosHabilidad >= 14 && ConcentracionActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 14;
                    ConcentracionActive = true;
                    cout << "Habilidad ACTIVADA !!!  ";
                }
                else if (puntosHabilidad < 14) {
                    cout << "Insuficiente cantidad de puntos";
                }
                else {
                    cout << "Esta habilidadad ya esta activa";
                }
                break;
            case 3:
                cout << "Para activar esta habilidad requiere 24 pH" << endl;
                if (puntosHabilidad >= 25 && PunnaladaLetalActive == false)
                {
                    puntosHabilidad = puntosHabilidad - 25;
                    PunnaladaLetalActive = true;
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


string Ladron::getName() {
    return nombre;
}

Genero Ladron::getGenero() {
    return genero;
}

Raza Ladron::getRaza() {
    return raza;
}

Orientacion Ladron::getOr() {
    return orientacion;
}

int Ladron::getLVL()
{
    return nivel;
}

float Ladron::getGOLD() {
    return dinero;
}

int Ladron::getpH() {
    return puntosHabilidad;
}

int Ladron::getEST() {
    return estamina;
}

int Ladron::getMANA() {
    return mana;
}

int Ladron::getINTELECTO() {
    return intelecto;
}

int Ladron::getFUERZA() {
    return fuerza;
}

int Ladron::getAGILIDAD() {
    return agilidad;
}

int Ladron::getEXP() {
    return experiencia;
}

bool Ladron::getGolpeSigilosoActive() {
    return GolpeSigilosoActive;
}

bool Ladron::getConcentracionActive() {
    return ConcentracionActive;
}

bool Ladron::getPunnaladaLetalActive() {
    return PunnaladaLetalActive;
}

int Ladron::getLongInventario() {
    return inventario.size();
}

Item Ladron::getItem(int i) {
    return inventario[i];

}

vector<Item> Ladron::getINVENTARIO() {
    return inventario;
}

void Ladron::levelUp()
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

    cout << "Tu nivel:  " << nivel << " Tu experiencia:  " << experiencia << endl;
    

}

void Ladron::DineroGAnado(float gold)
{
    dinero = dinero + gold;
}

void Ladron::StatusActual()
{
    cout << "Nivel: " << nivel << endl;
    cout << "Estamina: " << estamina << endl;
    cout << "Mana: " << mana << endl;
}

void Ladron::ConsecuenciasMuerte()
{
    dinero = dinero / 2;
}

void Ladron::PostMortum(int ne, int nm) {

    estamina = ne;
    mana = nm;
}

bool Ladron::noSigueVivo()
{
    return estamina < 0;
}

void Ladron::IncrentoExp(int x)
{
    experiencia += x;
    cout << "Tu experiencia es equivalente a : " << experiencia;
}

void Ladron::estaminaPerdida(int eP)
{
    
    if (Uncuarto == false) {
        estamina = estamina - eP;
    }
    else {
        cout << "Habilidad encendida, la reducción a tu estamina es menor" << endl;
        estamina = estamina - (eP / 4);
    }
    
    if (estamina <= 0)
    {
        cout << "La batalla fue dificil. ¡Has muerto! Pierdes la mitad de tu dinero y con ello todo tu inventario a exepción de tu primer arma." << endl;
    }
}

int Ladron::Ataque(int enemigolvl, int extra)
{
    int dbase = 3;
    int dvar = rand() % 5 + 1;
    int danno = (dvar + dbase) * nivel;
    // int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return danno + extra;

}

int Ladron::GolpeSigiloso(int enemigolvl, int extra)
{
    int dbase = 4;
    int dvar = rand() % 9 + 1;
    int danno = (dvar + dbase) * nivel;
    //int danno = rand() % enemigolvl + 3;
    cout << "Daño infligido de : " << danno + extra << endl;
    return (2 * danno) + extra;

}

void Ladron::Concentracion(int enemigolvl) {
    ConcentracionTurns = 5;
}

int Ladron::PunnaladaLetal(int enemigolvl, int toten, int enh) {
    PunnaladaLetalTurns = rand() % 3 + 1;
    int dannno = 0;
    if (PunnaladaLetalTurns == 2)
    {
        dannno = enh;
    }
    else {
        dannno = enh / 2;
    }
    return dannno;
}

int Ladron::Atacar(int enemigolvl, int toten, int enh)
{
    int extra = 0;
    bool hayH = false;
    bool hayP = false;
    cout << ConcentracionTurns << endl;


    cout << "Es tu turno de atacar !" << endl;
    cout << "Eliga como quiere atacar. Actualmente tiene : " << mana << endl;
    cout << "0. Ataque " << "\t" << "Uso de mana = 2 puntos" << endl;

    if (GolpeSigilosoActive == true)
    {
        cout << "1. Golpe Sigiloso" << "\t" << "Uso de mana = 5 puntos" << endl;
    }
    if (ConcentracionActive == true)
    {
        cout << "2. Concentracion" << "\t" << "Uso de mana = 10 puntos" << endl;
    }
    if (PunnaladaLetalActive == true)
    {
        cout << "3. Punnalada Letal" << "\t" << "Uso de mana = 20 puntos" << endl;
    }
    if (ConcentracionTurns > 0)
    {
        Uncuarto = true;
        extra = enemigolvl * 0.5;
        cout << extra;
        --ConcentracionTurns;
    }
    else {
        extra = 0;
        Uncuarto = false;
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
            if (mana > 4 && GolpeSigilosoActive == true)
            {
                mana = mana - 5;
                moduloAtaque = GolpeSigiloso(enemigolvl, extra); //LLAMAR HABILIDAD

            }
            break;
        case 2:
            if (mana > 9 && ConcentracionActive == true)
            {
                mana = mana - 10;
                cout << "Has activado Rayo de Hielo" << endl;
                Concentracion(enemigolvl);//LLAMAR HABILIDAD //Genera el extra
            }
            break;
        case 3:
            if (mana > 19 && PunnaladaLetalActive == true)
            {
                mana = mana - 20;
                cout << "Has activado Fuego Radiante" << endl;
                moduloAtaque = PunnaladaLetal(enemigolvl, toten, enh);
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

    return moduloAtaque + extra;

}

