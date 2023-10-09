#include "Maze.h"
#include <iostream>

// Constructor for initializing the maze with the given size
Maze::Maze(int size) {
    this->mazeSize = size;

    // Allocate memory for the maze grid
    this->maze = new int*[size];
    for (int i = 0; i < size; i++) {
        this->maze[i] = new int[size];

        // Initialize the maze cells to 0 (empty)
        for (int j = 0; j < size; j++) {
            this->maze[i][j] = 0;
        }
    }

    // Create the operations for moving within the maze
    this->op[0] = Operation(1);
    this->op[1] = Operation(-1);
    this->op[2] = Operation(2);
    this->op[3] = Operation(-2);
    this->op[4] = Operation(3);
    this->op[5] = Operation(-3);
    this->op[6] = Operation(0);
}



Maze::~Maze() {
    for (int i = 0; i < this->mazeSize; i++) {
        delete[] this->maze[i];
    }
    delete[] this->maze;
}




void Maze::setFinal(int x, int y) {
    this->finalx = x;
    this->finaly = y;
}
bool Maze::isFinal(State* state) {
    return (state->autos->getAuto(0)->x == finalx && state->autos->getAuto(0)->y == finaly);
}

int Maze::heuristic(State* state, int finalx, int finaly) {
    return abs(state->autos->getAuto(0)->x - finalx) + abs(state->autos->getAuto(0)->y- finaly);
}



// A* algorithm
State* Maze::solve(State* initialState) {
    // Create stacks for open and closed states
    Stack open(10);
    Stack closed(10);
    // Push the initial state to the open stack
    open.push(initialState);
    while (!open.isEmpty()) {
        // Pop the state with the lowest total cost (f = g + h) from the open stack
        State* current = open.pop();
        // Push the current state to the closed stack
        closed.push(current);
        // Check if the current state is the goal state
        if (this->isFinal(current)) {
            return current; }
        for (int i = 0; i < current->autos->amountOfAutos(); i++) {
            // Generate and evaluate successor states
            for (int j = 0; j <= 6; j++) {
                //for(int k = 0; k <= 6; k++){
                // Generate a new state
                State* newState = new State(current);
                newState->autos = current->autos;
                newState = this->op[j].operateAuto(newState, i);
                newState->autos->print();
                printf("\n");
                //newState = this->op[k].operateAuto(newState, 0);
                // Check if the new state is valid
                if (//!closed.contains(newState) &&
                    //!open.contains(newState) &&
                    newState->autos->checkValidAndDirection()) {
                        newState->autos->print();
                        // Calculate the heuristic value for the new state
                        int h = heuristic(newState, finalx, finaly);
                        // Calculate the total cost (f = g + h)
                        int g = current->g + 1;  // Assuming a cost of 1 to move to a neighboring state
                        int f = g + h;
                        newState->g = g;  // Update the g value for the new state
                        // Update the priority of the new state in the open stack
                        open.pushWithPriority(newState, f);
                }
            }
        }
    }
    // If no solution is found, return nullptr
    return nullptr;
}






