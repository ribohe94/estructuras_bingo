/* 
 * File:   Interfaz.cpp
 * Author: Riccardo
 * 
 * Created on 22 September 2015, 19:58
 */

#include "Interfaz.h"

Interfaz::Interfaz() {
    gestor = new GestorJuego();
}

Interfaz::Interfaz(const Interfaz& orig) {
}

Interfaz::~Interfaz() {
}

void Interfaz::init() {
    cout << "BIENVENIDO A NUESTRO JUEGO DE BINGO" << endl;
    cout << "1) Ingresar un nuevo jugador" << endl;
    cout << "2) Iniciar sesion" << endl;
    cout << "3) Mostrar Jugadores" << endl;

    int val = GestorJuego::VALIDAR_INT();

    switch (val) {
        case 1:
            registroJugador();
            break;
        case 2:
            iniciarSesion();
            break;
        case 3:
            mostrarJugadores();
            break;
        default:
            init();
    }

}

void Interfaz::registroJugador() {
    cout << "INGRESE EL NUEVO JUGADOR" << endl;
    cout << "1) Ingrese el nombre del nuevo jugador" << endl;
    string nombre = GestorJuego::VALIDAR_STRING();
    cout << "2) Ingrese el nombre de usuario del nuevo jugador" << endl;
    string user = "";
    cin>>user;
    cout << "3) Ingrese la edad del nuevo jugador" << endl;
    int edad = GestorJuego::VALIDAR_INT();
    cout << "4) Ingrese la contrasena nuevo jugador" << endl;
    string aux;
    cin>>aux;
    gestor->getJugadores()->agregarJugador(new NodoJugador(new Jugador(edad, 2000, user, nombre, aux)));
    
    
    init();
}

void Interfaz::iniciarSesion() {
    cout << "1) Ingrese su nick" << endl;
    string nick;
    cin >> nick;
    cout << "2) Ingrese su contrasena" << endl;
    string pass = "";
    cin>>pass;
    cout << "3) Ingrese la cantidad de cartones que desea usar" << endl;
    int n = GestorJuego::VALIDAR_INT();
    if (gestor->getJugadores()->ValidarJugador(nick, pass) != NULL) {
        gestor->crearJuego(gestor->getJugadores()->ValidarJugador(nick, pass)->GetDato(), n);
        seleccioneJuego();
    } else {
        cout << "Informacion incorrecta" << endl;
        cout << "1) Reintentar" << endl;
        cout << "2) Regresar" << endl;
        int val = GestorJuego::VALIDAR_INT();
        switch (val) {
            case 1:
                iniciarSesion();
                break;
            case 2:
                init();
                break;
            default:
                init();
        }
    }

}

void Interfaz::seleccioneJuego() {
    cout << "BIENVENIDO A NUESTRO JUEGO DE BINGO" << endl;
    cout << "Seleccione el tipo de juego que desea jugar" << endl;
    cout << "1) Linea Horizontal" << endl;
    cout << "2) Linea Diagonal" << endl;
    cout << "3) Figura C" << endl;
    cout << "4) Figura X" << endl;
    cout << "5) Figura U" << endl;
    cout << "6) Figura O" << endl;
    cout << "7) BINGO TOTAL" << endl;
    cout << "8) Salir" << endl;

    int val = GestorJuego::VALIDAR_INT();

    switch (val) {
        case 1:
            iniciarJuegoBingo();
            break;
        case 2:
            iniciarJuegoDiagonal();
            break;
        case 3:
            iniciarJuegoC();
            break;
        case 4:
            iniciarJuegoX();
            break;
        case 5:
            iniciarJuegoU();
            break;
        case 6:
            iniciarJuegoO();
            break;
        case 7:
            iniciarJuegoBingo();
            break;
        case 8:
            init();
            break;
        default:
            init();
    }
}

void Interfaz::iniciarJuegoBingo() {
    gestor->iniciarJuegoBingo();
    init();
}

void Interfaz::iniciarJuegoC() {
    gestor->iniciarJuegoC();
    init();
}

void Interfaz::iniciarJuegoDiagonal() {
    gestor->iniciarJuegoDiagonal();
    init();
}

void Interfaz::iniciarJuegoHorizontal() {
    gestor->iniciarJuegoHorizontal();
    init();
}

void Interfaz::iniciarJuegoO() {
    gestor->iniciarJuegoO();
    init();
}

void Interfaz::iniciarJuegoU() {
    gestor->iniciarJuegoU();
    init();
}

void Interfaz::iniciarJuegoX() {
    gestor->iniciarJuegoX();
    init();
}

void Interfaz::mostrarJugadores() {
    gestor->getJugadores()->mostrarLista();
    init();
}
