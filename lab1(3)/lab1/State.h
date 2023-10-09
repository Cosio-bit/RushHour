#ifndef STATE_H
#define STATE_H
#include <iostream>
#include "Autos.h"

// las operaciones basicamente donde estoy y que voy a hacer, no tiene que ver con los autos en si
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define UP2 5
#define DOWN2 6
#define LEFT2 7
#define RIGHT2 8
#define UP3 9
#define DOWN3 10
#define LEFT3 11
#define RIGHT3 12

class State{
    public:
        State(State *parent);
        State();
        ~State();
        int g; // costo acumulado
        Autos *autos; //cada estado guarda su formacion de autos
        State *parent; // es nulo si es estado inicial
};
#endif