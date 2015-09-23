/* 
 * File:   Interfaz.h
 * Author: Riccardo
 *
 * Created on 22 September 2015, 19:58
 */

#ifndef INTERFAZ_H
#define	INTERFAZ_H

class Interfaz {
public:
    Interfaz();
    Interfaz(const Interfaz& orig);
    virtual ~Interfaz();
    //Metodos
    void init();
    void registroJugador();
    void tipoJuego();
    void cantidadCartones();
    
private:

};

#endif	/* INTERFAZ_H */

