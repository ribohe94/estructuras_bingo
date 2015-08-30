/* 
 * File:   Nodo.cpp
 * Author: Riccardo
 * 
 * Created on 29 August 2015, 23:31
 */

#include "Nodo.h"

Nodo::Nodo() {
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::Nodo(int valor) {
    this->valor = valor;
}

Nodo::~Nodo() {
}

//Sets & Gets

Nodo Nodo::GetAbajo() const {
    return abajo;
}

void Nodo::SetAbajo(Nodo abajo) {
    this->abajo = abajo;
}

Nodo Nodo::GetArriba() const {
    return arriba;
}

void Nodo::SetArriba(Nodo arriba) {
    this->arriba = arriba;
}

Nodo Nodo::GetDerecha() const {
    return derecha;
}

void Nodo::SetDerecha(Nodo derecha) {
    this->derecha = derecha;
}

Nodo Nodo::GetIzquierda() const {
    return izquierda;
}

void Nodo::SetIzquierda(Nodo izquierda) {
    this->izquierda = izquierda;
}

Nodo Nodo::GetNe() const {
    return ne;
}

void Nodo::SetNe(Nodo ne) {
    this->ne = ne;
}

Nodo Nodo::GetNo() const {
    return no;
}

void Nodo::SetNo(Nodo no) {
    this->no = no;
}

int Nodo::GetPosicionX() const {
    return posicionX;
}

void Nodo::SetPosicionX(int posicionX) {
    this->posicionX = posicionX;
}

int Nodo::GetPosicionY() const {
    return posicionY;
}

void Nodo::SetPosicionY(int posicionY) {
    this->posicionY = posicionY;
}

Nodo Nodo::GetSe() const {
    return se;
}

void Nodo::SetSe(Nodo se) {
    this->se = se;
}

Nodo Nodo::GetSo() const {
    return so;
}

void Nodo::SetSo(Nodo so) {
    this->so = so;
}

int Nodo::GetValor() const {
    return valor;
}

void Nodo::SetValor(int valor) {
    this->valor = valor;
}