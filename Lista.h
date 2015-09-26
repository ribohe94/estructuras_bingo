/* 
 * File:   Lista.h
 * Author: Riccardo
 *
 * Created on 29 August 2015, 23:31
 */
#ifndef LISTA_H
#define	LISTA_H

#include "Nodo.h"

class Lista {
public:
    
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    //Metodos
    
    bool estaVacio();
    void mostrarLista();
    void generarBingo();
    void agregarNumero(Nodo* nuevoNodo);
    Nodo* obtenerPosicion(int, int);
    int fichasVerticalesX();
    int fichasHorizontalesX();
    int fichasDiagonalX();
    int fichas2DaDiagonalX();
    int fichasFormaC();
    int fichasFormaX();
    int fichasFormaU();
    int fichasFormaO();
    int BingoCompleto();
    void PonerX(int x, int y);
    
    //Atributos
    static const int TAMANO_BINGO = 5;
private:
    Nodo* primero;
    Nodo* ultimo;
};

#endif	/* LISTA_H */

