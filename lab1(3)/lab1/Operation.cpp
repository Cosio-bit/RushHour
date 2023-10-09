#include "Operation.h"

Operation::Operation(int step) {
    this->step = step;
}

Operation::Operation() {
    this->step = -1;
}

Operation::~Operation() {
    // std::cout << "Operation destructor" << std::endl;
}

void Operation::print() {
    std::cout << " step: " << this->step << std::endl;
}


State * Operation::operateAuto(State *estado, int autoIndex) {
    // Obtenemos el automóvil desde el estado
    // Calculamos el desplazamiento tal que el dir sea el mismo de op y el dir sea el mismo
    int dx = 0, dy = 0;
    if(estado->autos->getAuto(autoIndex)->dir == HORIZONTAL)
        dx = this->step;
    else if(estado->autos->getAuto(autoIndex)->dir == VERTICAL)
        dy = this->step;
    //printf("step: %d\n", this->step);
    //printf("dx: %d, dy: %d\n", dx, dy); 

    // Movemos el automóvil
    
    // reemplazamos el automóvil en el estado
    //autos1.replaceAuto(autoIndex, autos1.getAuto(autoIndex));
    
    // Creamos el nuevo estado
    //sacar lo de x, y
    //State *newState = new State(estado);
    //newState->autos = estado->autos;
    estado->autos->getAuto(autoIndex)->x += dx;
    estado->autos->getAuto(autoIndex)->y += dy;
    //newState->autos->printCarsGrid();

    return estado;
}



