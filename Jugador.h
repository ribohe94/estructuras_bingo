/* 
 * File:   Jugador.h
 * Author: Estudiante
 *
 * Created on 19 de septiembre de 2015, 14:12
 */

#ifndef JUGADOR_H
#define	JUGADOR_H
#include "Lista.h"

class Jugador {
public:
    Jugador(int cantidadCartones);
    Jugador(const Jugador& orig);
    virtual ~Jugador();
private:
    int fichas;
    
};

#endif	/* JUGADOR_H */

