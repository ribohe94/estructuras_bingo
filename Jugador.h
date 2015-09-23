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
    //Sets & Gets
    Lista** GetCartones() const;
    void SetCartones(Lista** cartones);
    int GetFichas() const;
    void SetFichas(int fichas);
    // Metodos
    void mostrarCartones();
private:
    int fichas;
    int cantidad;
    string nombre;
    string nick;
    int edad;
    Lista** cartones;
};

#endif	/* JUGADOR_H */

