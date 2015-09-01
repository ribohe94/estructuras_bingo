/* 
 * File:   Lista.cpp
 * Author: Riccardo
 * 
 * Created on 29 August 2015, 23:31
 */

#include "Lista.h"

Lista::Lista() {

}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::agregarNumero(Nodo* nuevo) {

    if (estaVacio()) {
        primero = ultimo = nuevo;
    } else {
        if (primero->GetDerecha() == NULL) {
            primero->SetDerecha(nuevo);
            ultimo = nuevo;
        } else {
            ultimo->SetDerecha(nuevo);
            ultimo = nuevo;
        }
    }
}

void Lista::generarBingo() {
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        for (int j = 0; j < Lista::TAMANO_BINGO; j++) {
            agregarNumero(new Nodo(j, i, 1 + (rand() % 15)));
        }
    }

    Nodo* aux = primero;
    while (aux) {
        aux->SetArriba(obtenerPosicion(aux->GetPosicionX(), aux->GetPosicionY() - 1));
        aux->SetNe(obtenerPosicion(aux->GetPosicionX() + 1, aux->GetPosicionY() - 1));
//        aux->SetDerecha(obtenerPosicion(aux->GetPosicionX() + 1, aux->GetPosicionY()));
        aux->SetSe(obtenerPosicion(aux->GetPosicionX() + 1, aux->GetPosicionY() + 1));
        aux->SetAbajo(obtenerPosicion(aux->GetPosicionX(), aux->GetPosicionY() + 1));
        aux->SetSo(obtenerPosicion(aux->GetPosicionX() - 1, aux->GetPosicionY() + 1));
        aux->SetIzquierda(obtenerPosicion(aux->GetPosicionX() - 1, aux->GetPosicionY()));
        aux->SetNo(obtenerPosicion(aux->GetPosicionX() - 1, aux->GetPosicionY() - 1));
        aux=aux->GetDerecha();
    }
}

bool Lista::estaVacio() {
    return primero == NULL;
}

void Lista::mostrarLista() {
    if (estaVacio()) {

    } else {
        Nodo* aux = primero;
        cout << "BINGO" << endl;
        int i = 0;
        while (aux) {
            if (i % 5 == 0) {
                cout << endl;
            }
            cout << " - " << aux->GetPosicionX() << ", " << aux->GetPosicionY() << " - ";
            //            cout << aux->GetValor() << "  ";
            aux = aux->GetDerecha();
            i++;
        }
    }
}

Nodo* Lista::obtenerPosicion(int x, int y) {
    Nodo* aux = primero;
    while (aux) {
        if (aux->GetPosicionX() == x && aux->GetPosicionY() == y) {
            return aux;
        }
        aux = aux->GetDerecha();
    }
    return NULL;
}
