/* 
 * File:   Jugador.cpp
 * Author: Estudiante
 * 
 * Created on 19 de septiembre de 2015, 14:12
 */

#include "Jugador.h"

Jugador::Jugador() {

}

Jugador::Jugador(const Jugador& orig) {
}

Jugador::Jugador(int edad, int fichas, string nick, string nombre, string pass) :
edad(edad), fichas(2000), nick(nick), nombre(nombre), pass(pass) {
}

Jugador::~Jugador() {
}

int Jugador::GetEdad() const {
    return edad;
}

void Jugador::SetEdad(int edad) {
    this->edad = edad;
}

string Jugador::GetNick() const {
    return nick;
}

void Jugador::SetNick(string nick) {
    this->nick = nick;
}

string Jugador::GetNombre() const {
    return nombre;
}

void Jugador::SetNombre(string nombre) {
    this->nombre = nombre;
}

int Jugador::GetFichas() const {
    return fichas;
}

void Jugador::SetFichas(int fichas) {
    this->fichas = fichas;
}

string Jugador::GetPass() const {
    return pass;
}

void Jugador::SetPass(string pass) {
    this->pass = pass;
}

string Jugador::toString() {
    stringstream s;
    s << "Nombre: " << nombre << endl
            << "Nick: " << nick << endl
            << "Edad: " << edad << endl
            << "Fichas" << fichas <<endl;
    return s.str();
}
