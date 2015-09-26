/* 
 * File:   Juego.cpp
 * Author: bove
 * 
 * Created on September 24, 2015, 8:12 PM
 */

#include "Juego.h"

Juego::Juego(int n) {
    cantidad = n;
    cartones = new Lista*[n];
    for (int i = 0; i < n; i++) {
        cartones[i] = new Lista();
    }
    for (int i = 1; i < 76; i++) {
        pila.push_back(i);
    }
    std::random_shuffle(pila.begin(), pila.end());
    it = pila.begin();
}

Juego::Juego(const Juego& orig) {
}

Juego::Juego() {
}

Juego::~Juego() {
}

//Sets & Gets

Lista** Juego::GetCartones() const {
    return cartones;
}

void Juego::SetCartones(Lista** cartones) {
    this->cartones = cartones;
}

int Juego::GetCantidad() const {
    return cantidad;
}

void Juego::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

std::vector<int> Juego::GetPila() const {
    return pila;
}

void Juego::SetPila(std::vector<int> pila) {
    this->pila = pila;
}
//Metodos

void Juego::mostrarCartones() {
    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cartones[i]->mostrarLista();
        cout << endl;
    }
}

int Juego::obtenerProximoNumero() {
    int n = *it;
    it++;
    return n;
}
