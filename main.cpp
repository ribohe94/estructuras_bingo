/* 
 * File:   main.cpp
 * Author: Riccardo
 *
 * Created on 21 de agosto de 2015, 22:26
 */

#include <cstdlib>

#include "Lista.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Lista* l1 = new Lista();
    l1->generarBingo();
    l1->mostrarLista();
    
    return 0;
}

