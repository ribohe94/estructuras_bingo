/* 
 * File:   Jugador.cpp
 * Author: Estudiante
 * 
 * Created on 19 de septiembre de 2015, 14:12
 */

#include "Jugador.h"

Jugador::Jugador(int n) {
    fichas = 2000;
    Lista** cartones = new Lista*[n];
    for (int i = 0; i < n; i++) {
        cartones[i] = new Lista();
    }
    
}

Jugador::Jugador(const Jugador& orig) {
}

Jugador::~Jugador() {
}

