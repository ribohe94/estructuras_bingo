/* 
 * File:   ContenedorJugadores.h
 * Author: Riccardo
 *
 * Created on 22 September 2015, 19:58
 */

#ifndef CONTENEDORJUGADORES_H
#define	CONTENEDORJUGADORES_H

#include "NodoJugador.h"


class ContenedorJugadores {
public:
    ContenedorJugadores();
    ContenedorJugadores(const ContenedorJugadores& orig);
    virtual ~ContenedorJugadores();
    
    //Metodos
    
    bool estaVacio();
    void mostrarLista();
    void agregarJugador(NodoJugador* nuevoJugador);
    NodoJugador* ValidarJugador(string nick, string contrasena);

private:
    NodoJugador* primero;
    NodoJugador* ultimo;
};

#endif	/* CONTENEDORJUGADORES_H */

