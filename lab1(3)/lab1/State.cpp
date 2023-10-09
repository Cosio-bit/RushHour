#include "State.h"

State::State(State *parent) {
    this->parent = parent;
}

State::State() {
    // std::cout << "State constructor" << std::endl;
    this->parent=nullptr;
}

State::~State() {
    // std::cout << "State destructor" << std::endl;
}
/*
void State::print() {
    if (this->parent != NULL) {
        this->parent->print();
    }
    switch (this->op) {
        case UP:
            std::cout << "UP" << std::endl;
            break;
        case DOWN:
            std::cout << "DOWN" << std::endl;
            break;
        case LEFT:
            std::cout << "LEFT" << std::endl;
            break;
        case RIGHT:
            std::cout << "RIGHT" << std::endl;
            break;
        case UP2:
            std::cout << "UP2" << std::endl;
            break;
        case DOWN2:
            std::cout << "DOWN2" << std::endl;
            break;
        case LEFT2:
            std::cout << "LEFT2" << std::endl;
            break;
        case RIGHT2:
            std::cout << "RIGHT2" << std::endl;
            break;
        case UP3:    
            std::cout << "UP3" << std::endl;
            break;
        case DOWN3:                    
            std::cout << "DOWN3" << std::endl;
            break;
        case LEFT3:
            std::cout << "LEFT3" << std::endl;
            break;
        case RIGHT3:                            
            std::cout << "RIGHT3" << std::endl;
            break;

    }*/



