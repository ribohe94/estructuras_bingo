/* 
 * File:   Lista.h
 * Author: Riccardo
 *
 * Created on 29 August 2015, 23:31
 */

#ifndef LISTA_H
#define	LISTA_H

#include "Nodo.h"

template <class T>
class Lista {
public:
    
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    //Metodos
    
    bool estaVacio();
    void mostrarLista();
    void generarBingo();
    void agregarNumero(Nodo<T>* nuevoNodo);
    Nodo<T>* obtenerPosicion(int, int);
    int fichasVerticalesX();
    int fichasHorizontalesX();
    int fichasDiagonalX();
    int fichas2DaDiagonalX();
    int fichasFormaC();
    int fichasFormaX();
    int fichasFormaU();
    int fichasFormaO();
    int BingoCompleto();
    
    //Atributos
    static const int TAMANO_BINGO = 5;
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
};

template class Lista<int>;
#endif	/* LISTA_H */
//Prueba

