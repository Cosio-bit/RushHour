#include "Stack.h"
// Aqui vamos a implementar todos los metodos
// Constructor
Stack::Stack(int size) {
    this->size = size;
    this->top = -1;
    this->stack = new State*[size];
    this->priorities = new int[size]; // Initialize the priorities array
}

Stack::~Stack() {
    delete[] this->stack;
    delete[] this->priorities; // Deallocate the priorities array
}

void Stack::push(State *value) {
    if (this->top == this->size - 1) { // si ya no queda mas memoria entonces duplicamos
        State **newState = new State*[this->size * 2];
        for (int i = 0; i < this->size; i++) {
            newState[i] = this->stack[i];
        }
        delete[] this->stack;
        this->stack = newState;
        this->size *= 2;
    }    
    this->top++;
    this->stack[this->top] = value;
}

void Stack::pushWithPriority(State* value, int priority) {
    if (this->top == this->size - 1) { // If there's not enough space, double the size
        State** newState = new State*[this->size * 2];
        int* newPriorities = new int[this->size * 2];

        for (int i = 0; i <= this->top; i++) {
            newState[i] = this->stack[i];
            newPriorities[i] = this->priorities[i];
        }

        delete[] this->stack;
        delete[] this->priorities;

        this->stack = newState;
        this->priorities = newPriorities;

        this->size *= 2;
    }

    this->top++;
    this->stack[this->top] = value;
    this->priorities[this->top] = priority; // Store the priority alongside the state
}


State* Stack::pop() {
    if (this->isEmpty()) {
        throw "Stack is empty";
    }
    State *value = this->stack[this->top];
    this->top--;
    return value;
}

bool Stack::isEmpty() {
    return this->top == -1;
}

void Stack::print() {
    std::cout << "[";
    for (int i = 0; i < this->top; i++) {
        std::cout << this->stack[i]->autos->getAuto(0)->x << "-" << this->stack[i]->autos->getAuto(0)->x << ", ";
    }
    if (this->top != -1) {
        std::cout << this->stack[top]->autos->getAuto(0)->x << "-" << this->stack[top]->autos->getAuto(0)->x ;
    }
    std::cout << "]" << std::endl;
}

// This method checks if the stack contains a state with the same values as the given state
bool Stack::contains(State *value) {
    for (int i = 0; i <= this->top; i++) {
        if (this->stack[i]->autos->equalAutos(value->autos)) {
            return true;
        }
    }
    return false;
}