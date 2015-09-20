/* 
 * File:   Jugador.cpp
 * Author: Estudiante
 * 
 * Created on 19 de septiembre de 2015, 14:12
 */

#include "Jugador.h"

Jugador::Jugador(int n) {
    fichas = 2000;
    cantidad = n;
    cartones = new Lista*[n];
    for (int i = 0; i < n; i++) {
        cartones[i] = new Lista();
    }
}

Jugador::Jugador(const Jugador& orig) {
}

Jugador::~Jugador() {
}

//Sets & Gets

Lista** Jugador::GetCartones() const {
    return cartones;
}

void Jugador::SetCartones(Lista** cartones) {
    this->cartones = cartones;
}

int Jugador::GetFichas() const {
    return fichas;
}

void Jugador::SetFichas(int fichas) {
    this->fichas = fichas;
}

//Metodos

void Jugador::mostrarCartones() {
    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cartones[i]->mostrarLista();
        cout << endl;
    }
}
