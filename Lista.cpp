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
        aux->SetSe(obtenerPosicion(aux->GetPosicionX() + 1, aux->GetPosicionY() + 1));
        aux->SetAbajo(obtenerPosicion(aux->GetPosicionX(), aux->GetPosicionY() + 1));
        aux->SetSo(obtenerPosicion(aux->GetPosicionX() - 1, aux->GetPosicionY() + 1));
        aux->SetIzquierda(obtenerPosicion(aux->GetPosicionX() - 1, aux->GetPosicionY()));
        aux->SetNo(obtenerPosicion(aux->GetPosicionX() - 1, aux->GetPosicionY() - 1));
        aux = aux->GetDerecha();
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

int Lista::fichasVerticalesX() {
    bool flag;
    int fichas = 0;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        flag = true;
        for (int j = 0; j < Lista::TAMANO_BINGO; j++) {
            if (obtenerPosicion(i, j)->GetValor() != "X") {
                flag = false;
            }
        }
        if (flag)
            fichas += 400;
    }
    return fichas;
}

int Lista::fichasHorizontalesX() {
    bool flag;
    int fichas = 0;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        flag = true;
        for (int j = 0; j < Lista::TAMANO_BINGO; j++) {
            if (obtenerPosicion(j, i)->GetValor() != "X") {
                flag = false;
            }
        }
        if (flag)
            fichas += 400;
    }
    return fichas;
}

int Lista::fichasDiagonalX() {
    bool flag;
    int fichas = 0;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        flag = true;
        if (obtenerPosicion(i, i)->GetValor() != "X") {
            flag = false;
        }
        if (flag)
            fichas += 800;
    }
    return fichas;
}

int Lista::fichas2DaDiagonalX() {
    bool flag;
    int fichas = 0;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        flag = true;
        if (obtenerPosicion(i, Lista::TAMANO_BINGO - i)->GetValor() != "X") {
            flag = false;
        }
        if (flag)
            fichas += 800;
    }
    return fichas;
}

int Lista::fichasFormaC() {
    bool flag = true;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        if ((obtenerPosicion(0, i)->GetValor() != "X") ||
                (obtenerPosicion(i, 0)->GetValor() != "X") ||
                (obtenerPosicion(4, i)->GetValor() != "X")) {
            flag = false;
        }
    }
    if (flag)
        return 1000;
    else
        return 0;
}

int Lista::fichasFormaX() {
    if (fichasDiagonalX() != 0 && fichas2DaDiagonalX() != 0)
        return 1200;
}

int Lista::fichasFormaU() {
    bool flag = true;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        if ((obtenerPosicion(i, 0)->GetValor() != "X") ||
                (obtenerPosicion(4, i)->GetValor() != "X") ||
                (obtenerPosicion(i, 4)->GetValor() != "X")) {
            flag = false;
        }
    }
    if (flag)
        return 1500;
    else
        return 0;
}

int Lista::fichasFormaO() {
    bool flag = true;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        if ((obtenerPosicion(0, 1)->GetValor() != "X") ||
                (obtenerPosicion(i, 0)->GetValor() != "X") ||
                (obtenerPosicion(4, i)->GetValor() != "X") ||
                (obtenerPosicion(i, 4)->GetValor() != "X")) {
            flag = false;
        }
    }
    if (flag)
        return 2000;
    else
        return 0;
}

int Lista::BingoCompleto() {
    bool flag = true;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        for (int j = 0; j < Lista::TAMANO_BINGO; j++) {
            if (obtenerPosicion(i, j)->GetValor() != "X") {
                flag = false;
            }
        }
    }
    if (flag)
        return 10000;
    else
        return 0;
}
