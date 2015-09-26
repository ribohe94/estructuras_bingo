/* 
 * File:   GestorJuego.h
 * Author: Riccardo
 *
 * Created on 22 September 2015, 19:58
 */

#ifndef GESTORJUEGO_H
#define	GESTORJUEGO_H
#include "Juego.h"
#include "ContenedorJugadores.h"

class GestorJuego {
public:
    GestorJuego(Jugador* jugadorActivo, int cantidadCartones);
    GestorJuego();
    GestorJuego(const GestorJuego& orig);
    virtual ~GestorJuego();
    //Sets & Gets
    int getCantidad() const;
    void setCantidad(int cantidad);
    Juego* getJuegoActivo() const;
    void setJuegoActivo(Juego* juegoActivo);
    Jugador* getJugadorActivo() const;
    void setJugadorActivo(Jugador* jugadorActivo);
    ContenedorJugadores* getJugadores() const;
    void setJugadores(ContenedorJugadores* jugadores);
    //Metodos
    void crearJuego(Jugador* j, int n);
    void iniciarJuegoHorizontal();
    void iniciarJuegoDiagonal();
    void iniciarJuegoC();
    void iniciarJuegoX();
    void iniciarJuegoU();
    void iniciarJuegoO();
    void iniciarJuegoBingo();
    void agregarJugador(Jugador* jugadorNuevo);
    bool ingresarValor();
    bool validarEntrada(int x, int y, int numeroCarton);
    void mostrarTablero();
    int obtenerProximoNumero();
    

    static int VALIDAR_INT();
    static string VALIDAR_STRING();
    static Jugador* ENCONTRAR_JUGADOR();
private:
    Jugador* jugadorActivo;
    Juego* juegoActivo;
    ContenedorJugadores* jugadores;
    int cantidad;
    int numeroActual;
    std::vector<int>::iterator it;
};

#endif	/* GESTORJUEGO_H */

