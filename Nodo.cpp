/* 
 * File:   Nodo.cpp
 * Author: Riccardo
 * 
 * Created on 29 August 2015, 23:31
 */

#include "Nodo.h"


template <class T>
Nodo<T>::Nodo() {
}

//template <class T>
//Nodo<T>::Nodo(Nodo<T>* abajo, Nodo<T>* arriba, Nodo<T>* derecha, Nodo<T>* izquierda, Nodo<T>* ne, Nodo<T>* no, int posicionX, int posicionY, Nodo<T>* se, Nodo<T>* so, int valor) :
//abajo(abajo), arriba(arriba), derecha(derecha), izquierda(izquierda), ne(ne), no(no), posicionX(posicionX), posicionY(posicionY), se(se), so(so), valor(valor) {
//}

template <class T>
Nodo<T>::Nodo(int posicionX, int posicionY, int valor) :
posicionX(posicionX), posicionY(posicionY), valor(valor) {
}

template <class T>
Nodo<T>::Nodo(const Nodo& orig) {
}

template <class T>
Nodo<T>::~Nodo() {
}

//Sets & Gets

template <class T>
Nodo<T>* Nodo<T>::GetAbajo() const {
    return abajo;
}

template <class T>
void Nodo<T>::SetAbajo(Nodo<T>* abajo) {
    this->abajo = abajo;
}

template <class T>
Nodo<T>* Nodo<T>::GetArriba() const {
    return arriba;
}

template <class T>
void Nodo<T>::SetArriba(Nodo<T>* arriba) {
    this->arriba = arriba;
}

template <class T>
Nodo<T>* Nodo<T>::GetDerecha() const {
    return derecha;
}

template <class T>
void Nodo<T>::SetDerecha(Nodo<T>* derecha) {
    this->derecha = derecha;
}

template <class T>
Nodo<T>* Nodo<T>::GetIzquierda() const {
    return izquierda;
}

template <class T>
void Nodo<T>::SetIzquierda(Nodo<T>* izquierda) {
    this->izquierda = izquierda;
}

template <class T>
Nodo<T>* Nodo<T>::GetNe() const {
    return ne;
}

template <class T>
void Nodo<T>::SetNe(Nodo<T>* ne) {
    this->ne = ne;
}

template <class T>
Nodo<T>* Nodo<T>::GetNo() const {
    return no;
}

template <class T>
void Nodo<T>::SetNo(Nodo<T>* no) {
    this->no = no;
}

template <class T>
int Nodo<T>::GetPosicionX() const {
    return posicionX;
}

template <class T>
void Nodo<T>::SetPosicionX(int posicionX) {
    this->posicionX = posicionX;
}

template <class T>
int Nodo<T>::GetPosicionY() const {
    return posicionY;
}

template <class T>
void Nodo<T>::SetPosicionY(int posicionY) {
    this->posicionY = posicionY;
}

template <class T>
Nodo<T>* Nodo<T>::GetSe() const {
    return se;
}

template <class T>
void Nodo<T>::SetSe(Nodo<T>* se) {
    this->se = se;
}

template <class T>
Nodo<T>* Nodo<T>::GetSo() const {
    return so;
}

template <class T>
void Nodo<T>::SetSo(Nodo<T>* so) {
    this->so = so;
}

template <class T>
T Nodo<T>::GetValor() const {
    return valor;
}

template <class T>
void Nodo<T>::SetValor(T valor) {
    this->valor = valor;
}