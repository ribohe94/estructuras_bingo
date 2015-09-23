/* 
 * File:   main.cpp
 * Author: Riccardo
 *
 * Created on 21 de agosto de 2015, 22:26
 */
#include <cstdlib>

#include "Jugador.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Jugador* j1 = new Jugador(4);
    j1->mostrarCartones();
//    int* n = (int*) 5;
//    printf("%p\n", (void*)n);
    
    
    return 0;
}

