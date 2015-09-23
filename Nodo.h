/* 
 * File:   Nodo.h
 * Author: Riccardo
 *
 * Created on 29 August 2015, 23:31
 */
#ifndef NODO_H
#define	NODO_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <stdio.h>

using namespace std;


template <class T>
class Nodo {
public:
    Nodo();
//    Nodo(Nodo<T>* abajo, Nodo<T>* arriba, Nodo<T>* derecha, Nodo<T>* izquierda, Nodo<T>* ne, Nodo<T>* no, int posicionX, int posicionY, Nodo<T>* se, Nodo<T>* so, int valor);
    Nodo(const Nodo& orig);
    Nodo(int posicionX, int posicionY, int valor);
    Nodo(int posicionX, int posicionY);
    virtual ~Nodo();
    //Sets & Gets
    Nodo<T>* GetAbajo() const;
    void SetAbajo(Nodo<T>* abajo);
    Nodo<T>* GetArriba() const;
    void SetArriba(Nodo<T>* arriba);
    Nodo<T>* GetDerecha() const;
    void SetDerecha(Nodo<T>* derecha);
    Nodo<T>* GetIzquierda() const;
    void SetIzquierda(Nodo<T>* izquierda);
    Nodo<T>* GetNe() const;
    void SetNe(Nodo<T>* ne);
    Nodo<T>* GetNo() const;
    void SetNo(Nodo<T>* no);
    int GetPosicionX() const;
    void SetPosicionX(int posicionX);
    int GetPosicionY() const;
    void SetPosicionY(int posicionY);
    Nodo<T>* GetSe() const;
    void SetSe(Nodo<T>* se);
    Nodo<T>* GetSo() const;
    void SetSo(Nodo<T>* so);
    T GetValor() const;
    void SetValor(T valor);

private:

    T valor;
    int posicionX;
    int posicionY;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;
    Nodo<T>* arriba;
    Nodo<T>* abajo;
    Nodo<T>* no;
    Nodo<T>* ne;
    Nodo<T>* so;
    Nodo<T>* se;

};

template class Nodo<int>;

#endif	/* NODO_H */

