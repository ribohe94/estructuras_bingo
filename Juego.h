/* 
 * File:   Juego.h
 * Author: bove
 *
 * Created on September 24, 2015, 8:12 PM
 */

#ifndef JUEGO_H
#define	JUEGO_H

#include "Lista.h"
//class Lista;

class Juego {
public:
    Juego(int cantidadCartones);
    Juego(const Juego& orig);
    Juego();
    virtual ~Juego();
    //Sets & Gets
    Lista** GetCartones() const;
    void SetCartones(Lista** cartones);
    int GetCantidad() const;
    void SetCantidad(int cantidad);
    std::vector<int> GetPila() const;
    void SetPila(std::vector<int> pila);
    // Metodos
    void mostrarCartones();
    int obtenerProximoNumero();
private:
    int cantidad;
    Lista** cartones;
    std::vector<int>pila;
    std::vector<int>::iterator it;
};
#endif	/* JUEGO_H */

