/* 
 * File:   ContenedorJugadores.cpp
 * Author: Riccardo
 * 
 * Created on 22 September 2015, 19:58
 */

#include "ContenedorJugadores.h"

ContenedorJugadores::ContenedorJugadores() {
    primero = ultimo = NULL;
}

ContenedorJugadores::ContenedorJugadores(const ContenedorJugadores& orig) {

}

ContenedorJugadores::~ContenedorJugadores() {

}

NodoJugador* ContenedorJugadores::ValidarJugador(string nick, string contrasena) {
    if (estaVacio()) {
        cout << "No hay jugadores" << endl;
    } else {
        NodoJugador* aux = primero;
        while (aux) {
            if (aux->GetDato()->GetNick() == nick && aux->GetDato()->GetPass() == contrasena) {
                return aux;
            }
            aux = aux->GetSiguiente();
        }
        return NULL;
    }
}

void ContenedorJugadores::agregarJugador(NodoJugador* nuevoJugador) {
    if (estaVacio()) {
        primero = ultimo = nuevoJugador;
    } else {
        if (primero->GetSiguiente() == NULL) {
            primero->SetSiguiente(nuevoJugador);
            ultimo = nuevoJugador;
        } else {
            ultimo->SetSiguiente(nuevoJugador);
            ultimo = nuevoJugador;
        }
    }
}

bool ContenedorJugadores::estaVacio() {
    return primero == NULL;
}

void ContenedorJugadores::mostrarLista() {
    if (estaVacio()) {
        cout << "No hay jugadores" << endl;
    } else {
        NodoJugador* aux = primero;
        while (aux) {
            cout << aux->GetDato()->toString();
            aux = aux->GetSiguiente();
        }
    }
}
