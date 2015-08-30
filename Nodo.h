/* 
 * File:   Nodo.h
 * Author: Riccardo
 *
 * Created on 29 August 2015, 23:31
 */

#ifndef NODO_H
#define	NODO_H

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    Nodo(int);
    virtual ~Nodo();
    //Sets & Gets
    Nodo GetAbajo() const;
    void SetAbajo(Nodo abajo);
    Nodo GetArriba() const;
    void SetArriba(Nodo arriba);
    Nodo GetDerecha() const;
    void SetDerecha(Nodo derecha);
    Nodo GetIzquierda() const;
    void SetIzquierda(Nodo izquierda);
    Nodo GetNe() const;
    void SetNe(Nodo ne);
    Nodo GetNo() const;
    void SetNo(Nodo no);
    int GetPosicionX() const;
    void SetPosicionX(int posicionX);
    int GetPosicionY() const;
    void SetPosicionY(int posicionY);
    Nodo GetSe() const;
    void SetSe(Nodo se);
    Nodo GetSo() const;
    void SetSo(Nodo so);
    int GetValor() const;
    void SetValor(int valor);

private:

    int valor;
    int posicionX;
    int posicionY;
    Nodo izquierda;
    Nodo derecha;
    Nodo arriba;
    Nodo abajo;
    Nodo no;
    Nodo ne;
    Nodo so;
    Nodo se;
    
};

#endif	/* NODO_H */

