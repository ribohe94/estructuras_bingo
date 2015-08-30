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
private:
    int tamano;
};

#endif	/* LISTA_H */

