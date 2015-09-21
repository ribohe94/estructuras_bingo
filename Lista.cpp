/* 
 * File:   Lista.cpp
 * Author: Riccardo
 * 
 * Created on 29 August 2015, 23:31
 */

#include "Lista.h"

Lista::Lista() {
    primero = ultimo = NULL;
    generarBingo();
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
    std::vector<int>array1_15;
    std::vector<int>array16_30;
    std::vector<int>array31_45;
    std::vector<int>array46_60;
    std::vector<int>array61_75;

    for (int i = 1; i < 16; i++) {
        array1_15.push_back(i);
        array16_30.push_back(i + 15);
        array31_45.push_back(i + 30);
        array46_60.push_back(i + 45);
        array61_75.push_back(i + 60);
    }

    std::random_shuffle(array1_15.begin(), array1_15.end());
    std::random_shuffle(array16_30.begin(), array16_30.end());
    std::random_shuffle(array31_45.begin(), array31_45.end());
    std::random_shuffle(array46_60.begin(), array46_60.end());
    std::random_shuffle(array61_75.begin(), array61_75.end());

    std::vector<int>::iterator it1;
    std::vector<int>::iterator it2;
    std::vector<int>::iterator it3;
    std::vector<int>::iterator it4;
    std::vector<int>::iterator it5;

    it1 = array1_15.begin();
    it2 = array16_30.begin();
    it3 = array31_45.begin();
    it4 = array46_60.begin();
    it5 = array61_75.begin();

    //    for (it = array1_15.begin(); it < array1_15.end(); it++) {
    //        cout << *it << endl;
    //    }

    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        for (int j = 0; j < Lista::TAMANO_BINGO; j++) {
            if (j == 0)
                agregarNumero(new Nodo(i, j, *it1));
            if (j == 1)
                agregarNumero(new Nodo(i, j, *it2));
            if (j == 2)
                agregarNumero(new Nodo(i, j, *it3));
            if (j == 3)
                agregarNumero(new Nodo(i, j, *it4));
            if (j == 4)
                agregarNumero(new Nodo(i, j, *it5));

        }

        it1++;
        it2++;
        it3++;
        it4++;
        it5++;
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
            //            cout << " - " << aux->GetPosicionX() << ", " << aux->GetPosicionY() << " - ";
            if (aux->GetValor() == 0) {
                cout << "X  ";
            } else {
                cout << aux->GetValor() << "  ";
            }
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
            if (obtenerPosicion(i, j)->GetValor() != 0) {
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
            if (obtenerPosicion(j, i)->GetValor() != 0) {
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
        if (obtenerPosicion(i, i)->GetValor() != 0) {
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
        if (obtenerPosicion(i, Lista::TAMANO_BINGO - i)->GetValor() != 0) {
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
        if ((obtenerPosicion(0, i)->GetValor() != 0) ||
                (obtenerPosicion(i, 0)->GetValor() != 0) ||
                (obtenerPosicion(4, i)->GetValor() != 0)) {
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
    else
        return 0;
}

int Lista::fichasFormaU() {
    bool flag = true;
    for (int i = 0; i < Lista::TAMANO_BINGO; i++) {
        if ((obtenerPosicion(i, 0)->GetValor() != 0) ||
                (obtenerPosicion(4, i)->GetValor() != 0) ||
                (obtenerPosicion(i, 4)->GetValor() != 0)) {
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
        if ((obtenerPosicion(0, 1)->GetValor() != 0) ||
                (obtenerPosicion(i, 0)->GetValor() != 0) ||
                (obtenerPosicion(4, i)->GetValor() != 0) ||
                (obtenerPosicion(i, 4)->GetValor() != 0)) {
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
            if (obtenerPosicion(i, j)->GetValor() != 0) {
                flag = false;
            }
        }
    }
    if (flag)
        return 10000;
    else
        return 0;
}
