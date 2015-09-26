/* 
 * File:   NodoJugador.cpp
 * Author: bove
 * 
 * Created on September 25, 2015, 10:36 PM
 */

#include "NodoJugador.h"

NodoJugador::NodoJugador() {
}

NodoJugador::NodoJugador(const NodoJugador& orig) {
}

NodoJugador::NodoJugador(Jugador* dato) :
dato(dato) {
}

NodoJugador::~NodoJugador() {
}

Jugador* NodoJugador::GetDato() const {
    return dato;
}

void NodoJugador::SetDato(Jugador* dato) {
    this->dato = dato;
}

NodoJugador* NodoJugador::GetSiguiente() const {
    return siguiente;
}

void NodoJugador::SetSiguiente(NodoJugador* siguiente) {
    this->siguiente = siguiente;
}