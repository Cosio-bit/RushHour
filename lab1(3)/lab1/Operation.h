#ifndef OPERATION_H
#define OPERATION_H


#include <iostream>
#include "State.h"

#define HORIZONTAL 1
#define VERTICAL 0


static int op[7];


class Operation {
public:
    int step; // 1, 2 o 3   
    Operation(int step);
    Operation();
    ~Operation();
    void print(); // imprime todas las operaciones hasta la raiz
    //State *operate(State *s); // podria haber sido x[dir] += step
    State * operateAuto(State *s, int autoIndex);
};



#endif