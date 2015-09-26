/* 
 * File:   Jugador.h
 * Author: Estudiante
 *
 * Created on 19 de septiembre de 2015, 14:12
 */
#ifndef JUGADOR_H
#define	JUGADOR_H

#include <iostream>
#include <sstream>

using namespace std;

class Jugador {
public:
    Jugador();
    Jugador(const Jugador& orig);
    Jugador(int edad, int fichas, string nick, string nombre, string pass);
    virtual ~Jugador();
    //Sets & Gets
    int GetEdad() const;
    void SetEdad(int edad);
    string GetNick() const;
    void SetNick(string nick);
    string GetNombre() const;
    void SetNombre(string nombre);
    int GetFichas() const;
    void SetFichas(int fichas);
    string GetPass() const;
    void SetPass(string pass);
    
    string toString();
    
private:
    string nombre;
    string nick;
    int edad;
    int fichas;
    string pass;
    
};

#endif	/* JUGADOR_H */

