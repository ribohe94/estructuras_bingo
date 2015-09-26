/* 
 * File:   GestorJuego.cpp
 * Author: Riccardo
 * 
 * Created on 22 September 2015, 19:58
 */

#include "GestorJuego.h"

GestorJuego::GestorJuego(Jugador* j, int n) {
    this->jugadores = new ContenedorJugadores();
    jugadorActivo = jugadores->ValidarJugador(j->GetNick(), j->GetPass())->GetDato();
    juegoActivo = new Juego(n);
    cantidad = n;
    it = juegoActivo->GetPila().begin();
    numeroActual = *it;
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "Bove", "Riccardo", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "ecc12", "Juan", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "JAX34", "Jack", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "MammaMia94", "Alejandro", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "UmpaLumpa123", "Willy", "123")));
}

GestorJuego::GestorJuego() {
    this->jugadores = new ContenedorJugadores();
    jugadorActivo = NULL;
    juegoActivo = NULL;
    cantidad = 0;
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "Bove", "Riccardo", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "ecc12", "Juan", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "JAX34", "Jack", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "MammaMia94", "Alejandro", "123")));
    jugadores->agregarJugador(new NodoJugador(new Jugador(20, 2000, "UmpaLumpa123", "Willy", "123")));
}

GestorJuego::GestorJuego(const GestorJuego& orig) {
}

GestorJuego::~GestorJuego() {
}

int GestorJuego::getCantidad() const {
    return cantidad;
}

void GestorJuego::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

Juego* GestorJuego::getJuegoActivo() const {
    return juegoActivo;
}

void GestorJuego::setJuegoActivo(Juego* juegoActivo) {
    this->juegoActivo = juegoActivo;
}

Jugador* GestorJuego::getJugadorActivo() const {
    return jugadorActivo;
}

void GestorJuego::setJugadorActivo(Jugador* jugadorActivo) {
    this->jugadorActivo = jugadorActivo;
}

ContenedorJugadores* GestorJuego::getJugadores() const {
    return jugadores;
}

void GestorJuego::setJugadores(ContenedorJugadores* jugadores) {
    this->jugadores = jugadores;
}

void GestorJuego::crearJuego(Jugador* j, int n) {
    jugadorActivo = jugadores->ValidarJugador(j->GetNick(), j->GetPass())->GetDato();
    juegoActivo = new Juego(n);
    cantidad = n;
    it = juegoActivo->GetPila().begin();
    numeroActual = *it;

}

void GestorJuego::iniciarJuegoBingo() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->BingoCompleto() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::iniciarJuegoC() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        ingresarValor();
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->fichasFormaC() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::iniciarJuegoDiagonal() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        ingresarValor();
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->fichasDiagonalX() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::iniciarJuegoHorizontal() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        ingresarValor();
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->fichasHorizontalesX() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::iniciarJuegoO() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        ingresarValor();
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->fichasFormaO() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::iniciarJuegoU() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        ingresarValor();
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->fichasFormaU() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::iniciarJuegoX() {
    bool flag = false;
    bool estadoCartones[cantidad];
    for (int i = 0; i < cantidad; i++) {
        estadoCartones[i] = false;
    }
    while (!flag) {
        obtenerProximoNumero();
        mostrarTablero();
        cout << "El numero actual es: " << numeroActual << endl;
        if (!ingresarValor()) {
            jugadorActivo->SetFichas(jugadorActivo->GetFichas() - 20);
        }
        ingresarValor();
        int n = 0;
        for (int i = 0; i < cantidad; i++) {
            if (juegoActivo->GetCartones()[i]->fichasFormaX() != 0) {
                n++;
                if (!estadoCartones[i]) {
                    estadoCartones[i] = true;
                    jugadorActivo->SetFichas(jugadorActivo->GetFichas() + juegoActivo->GetCartones()[i]->BingoCompleto());
                }
            }
            if (n == cantidad) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Felicidades! Ha ganado el bingo!" << endl;
    }
}

void GestorJuego::agregarJugador(Jugador* j) {
    jugadores->agregarJugador(new NodoJugador(j));
}

bool GestorJuego::validarEntrada(int x, int y, int z) {
    if (juegoActivo->GetCartones()[z]->obtenerPosicion(x, y)->GetValor() == numeroActual)
        return true;
    else
        return false;
}

void GestorJuego::mostrarTablero() {
    cout << jugadorActivo->toString();
    for (int i = 0; i < cantidad; i++) {
        juegoActivo->GetCartones()[i]->mostrarLista();
    }

}

bool GestorJuego::ingresarValor() {
    cout << "Ingrese el numero de carton o ingrese 9 para saltar de turno" << endl;
    int z = VALIDAR_INT();
    if (z == 9)
        return true;
    while (z < 0 || z >= cantidad)
        z = VALIDAR_INT();
    cout << "Ingrese el numero en el eje X" << endl;
    int x = VALIDAR_INT();
    cout << "Ingrese el numero en el eje Y" << endl;
    int y = VALIDAR_INT();

    if (validarEntrada(x, y, z))
        juegoActivo->GetCartones()[z]->PonerX(x, y);
    else
        return false;
}

int GestorJuego::obtenerProximoNumero() {
    numeroActual = juegoActivo->obtenerProximoNumero();
    return numeroActual;
}

int GestorJuego::VALIDAR_INT() {
    int input = -1;
    bool valid = false;
    do {
        cout << flush;
        cin >> input;
        if (cin.good()) {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        } else {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor invalido, por favor intente de nuevo." << endl;
        }
    } while (!valid);

    return (input);
}

string GestorJuego::VALIDAR_STRING() {
    std::string input;

    bool valid;

    do {
        cin >> input; // get a line of input
        valid = true; // assume it's valid
        for (int i = 0; i < input.length(); i++) // check each character in the input string
        {
            if (!std::isalpha(input[i])) // is it an alphabetical character?
            {
                valid = false; // if not, mark it as invalid
                // print an error to the user
                std::cout << "Valor invalido, por favor intente de nuevo." << std::endl;
                break; // break out of the for() loop, as we have already established the input is invalid
            }
        }
    } while (!valid); // keep going until we get input that's valid

    return input; // once we have valid input, return it
}

Jugador* GestorJuego::ENCONTRAR_JUGADOR() {

}

