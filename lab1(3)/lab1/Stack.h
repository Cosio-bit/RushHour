#include <iostream>
#include "State.h"

class Stack {
public:
    Stack(int size);
    ~Stack();
    void push(State* value);
    State* pop();
    bool isEmpty();
    void print();
    bool contains(State* value);
    void pushWithPriority(State* value, int priority);

private:
    State** stack;      // Pointer to the array that will store the stack
    int* priorities;    // Pointer to an array that stores priorities
    int top;
    int size;
};