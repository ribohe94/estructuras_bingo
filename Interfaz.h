/* 
 * File:   Interfaz.h
 * Author: Riccardo
 *
 * Created on 22 September 2015, 19:58
 */

#ifndef INTERFAZ_H
#define	INTERFAZ_H
class GestorJuego;
#include "GestorJuego.h"

class Interfaz {
public:
    Interfaz();
    Interfaz(const Interfaz& orig);
    virtual ~Interfaz();
    //Metodos
    void init();
    void registroJugador();
    void iniciarSesion();
    void seleccioneJuego();
    void iniciarJuegoHorizontal();
    void iniciarJuegoDiagonal();
    void iniciarJuegoC();
    void iniciarJuegoX();
    void iniciarJuegoU();
    void iniciarJuegoO();
    void iniciarJuegoBingo();
    void mostrarJugadores();
    
private:
    GestorJuego* gestor;
};

#endif	/* INTERFAZ_H */

