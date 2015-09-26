/* 
 * File:   NodoJugador.h
 * Author: bove
 *
 * Created on September 25, 2015, 10:36 PM
 */

#ifndef NODOJUGADOR_H
#define	NODOJUGADOR_H
#include "Jugador.h"

class NodoJugador {
public:
    NodoJugador();
    NodoJugador(const NodoJugador& orig);
    NodoJugador(Jugador* dato);
    virtual ~NodoJugador();
    
    Jugador* GetDato() const;
    void SetDato(Jugador* dato);
    NodoJugador* GetSiguiente() const;
    void SetSiguiente(NodoJugador* siguiente);
private:
    Jugador* dato;
    NodoJugador* siguiente;
};

#endif	/* NODOJUGADOR_H */

